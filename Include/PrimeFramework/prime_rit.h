/**
 * \file	prime_rit.h
 * \brief   RIT Driver Discription for LPC1768.
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
 * \defgroup PF_RIT RIT
 * @{
 * 
 * 	\brief RIT driver
 * 	\details  RIT driver for GPIO Peripheral
 */
 
/** \brief Configuration macros for RIT		*/
#define RIT_CH				RIT
#define RIT_CHANNEL			PERIPH(RIT_CH)
#define RIT_INT_HANDLER		INT_HANDLER(RIT_CH)
 
/** Configuration structure for RIT		*/ 
typedef struct
{
	PFdword			compareValue;		/**< Compare value for RIT to generate interrupt						*/
	PFdword			compareMask;		/**< Bits marked as '1' only will be compared							*/
	PFcallback		callback;			/**< Callback function for RIT ISR										*/
	PFEnPclkDivider	clkDiv;				/**< Peripheral clock divider for RIT module							*/
	PFEnBoolean		haltOnBreak;		/**< The timer is halted when the processor is halted for debugging		*/
	PFEnBoolean		resetOnMatch;		/**< The timer is reset to zero when match occurs						*/
}PFCfgRit;

/** \brief Pointer to PFCfgRit structure		*/
typedef PFCfgRit* PFpCfgRit;

/**
 * Initializes RIT module with given parameters.
 *
 * \param config Pointer to RIT configuration structure
 * 
 * \return RIT initialization status
 */
PFEnStatus pfRitOpen(PFpCfgRit config);

/**
 * Stops RIT operation and turns off the RIT module
 */
void pfRitClose(void); 

/**
 * Starts RIT counting.
 *
 * \return RIT enable status
 */
PFEnStatus pfRitStart(void);

/**
 * Stops RIT counting.
 *
 * \return RIT disable status
 */
PFEnStatus pfRitStop(void);


/** @} */

