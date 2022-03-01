/**
 * \file	prime_can1.h
 * \brief   CAN Driver Discription for LPC1768.
 * \copyright Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 * 
 * Review status: NO
 *
 */
#pragma once

/**
 * \ingroup PF_CAN
 * \defgroup PF_CAN1 CAN 1
 * @{
 * 	
 * 	\brief CAN1 driver
 * 	\details  CAN driver for onchip CAN Peripheral
 */
 
/** \brief CAN1 configuration MACRO	*/ 
#define CAN1_CONTROLLER			1
#define CAN1_CH					PF_CONCAT(CAN,CAN1_CONTROLLER)
#define CAN1_CHANNEL			PERIPH(CAN1_CH)
#define CAN1_INT_HANDLER		INT_HANDLER(CAN1_CH)

/** 
 * \brief CAN1 FIFO Macro
 * \note PF_CAN1_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_CAN1_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */	
#define PF_CAN1_USE_FIFO				1
	
#if(PF_CAN1_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define CAN1_BUFFER_SIZE		256
#endif	// #if(PF_CAN1_USE_FIFO != 0)

/** \brief Enumeration for CAN1 status flags		*/
typedef enum
{
	enCan1StatusRxBuffer = BIT_MASK_0,		/**< Message received status					*/
	enCan1StatusDataOverrun = BIT_MASK_1,	/**< Received data overflow	status				*/
	enCan1StatusTxBuffer = BIT_MASK_2,		/**< Transmit buffer occupancy status			*/
	enCan1StatusTxComplete = BIT_MASK_3,		/**< Transmit complete status					*/
	enCan1StatusReceive = BIT_MASK_4,		/**< CAN1 message receive in progress status		*/
	enCan1StatusTransmit = BIT_MASK_5,		/**< CAN1 message transmit in progress status	*/
	enCan1StatusError = BIT_MASK_6,			/**< Error counter level status					*/
	enCan1StatusBus = BIT_MASK_7				/**< CAN1 bus activity status					*/
}PFEnCan1Status;
	
/**	\brief	Enumeration for interrupts to enable for the CAN1 channel		*/
typedef enum
{
	enCan1IntNone = 0,				/**< no interrupt	*/
	enCan1IntRx,						/**< receive interrupt	*/
	enCan1IntTx,						/**< transmit interrupt	*/
	enCan1IntTxRx					/**< transmit and receive interrupt	*/
}PFEnCan1Interrupt;

/**	\brief	CAN1 Configuration Structure				*/
typedef struct
{
#if(PF_CAN1_USE_FIFO == 0)			
	PFcallback rxCallback;			/**< Callback for message receive interrupt			*/
	PFcallback txCallback;			/**< Callback for message transmit interrupt		*/
#endif // #if(PF_CAN1_USE_FIFO == 0)	
	PFdword baudrate;				/**< Baudrate for CAN1 module						*/
	PFcallback errCallback;			/**< Callback for error counter overflow			*/
	PFEnPclkDivider clkDiv;			/**< Peripheral clock divider for CAN1 module		*/
	PFEnCan1Interrupt interrupt;		/**< Interrupts to enable for CAN1 channel			*/
}PFCfgCan1;

/** \brief Pointer to PFCfgCan1 structure		*/
typedef PFCfgCan1* PFpCfgCan1;

/**
 * Initializes CAN1 channel with provided settings
 * 
 * \param config Pointer to configuration structure for CAN1 channel.
 * \return Status
 */
PFEnStatus pfCan1Open(PFpCfgCan1 config);

/**
 * Deinitializes and turns off CAN1 channel.
 * 
 * \return Status
 */
PFEnStatus pfCan1Close(void);

/**
 * This function Sends multiple messages (with same message header) over CAN2 bus. 
 * It creates multiple messages to send more than 8 bytes of data.
 * According to the macro and initialization settings chosen, 
 * this function will decide to write the message directly or push it onto FIFO buffer.
 * 
 * \param msgHeader Pointer to CAN message header structure to be used.
 * \param data Pointer to the data to be sent. 
 * \param size Total number of bytes to send.
 * \return CAN2 write data Status.
 */
PFEnStatus pfCan1Write(PFpCanMsgHeader msgHeader,PFbyte* data, PFdword size);

/**
 * Reads a message received from CAN1 bus. 
 * According to the macro and initialization settings chosen, 
 * this function will decide to read the message directly or from FIFO buffer.
 * 
 * \param message Pointer to CAN1 message structure at which the received message should be stored.
 * \return Status
 */
PFEnStatus pfCan1Read(PFpCanMessage message);

/**
 * The function will check the CAN1 status flag for mentioned parameter.
 *
 * \param param Parameter to check the status for.
 * \return Status of the mentioned parameter, if the flag is raised is or not.
 */
PFEnBoolean pfCan1CheckStatus(PFEnCan1Status param);

/**
 * The function will check the CAN2 status flag for mentioned parameter.
 *
 * \param cmd Command
 * \param enable State.
 * 
 * \return Status of the mentioned parameter, if the flag is raised is or not.
 */
PFEnStatus pfCan2SetCommand(PFdword cmd, PFEnBoolean enable);

/**
 * This function gets interrupt status of CAN1 channel.
 * 
 * \param status pointer to Interrupt status.
 * \return Set Channel status.
 */

PFEnStatus pfCan1GetIntStatus(PFdword* status);

/**
 * This function gets Control status of CAN1 channel.
 * 
 * \param status pointer to Control status.
 * \return Set Channel status.
 */
 
PFEnStatus pfCan1GetCtrlStatus(PFdword* status);

/**
 * The function provides interface to read transmission error counter.
 *
 * \param errCount Pointer to byte to which the function should write error counter value.
 * \return status
 */
 
PFEnStatus pfCan1GetTxErrCounter(PFbyte* errCount);

/**
 * The function provides interface to read reception error counter.
 *
 * \param errCount Pointer to byte to which the function should write error counter value.
 * \return status
 */
PFEnStatus pfCan1GetRxErrCounter(PFbyte* errCount);

#if(PF_CAN1_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan1GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in CAN1 buffer.
 *
 * \param count Pointer to variable where count for CAN1 messages received in buffer will be loaded.
 * 
 * \return Buffer count status.
 */
PFEnStatus pfCan1GetRxBufferCount(PFdword* count);

/**
 * This function empties the receive buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfCan1RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan1GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in CAN1 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan1GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfCan1TxBufferFlush(void);



#endif	// #if(PF_CAN1_USE_FIFO != 0)

/** @} */
 