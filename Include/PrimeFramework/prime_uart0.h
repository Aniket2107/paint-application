/**
 * \file	prime_uart0.h
 * \brief   UART 0 Driver Discription for LPC1768.
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
 * \defgroup PF_UART0 UART 0
 * @{
 * 
 * 	\brief UART 0 driver
 * 	\details  UART 0 driver for onchip UART 0 Peripheral
 */

/** \brief UART0 Configuration macros 		*/
#define UART0_CH			UART0
#define UART0_CHANNEL		PERIPH(UART0_CH)
#define UART0_INT_HANDLER	INT_HANDLER(UART0_CH)

/** 
 * \brief UART0 FIFO Macro
 * \note PF_UART0_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_UART0_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_UART0_USE_FIFO				1
	
#if(PF_UART0_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define UART0_BUFFER_SIZE		256
#endif	// #if(PF_UART0_USE_FIFO != 0)

/**	\brief	Enumeration for baudrate to set for UART0 channel				*/
typedef enum
{
	enUart0Baudrate_2400 = 0,		/**< baudrate 2400					*/
	enUart0Baudrate_4800,			/**< baudrate 4800					*/
	enUart0Baudrate_9600,			/**< baudrate 9600					*/
	enUart0Baudrate_19200,			/**< baudrate 19200					*/
	enUart0Baudrate_38400,			/**< baudrate 34800					*/
	enUart0Baudrate_57600,			/**< baudrate 57600					*/
	enUart0Baudrate_115200,			/**< baudrate 115200				*/
}PFEnUart0Baudrate;

/** \brief Enumeration for databits for UART0 channel							*/
typedef enum
{
	enUart0Databits_5 = 0,			/**< databits 5						*/
	enUart0Databits_6,				/**< databits 6						*/
	enUart0Databits_7,				/**< databits 7						*/
	enUart0Databits_8,				/**< databits 8						*/
}PFEnUart0Databits;

/**	\brief	Enumeration for parity setting for the UART0 channel				*/
typedef enum
{
	enUart0ParityNone = 0x00,		/**< no parity						*/
	enUart0parityOdd = 0x01,			/**< odd parity						*/
	enUart0ParityEven = 0x03,		/**< even parity					*/
	enUart0ParityOne = 0x05,			/**< forced one parity				*/
	enUart0ParityZero = 0x07			/**< forced zero parity				*/
}PFEnUart0Parity;

/**	\brief	Enumeration for number of stop bits to use for UART0 channel		*/
typedef enum
{
	enUart0StopBits_1 = 0,			/**< one stop bit					*/
	enUart0StopBits_2,				/**< two stop bits					*/
}PFEnUart0StopBits;

/**	\brief	Enumeration for interrupts to enable for the UART0 channel		*/
typedef enum
{
	enUart0IntNone = 0,				/**< no interrupt					*/
	enUart0IntRx,					/**< receive interrupt				*/
	enUart0IntTx,					/**< transmit interrupt				*/
	enUart0IntTxRx					/**< transmit and receive interrupt	*/
}PFEnUart0Interrupt;

/**	\brief	UART0 configuration structure									*/
typedef struct
{
	PFEnPclkDivider		clkDiv;				/**< Peripheral clock divider for UART0 module		*/
	PFEnUart0Baudrate 	baudrate;			/**< Set baudrate for channel						*/
	PFEnUart0Databits	databits;			/**< Data bits used for one transmission			*/
	PFEnUart0Parity 	parity;				/**< Parity to be used for communication			*/
	PFEnUart0StopBits 	stopBits;			/**< Number of stop bits to be used					*/
	PFEnUart0Interrupt 	interrupts;			/**< Interrupts to enable for the channel			*/
#if(PF_UART0_USE_FIFO == 0)
	PFcallback			transmitCallback;	/**< User call back for transmit interrupt			*/
	PFcallback			receiveCallback;	/**< User call back for receive interrupt			*/
#endif	// 	#if(PF_UART0_USE_FIFO == 0)	
}PFCfgUart0;

/**
 * \brief pointer to PFCfgGpio structure
 */
typedef PFCfgUart0* PFpCfgUart0;

/**
 * Initializes the UART0 channel with provided settings
 *
 * \param config Pointer to configuration structure which contains the settings for the communication channel to be used.
 *
 * \return UART0 initialization status.
 */
PFEnStatus pfUart0Open(PFpCfgUart0 config);

/**
 * Turn offs the UART0 channel
 */
void pfUart0Close(void);

/**
 * This function writes one byte to UART0 data register.
 *
 * \param data 8 bit data to write to the UART0 channel.
 * \return UART0 write status.
 */
PFEnStatus pfUart0WriteByte(PFbyte data);

/**
 * The function sends multiple bytes on UART0 channel.  
 * If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 * Otherwise it will wait in the function and send each byte by polling the line status.
 *
 * \param data Pointer to the data to be sent.
 * \param size Total number of bytes to send.
 *
 * \return UART0 write status.
 */
PFEnStatus pfUart0Write(PFbyte* data, PFdword size);

/**
 * The function sends a string on the UART0 channel.
 * The function needs a null terminated string.
 * 
 * \param data Pointer to the data to be sent.
 * \return UART0 write status.
 */
PFEnStatus pfUart0WriteString(const char * data);

/**
 * The function reads one byte from UART0 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param rxByte Pointer to a byte where the received byte will be loaded
 *
 * \return read byte status.
 */
PFEnStatus pfUart0ReadByte(PFbyte* rxByte);

/**
 * The function reads one byte from UART0 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param data Unsigned char pointer to the buffer where the read data should be loaded.
 * \param size Total number of bytes to read.
 * \param readBytes pointer to double word, in which function will fill number bytes actually read. 
 *
 * \return UART0 read status.
 */
PFEnStatus pfUart0Read(PFbyte* data, PFdword size, PFdword* readBytes);

#if(PF_UART0_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart0GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in UART0 buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart0GetRxBufferCount(PFdword* count);

/**
 * This function empties the receive buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart0RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart0GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in UART0 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart0GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart0TxBufferFlush(void);
#endif	// #if(PF_UART0_USE_FIFO != 0)

/** @} */