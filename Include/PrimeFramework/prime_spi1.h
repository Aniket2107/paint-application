/**
 *  \file       prime_spi1.h
 *  \brief      SPI 1 Driver Discription for LPC1768.
 *  \copyright  Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 *  
 *  \par
 *   For licensing information, see the file 'LICENSE' in the root folder of
 *   this software module.
 * 
 *  Review status: NO
 *
 */
#pragma once
/**
 * \ingroup     PF_SPI
 * \defgroup    PF_SPI1 SPI1
 * @{
 * 
 *  \brief      SPI1 driver
 *  \details    SPI1 driver for onchip SPI1 Peripheral for LPC1768
 */

/** \brief Configuration macros for SPI1        */
#define SPI1_CH                     SSP1
#define SPI1_CHANNEL                PERIPH(SPI1_CH)
#define SPI1_INT_HANDLER            INT_HANDLER(SPI1_CH)

/** 
 * \brief SPI1 FIFO Macro
 * \note PF_SPI1_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_SPI1_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_SPI1_USE_FIFO        1

#if(PF_SPI1_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
    #define SPI1_BUFFER_SIZE        256
#endif  // #if(PF_SPI1_USE_FIFO != 0)

/** \brief Enumeration for SPI1 databits        */
typedef enum
{
    enSpi1Databits_4 = 3,       /**< 4 bits trasnfer per frame      */
    enSpi1Databits_5,           /**< 5 bits trasnfer per frame      */
    enSpi1Databits_6,           /**< 6 bits trasnfer per frame      */
    enSpi1Databits_7,           /**< 7 bits trasnfer per frame      */
    enSpi1Databits_8,           /**< 8 bits trasnfer per frame      */
    enSpi1Databits_9,           /**< 9 bits trasnfer per frame      */
    enSpi1Databits_10,          /**< 10 bits trasnfer per frame     */
    enSpi1Databits_11,          /**< 11 bits trasnfer per frame     */
    enSpi1Databits_12,          /**< 12 bits trasnfer per frame     */
    enSpi1Databits_13,          /**< 13 bits trasnfer per frame     */
    enSpi1Databits_14,          /**< 14 bits trasnfer per frame     */
    enSpi1Databits_15,          /**< 15 bits trasnfer per frame     */
    enSpi1Databits_16,          /**< 16 bits trasnfer per frame     */
}PFEnSpi1Databits;

/** \brief Enumeration for SPI1 modes       */
typedef enum
{
    enSpi1Mode_0 = 0,       /**< SPI1 mode 0: Phase 0, Polarity 0   */
    enSpi1Mode_1,           /**< SPI1 mode 1: Phase 0, Polarity 1   */
    enSpi1Mode_2,           /**< SPI1 mode 2: Phase 1, Polarity 0   */
    enSpi1Mode_3,           /**< SPI1 mode 3: Phase 1, Polarity 1   */
}PFEnSpi1Mode;

/** \brief Enumeration for SPI1 interrupts      */
typedef enum
{
    enSpi1IntNone               = 0,    /**< No interrupt is enabled                        */
    enSpi1IntRxOverrun          = 1,    /**< Enable receive overrun interrupt               */
    enSpi1IntRxTimeout          = 2,    /**< Enable receive timeout interrupt               */
    enSpi1IntRxBuffHalfFull     = 4,    /**< Enable receive buffer half full interrupt      */
    enSpi1IntTxBuffHalfEmpty    = 8,    /**< Enable receive buffer half empty interrupt     */
}PFEnSpi1Interrupt;

/** \brief SPI1 configuration structure         */
typedef struct
{
    PFEnPclkDivider     clkDiv;         /**< Peripheral clock divider for SPI1 module   */
    PFEnBoolean         masterMode;     /**< Select master or slave mode for SPI1       */
    PFEnSpi1Databits    datasize;       /**< Set datasize for SPI1 packet               */
    PFEnSpi1Mode        mode;           /**< Select SPI1 mode                           */
    PFdword             baudrate;       /**< SPI1 channel baudrate in bits/second`      */
    PFEnSpi1Interrupt   interrupt;      /**< Select SPI1 interrupts to enable           */
#if(PF_SPI1_USE_FIFO == 0)
    PFcallback          callback;       /**< User call back for interrupt               */
#endif  //  #if(PF_SPI1_USE_FIFO == 0)
}PFCfgSpi1;

/** \brief Pointer to PFCfgSpi1 structure           */
typedef PFCfgSpi1* PFpCfgSpi1;

/**
 *  Initializes the SPI1 channel with provided settings
 *  
 *  \param      config  Pointer to configuration structure which contains the settings for the communication channel to be used.
 *  
 *  \return     SPI1 initialization status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi1Open(PFpCfgSpi1 config);

/**
 *  Turn offs the SPI1 channel
 *  
 *  \return     SPI1 Close status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi1Close(void);

/**
 *  Registers SPI1 device to operate. 
 *  The SPI1 device should be registered before any read write operation take place for that device.
 *  
 *  \param      id          Pointer to load the id generated for the device being registered.
 *                          This id is required to carry out any operation on that device.
 *  \param      chipSelect  Pointer to PFGpioPortPin structure which describes the chip select pin used for the device.
 *  
 *  \return     Device registration status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi1RegisterDevice(PFbyte* id, PFpGpioPortPin chipSelect);

/**
 *  Unregisters the SPI1 device from the device list.
 *  No operation on the device is possible once it is unregistered.
 *  In order to operate on that device, it needs to be registered again.
 *  
 *  \param      id      Pointer to id of the device to be unregistered.
 *  
 *  \return Device unregistration status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi1UnregisterDevice(PFbyte* id);

/**
 *  Operate chip select pin of the device to start or stop the communication.
 *  
 *  \param      id          Pointer to id of the device to operate the chip select pin
 *  \param      pinStatus   Status of the chip select pin to set. 0 for making chip select low, 1 for making it high
 *  
 *  \return     Chip select operation status
 *  
 *  \note    Before calling any SPI1 read/write function for a device, it necessary to assert the chip select first.
 *           Once chip select of any device is asserted, chip select for any other device can not be asserted before 
 *           de-asserting the previous device chip select.
 *  \see     PFEnStatus 
 */
PFEnStatus pfSpi1ChipSelect(PFbyte* id, PFbyte pinStatus);

/**
 *  This function writes 8 bit data to SPI1 data register and 
 *  returns 8 bit received from SPI1 bus.
 *  
 *  \param   id      ID for subscribed device.
 *  \param   data    8 bit data to write to the SPI1 channel.
 *  \param   rxData  8 bit data to write to the SPI1 channel.
 *  
 *  \return  8 bit data received from SPI1 bus. 
 *  
 *  \note    Even if the datasize for parameter and return data is 8 bit,
 *           valid data size will depend upon the databits setting for the channel. 
 *  \see     PFEnStatus 
 */
PFEnStatus pfSpi1ExchangeByte(PFbyte *id, PFbyte data, PFbyte* rxData);

/**
 *  The function sends multiple bytes on SPI channel.  
 *  If transmit interrupt is enabled, the function will enqueue the data in transmit FIFO.
 *  Otherwise it will wait in the function and send each byte by polling the line status.
 *  
 *  \param   id              ID for subscribed device.
 *  \param   data            Pointer to the data to be sent.
 *  \param   size            Total number of bytes to send.
 *  \param   delayCallback   Function ptr of type PFcallback, for providing the delay between to concecutive bytes.
 *  
 *  \return  SPI write status.
 *  
 *  \note    Parameter delayCallback is only usefull in Polling  Mode. user can pass NULL Pointer to avoid delay.
 *  \see     PFEnStatus, PFcallback, PF_NULL_PTR
 */
PFEnStatus pfSpi1Write(PFbyte* id, PFbyte* data, PFdword size, PFcallback delayCallback);

/**
 *  The function reads one byte from SPI channel.
 *  If receive interrupt is enabled, the function will read the byte from receive FIFO.
 *  Otherwise it will wait in the function for one byte to receive by polling the line status.
 *  
 *  \param   id              ID for subscribed device.
 *  \param   data            pointer to the buffer where the read data should be loaded.
 *  \param   size            total number of bytes to read.
 *  \param   readBytes       pointer to double word, in which function will fill number bytes actually read.
 *  \param   delayCallback   Function ptr of type PFcallback, for providing the delay between to concecutive bytes.
 *  
 *  \return  SPI read status.
 *  
 *  \note    Parameter delayCallback is only usefull in Polling  Mode. user can pass NULL Pointer to avoid delay.
 *  \see     PFEnStatus, PFcallback, PF_NULL_PTR
 */
PFEnStatus pfSpi1Read(PFbyte* id, PFbyte* data, PFdword size, PFdword* readBytes, PFcallback delayCallback);

/**
 *  Returns the SPI1 channel interrupt status
 *  
 *  \return interrupt status for SPI1 channel
 */
PFdword pfSpi1GetIntStatus(void);

/**
 *  Clears pending flags for given interrupts
 *  
 *  \param   intStatus interrupts for which flags are to be cleared
 *  
 *  \return  interrupt flag clear status
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi1ClearIntStatus(PFdword intStatus);

#if(PF_SPI1_USE_FIFO != 0)

/**
 *  The function gives the size of receive FIFO buffer in bytes.
 *  
 *  \param   size    Pointer to variable where the buffer size will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1GetRxBufferSize(PFdword* size);

/**
 *  Returns the number of bytes received in SPI Receive buffer.
 *  
 *  \param   count   Pointer to variable where the buffer count will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1GetRxBufferCount(PFdword* count);

/**
 *  This function empties the receive buffer.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1RxBufferFlush(void);

/**
 *  The function gives the size of transmit FIFO buffer in bytes.
 *  
 *  \param   size    Pointer to variable where the buffer size will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1GetTxBufferSize(PFdword* size);

/**
 *  Returns the number of bytes pending in SPI transmit buffer.
 *  
 *  \param   count   Pointer to variable where the buffer count will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1GetTxBufferCount(PFdword* count);

/**
 *  This function empties the transmit buffer.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi1TxBufferFlush(void);

#endif  // #if(PF_SPI1_USE_FIFO != 0)

/** @} */

