/**
 * \file	prime_can2.h
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
 * \defgroup PF_CAN2 CAN 2
 * @{
 * 	
 * 	\brief CAN2 driver
 * 	\details  CAN driver for onchip CAN Peripheral
 */
 
/** \brief CAN2 configuration MACRO	*/ 
#define CAN2_CONTROLLER			2
#define CAN2_CH					PF_CONCAT(CAN,CAN2_CONTROLLER)
#define CAN2_CHANNEL			PERIPH(CAN2_CH)
#define CAN2_INT_HANDLER		INT_HANDLER(CAN2_CH)

/** 
 * \brief CAN2 FIFO Macro
 * \note PF_CAN2_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_CAN2_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */	
#define PF_CAN2_USE_FIFO				0
	
#if(PF_CAN2_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define CAN2_BUFFER_SIZE		256
#endif	// #if(PF_CAN2_USE_FIFO != 0)

/** Enumeration for CAN2 status flags		*/
typedef enum
{
	enCan2StatusRxBuffer = BIT_MASK_0,			/**< Message received status					*/
	enCan2StatusDataOverrun = BIT_MASK_1,		/**< Received data overflow	status				*/
	enCan2StatusTxBuffer = BIT_MASK_2,			/**< Transmit buffer occupancy status			*/
	enCan2StatusTxComplete = BIT_MASK_3,		/**< Transmit complete status					*/
	enCan2StatusReceive = BIT_MASK_4,			/**< CAN2 message receive in progress status		*/
	enCan2StatusTransmit = BIT_MASK_5,			/**< CAN2 message transmit in progress status	*/
	enCan2StatusError = BIT_MASK_6,				/**< Error counter level status					*/
	enCan2StatusBus = BIT_MASK_7				/**< CAN2 bus activity status					*/
}PFEnCan2Status;
	
/**	\brief	Enumeration for interrupts to enable for the CAN2 channel		*/
typedef enum
{
	enCan2IntNone = 0,				/**< no interrupt	*/
	enCan2IntRx,						/**< receive interrupt	*/
	enCan2IntTx,						/**< transmit interrupt	*/
	enCan2IntTxRx					/**< transmit and receive interrupt	*/
}PFEnCan2Interrupt;

/**	\brief	CAN2 Configuration Structure				*/
typedef struct
{
#if(PF_CAN2_USE_FIFO == 0)			
	PFcallback rxCallback;			/**< Callback for message receive interrupt			*/
	PFcallback txCallback;			/**< Callback for message transmit interrupt		*/
#endif // #if(PF_CAN2_USE_FIFO == 0)	
	PFdword baudrate;				/**< Baudrate for CAN2 module						*/
	PFcallback errCallback;			/**< Callback for error counter overflow			*/
	PFEnPclkDivider clkDiv;			/**< Peripheral clock divider for CAN2 module		*/
	PFEnCan2Interrupt interrupt;		/**< Interrupts to enable for CAN2 channel			*/
}PFCfgCan2;

/** \brief Pointer to PFCfgCan2 structure		*/
typedef PFCfgCan2* PFpCfgCan2;

/**
 * Initializes CAN2 channel with provided settings
 * 
 * \param config Pointer to configuration structure for CAN2 channel.
 * \return Status
 */
PFEnStatus pfCan2Open(PFpCfgCan2 config);

/**
 * Deinitializes and turns off CAN2 channel.
 * 
 * \return Status
 */
PFEnStatus pfCan2Close(void);

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
PFEnStatus pfCan2Write(PFpCanMsgHeader msgHeader,PFbyte* data, PFdword size);

/**
 * Reads a message received from CAN2 bus. 
 * According to the macro and initialization settings chosen, 
 * this function will decide to read the message directly or from FIFO buffer.
 * 
 * \param message Pointer to CAN2 message structure at which the received message should be stored.
 * \return Status
 */
PFEnStatus pfCan2Read(PFpCanMessage message);

/**
 * The function will check the CAN2 status flag for mentioned parameter.
 *
 * \param param Parameter to check the status for.
 * \return Status of the mentioned parameter, if the flag is raised is or not.
 */
PFEnBoolean pfCan2CheckStatus(PFEnCan2Status param);

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

PFEnStatus pfCan2GetIntStatus(PFdword* status);

/**
 * This function gets Control status of CAN2 channel.
 * 
 * \param status pointer to Control status.
 * \return Set Channel status.
 */
 
PFEnStatus pfCan2GetCtrlStatus(PFdword* status);

/**
 * The function provides interface to read transmission error counter.
 *
 * \param errCount Pointer to byte to which the function should write error counter value.
 * \return status
 */
 
PFEnStatus pfCan2GetTxErrCounter(PFbyte* errCount);

/**
 * The function provides interface to read reception error counter.
 *
 * \param errCount Pointer to byte to which the function should write error counter value.
 * \return status
 */
PFEnStatus pfCan2GetRxErrCounter(PFbyte* errCount);

#if(PF_CAN2_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan2GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in CAN2 buffer.
 *
 * \param count Pointer to variable where count for CAN2 messages received in buffer will be loaded.
 * 
 * \return Buffer count status.
 */
PFEnStatus pfCan2GetRxBufferCount(PFdword* count);


/**
 * This function empties the receive buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfCan2RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan2GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in CAN2 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfCan2GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfCan2TxBufferFlush(void);


#endif	// #if(PF_CAN2_USE_FIFO != 0)

/** @} */