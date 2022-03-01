/**
 * \file	prime_i2c1.h
 * \brief   I2C 1 Driver Discription for LPC1768.
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
 * \ingroup PF_I2C
 * \defgroup PF_I2C1 I2C 1
 * @{
 * 
 * 	\brief I2C 1 driver
 * 	\details  I2C 1 driver for onchip I2C 1 Peripheral
 */
 
/** \brief I2C 1 Configuration macros 		*/
#define I2C1_CH					I2C1
#define I2C1_CHANNEL			PERIPH(I2C1_CH)
#define I2C1_INT_HANDLER		INT_HANDLER(I2C1_CH)

/** 
 * \brief I2C1 FIFO Macro
 * \note PF_I2C1_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_I2C1_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_I2C1_USE_FIFO				0
	
#if(PF_I2C1_USE_FIFO != 0)
/** 
 * Define size in bytes for internal software buffer.
 * The buffer size should be a non-zero and power of 2 number.
 */
	#define I2C1_BUFFER_SIZE		256
#endif	// #if(I2C1_USE_FIFO != 0)

/**	\brief Configuration structure for I2C1		*/
typedef struct
{
	PFdword baudRate;			/**< Baudrate for I2C1 bus clock. This parameter is valid for master mode*/
	PFEnPclkDivider	clkDiv;		/**< Peripheral clock divider for I2C1 module		*/
	PFbyte dutyCycle;			/**< Duty cycle for bus clock in percentage. This parameter is valid for master mode	*/
	PFEnBoolean enableAck;		/**< Enable or disable sending acknowledgement		*/
	PFEnBoolean enableGenCall;	/**< Enable or disable acknowledgement to general call. This parameter is valid for slave mode*/
	PFbyte ownAddress[4];		/**< Set own I2C1 addresses. The addreses should be left aligned. This parameter is valid for slave mode*/
	PFbyte addrMask[4];			/**< Set mask for own I2C1 addresses. Bits set to 1 will be ignored in address comparision. The addreses should be left aligned. This parameter is valid for slave mode*/
	PFEnBoolean intEnable;
	#if(PF_I2C1_USE_FIFO == 0)
	PFcallback callback;		/**< callback to handle I2C1 interrupt				*/
#endif	// #if(PF_I2C1_USE_FIFO != 0)
}PFCfgI2c1;

/** \brief Pointer to PFCfgI2c1 structure		*/
typedef PFCfgI2c1* PFpCfgI2c1;

/**
 * The function initializes the I2C channel according to the configuration structure.
 *
 * \param config configuration structure which contains the settings for the communication channel to be used.
 * \return I2C1 initialization status.
 */
PFEnStatus pfI2c1Open(PFpCfgI2c1 config);

/**
 * The function turns off the I2C1 channel
 */
PFEnStatus pfI2c1Close(void);

/**
 * The function enables I2C1 interrupt
 * 
 * \return Interrupt enable status
 */
PFEnStatus pfI2c1IntEnable(void);

/**
 * The function disables I2C1 interrupt
 * 
 * \return Interrupt disable status
 */
PFEnStatus pfI2c1IntDisable(void);

/**
 * The function sets the given flag in I2C1 control register
 *
 * \param flag Control register flag to set
 *
 * \return status for setting control flag
 */
PFEnStatus pfI2c1SetControlFlag(PFbyte flag);

/**
 * The function clears the given flag in I2C1 control register
 *
 * \param flag Control register flag to clear
 *
 * \return status for clearing control flag
 */
PFEnStatus pfI2c1ClearControlFlag(PFbyte flag);

/**
 * The function gives current I2C1 communication state
 *
 * \param state pointer to PFbyte to load current I2C1 state
 *
 * \return status for reading current state
 */
PFEnStatus pfI2c1GetState(PFbyte* state);

/**
 * The function sends multiple bytes on I2C1 channel.  
 * If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 * Otherwise it will wait in the function and send each byte by polling the line status.
 *
 * \param data 			pointer to the data to be sent.
 * \param master 		using I2C in master or in slave mode.
 * \param slaveAddr		left aligned address of slave.
 * \param busRelease	to release the bus after sending data or not.If true, it will send STOP bit after sending given no. of bytes.It is valid only in Master mode.
 * \param size 			total number of bytes to send.
 *
 * \return				I2C1 write status.
 */
PFEnStatus pfI2c1Write(PFbyte* data, PFEnBoolean master, PFbyte slaveAddr, PFEnBoolean busRelease, PFdword size);

/**
 * The function reads one byte from I2C1 channel.
 * If receive interrupt is enabled, the function will read the byte from receive FIFO.
 * Otherwise it will wait in the function and receive each byte by polling the line status.
 *
 * \param data			pointer to the buffer where the read data should be loaded.
 * \param master 		using I2C in master or in slave mode.
 * \param slaveAddr 	left aligned address of slave.
 * \param busRelease	to release the bus after reading data or not.If true, it will send STOP bit after reading given no. of bytes.It is valid only in Master mode.
 * \param size			Total number of bytes to read.
 * \param readBytes 	pointer of the variable where function will load number of bytes actually read. 
 *
 * \return 				I2C1 read status.
 */
PFEnStatus pfI2c1Read(PFbyte* data, PFEnBoolean master, PFbyte slaveAddr, PFEnBoolean busRelease, PFdword size, PFdword* readBytes);

#if(PF_I2C1_USE_FIFO != 0)
/**
 * The function returns number of bytes received in I2C Receive buffer.
 *
 * \param count pointer to load number of bytes received in I2C1 buffer.
 *
 * \return status for getting received byte count
 */
PFEnStatus pfI2c1GetRxBufferCount(PFdword* count);

/**
 * This function empties the transmit buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfI2c1TxBufferFlush(void);

/**
 * This function empties the receive buffer.
 * 
 * \return Buffer flush status.
 */
PFEnStatus pfI2c1RxBufferFlush(void);
#endif	// #if(PF_I2C1_USE_FIFO != 0)
/** @} */ 
