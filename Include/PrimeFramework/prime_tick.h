/**
 * \file        prime_tick.h
 * \brief       Prime Framework Time Tick APIs
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
 *  \defgroup    PF_TICK_API TICK API
 *  @{
 *  
 *  \brief      Prime TICK API
 *  \details     Configure Timer for using tick APIs.
 *               Set Timer Period using pfTickSetTimerPeriod(), before using tick APIs.
 *  			 Also, pass pfTickUpdate() as a Callback in the config structure of your respective Timer.
 */

/**
 * Sets timer period for tick APIs
 * All calculations in the delay function will be done on the basis of timerPeriod.
 *
 * \param timerPeriod Time taken by timer in Milliseconds(ms) to count from 0 to the value in Compare Match Register.
 * \note This function should be called before using tick APIs.
 * 		 For eg: Timer Clock 				  = 	1Mhz
 * 				 Match Compare Register Value = 	100000				
 *				 TimerPeriod 				  = 	100ms(MilliSeconds)
 */
void pfTickSetTimerPeriod(PFdword timerPeriod);

/**
 * Increments tick value by 1.
 * This function should be provided to timer as callback.
 */
void pfTickUpdate(void);

/**
 * Resets tick value to zero
 */
void pfTickReset(void);

/**
 * Set timeout value. 
 * This will calculate the number ticks required depending on the timer period set 
 * and returns the number number of ticks required till timeout
 *
 * \param time Timeout value in milli seconds.
 *
 * \return Value of \a tick which will occur at timeout
 */
PFdword pfTickSetTimeoutMs(PFdword time);

/**
 * The function compares \a time with the current \a tick value and decides if the timeout is over or not
 *
 * \param timeoutTick Timeout tick value. This value should be the one returned by \a  pfTickSetTimeoutMs function
 *
 * \return Timeout status in boolean.
 */
PFEnBoolean pfTickCheckTimeout(PFdword timeoutTick);

/**
 * Generate delay in MilliSeconds.
 *
 * \param delayMs Delay value in milli seconds
 */
void pfTickDelayMs(PFdword delayMs);

/** @}  */


