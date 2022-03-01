/**
 *  \file       prime_spi0.h
 *  \brief      SPI 0 Driver Discription for LPC1768.
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
 * \defgroup    PF_SPI0 SPI0
 * @{
 * 
 *  \brief      SPI0 driver
 *  \details    SPI0 driver for onchip SPI0 Peripheral for LPC1768
 */

/** \brief Configuration macros for SPI0        */
#define SPI0_CH                     SSP0
#define SPI0_CHANNEL                PERIPH(SPI0_CH)
#define SPI0_INT_HANDLER            INT_HANDLER(SPI0_CH)

/** 
 * \brief SPI0 FIFO Macro
 * \note PF_SPI0_USE_FIFO as 1 if internal software buffer is to be used in interrupt based communication.
 * \warning PF_SPI0_USE_FIFO  is set to 0 , Then user should provide callbacks to handle transmit and receive interrupts.
 */
#define PF_SPI0_USE_FIFO        1

#if(PF_SPI0_USE_FIFO != 0)
/** 
 * \brief Define size in bytes for internal software buffer.
 * \note The buffer size should be a non-zero and power of 2 number.
 */
    #define SPI0_BUFFER_SIZE        256
#endif  // #if(PF_SPI0_USE_FIFO != 0)

/** \brief Enumeration for SPI0 databits        */
typedef enum
{
    enSpi0Databits_4 = 3,       /**< 4 bits trasnfer per frame      */
    enSpi0Databits_5,           /**< 5 bits trasnfer per frame      */
    enSpi0Databits_6,           /**< 6 bits trasnfer per frame      */
    enSpi0Databits_7,           /**< 7 bits trasnfer per frame      */
    enSpi0Databits_8,           /**< 8 bits trasnfer per frame      */
    enSpi0Databits_9,           /**< 9 bits trasnfer per frame      */
    enSpi0Databits_10,          /**< 10 bits trasnfer per frame     */
    enSpi0Databits_11,          /**< 11 bits trasnfer per frame     */
    enSpi0Databits_12,          /**< 12 bits trasnfer per frame     */
    enSpi0Databits_13,          /**< 13 bits trasnfer per frame     */
    enSpi0Databits_14,          /**< 14 bits trasnfer per frame     */
    enSpi0Databits_15,          /**< 15 bits trasnfer per frame     */
    enSpi0Databits_16,          /**< 16 bits trasnfer per frame     */
}PFEnSpi0Databits;

/** \brief Enumeration for SPI0 modes       */
typedef enum
{
    enSpi0Mode_0 = 0,       /**< SPI0 mode 0: Phase 0, Polarity 0   */
    enSpi0Mode_1,           /**< SPI0 mode 1: Phase 0, Polarity 1   */
    enSpi0Mode_2,           /**< SPI0 mode 2: Phase 1, Polarity 0   */
    enSpi0Mode_3,           /**< SPI0 mode 3: Phase 1, Polarity 1   */
}PFEnSpi0Mode;

/** \brief Enumeration for SPI0 interrupts      */
typedef enum
{
    enSpi0IntNone               = 0,    /**< No interrupt is enabled                        */
    enSpi0IntRxOverrun          = 1,    /**< Enable receive overrun interrupt               */
    enSpi0IntRxTimeout          = 2,    /**< Enable receive timeout interrupt               */
    enSpi0IntRxBuffHalfFull     = 4,    /**< Enable receive buffer half full interrupt      */
    enSpi0IntTxBuffHalfEmpty    = 8,    /**< Enable receive buffer half empty interrupt     */
}PFEnSpi0Interrupt;

/** \brief SPI0 configuration structure         */
typedef struct
{
    PFEnPclkDivider     clkDiv;         /**< Peripheral clock divider for SPI0 module   */
    PFEnBoolean         masterMode;     /**< Select master or slave mode for SPI0       */
    PFEnSpi0Databits    datasize;       /**< Set datasize for SPI0 packet               */
    PFEnSpi0Mode        mode;           /**< Select SPI0 mode                           */
    PFdword             baudrate;       /**< SPI0 channel baudrate in bits/second`      */
    PFEnSpi0Interrupt   interrupt;      /**< Select SPI0 interrupts to enable           */
#if(PF_SPI0_USE_FIFO == 0)
    PFcallback          callback;       /**< User call back for interrupt               */
#endif  //  #if(PF_SPI0_USE_FIFO == 0)
}PFCfgSpi0;

/** \brief Pointer to PFCfgSpi0 structure           */
typedef PFCfgSpi0* PFpCfgSpi0;

/**
 *  Initializes the SPI0 channel with provided settings
 *  
 *  \param      config  Pointer to configuration structure which contains the settings for the communication channel to be used.
 *  
 *  \return     SPI0 initialization status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi0Open(PFpCfgSpi0 config);

/**
 *  Turn offs the SPI0 channel
 *  
 *  \return     SPI0 Close status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi0Close(void);

/**
 *  Registers SPI0 device to operate. 
 *  The SPI0 device should be registered before any read write operation take place for that device.
 *  
 *  \param      id          Pointer to load the id generated for the device being registered.
 *                          This id is required to carry out any operation on that device.
 *  \param      chipSelect  Pointer to PFGpioPortPin structure which describes the chip select pin used for the device.
 *  
 *  \return     Device registration status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi0RegisterDevice(PFbyte* id, PFpGpioPortPin chipSelect);

/**
 *  Unregisters the SPI0 device from the device list.
 *  No operation on the device is possible once it is unregistered.
 *  In order to operate on that device, it needs to be registered again.
 *  
 *  \param      id      Pointer to id of the device to be unregistered.
 *  
 *  \return Device unregistration status.
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi0UnregisterDevice(PFbyte* id);

/**
 *  Operate chip select pin of the device to start or stop the communication.
 *  
 *  \param      id          Pointer to id of the device to operate the chip select pin
 *  \param      pinStatus   Status of the chip select pin to set. 0 for making chip select low, 1 for making it high
 *  
 *  \return     Chip select operation status
 *  
 *  \note    Before calling any SPI0 read/write function for a device, it necessary to assert the chip select first.
 *           Once chip select of any device is asserted, chip select for any other device can not be asserted before 
 *           de-asserting the previous device chip select.
 *  \see     PFEnStatus 
 */
PFEnStatus pfSpi0ChipSelect(PFbyte* id, PFbyte pinStatus);

/**
 *  This function writes 8 bit data to SPI0 data register and 
 *  returns 8 bit received from SPI0 bus.
 *  
 *  \param   id      ID for subscribed device.
 *  \param   data    8 bit data to write to the SPI0 channel.
 *  \param   rxData  8 bit data to write to the SPI0 channel.
 *  
 *  \return  8 bit data received from SPI0 bus. 
 *  
 *  \note    Even if the datasize for parameter and return data is 8 bit,
 *           valid data size will depend upon the databits setting for the channel. 
 *  \see     PFEnStatus 
 */
PFEnStatus pfSpi0ExchangeByte(PFbyte *id, PFbyte data, PFbyte* rxData);

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
PFEnStatus pfSpi0Write(PFbyte* id, PFbyte* data, PFdword size, PFcallback delayCallback);

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
PFEnStatus pfSpi0Read(PFbyte* id, PFbyte* data, PFdword size, PFdword* readBytes, PFcallback delayCallback);

/**
 *  Returns the SPI0 channel interrupt status
 *  
 *  \return interrupt status for SPI0 channel
 */
PFdword pfSpi0GetIntStatus(void);

/**
 *  Clears pending flags for given interrupts
 *  
 *  \param   intStatus interrupts for which flags are to be cleared
 *  
 *  \return  interrupt flag clear status
 *  \see        PFEnStatus 
 */
PFEnStatus pfSpi0ClearIntStatus(PFdword intStatus);

#if(PF_SPI0_USE_FIFO != 0)

/**
 *  The function gives the size of receive FIFO buffer in bytes.
 *  
 *  \param   size    Pointer to variable where the buffer size will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0GetRxBufferSize(PFdword* size);

/**
 *  Returns the number of bytes received in SPI Receive buffer.
 *  
 *  \param   count   Pointer to variable where the buffer count will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0GetRxBufferCount(PFdword* count);

/**
 *  This function empties the receive buffer.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0RxBufferFlush(void);

/**
 *  The function gives the size of transmit FIFO buffer in bytes.
 *  
 *  \param   size    Pointer to variable where the buffer size will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0GetTxBufferSize(PFdword* size);

/**
 *  Returns the number of bytes pending in SPI transmit buffer.
 *  
 *  \param   count   Pointer to variable where the buffer count will be loaded.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0GetTxBufferCount(PFdword* count);

/**
 *  This function empties the transmit buffer.
 *  
 *  \return  Status.
 *  
 *  \see     PFEnStatus
 */
PFEnStatus pfSpi0TxBufferFlush(void);

#endif  // #if(PF_SPI0_USE_FIFO != 0)

/** @} */

