/**
 *
 *                              Copyright (c) 2014
 *                         PhiRobotics Research Pvt Ltd
 *
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 *
 * \brief Prime Framework Touch Driver
 *
 * Review status: NO
 *
 */
#pragma once
/**
 * \defgroup TOUCH_DRIVER_API TOUCH Driver API
 * @{
 */
  
 /**	Enumeration for the reference select of touch panel driver		*/
typedef enum{
	enTouchReferenceSelect_Differential = 0, /**< Differential reference select */
	enTouchReferenceSelect_Single = 1 		 /**< Single reference select */
}EnTouchReferenceSelect;

/**		Enumeration for the precision of touch panel driver	*/
typedef enum{
	enTouchPrecision_8bit= 0,          /**< 8 bit precision */
	enTouchPrecision_12bit=0x08		   /**< 12 bit precision */
}EnTouchPrecision;

/**		Structure for the configuration of touch panel driver	*/
typedef struct
{
	 PFGpioPortPin gpioTouchIntPin;     			/**< Touch interrupt pin */
	 PFGpioPortPin gpioTouchBusyPin;	 			/**< Touch busy pin*/
	 PFGpioPortPin gpioTouchCsGpio;	 				/**< Touch chip select pin */
	 EnTouchReferenceSelect refsel; 				/**< Touch reference pin */
	 EnTouchPrecision precsel; 					/**< Touch precision pin */
	 PFEnStatus (*spiRegisterDevice)(PFbyte* id, PFpGpioPortPin chipSelect); /**< Function pointer to SPI register device */
	 PFEnStatus (*spiChipSelect)(PFbyte* id, PFbyte pinStatus); /**< Function pointer to SPI chip select */
	 PFEnStatus (*spiWrite)(PFbyte* id, PFbyte* data, PFdword size,  PFcallback delayCallback); /**< Function pointer to SPI write */
	 PFEnStatus (*spiRead)(PFbyte* id, PFbyte* data, PFdword size, PFdword* readBytes,   PFcallback delayCallback); /**< Function pointer to SPI read */
}CfgTouch;

/** pointer to structure CgfTouch */
typedef CfgTouch*	pCfgTouch;

/**
 * To initialize touch module
 *
 * \param TouchConfig, pointer to config structure to configure touch driver 
 *
 * \return status of initialize
 * 
 */
PFEnStatus touchOpen(pCfgTouch touchConfig);
/**
 * To get the coordinates from touch module
 *
 * \param pointer to x and y to store the coordinates from touch driver
 *
 * \return status of whether the user got coordinates from touch driver
 * 
 */
PFEnStatus touchGetCoordinates(PFdword* x_pos, PFdword* y_pos);
/**
 * To check whethe the data is available from touch panel module
 *
 * \param Boolean parameter to check whether data is available
 *
 * \return status of whether the touch panel is closed or not
 * 
 */
PFEnStatus touchDataAvailable(PFEnBoolean *data);


/**
 * To detect touch instantaneously and get coordinates of touch
 *
 * \param pointer to x and y to store the coordinates from touch driver
 *
 * \return  Boolean parameter to check whether data is available
 * 
 */
 PFEnBoolean touchAvailable(PFdword* xPos, PFdword* yPos);
/**
 * To close the touch panel module
 *
 * \return status of whether the touch panel is closed or not
 * 
 */
PFEnStatus touchClose(void);

/** } */


