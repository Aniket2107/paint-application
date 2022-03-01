/**
 * \file	prime_timer1.h
 * \brief   TIMER 1 Driver Discription for LPC1768.
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
 * \defgroup PF_TIMER1 TIMER 1
 * @{
 * 
 * 	\brief TIMER 1 driver
 * 	\details  TIMER 1 driver for onchip TIMER 1 Peripheral
 */

/** \brief	TIMER 1 Configuration macros	*/
#define TIMER1_CH					TIMER1
#define TIMER1_CHANNEL				PERIPH(TIMER1_CH)
#define TIMER1_INT_HANDLER			INT_HANDLER(TIMER1_CH)

/** \brief Enumeration for timer1 modes			*/
typedef enum
{
	enTimer1ModeTimer = 0,					/**< Use timer1 in timer1 mode												*/
	enTimer1ModeCounterCap0RisingEdge,		/**< Use timer1 in counter mode, increment count on rising edge of CAP0 pin	*/
	enTimer1ModeCounterCap0FallingEdge,		/**< Use timer1 in counter mode, increment count on falling edge of CAP0 pin	*/
	enTimer1ModeCounterCap0BothEdge,		/**< Use timer1 in counter mode, increment count on both edges of CAP0 pin	*/
	enTimer1ModeCounterCap1RisingEdge = 5,	/**< Use timer1 in counter mode, increment count on rising edge of CAP1 pin	*/
	enTimer1ModeCounterCap1FallingEdge,		/**< Use timer1 in counter mode, increment count on falling edge of CAP1 pin	*/
	enTimer1ModeCounterCap1BothEdge,		/**< Use timer1 in counter mode, increment count on both edges of CAP1 pin	*/			
}PFEnTimer1Mode;

/** \brief Enumeration for timer1 count match action		*/
typedef enum
{
	enTimer1MatchActNone = 0,					/**< Take no action on count match					*/
	enTimer1MatchActInterrupt,					/**< Raise interrupt								*/
	enTimer1MatchActReset,						/**< Reset the timer1								*/
	enTimer1MatchActResetInt,					/**< Raise interrupt and reset the timer1			*/
	enTimer1MatchActStop,						/**< Stop the timer1 on count match					*/
	enTimer1MatchActStopInt,						/**< Stop timer1 and raise interrupt					*/
	enTimer1MatchActStopReset,					/**< Reset and stop the timer1						*/
	enTimer1MatchActStopResetInt,				/**< Raise interrupt and stop and reset the timer1	*/
}PFEnTimer1MatchAction;

/** \brief Enumeration for external match control		*/
typedef enum
{
	enTimer1ExtMatchCtrlNone = 0,					/**< Do nothing on count match						*/
	enTimer1ExtMatchCtrlClearPin,					/**< Clear match pin								*/
	enTimer1ExtMatchCtrlSetPin,						/**< Set match pin									*/
	enTimer1ExtMatchCtrlTogglePin,					/**< Toggle match pin								*/
}PFEnTimer1ExtMatchCtrl;

/**	\brief	Timer1 configure structure		*/
typedef struct
{
	PFdword					prescaler;			/**< Prescaler for timer1 clock count				*/
	PFdword					matchValue[4];		/**< Match register values							*/
	PFEnTimer1MatchAction	matchAction[4];		/**< Compare match action for each match register	*/
	PFEnTimer1ExtMatchCtrl	exMatchAction[4];	/**< match pin control on count match 				*/ 
	PFcallback				callback;			/**< Callback function for timer1 ISR				*/
	PFEnPclkDivider			clkDiv;				/**< Peripheral clock divider for timer1 module		*/
	PFEnTimer1Mode			timer1Mode;			/**< Select timer1/counter mode with clock source for counter mode	*/
	PFEnBoolean				interrupt;			/**< To enable or disable timer1 interrupt			*/
}PFCfgTimer1;

/** \brief Pointer to PFCfgTiemr structure		*/
typedef PFCfgTimer1* PFpCfgTimer1;

/**
 * Initialized timer1 with given parameters
 * 
 * \param config Pointer to timer1 configuration structure
 * 
 * \return timer1 initialization status
 */
PFEnStatus pfTimer1Open(PFpCfgTimer1 config);

/**
 * Stops timer1 operation and turns off the timer1 module
 */
void pfTimer1Close(void);

/**
 * Starts timer1 operation
 * 
 * \return timer1 start status
 */
PFEnStatus pfTimer1Start(void);

/**
 * Stops timer1 operation
 * 
 * \return timer1 stop status
 */
PFEnStatus pfTimer1Stop(void);

/**
 * Resets the timer1 operation. Timer1 will start counting from zero again.
 * 
 * \return timer1 reset status
 */
PFEnStatus pfTimer1Reset(void);

/**
 * Writes new value to the match register and enables latch for the match register
 *
 * \param regNum index of match register to be updated
 * \param regVal new value for match register
 *
 * \return match register update status
 */
PFEnStatus pfTimer1UpdateMatchRegister(PFbyte regNum, PFdword regVal);

/**
 * Returns the timer1 count
 * 
 * \param count Pointer to variable where timer1 count will be stored.
 * 
 * \return Timer1 status.
 */
 PFEnStatus pfTimer1ReadCount(PFdword* count);

/**
 * Returns timer1 interrupt status.
 * 
 * \param status Pointer to variable where timer1 interrupt status will be stored.
 * 
 * \return Timer1 status.
 */
 PFEnStatus pfTimer1GetIntStatus(PFdword* status);

/**
 * Clears timer1 interrupt status flags
 * 
 * \param intStatus timer1 interrupts for which flag is to be cleared.
 * 
 * \return Timer1 status.
 */
PFEnStatus pfTimer1ClearIntStatus(PFdword intStatus);

/**
 * Enables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer1IntEnable(void);

/**
 * Disables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer1IntDisable(void);

/**
 * Get timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Pointer to variable where timer tick frequency in hertz will be loaded.
 *
 * \return status
 */
PFEnStatus pfTimer1GetTickFreq(PFdword* tickFreq);

/**
 * Set timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Timer tick frequency in hertz.
 *
 * \return status
 */
PFEnStatus pfTimer1SetTickFreq(PFdword tickFreq);

/**
 * Updates match action of match register.
 *
 * \param regNum index of match register for which count match action to be updated.
 * \param matchAction match action for match register(regNum). 
 *
 * \return match control register update status
 */
PFEnStatus pfTimer1UpdateMatchControlRegister(PFbyte regNum,PFEnTimer1MatchAction matchAction);

/** @} */
