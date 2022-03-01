/**
 * \file	prime_wdt.h
 * \brief   WDT Driver Discription for LPC1768.
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
 * \defgroup PF_WDT WDT
 * @{
 * 
 * 	\brief WDT driver
 * 	\details  WDT driver for onchip WDT Peripheral
 */

/** \brief WatchDog Timer Configuration macros 		*/
#define WDT_CH				WDT
#define WDT_CHANNEL			PERIPH(WDT_CH)
#define WDT_INT_HANDLER		INT_HANDLER(WDT_CH) 

/** \brief Enumeration for Watchdog clock Source 		*/
typedef enum
{
	enWatchdogClkIRC = 0,					/**< Use clock from internal RC oscillator		*/
	enWatchdogClkPCLK = 1,				/**< Use clock of APB peripheral clock			*/
	enWatchdogClkRTC = 2					/**< Use clock from RTC oscillator				*/	
}PFEnWatchdogClkSrc;

/**	\brief Watchdog configure structure		*/
typedef struct
{
	PFEnWatchdogClkSrc clksrc;		/**< Clock source selection for watchdog */
	PFdword	timeout; 							/**< Timeout value of watchdog timer in Microseconds		*/
	PFEnPclkDivider clkDiv;				/**< clkDiv to be used only if PCLk is used as watchdog timer clock Source		*/
}PFCfgWatchdog;

/** \brief Pointer to PFCfgWatchDog structure		*/
typedef PFCfgWatchdog* PFpCfgWatchdog;

/**
 * Initialized watchdog  with given parameters
 * 
 * \param config pointer to watchdog configuration structure
 * 
 * \return watchdog initialization status
 */
PFEnStatus pfWatchdogOpen(PFpCfgWatchdog config);
/**
 * Close watchdog module 
 *
 * \return watchdog module close status 
 */
PFEnStatus pfWatchdogClose(void);
/**
 * Starts watchdog operation
 * 
 * \return watchdog start status
 */
PFEnStatus pfWatchdogStart(void);

/**
 * Stops watchdog operation, will put in temporary halt condition
 * 
 * \return watchdog start status
 */
PFEnStatus pfWatchdogStop(void);
/**
 * Gives current value of the watchdog counter 
 *
 *\param count pointer to store current count value 
 * 
 * \return  current value status
 */
PFEnStatus pfWatchdogGetCurrentCount(PFdword *count);

/**
 * Clear the timeout flag of the watchdog 
 * 
 * \return timeout flag status
 */
PFEnStatus pfWatchdogClearTimoutFlag(void);

/**
 * When WDTEN is set call this function to start the watchdog 
 * 
 * \return feed status
 */
PFEnStatus pfWatchdogFeed(void);

/**
 * Update the timeout value of the watchdog 
 * 
 * \param timeout Timeout value of watchdog timer in Microseconds
 *
 * \return update timeout status
 */
PFEnStatus pfWatchdogUpdateTimeout(PFdword timeout);

/**
 * Read the timout flag status
 * 
 * \param flagStatus Pointer to flag status variable 
 *
 * \return  read timeout status
 */
 PFEnStatus pfWatchTimerReadTimeoutFlag(PFEnBoolean *flagStatus);

  /** @} */