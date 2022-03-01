/**
 * \file	prime_eint1.h
 * \brief   EXT INT 1 Driver Discription for LPC1768.
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
 * \defgroup PF_EINT1 EXT INT 1
 * @{
 * 
 * 	\brief EXT INT 1 driver
 * 	\details  EXT INT 1 driver for onchip EXT INT 1
 */

/** \brief	External Interrupt Configuration macros	*/
#define EINT1_CH			1
#define EINT1_CHANNEL		PF_CONCAT(EINT, EINT1_CH)
#define EINT1_HANDLER		INT_HANDLER(EINT1_CHANNEL) 
 
/**	\brief Enumeration for External Interrupt mode	*/
typedef enum
{
	enEint1ModeLowLevel = 0,				/**< Low level trigerred interrupt							*/
	enEint1ModeHighLevel,				/**< High level trigerred interrupt							*/
	enEint1ModeFallingEdge,				/**< Falling edge trigerred interrupt						*/
	enEint1ModeRisingEdge				/**< Rising edge trigerred interrupt						*/
}PFEnEint1Mode;

/**	\brief	External interrupt	configure Structure	*/
typedef struct
{
	PFcallback* callbackList;			/**< Pointer to array of callbacks to attach to interrupt	*/
    PFbyte callbackCount;				/**< Number of callbacks provided in \a callbackList		*/
    PFEnEint1Mode mode;					/**< External interrupt mode								*/
}PFCfgEint1;

/**
 * \brief pointer to PFCfgEint1 structure
 */
typedef PFCfgEint1* PFpCfgEint1;

#if (EINT1_CH == GPIO_INT_CH)
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

#endif  // #if (EINT1_CH == GPIO_INT_CH)

/**
 * The function configures and enables External Interrupt with given settings.
 
 * \param config Pointer to configuration structure which contains the settings for the external interrupt to be used.

 * \return External Interrupt status.
 */
PFEnStatus pfEint1Open(PFpCfgEint1 config);

/**
 * The function enables External Interrupt 
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint1Enable(void);

/**
 * The function disables External Interrupt 
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint1Disable(void);

/**
 * The function adds a callback to callback.
 *
 * \param callback callback function to add in the callback list.
 *
 * \return add callback status
 */
PFEnStatus pfEint1AddCallback(PFcallback callback);

/**
 * The function removes the specified callback from callback list.
 *
 * \param callback callback function to add in the callback list.
 *
 * \return remove callback status
 */
PFEnStatus pfEint1RemoveCallback(PFcallback callback);

/**
 * The function disables External Interrupt .
 *
 * \return External Interrupt status.
 */
PFEnStatus pfEint1Close(void);

#if (EINT1_CH == GPIO_INT_CH)
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
 * \return GPIO Interrupt status.
 */
PFEnStatus pfGpioIntEnable(void);

/**
 * The function disables GPIO Interrupt with given GPIO Interrupt ID.
 * 
 * \param gpioIntID GPIO Interrupt ID for which Interrupt needs to be disable.
 *
 * \return GPIO Interrupt Close status.
 */
PFEnStatus pfGpioIntClose(PFbyte gpioIntID);

#endif  // #if (EINT1_CH == GPIO_INT_CH)

/** @} */