/**
 * \file    mmc.h
 * \brief   MMC Card Driver description.
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
 * \ingroup device
 * \defgroup MMC_CARD_API MMC Card API's
 * @{
 * 
 * \brief MMC Card driver
 */ 
 
/** \brief Configure maximum MMC cards to allow */
#define MMC_MAX_DEVICE_SUPPORTED        2

/** \brief Enable/disable write operations to the MMC card */
#define MMC_READONLY                    0
/** \brief Set to enable I/O control functions support for MMC card */
#define MMC_USE_IOCTL                1


/** \brief MMC card configuration structure */
typedef struct
{
    PFGpioPortPin gpioChipSelect;                                                          /**< GPIO pin used for SPI chip select */
    PFGpioPortPin gpioPower;                                                              /**< GPIO pin used for power control */
    PFGpioPortPin gpioCardDetect;                                                          /**< GPIO pin used for device detection */
    PFEnBoolean usePowerControl;                                                          /**< Use power control option for MMC card */
    PFEnBoolean useCardDetect;                                                              /**< Use card detect option for MMC card */
    PFEnStatus (*spiRegister)(PFbyte* id, PFpGpioPortPin chipSelect);                      /**< Pointer to SPI device register function */
    PFEnStatus (*spiUnregister)(PFbyte* id);                                              /**< Pointer to SPI device unregister function */
    PFEnStatus (*spiChipSelect)(PFbyte* id, PFbyte pinStatus);                              /**< Pointer to SPI chip select function */
    PFEnStatus (*spiExchangeByte)(PFbyte *id, PFbyte data, PFbyte* rxData);                  /**< Pointer to SPI exchange byte function */
	PFEnStatus (*spiWrite)(PFbyte* id, PFbyte* data, PFdword size,  PFcallback delayCallback); /**< Function pointer to SPI write */
	PFEnStatus (*spiRead)(PFbyte* id, PFbyte* data, PFdword size, PFdword* readBytes,   PFcallback delayCallback); /**< Function pointer to SPI read */
}CfgMmc;

/** \brief Pointer to CfgMmc structure */
typedef CfgMmc* pCfgMmc;

/**
 * \brief Initialize mmc card with the given configuration.
 *
 * \param deviceId Pointer to PFbyte variable to store the device deviceId for newly initialized device.
 * \param config Pointer to CfgMmc structure initialized with MMC card configuration.
 *
 * \return Status
 */
PFEnStatus mmcOpen(PFbyte* deviceId, pCfgMmc config);

/**
 * \brief The function returns current status of the mmc card.
 *
 * \param deviceId Device identification of the mmc card to get status.
 *
 * \return Mmc card status
 * enStatusSuccess: card physically present, initialized.
 * enStatusNotConfigured: mc card is physically present but not initialized
 * enStatusNotExist: mmc card is physically absent.
 */
PFEnStatus mmcGetStatus(PFbyte deviceId);

/**
 * \brief The function reads \a uCount sectors starting from sector number specified by \a sector from mmc card.
 *
 * \param deviceId deviceId of the mmc card to read
 * \param pBuf Pointer to buffer to store read data
 * \param sector Sector number to start reading
 * \param uCount Number of sectors to read
 *
 * \return Status
 */
PFEnStatus mmcRead(PFbyte deviceId, PFbyte *pBuf, PFdword sector, PFbyte uCount);

/**
 * \brief The function writes data to mmc card. Data from \a pBuf buffer is written to \a uCount sectors
 * starting from sector number specified by \a sector.
 *
 * \param deviceId deviceId of the mmc card to write
 * \param pBuf Pointer to buffer to be written on the device
 * \param sector Sector number to start writing
 * \param uCount Number of sectors to write
 *
 * \return Status
 */
PFEnStatus mmcWrite (PFbyte deviceId, const PFbyte *pBuf, PFdword sector, PFbyte uCount);

/**
 * \brief Control function for device specific features.
 *
 * \param deviceId DeviceId of the mmc card to access
 * \param ctrl Command code
 * \param pBuf Pointer to buffer for command dependent parameters. When not in use, null pointer should be used.
 *
 * \return Status
 */
PFEnStatus mmcIoCtrl(PFbyte deviceId, PFbyte ctrl,    void *pBuf);

/** @} */


