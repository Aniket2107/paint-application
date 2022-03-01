/**
 * \file	prime_timer2.h
 * \brief   TIMER 2 Driver Discription for ATMEGA2560.
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
 * \defgroup PF_TIMER2 TIMER 2
 * @{
 * 
 * 	\brief TIMER 2 driver
 * 	\details  TIMER 2 driver for onchip TIMER 2 Peripheral
 */

/** \brief	TIMER 2 Configuration macros	*/
#define TIMER2_CH					TIMER2
#define TIMER2_CHANNEL				PERIPH(TIMER2_CH)
#define TIMER2_INT_HANDLER			INT_HANDLER(TIMER2_CH)

/** \brief Enumeration for timer2 modes			*/
typedef enum
{
	enTimer2ModeTimer = 0,					/**< Use timer2 in timer2 mode												*/
	enTimer2ModeCounterCap0RisingEdge,		/**< Use timer2 in counter mode, increment count on rising edge of CAP0 pin	*/
	enTimer2ModeCounterCap0FallingEdge,		/**< Use timer2 in counter mode, increment count on falling edge of CAP0 pin	*/
	enTimer2ModeCounterCap0BothEdge,		/**< Use timer2 in counter mode, increment count on both edges of CAP0 pin	*/
	enTimer2ModeCounterCap1RisingEdge = 5,	/**< Use timer2 in counter mode, increment count on rising edge of CAP1 pin	*/
	enTimer2ModeCounterCap1FallingEdge,		/**< Use timer2 in counter mode, increment count on falling edge of CAP1 pin	*/
	enTimer2ModeCounterCap1BothEdge,		/**< Use timer2 in counter mode, increment count on both edges of CAP1 pin	*/			
}PFEnTimer2Mode;

/** \brief Enumeration for timer2 count match action		*/
typedef enum
{
	enTimer2MatchActNone = 0,					/**< Take no action on count match					*/
	enTimer2MatchActInterrupt,					/**< Raise interrupt								*/
	enTimer2MatchActReset,						/**< Reset the timer2								*/
	enTimer2MatchActResetInt,					/**< Raise interrupt and reset the timer2			*/
	enTimer2MatchActStop,						/**< Stop the timer2 on count match					*/
	enTimer2MatchActStopInt,						/**< Stop timer2 and raise interrupt					*/
	enTimer2MatchActStopReset,					/**< Reset and stop the timer2						*/
	enTimer2MatchActStopResetInt,				/**< Raise interrupt and stop and reset the timer2	*/
}PFEnTimer2MatchAction;

/** \brief Enumeration for external match control		*/
typedef enum
{
	enTimer2ExtMatchCtrlNone = 0,					/**< Do nothing on count match						*/
	enTimer2ExtMatchCtrlClearPin,					/**< Clear match pin								*/
	enTimer2ExtMatchCtrlSetPin,						/**< Set match pin									*/
	enTimer2ExtMatchCtrlTogglePin,					/**< Toggle match pin								*/
}PFEnTimer2ExtMatchCtrl;

/**	\brief Timer2 configure structure		*/
typedef struct
{
	PFdword					prescaler;			/**< Prescaler for timer2 clock count				*/
	PFdword					matchValue[4];		/**< Match register values							*/
	PFEnTimer2MatchAction	matchAction[4];		/**< Compare match action for each match register	*/
	PFEnTimer2ExtMatchCtrl	exMatchAction[4];	/**< match pin control on count match 				*/ 
	PFcallback				callback;			/**< Callback function for timer2 ISR				*/
	PFEnPclkDivider			clkDiv;				/**< Peripheral clock divider for timer2 module		*/
	PFEnTimer2Mode			timer2Mode;			/**< Select timer2/counter mode with clock source for counter mode	*/
	PFEnBoolean				interrupt;			/**< To enable or disable timer2 interrupt			*/
}PFCfgTimer2;

/** \brief Pointer to PFCfgTiemr structure		*/
typedef PFCfgTimer2* PFpCfgTimer2;

/**
 * Initialized timer2 with given parameters
 * 
 * \param config Pointer to timer2 configuration structure
 * 
 * \return timer2 initialization status
 */
PFEnStatus pfTimer2Open(PFpCfgTimer2 config);

/**
 * Stops timer2 operation and turns off the timer2 module
 */
void pfTimer2Close(void);

/**
 * Starts timer2 operation
 * 
 * \return timer2 start status
 */
PFEnStatus pfTimer2Start(void);

/**
 * Stops timer2 operation
 * 
 * \return timer2 stop status
 */
PFEnStatus pfTimer2Stop(void);

/**
 * Resets the timer2 operation. Timer2 will start counting from zero again.
 * 
 * \return timer2 reset status
 */
PFEnStatus pfTimer2Reset(void);

/**
 * Writes new value to the match register and enables latch for the match register
 *
 * \param regNum index of match register to be updated
 * \param regVal new value for match register
 *
 * \return match register update status
 */
PFEnStatus pfTimer2UpdateMatchRegister(PFbyte regNum, PFdword regVal);

/**
 * Returns the timer2 count
 * 
 * \param count Pointer to variable where timer2 count will be stored.
 * 
 * \return Timer2 status.
 */
 PFEnStatus pfTimer2ReadCount(PFdword* count);

/**
 * Returns timer2 interrupt status.
 * 
 * \param status Pointer to variable where timer2 interrupt status will be stored.
 * 
 * \return Timer2 status.
 */
 PFEnStatus pfTimer2GetIntStatus(PFdword* status);

/**
 * Clears timer2 interrupt status flags
 * 
 * \param intStatus timer2 interrupts for which flag is to be cleared.
 * 
 * \return Timer2 status.
 */
PFEnStatus pfTimer2ClearIntStatus(PFdword intStatus);

/**
 * Enables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer2IntEnable(void);

/**
 * Disables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer2IntDisable(void);

/**
 * Get timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Pointer to variable where timer tick frequency in hertz will be loaded.
 *
 * \return status
 */
PFEnStatus pfTimer2GetTickFreq(PFdword* tickFreq);

/**
 * Set timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Timer tick frequency in hertz.
 *
 * \return status
 */
PFEnStatus pfTimer2SetTickFreq(PFdword tickFreq);

/**
 * Updates match action of match register.
 *
 * \param regNum index of match register for which count match action to be updated.
 * \param matchAction match action for match register(regNum). 
 *
 * \return match control register update status
 */
PFEnStatus pfTimer2UpdateMatchControlRegister(PFbyte regNum,PFEnTimer2MatchAction matchAction);

/** @} */