/**
 * \file	prime_eint3.h
 * \brief   EXT INT 3 Driver Discription for LPC1768.
 * \copyright Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * @par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 * 
 * Review status: NO
 *
 */
#pragma once

/**
 * \ingroup PF_EINT
 * \defgroup PF_EINT3 EXT INT 3
 * @{
 * 
 * 	\brief EXT INT 3 driver
 * 	\details  EXT INT 3 driver for onchip EXT INT 3
 */
 
/** \brief External interrupt configuration macros 		*/
#define EINT3_CH			3
#define EINT3_CHANNEL		PF_CONCAT(EINT, EINT3_CH)
#define EINT3_HANDLER		INT_HANDLER(EINT3_CHANNEL) 
 
/**	\brief	Enumeration for External Interrupt mode	*/
typedef enum
{
	enEint3ModeLowLevel = 0,				/**< Low level trigerred interrupt							*/
	enEint3ModeHighLevel,				/**< High level trigerred interrupt							*/
	enEint3ModeFallingEdge,				/**< Falling edge trigerred interrupt						*/
	enEint3ModeRisingEdge				/**< Rising edge trigerred interrupt						*/
}PFEnEint3Mode;

/**	\brief	External interrupt	configure Structure	*/
typedef struct
{
	PFcallback* callbackList;			/**< Pointer to array of callbacks to attach to interrupt	*/
    PFbyte callbackCount;				/**< Number of callbacks provided in \a callbackList		*/
    PFEnEint3Mode mode;					/**< External interrupt mode								*/
}PFCfgEint3;

/**
 * \brief pointer to PFCfgEint3 structure
 */
typedef PFCfgEint3* PFpCfgEint3;

#if (EINT3_CH == GPIO_INT_CH)
/**	\brief Enumeration for GPIO Interrupt mode	*/
typedef enum
{
	enGpioIntModeFallingEdge = 1,                   /**< Trigger gpio interrupt on falling edge                     */	
	enGpioIntModeRisingEdge,                        /**< Trigger gpio interrupt on rising edge                      */
	enGpioIntModeBothEdge                           /**< Trigger gpio interrupt on both rising and falling edges    */
}PFEnGpioIntMode;

/**	\brief External interrupt configuration Structure	*/
typedef struct
{
	PFdword	gpioPortNo;					/**< Port No. of GPIO Interrupt pin.                    */
	PFdword	gpioIntPin;					/**< GPIO Pin name. Must use GPIO_PIN_XX macro.         */
	PFcallback callback;				/**< Callback for the GPIO Interrupt Pin.               */
    PFEnGpioIntMode mode;				/**< GPIO interrupt mode.                               */
}PFCfgGpioInt;

/** \brief Typedef for pointer to PFCfgGpioInt structure*/
typedef PFCfgGpioInt* PFpCfgGpioInt;

#endif  // #if (EINT3_CH == GPIO_INT_CH)

/**
 * The function configures and enables External Interrupt with given settings.
 
 * \param config Pointer to configuration structure which contains the settings for the external interrupt to be used.

 * \return External Interrupt status.
 */
PFEnStatus pfEint3Open(PFpCfgEint3 config);

/**
 * The function enables External Interrupt 
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint3Enable(void);

/**
 * The function disables External Interrupt 
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint3Disable(void);

/**
 * The function adds a callback to callback.
 *
 * \param callback callback function to add in the callback list.
 *
 * \return add callback status
 */
PFEnStatus pfEint3AddCallback(PFcallback callback);

/**
 * The function removes the specified callback from callback list.
 *
 * \param callback callback function to add in the callback list.
 *
 * \return remove callback status
 */
PFEnStatus pfEint3RemoveCallback(PFcallback callback);

/**
 * The function disables External Interrupt .
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint3Close(void);

#if (EINT3_CH == GPIO_INT_CH)
/**
 * The function configures and enables GPIO Interrupt with given settings.
 * 
 * \param id Pointer to variable where GPIO Interrupt ID will be written.
 * \param config configuration structure which contains the settings for the GPIO interrupt to be used.
 *
 * \return GPIO Interrupt configuration status.
 */
PFEnStatus pfGpioIntOpen(PFbyte* id, PFpCfgGpioInt config);

/**
 * The function enables GPIO Interrupt 
 *
 * \param id Id for the GPIO interrupt to enable
 * 
 * \return GPIO Interrupt status.
 */
PFEnStatus pfGpioIntEnable(PFbyte id);

/**
 * The function enables GPIO Interrupt 
 *
 * \param id Id for the GPIO interrupt to disable
 * 
 * \return GPIO Interrupt status.
 */
PFEnStatus pfGpioIntDisable(PFbyte id);

/**
 * The function disables GPIO Interrupt with given GPIO Interrupt ID.
 * 
 * \param id GPIO Interrupt ID for which Interrupt needs to be disable.
 *
 * \return GPIO Interrupt Close status.
 */
PFEnStatus pfGpioIntClose(PFbyte id);

#endif  // #if (EINT3_CH == GPIO_INT_CH)

/** @} */