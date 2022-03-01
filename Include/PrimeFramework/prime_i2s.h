/**
 * \file	prime_i2s.h
 * \brief   I2S Driver Discription for LPC1768.
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
 * \ingroup native
 * \defgroup PF_I2S I2S
 * @{
 * 	
 * \brief I2S 2 driver
 * \details  I2S 2 driver for onchip I2S 1 Peripheral
 */

/** \brief Configuration macros for I2S module		*/
#define I2S_CH					I2S
#define I2S_CHANNEL	 		PERIPH(I2S_CH)
#define I2S_INT_HANDLER		INT_HANDLER(I2S_CH)

#define PF_I2S_USE_FIFO				1

/** 
 * \brief I2S FIFO Macro
 * \note PF_I2S_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_I2S_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#if(PF_I2S_USE_FIFO != 0)
/** 
 * Define size in bytes for internal software buffer.
 * The buffer size should be a non-zero and power of 2 number.
 */
	#define I2S_BUFFER_SIZE		1024
#endif	// #if(PF_I2S_USE_FIFO != 0)

/** \brief Enumeration for I2S word width */
typedef enum
{
	enI2sWordWidth_8 = 0,	/**< Word Width of 8 bit data	*/
	enI2sWordWidth_16 = 1,	/**< Word Width of 16 bit data	*/
	enI2sWordWidth_32 = 3	/**< Word Width of 32 bit data	*/
}PFEnI2sWordWidth;

/** \brief Enumeration for I2S format */
typedef enum
{
	enI2sFormatStereo = 0,	/**< Mono Mode 	*/
	enI2sFormatMono = 1,	/**< Word Width of 16 bit data	*/	
}PFEnI2sFormat;

/** \brief Enumeration for I2S Clock Selection */
typedef enum
{ 
	 enI2sClkSel_FRDCLK=0,
	 enI2sClkSel_MCLK=2
}PFEnI2sClkSel;

/**	\brief	Enumeration for interrupts to enable for the I2S channel		*/
typedef enum
{
	enI2sIntNone = 0,				/**< no interrupt	*/
	enI2sIntRx,						/**< receive interrupt	*/
	enI2sIntTx,						/**< transmit interrupt	*/
	enI2sIntTxRx					/**< transmit and receive interrupt	*/
}PFEnI2sInterrupt;

/**	\brief	Enumeration for mode selection of the transmitter and receiver channel		*/
typedef enum
{
  enI2sModeTx = 0,		//
  enI2sModeRx 
}PFEnI2sMode;

/**	\brief Configuration structure for I2C0 Transmitter */
typedef struct
{ 
	 PFEnI2sWordWidth txWordWidth;      /** Wordwidth of transmitter channel */
	 PFEnBoolean  txStop;               /** To enable/disable stop mode Enable=1 Disable=0 	*/
	 PFEnBoolean  txReset;               /** To enable/disable reset mode Enable=1 Disable=0 	*/	
	 PFEnBoolean  txMute;				 /** To enable/disable mute Enable =1 Disable =0 		*/
	 PFEnI2sFormat txFormat; /** To select the format Mono/Stereo			*/
	 PFEnBoolean txMode;		 /** To select mode Master/Slave mode for TX channel	*/
	 PFEnI2sClkSel txClkSel; /** To select transmitter clk  FRD_CLK/MCLK */
	 PFEnBoolean txFpin; 	/** To enable/disable 4 pin Mode for transmitter channel Enable=1 Disable=0 */
	 PFEnBoolean txMcena;	/** TO enable/disable MCLK for output of transmitter channel Enable=1 Disable=0 */
	 PFdword frequency;		/** Frequency  */
	 PFbyte txInterruptFifoLevel;
}PFCfgI2sTransmitter;
typedef PFCfgI2sTransmitter* PFpCfgI2sTransmitter;

/**	\brief Configuration structure for I2C0 Receiver */
typedef struct
{ 
	 PFEnI2sWordWidth rxWordWidth;		/** Wordwidth of receiver channel */
	 PFEnBoolean  rxStop;               /** To enable/disable stop mode Enable=1 Disable=0 	*/
	 PFEnBoolean  rxReset;               /** To enable/disable reset mode Enable=1 Disable=0 	*/	
	 PFEnBoolean  rxMute;				 /** To enable/disable mute Enable =1 Disable =0 		*/
	 PFEnI2sFormat rxFormat; /** To select the format Mono/Stereo			*/
	 PFEnBoolean rxMode;		 /** To select mode Master/Slave mode for TX channel	*/
	 PFEnI2sClkSel rxClkSel; /** To select transmitter clk  FRD_CLK/MCLK */
	 PFEnBoolean rxFpin; 	/** To enable/disable 4 pin Mode for transmitter channel Enable=1 Disable=0 */
	 PFEnBoolean rxMcena;	/** TO enable/disable MCLK for output of transmitter channel Enable=1 Disable=0 */
	 PFdword rxfrequency;		/** Frequency  */
	 PFbyte rxInterruptFifoLevel;
}PFCfgI2sReceiver;

/** \brief Pointer to PFCfgI2sReceiver structure		*/
typedef PFCfgI2sReceiver* PFpCfgI2sReceiver;

/**		\brief	I2S Configuration Structure				*/
typedef struct
{
	PFEnPclkDivider	clkDiv;		/**< Peripheral clock divider for I2C0 module		*/
    PFpCfgI2sTransmitter txChannelConfig; /**< Transmitter channel configuration */
	PFpCfgI2sReceiver rxChannelConfig; /**< Receiver channel configuration */
	PFEnI2sInterrupt interrupt; //
	PFcallback txcallback; /**< callback to handle I2S transmitter channel interrupt		*/
    PFcallback rxcallback; /**< callback to handle I2S receiver channel interrupt	*/
}PFCfgI2s;

/** \brief Pointer to PFCfgI2s structure		*/
typedef PFCfgI2s* PFpCfgI2s;

/**
 * Initializes the I2S0 channel with provided settings
 *
 * \param config configuration structure which contains the settings for the communication channel to be used.
 *
 * \return I2S initialization status.
 */
PFEnStatus pfI2sOpen(PFpCfgI2s config);

/**
 * Turn offs the I2S channel
 * 
 * \return I2S close status
 */
PFEnStatus pfI2sClose(void);

/**
 * This function starts the I2S module
 *
 * \return I2S start status 
 *
 */
PFEnStatus pfI2sStart(void);

/**
 * Function enables I2C0 interrupt
 * 
 * \return Interrupt enable status
 */
PFEnStatus pfI2sIntEnable(void);

/**
 * Function disables I2C0 interrupt
 * 
 * \return Interrupt disable status
 */
PFEnStatus pfI2sIntDisable(void);

/**
 * The function sends multiple bytes on I2S channel.  
 *
 * \param data pointer to the data to be sent.
 *
 * \param size total number of bytes to be send
 *
 * \return I2C0 write status.
 */
PFEnStatus pfI2sWrite(PFbyte *data,PFdword size); 

/**
 * The function read multiple bytes on I2S channel.  
 *
 * \param data Unsigned char pointer to the buffer where the read data should be loaded.
 *
 * \param size ize Total number of bytes to read.
 *
 * \param readByte pointer to double word, in which function will fill number bytes actually read.
 *
 * \return I2C0 read status.
 */
PFEnStatus pfI2sRead(PFbyte *data,PFdword size,PFdword *readByte); 

/**
 * The function mute the respective channel (Tx/Rx channel)
 *
 * \param mode of I2S(Channel TX/RX).
 *
 * \return I2S pause status.
 */
PFEnStatus pfI2sPause(PFEnI2sMode mode);

/**
 * The function mute the respective channel (Tx/Rx channel)
 *
 * \param mode of I2S(Channel TX/RX).
 *
 * \return I2S mute status.
 */
PFEnStatus pfI2sMute(PFEnI2sMode mode);

/**
 * The function give depth of FIFO level on which to create an irq request
 *
 * \param mode of I2S(Channel TX/RX).
 *
 * \param depth value on which interrupt has to be generated
 *
 * \return I2S Get irq depth status.
 */
PFEnStatus pfI2SGetIRQDepth(PFEnI2sMode mode,PFdword *depth);

/**
 * The function give current level of FIFO 
 *
 * \param mode of I2S(Channel TX/RX).
 *
 * \return I2S Get level status.
 */
PFword pfI2SGetFifoLevel(PFEnI2sMode mode);

/**
 * The function give interrupt status of I2S 
 *
 * \param mode of I2S(Channel TX/RX).
 *
 * \param checkStatus value in which status has to be stored
 *
 * \return I2S Get irq depth status.
 */
PFEnStatus pfI2sGetIRQStatus(PFEnI2sMode mode,PFbyte *checkStatus);

/** @} */ 