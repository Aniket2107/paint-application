/**
 * \file	prime_timer0.h
 * \brief   TIMER 0 Driver Discription for ATMEGA2560.
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
 * \ingroup PF_TIMER
 * \defgroup PF_TIMER0 TIMER 0
 * @{
 * 
 * 	\brief TIMER 0 driver
 * 	\details  TIMER 0 driver for onchip TIMER 0 Peripheral
 */

/** \brief	TIMER 0 Configuration macros	*/
#define TIMER0_CH					TIMER0
#define TIMER0_CHANNEL				PERIPH(TIMER0_CH)
#define TIMER0_INT_HANDLER			INT_HANDLER(TIMER0_CH)

/** \brief Enumeration for timer0 modes			*/
typedef enum
{
	enTimer0ModeTimer = 0,					/**< Use timer0 in timer0 mode												*/
	enTimer0ModeCounterCap0RisingEdge,		/**< Use timer0 in counter mode, increment count on rising edge of CAP0 pin	*/
	enTimer0ModeCounterCap0FallingEdge,		/**< Use timer0 in counter mode, increment count on falling edge of CAP0 pin	*/
	enTimer0ModeCounterCap0BothEdge,		/**< Use timer0 in counter mode, increment count on both edges of CAP0 pin	*/
	enTimer0ModeCounterCap1RisingEdge = 5,	/**< Use timer0 in counter mode, increment count on rising edge of CAP1 pin	*/
	enTimer0ModeCounterCap1FallingEdge,		/**< Use timer0 in counter mode, increment count on falling edge of CAP1 pin	*/
	enTimer0ModeCounterCap1BothEdge,		/**< Use timer0 in counter mode, increment count on both edges of CAP1 pin	*/			
}PFEnTimer0Mode;

/** \brief Enumeration for timer0 count match action		*/
typedef enum
{
	enTimer0MatchActNone = 0,					/**< Take no action on count match					*/
	enTimer0MatchActInterrupt,					/**< Raise interrupt								*/
	enTimer0MatchActReset,						/**< Reset the timer0								*/
	enTimer0MatchActResetInt,					/**< Raise interrupt and reset the timer0			*/
	enTimer0MatchActStop,						/**< Stop the timer0 on count match					*/
	enTimer0MatchActStopInt,					/**< Stop timer0 and raise interrupt					*/
	enTimer0MatchActStopReset,					/**< Reset and stop the timer0						*/
	enTimer0MatchActStopResetInt,				/**< Raise interrupt and stop and reset the timer0	*/
}PFEnTimer0MatchAction;

/** \brief Enumeration for external match control		*/
typedef enum
{
	enTimer0ExtMatchCtrlNone = 0,					/**< Do nothing on count match						*/
	enTimer0ExtMatchCtrlClearPin,					/**< Clear match pin								*/
	enTimer0ExtMatchCtrlSetPin,						/**< Set match pin									*/
	enTimer0ExtMatchCtrlTogglePin,					/**< Toggle match pin								*/
}PFEnTimer0ExtMatchCtrl;

/**	\brief	Timer0 configure structure		*/
typedef struct
{
	PFdword					prescaler;			/**< Prescaler for timer0 clock count				*/
	PFdword					matchValue[4];		/**< Match register values							*/
	PFEnTimer0MatchAction	matchAction[4];		/**< Compare match action for each match register	*/
	PFEnTimer0ExtMatchCtrl	exMatchAction[4];	/**< match pin control on count match 				*/ 
	PFcallback				callback;			/**< Callback function for timer0 ISR				*/
	PFEnPclkDivider			clkDiv;				/**< Peripheral clock divider for timer0 module		*/
	PFEnTimer0Mode			timer0Mode;			/**< Select timer0/counter mode with clock source for counter mode	*/
	PFEnBoolean				interrupt;			/**< To enable or disable timer0 interrupt			*/
}PFCfgTimer0;

/** \brief Pointer to PFCfgTiemr structure		*/
typedef PFCfgTimer0* PFpCfgTimer0;

/**
 * Initialized timer0 with given parameters
 * 
 * \param config Pointer to timer0 configuration structure
 * 
 * \return timer0 initialization status
 */
PFEnStatus pfTimer0Open(PFpCfgTimer0 config);

/**
 * Stops timer0 operation and turns off the timer0 module
 */
void pfTimer0Close(void);

/**
 * Starts timer0 operation
 * 
 * \return timer0 start status
 */
PFEnStatus pfTimer0Start(void);

/**
 * Stops timer0 operation
 * 
 * \return timer0 stop status
 */
PFEnStatus pfTimer0Stop(void);

/**
 * Resets the timer0 operation. Timer0 will start counting from zero again.
 * 
 * \return timer0 reset status
 */
PFEnStatus pfTimer0Reset(void);

/**
 * Writes new value to the match register and enables latch for the match register
 *
 * \param regNum index of match register to be updated
 * \param regVal new value for match register
 *
 * \return match register update status
 */
PFEnStatus pfTimer0UpdateMatchRegister(PFbyte regNum, PFdword regVal);

/**
 * Returns the timer0 count
 * 
 * \param count Pointer to variable where timer0 count will be stored.
 * 
 * \return Timer0 status.
 */
 PFEnStatus pfTimer0ReadCount(PFdword* count);

/**
 * Returns timer0 interrupt status.
 * 
 * \param status Pointer to variable where timer0 interrupt status will be stored.
 * 
 * \return Timer0 status.
 */
 PFEnStatus pfTimer0GetIntStatus(PFdword* status);

/**
 * Clears timer0 interrupt status flags
 * 
 * \param intStatus timer0 interrupts for which flag is to be cleared.
 * 
 * \return Timer0 status.
 */
PFEnStatus pfTimer0ClearIntStatus(PFdword intStatus);

/**
 * Enables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer0IntEnable(void);

/**
 * Disables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer0IntDisable(void);

/**
 * Get timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Pointer to variable where timer tick frequency in hertz will be loaded.
 *
 * \return status
 */
PFEnStatus pfTimer0GetTickFreq(PFdword* tickFreq);

/**
 * Set timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Timer tick frequency in hertz.
 *
 * \return status
 */
PFEnStatus pfTimer0SetTickFreq(PFdword tickFreq);

/**
 * Updates match action of match register.
 *
 * \param regNum index of match register for which count match action to be updated.
 * \param matchAction match action for match register(regNum). 
 *
 * \return match control register update status
 */
PFEnStatus pfTimer0UpdateMatchControlRegister(PFbyte regNum,PFEnTimer0MatchAction matchAction);

/** @} */