/**
 * \file	prime_uart3.h
 * \brief   UART 3 Driver Discription for LPC1768.
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
 * \defgroup PF_UART3 UART 3
 * @{
 * 
 * 	\brief UART 3 driver
 * 	\details  UART 3 driver for onchip UART 3 Peripheral
 */

/** \brief UART3 Configuration macros 		*/
#define UART3_CH				UART3
#define UART3_CHANNEL		PERIPH(UART3_CH)
#define UART3_INT_HANDLER	INT_HANDLER(UART3_CH)

/** 
 * \brief UART3 FIFO Macro
 * \note PF_UART3_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_UART3_USE_FIFO  is set to 2 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_UART3_USE_FIFO				0
	
#if(PF_UART3_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
	#define UART3_BUFFER_SIZE		256
#endif	// #if(PF_UART3_USE_FIFO != 0)

/**	\brief	Enumeration for baudrate to set for UART3 channel				*/
typedef enum
{
	enUart3Baudrate_2400 = 0,		/**< baudrate 2400					*/
	enUart3Baudrate_4800,			/**< baudrate 4800					*/
	enUart3Baudrate_9600,			/**< baudrate 9600					*/
	enUart3Baudrate_19200,			/**< baudrate 19200					*/
	enUart3Baudrate_38400,			/**< baudrate 34800					*/
	enUart3Baudrate_57600,			/**< baudrate 57600					*/
	enUart3Baudrate_115200,			/**< baudrate 115200				*/
}PFEnUart3Baudrate;

/** \brief Enumeration for databits for UART3 channel							*/
typedef enum
{
	enUart3Databits_5 = 0,			/**< databits 5						*/
	enUart3Databits_6,				/**< databits 6						*/
	enUart3Databits_7,				/**< databits 7						*/
	enUart3Databits_8,				/**< databits 8						*/
}PFEnUart3Databits;

/**	\brief	Enumeration for parity setting for the UART3 channel				*/
typedef enum
{
	enUart3ParityNone = 0x00,		/**< no parity						*/
	enUart3parityOdd = 0x01,			/**< odd parity						*/
	enUart3ParityEven = 0x03,		/**< even parity					*/
	enUart3ParityOne = 0x05,			/**< forced one parity				*/
	enUart3ParityZero = 0x07			/**< forced zero parity				*/
}PFEnUart3Parity;

/**	\brief	Enumeration for number of stop bits to use for UART3 channel		*/
typedef enum
{
	enUart3StopBits_1 = 0,			/**< one stop bit					*/
	enUart3StopBits_2,				/**< two stop bits					*/
}PFEnUart3StopBits;

/**	\brief	Enumeration for interrupts to enable for the UART3 channel		*/
typedef enum
{
	enUart3IntNone = 0,				/**< no interrupt					*/
	enUart3IntRx,					/**< receive interrupt				*/
	enUart3IntTx,					/**< transmit interrupt				*/
	enUart3IntTxRx					/**< transmit and receive interrupt	*/
}PFEnUart3Interrupt;

/**	\brief	UART3 configuration structure									*/
typedef struct
{
	PFEnPclkDivider		clkDiv;				/**< Peripheral clock divider for UART3 module		*/
	PFEnUart3Baudrate 	baudrate;			/**< Set baudrate for channel						*/
	PFEnUart3Databits	databits;			/**< Data bits used for one transmission			*/
	PFEnUart3Parity 	parity;				/**< Parity to be used for communication			*/
	PFEnUart3StopBits 	stopBits;			/**< Number of stop bits to be used					*/
	PFEnUart3Interrupt 	interrupts;			/**< Interrupts to enable for the channel			*/
#if(PF_UART3_USE_FIFO == 0)
	PFcallback			transmitCallback;	/**< User call back for transmit interrupt			*/
	PFcallback			receiveCallback;	/**< User call back for receive interrupt			*/
#endif	// 	#if(PF_UART3_USE_FIFO == 0)
}PFCfgUart3;

/**
 * \brief pointer to PFCfgGpio structure
 */
typedef PFCfgUart3* PFpCfgUart3;

/**
 * Initializes the UART3 channel with provided settings
 *
 * \param config Pointer to configuration structure which contains the settings for the communication channel to be used.
 *
 * \return UART3 initialization status.
 */
PFEnStatus pfUart3Open(PFpCfgUart3 config);

/**
 * Turn offs the UART3 channel
 */
void pfUart3Close(void);

/**
 * This function writes one byte to UART3 data register.
 *
 * \param data 8 bit data to write to the UART3 channel.
 * \return UART3 write status.
 */
PFEnStatus pfUart3WriteByte(PFbyte data);

/**
 * The function sends multiple bytes on UART3 channel.  
 * If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 * Otherwise it will wait in the function and send each byte by polling the line status.
 *
 * \param data Pointer to the data to be sent.
 * \param size Total number of bytes to send.
 *
 * \return UART3 write status.
 */
PFEnStatus pfUart3Write(PFbyte* data, PFdword size);

/**
 * The function sends a string on the UART3 channel.
 * The function needs a null terminated string.
 * 
 * \param data Pointer to the data to be sent.
 * \return UART3 write status.
 */
PFEnStatus pfUart3WriteString(const char * data);

/**
 * The function reads one byte from UART3 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param rxByte Pointer to a byte where the received byte will be loaded
 *
 * \return read byte status.
 */
PFEnStatus pfUart3ReadByte(PFbyte* rxByte);

/**
 * The function reads one byte from UART3 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function for one byte to receive by polling the line status.
 *
 * \param data Unsigned char pointer to the buffer where the read data should be loaded.
 * \param size Total number of bytes to read.
 * \param readBytes pointer to double word, in which function will fill number bytes actually read. 
 *
 * \return UART3 read status.
 */
PFEnStatus pfUart3Read(PFbyte* data, PFdword size, PFdword* readBytes);

#if(PF_UART3_USE_FIFO != 0)
/**
 * The function gives the size of receive FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart3GetRxBufferSize(PFdword* size);

/**
 * Returns the number of bytes received in UART3 buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart3GetRxBufferCount(PFdword* count);

/**
 * This function empties the receive buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart3RxBufferFlush(void);

/**
 * The function gives the size of transmit FIFO buffer in bytes.
 *
 * \param size Pointer to variable where the buffer size will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart3GetTxBufferSize(PFdword* size);

/**
 * Returns the number of bytes pending in UART3 transmit buffer.
 *
 * \param count Pointer to variable where the buffer count will be loaded.
 * 
 * \return Status.
 */
PFEnStatus pfUart3GetTxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Status.
 */
PFEnStatus pfUart3TxBufferFlush(void);
#endif	// #if(PF_UART3_USE_FIFO != 0)

/** @} */