/**
 * \file        prime_delay.h
 * \brief       Prime Framework Delay API
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: NO
 *
 */
#pragma once

/**
 *  \ingroup     core
 *  \defgroup    PF_DELAY    DELAY
 *  @{
 *  
 *  \brief      Delay Generation configuration
 *  \details    
 */

/**
 *  \brief Delay Source Macro
 *  
 *  \details
 *  <PRE>
 *       Macro TIMER_CONFIGURED = 1,     If using Timer for Delay Generation.
 *                                       Set Timer Period using pfDelaySetTimerPeriod(), before using delay APIs.
 *  									 Also, pass pfDelayTickUpdate() as a Callback in the config structure of your respective Timer.
 *       Macro TIMER_CONFIGURED = 0,     If not using Timer for delay generation, delay will be generated using for loop(approx delay).
 *  </PRE>
 */
#define TIMER_CONFIGURED 1

/**
 * Sets timer period for DELAY APIs
 * 
 * All calculations in the delay function will be done on the basis of timerPeriod.
 * 
 * \param timerPeriod Time taken by timer in Micoseconds(us) to count from 0 to the value in Compare Match Register.
 * \note If TIMER_CONFIGURED = 1, this function should be called before using delay APIs.
 * 		 For eg: Timer Clock 				  = 	1Mhz
 * 				 Match Compare Register Value = 	1000				
 *				 TimerPeriod 				  = 	1000us(MicroSeconds)		
 */
void pfDelaySetTimerPeriod(PFdword timerPeriod);

/**
 * Increments tick value by 1.
 * This function should be provided to timer as callback.
 */
void pfDelayTickUpdate(void);

/**
 * This will return timer Resolution in micro second
 *
 * \return timer resolution 
 */ 
PFdword pfDelayGetTimerPeriod(void);

/**
 * This will return delay tick 
 *
 * \return current Value of Delay-tick
 */
PFdword pfDelayGetTick(void);

/**
 * Resets tick value to zero
 */
void pfDelayTickReset(void);

/**
 * Set timeout value. 
 * This will calculate the number ticks required depending on the timer period set 
 * and returns the number of ticks required till timeout
 *
 * \param time Timeout value in micro seconds.
 *
 * \return Value of \a tick which will occur at timeout
 */
PFdword pfDelaySetTimeout(PFdword time);

/**
 * The function compares \a time with the current \a tick value and decides if the timeout is over or not
 *
 * \param timeoutTick Timeout tick value. This value should be the one returned by \a  pfTickSetTimeoutMs function
 *
 * \return Timeout status in boolean.
 */
PFEnBoolean pfDelayCheckTimeout(PFdword timeoutTick);

/**
 * Generate delay in MicroSeconds.
 *
 * \param delayUs Delay value in micro seconds
 */ 
void pfDelayMicroSec(PFdword delayUs);

/**
 * Generate delay in MilliSeconds.
 *
 * \param delayMs Delay value in milli seconds
 */
void pfDelayMilliSec(PFdword delayMs);

/** @}  */


