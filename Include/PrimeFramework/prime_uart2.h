/**
 * \file	prime_uart2.h
 * \brief   UART 2 Driver Discription for LPC1768.
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
 * \ingroup PF_UART
 * \defgroup PF_UART2 UART 2
 * @{
 * 
 * 	\brief UART 2 driver
 * 	\details  UART 2 driver for onchip UART 2 Peripheral
 */

/** \brief UART2 Configuration macros 		*/
#define UART2_CH				UART2
#define UART2_CHANNEL		PERIPH(UART2_CH)
#define UART2_INT_HANDLER	INT_HANDLER(UART2_CH)

/** 
 * \brief UART2 FIFO Macro
 * \note PF_UART2_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_UART2_USE_FIFO  is set to 2 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_UART2_USE_FIFO				1
	
#if(PF_UART2_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define UART2_BUFFER_SIZE		256
#endif	// #if(PF_UART2_USE_FIFO != 0)

/**	\brief	Enumeration for baudrate to set for UART2 channel				*/
typedef enum
{
	enUart2Baudrate_2400 = 0,		/**< baudrate 2400					*/
	enUart2Baudrate_4800,			/**< baudrate 4800					*/
	enUart2Baudrate_9600,			/**< baudrate 9600					*/
	enUart2Baudrate_19200,			/**< baudrate 19200					*/
	enUart2Baudrate_38400,			/**< baudrate 34800					*/
	enUart2Baudrate_57600,			/**< baudrate 57600					*/
	enUart2Baudrate_115200,			/**< baudrate 115200				*/
}PFEnUart2Baudrate;

/** \brief Enumeration for databits for UART2 channel							*/
typedef enum
{
	enUart2Databits_5 = 0,			/**< databits 5						*/
	enUart2Databits_6,				/**< databits 6						*/
	enUart2Databits_7,				/**< databits 7						*/
	enUart2Databits_8,				/**< databits 8						*/
}PFEnUart2Databits;

/**	\brief	Enumeration for parity setting for the UART2 channel				*/
typedef enum
{
	enUart2ParityNone = 0x00,		/**< no parity						*/
	enUart2parityOdd = 0x01,			/**< odd parity						*/
	enUart2ParityEven = 0x03,		/**< even parity					*/
	enUart2ParityOne = 0x05,			/**< forced one parity				*/
	enUart2ParityZero = 0x07			/**< forced zero parity				*/
}PFEnUart2Parity;

/**	\brief	Enumeration for number of stop bits to use for UART2 channel		*/
typedef enum
{
	enUart2StopBits_1 = 0,			/**< one stop bit					*/
	enUart2StopBits_2,				/**< two stop bits					*/
}PFEnUart2StopBits;

/**	\brief	Enumeration for interrupts to enable for the UART2 channel		*/
typedef enum
{
	enUart2IntNone = 0,				/**< no interrupt					*/
	enUart2IntRx,					/**< receive interrupt				*/
	enUart2IntTx,					/**< transmit interrupt				*/
	enUart2IntTxRx					/**< transmit and receive interrupt	*/
}PFEnUart2Interrupt;

/**	\brief	UART2 configuration structure									*/
typedef struct
{
	PFEnPclkDivider		clkDiv;				/**< Peripheral clock divider for UART2 module		*/
	PFEnUart2Baudrate 	baudrate;			/**< Set baudrate for channel						*/
	PFEnUart2Databits	databits;			/**< Data bits used for one transmission			*/
	PFEnUart2Parity 	parity;				/**< Parity to be used for communication			*/
	PFEnUart2StopBits 	stopBits;			/**< Number of stop bits to be used					*/
	PFEnUart2Interrupt 	interrupts;			/**< Interrupts to enable for the channel			*/
#if(PF_UART2_USE_FIFO == 0)
	PFcallback			transmitCallback;	/**< User call back for transmit interrupt			*/
	PFcallback			receiveCallback;	/**< User call back for receive interrupt			*/
#endif	// 	#if(PF_UART2_USE_FIFO == 0)	
}PFCfgUart2;

/**
 * \brief pointer to PFCfgGpio structure
 */
typedef PFCfgUart2* PFpCfgUart2;

/**
 * Initializes the UART2 channel with provided settings
 *
 * \param config Pointer to configuration structure which contains the settings for the communication channel to be used.
 *
 * \return UART2 initialization status.
 */
PFEnStatus pfUart2Open(PFpCfgUart2 config);

/**
 * Turn offs the UART2 channel
 */
void pfUart2Close(void);

/**
 * This function writes one byte to UART2 data register.
 *
 * \param data 8 bit data to write to the UART2 channel.
 * \return UART2 write status.
 */
PFEnStatus pfUart2WriteByte(PFbyte data);

/**
 * The function sends multiple bytes on UART2 channel.  
 * If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 * Otherwise it will wait in the function and send each byte by polling the line status.
 *
 * \param data Pointer to the data to be sent.
 * \param size Total number of bytes to send.
 *
 * \return UART2 write status.
 */
PFEnStatus pfUart2Write(PFbyte* data, PFdword size);

/**
 * The function sends a string on the UART2 channel.
 * The function needs a null terminated string.
 * 
 * \param data Pointer to the data to be sent.
 * \return UART2 write status.
 */
PFEnStatus pfUart2WriteString(const char * data);

/**
 * The function reads one byte from UART2 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param rxByte Pointer to a byte where the received byte will be loaded
 *
 * \return read byte status.
 */
PFEnStatus pfUart2ReadByte(PFbyte* rxByte);

/**
 * The function reads one byte from UART2 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param data Unsigned char pointer to the buffer where the read data should be loaded.
 * \param size Total number of bytes to read.
 * \param readBytes pointer to double word, in which function will fill number bytes actually read. 
 *
 * \return UART2 read status.
 */
PFEnStatus pfUart2Read(PFbyte* data, PFdword size, PFdword* readBytes);

#if(PF_UART2_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart2GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in UART2 buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart2GetRxBufferCount(PFdword* count);

/**
 * This function empties the receive buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart2RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart2GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in UART2 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart2GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart2TxBufferFlush(void);
#endif	// #if(PF_UART2_USE_FIFO != 0)

/** @} */