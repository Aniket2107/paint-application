/**
 * \file	prime_usb.h
 * \brief   USB Driver Discription for LPC1768.
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
 * \defgroup PF_USB USB
 * @{
 * 
 * 	\brief USB driver
 * 	\details  USB driver for onchip USB Peripheral
 */

/** \brief USB configuration MACRO */
#define USB_CH				USB
#define USB_CHANNEL			PERIPH(USB_CH)
#define USB_INT_HANDLER		INT_HANDLER(USB_CH) 

/** \brief	Enumeration for USB Mode */
typedef enum
{
	enUsbModeIdle = 0,
	enUsbModeHost,
	enUsbModeDevice,
	enUsbModeOTG
}PFEnUsbMode;

/**	\brief USB configure Structure	*/
typedef struct
{
	int a;
}PFCfgUsb;

/**
 * \brief pointer to PFCfgUsb structure
 */
typedef PFCfgUsb*	PFpCfgUsb;

/**
 * \brief The function configures USB with given settings.
 *
 * \return USB initialization status.
 */
PFEnStatus pfUsbOpen(void);

/**
 * \brief The function disables USB module.
 *
 * \return USB disable status.
 */
void pfUsbClose(void);

/**
 * \brief The function returns last conversion value from global data register.
 * 
 * \param usbMode  Setting the usbmode
 *
 * \return void.
 */
void pfUsbSetMode(PFEnUsbMode usbMode);

/**
 * \brief The function returns USB Mode
 *
 * \return PFEnUsbMode Get Mode.
 */
PFEnUsbMode pfUsbGetMode(void);

/**
 * \brief The function Interupt enable
 * 
 * \return Enable status
 */
PFEnStatus pfUsbIntEnable(void);

/**
 * \brief The function Interupt Disable
 * 
 * \return Disable status
 */
PFEnStatus pfUsbIntDisable(void);

/**
 * \brief The function Discription
 * 
 * \param  deviceCallback	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbSetDeviceCallback(PFcallback deviceCallback);

/**
 * \brief The function Discription
 * 
 * \param  hostCallback	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbSetHostCallback(PFcallback hostCallback);

/**
 * \brief The function Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbDeviceClockEnable(void);

/**
 * \brief The function Discription
 * 
 * \param  devInt	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbEnableDeviceInterrupts(PFdword devInt);

/**
 * \brief The function Discription
 * 
 * \param  epInt	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbEnableEpInterrupts(PFdword epInt);

/**
 * \brief The function Discription
 * 
 * \param  devInt	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbClearDeviceInterrupts(PFdword devInt);
/**
 * \brief The function Discription
 * 
 * \param  epInt	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbClearEpInterrupts(PFdword epInt);
/**
 * \brief The function Discription
 * 
 * \param  epIntPriority	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbSetEpInterruptPriority(PFdword epIntPriority);
/**
 * \brief The function Discription
 * 
 * \param  dmaInterrupts	Discription
 * 
 * \return PFEnStatus status
 */
PFEnStatus pfUsbEnableDmaInterrupts(PFdword dmaInterrupts);
/**
 * \brief The function Discription
 * 
 * \param  connectStatus	Discription
 * 
 * \return PFEnStatus status
 */
void pfUsbSoftconnect(PFEnBoolean connectStatus);

//PFEnStatus pfUsbDeviceReset(void);

/**
 * \brief The function Discription
 * 
 * \param  cmd	Discription
 * 
 * \return Void
 */
void pfUsbSIEWriteCommamd(PFdword cmd) ;

/**
 * \brief The function Discription
 * 
 * \param  val	Discription
 * \param  cmd	Discription
 * 
 * \return Void
 */
void pfUsbSIEWriteCommamdData(PFdword cmd, PFdword val) ;

/**
 * \brief The function Discription
 * 
 * \param  cmd	Discription
 * 
 * \return PFdword
 */
PFdword pfUsbSIEReadCommandData(PFdword cmd);
/**
 * \brief The function Discription
 * 
 * \param  phyEpNum	Discription
 * \param  maxPacketSize	Discription
 * 
 * \return Void
 */
void pfUsbRealizeEndpoint(PFbyte phyEpNum, PFdword maxPacketSize);

/** @} */