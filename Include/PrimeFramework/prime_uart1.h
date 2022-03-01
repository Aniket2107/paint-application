/**
 * \file	prime_uart1.h
 * \brief   UART 1 Driver Discription for LPC1768.
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
 * \defgroup PF_UART1 UART 1
 * @{
 * 
 * 	\brief UART 1 driver
 * 	\details  UART 1 driver for onchip UART 1 Peripheral
 */

/** \brief UART1 Configuration macros 		*/
#define UART1_CH				UART1
#define UART1_CHANNEL		PERIPH(UART1_CH)
#define UART1_INT_HANDLER	INT_HANDLER(UART1_CH)

/** 
 * \brief UART1 FIFO Macro
 * \note PF_UART1_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_UART1_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_UART1_USE_FIFO				0
	
#if(PF_UART1_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define UART1_BUFFER_SIZE		256
#endif	// #if(PF_UART1_USE_FIFO != 0)

/**	\brief	Enumeration for baudrate to set for UART1 channel				*/
typedef enum
{
	enUart1Baudrate_2400 = 0,		/**< baudrate 2400					*/
	enUart1Baudrate_4800,			/**< baudrate 4800					*/
	enUart1Baudrate_9600,			/**< baudrate 9600					*/
	enUart1Baudrate_19200,			/**< baudrate 19200					*/
	enUart1Baudrate_38400,			/**< baudrate 34800					*/
	enUart1Baudrate_57600,			/**< baudrate 57600					*/
	enUart1Baudrate_115200,			/**< baudrate 115200				*/
}PFEnUart1Baudrate;

/** \brief Enumeration for databits for UART1 channel							*/
typedef enum
{
	enUart1Databits_5 = 0,			/**< databits 5						*/
	enUart1Databits_6,				/**< databits 6						*/
	enUart1Databits_7,				/**< databits 7						*/
	enUart1Databits_8,				/**< databits 8						*/
}PFEnUart1Databits;

/**	\brief	Enumeration for parity setting for the UART1 channel				*/
typedef enum
{
	enUart1ParityNone = 0x00,		/**< no parity						*/
	enUart1parityOdd = 0x01,			/**< odd parity						*/
	enUart1ParityEven = 0x03,		/**< even parity					*/
	enUart1ParityOne = 0x05,			/**< forced one parity				*/
	enUart1ParityZero = 0x07			/**< forced zero parity				*/
}PFEnUart1Parity;

/**	\brief	Enumeration for number of stop bits to use for UART1 channel		*/
typedef enum
{
	enUart1StopBits_1 = 0,			/**< one stop bit					*/
	enUart1StopBits_2,				/**< two stop bits					*/
}PFEnUart1StopBits;

/**	\brief	Enumeration for interrupts to enable for the UART1 channel		*/
typedef enum
{
	enUart1IntNone = 0,				/**< no interrupt					*/
	enUart1IntRx,					/**< receive interrupt				*/
	enUart1IntTx,					/**< transmit interrupt				*/
	enUart1IntTxRx					/**< transmit and receive interrupt	*/
}PFEnUart1Interrupt;

/**	\brief	UART1 configuration structure									*/
typedef struct
{
	PFEnPclkDivider		clkDiv;				/**< Peripheral clock divider for UART1 module		*/
	PFEnUart1Baudrate 	baudrate;			/**< Set baudrate for channel						*/
	PFEnUart1Databits	databits;			/**< Data bits used for one transmission			*/
	PFEnUart1Parity 	parity;				/**< Parity to be used for communication			*/
	PFEnUart1StopBits 	stopBits;			/**< Number of stop bits to be used					*/
	PFEnUart1Interrupt 	interrupts;			/**< Interrupts to enable for the channel			*/
#if(PF_UART1_USE_FIFO == 0)
	PFcallback			transmitCallback;	/**< User call back for transmit interrupt			*/
	PFcallback			receiveCallback;	/**< User call back for receive interrupt			*/
#endif	// 	#if(PF_UART1_USE_FIFO == 0)	
}PFCfgUart1;

/**
 * \brief pointer to PFCfgGpio structure
 */
typedef PFCfgUart1* PFpCfgUart1;

/**
 * Initializes the UART1 channel with provided settings
 *
 * \param config Pointer to configuration structure which contains the settings for the communication channel to be used.
 *
 * \return UART1 initialization status.
 */
PFEnStatus pfUart1Open(PFpCfgUart1 config);

/**
 * Turn offs the UART1 channel
 */
void pfUart1Close(void);

/**
 * This function writes one byte to UART1 data register.
 *
 * \param data 8 bit data to write to the UART1 channel.
 * \return UART1 write status.
 */
PFEnStatus pfUart1WriteByte(PFbyte data);

/**
 * The function sends multiple bytes on UART1 channel.  
 * If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 * Otherwise it will wait in the function and send each byte by polling the line status.
 *
 * \param data Pointer to the data to be sent.
 * \param size Total number of bytes to send.
 *
 * \return UART1 write status.
 */
PFEnStatus pfUart1Write(PFbyte* data, PFdword size);

/**
 * The function sends a string on the UART1 channel.
 * The function needs a null terminated string.
 * 
 * \param data Pointer to the data to be sent.
 * \return UART1 write status.
 */
PFEnStatus pfUart1WriteString(const char * data);

/**
 * The function reads one byte from UART1 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param rxByte Pointer to a byte where the received byte will be loaded
 *
 * \return read byte status.
 */
PFEnStatus pfUart1ReadByte(PFbyte* rxByte);

/**
 * The function reads one byte from UART1 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param data Unsigned char pointer to the buffer where the read data should be loaded.
 * \param size Total number of bytes to read.
 * \param readBytes pointer to double word, in which function will fill number bytes actually read. 
 *
 * \return UART1 read status.
 */
PFEnStatus pfUart1Read(PFbyte* data, PFdword size, PFdword* readBytes);

#if(PF_UART1_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart1GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in UART1 buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart1GetRxBufferCount(PFdword* count);

/**
 * This function empties the receive buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart1RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart1GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in UART1 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart1GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart1TxBufferFlush(void);
#endif	// #if(PF_UART1_USE_FIFO != 0)

/** @} */