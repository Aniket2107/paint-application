/**
 * \file	prime_systick.h
 * \brief   Sys Tick Driver Discription for LPC1768.
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
 * \defgroup PF_SYSTICK SYS TICK
 * @{
 * 
 * 	\brief SYS TICK driver
 * 	\details  SYS TICK driver for SYS TICK Peripheral
 */

 
/** \brief Enumeration for Sys Tick Source 	*/ 
typedef enum
{
	enSystickClkExt = 0,					/**< Select external clock to pin STCLK as clock source 				*/
	enSystickClkCpu							/**< Select internal CPU clock as clock source							*/
}PFEnSystickClkSrc;		
 
/** \brief Configuration structure for SysTick		*/ 
typedef struct
{
	PFdword				compareValue;		/**< Compare value for SysTick to generate interrupt, 0x00 - 0xFFFFFF	*/
	PFcallback			callback;			/**< Callback function for SysTick ISR									*/
	PFEnSystickClkSrc 	clkSource;			/**< Clock source for SysTick timer										*/
}PFCfgSystick;

/** \brief Pointer to PFCfgSystick structure		*/
typedef PFCfgSystick* PFpCfgSystick;

/**
 * Initializes SysTick module with given parameters.
 *
 * \param config Pointer to SysTick configuration structure.
 * 
 * \return SysTick initialization status
 */
PFEnStatus pfSystickOpen(PFpCfgSystick config);

/**
 * Stops SysTick operation and turns off the SysTick module
 */
void pfSystickClose(void); 

/**
 * Return systick count which is incremented on every SysTick interrupt.
 *
 * \param count Pointer to variable where systick count will be loaded.
 * 
 * \return SysTick get count status
 */
 PFEnStatus pfSystickGetCount(PFdword* count);


/** @} */

