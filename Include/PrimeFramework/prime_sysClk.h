/**
 * \file	prime_sysClk.h
 * \brief   Sys CLK Driver Discription for LPC1768.
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
#include "prime_types.h"
/**
 * \ingroup native
 * \defgroup PF_SYSCLK SYS CLK
 * @{
 * 
 * 	\brief SYS CLK driver
 * 	\details  SYS CLK driver for SYS CLK Peripheral
 */

/** \brief	Enumeration for PLL Clock Source Selection			*/
typedef enum
{
	enPllClkSrcInternalRC = 0x00,		/**< Selects the Internal RC oscillator as the PLL0 clock source.	*/
	enPllClkSrcMainOSC,					/**< Selects the main oscillator as the PLL0 clock source.			*/	
	enPllClkSrcRtcOSC,					/**< Selects the RTC oscillator as the PLL0 clock source.			*/
}PFEnClkSrc;

/** \brief Enumeration for peripheral clock divider		*/
typedef enum
{
	enPclkDiv_4 = 0,					/**< PCLK_peripheral = CCLK/4.		*/
	enPclkDiv_1,						/**< PCLK_peripheral = CCLK/1.		*/
	enPclkDiv_2,						/**< PCLK_peripheral = CCLK/2.		*/
	enPclkDiv_8							/**< PCLK_peripheral = CCLK/8.		*/
}PFEnPclkDivider;

/**	\brief	CPU Clock configure Structure	*/
typedef struct
{
	PFdword cpuFreqHz;					/**< Set frequency of CPU Clock.			*/
	PFdword oscFreq;					/**< Value of Oscillator Frequency in Hz.  	*/
	PFEnClkSrc pllClkSrc;				/**< Set Clock Source for PLL.				*/
}PFCfgClk; 

/** \brief Pointer to PFCfgClk Structure		*/
typedef PFCfgClk*	PFpCfgClk;

/**
 * The function sets the CPU Clock(CCLK) frequency with given settings.
 * The function internally calculates PLL0 Multiplier value(M),PLL0 Pre-Divider value(N), CPU clock divider(D) form given settings.
 * It calls pfPllInit with calculated arguments for that.
 *
 * \param config Pointer to configuration structure which contains the settings for PLL and CPU clock.
 * 
 * \return CPU clock config Status.
 */
PFEnStatus pfSysSetCpuClock(PFpCfgClk config);

/**
 * The function calculates Frequency of CPU Clock(CCLK).
 *
 * \return CPU clock Frequency in Hz.
 */
PFdword pfSysGetCpuClock (void);

/**
 * Function provides detailed configuration of PLL with given arguments. 
 * CPU Freq = ((SrcClkFreq / N) * 2M) / D
 *
 * \param pllPreDivider PLL0 Pre-Divider value "N". 
 * \param pllMultiplier PLL0 Multiplier value "M". 
 * \param cpuClkDivider	PLL clock will be divided by this value to produce the CPU clock.
 * \param pllClksrc	Selects the clock source for PLL0
 *  
 * \return PLL config Status.
 */
PFEnStatus pfPllConfig(PFdword pllPreDivider,PFdword pllMultiplier,PFdword cpuClkDivider,PFdword pllClksrc);


/**
 * Function sets peripheral clock divider. 
 * CPU clock is divided by the peripheral clock divider and then fed to peripheral.
 *
 * \param peripheral peripheral number to set clock divider.
 * \param clockDiv clock divider to set for peripheral.
 */
void pfSysSetPclkDiv(PFdword peripheral, PFdword clockDiv);

/**
 * The function reads the clock divider set for the peripheral and calculates peripheral clock frequency
 *
 * \param peripheral peripheral number to get clock frequency
 *
 * \return peripheral clock frequency in hertz
 */
PFdword pfSysGetPclk(PFdword peripheral);

/** @} */