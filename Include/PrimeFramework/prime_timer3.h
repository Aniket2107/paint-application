/**
 * \file	prime_timer3.h
 * \brief   TIMER 3 Driver Discription for ATMEGA2560.
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
 * \defgroup PF_TIMER3 TIMER 3
 * @{
 * 
 * 	\brief TIMER 3 driver
 * 	\details  TIMER 3 driver for onchip TIMER 3 Peripheral
 */

/** \brief	TIMER 3 Configuration macros	*/
#define TIMER3_CH					TIMER3
#define TIMER3_CHANNEL				PERIPH(TIMER3_CH)
#define TIMER3_INT_HANDLER			INT_HANDLER(TIMER3_CH)

/** \brief Enumeration for timer3 modes			*/
typedef enum
{
	enTimer3ModeTimer = 0,					/**< Use timer3 in timer3 mode												*/
	enTimer3ModeCounterCap0RisingEdge,		/**< Use timer3 in counter mode, increment count on rising edge of CAP0 pin	*/
	enTimer3ModeCounterCap0FallingEdge,		/**< Use timer3 in counter mode, increment count on falling edge of CAP0 pin	*/
	enTimer3ModeCounterCap0BothEdge,		/**< Use timer3 in counter mode, increment count on both edges of CAP0 pin	*/
	enTimer3ModeCounterCap1RisingEdge = 5,	/**< Use timer3 in counter mode, increment count on rising edge of CAP1 pin	*/
	enTimer3ModeCounterCap1FallingEdge,		/**< Use timer3 in counter mode, increment count on falling edge of CAP1 pin	*/
	enTimer3ModeCounterCap1BothEdge,		/**< Use timer3 in counter mode, increment count on both edges of CAP1 pin	*/			
}PFEnTimer3Mode;

/** \brief Enumeration for timer3 count match action		*/
typedef enum
{
	enTimer3MatchActNone = 0,					/**< Take no action on count match					*/
	enTimer3MatchActInterrupt,					/**< Raise interrupt								*/
	enTimer3MatchActReset,						/**< Reset the timer3								*/
	enTimer3MatchActResetInt,					/**< Raise interrupt and reset the timer3			*/
	enTimer3MatchActStop,						/**< Stop the timer3 on count match					*/
	enTimer3MatchActStopInt,						/**< Stop timer3 and raise interrupt					*/
	enTimer3MatchActStopReset,					/**< Reset and stop the timer3						*/
	enTimer3MatchActStopResetInt,				/**< Raise interrupt and stop and reset the timer3	*/
}PFEnTimer3MatchAction;

/** \brief Enumeration for external match control		*/
typedef enum
{
	enTimer3ExtMatchCtrlNone = 0,					/**< Do nothing on count match						*/
	enTimer3ExtMatchCtrlClearPin,					/**< Clear match pin								*/
	enTimer3ExtMatchCtrlSetPin,						/**< Set match pin									*/
	enTimer3ExtMatchCtrlTogglePin,					/**< Toggle match pin								*/
}PFEnTimer3ExtMatchCtrl;

/**	\brief	Timer3 configure structure		*/
typedef struct
{
	PFdword					prescaler;			/**< Prescaler for timer3 clock count				*/
	PFdword					matchValue[4];		/**< Match register values							*/
	PFEnTimer3MatchAction	matchAction[4];		/**< Compare match action for each match register	*/
	PFEnTimer3ExtMatchCtrl	exMatchAction[4];	/**< match pin control on count match 				*/ 
	PFcallback				callback;			/**< Callback function for timer3 ISR				*/
	PFEnPclkDivider			clkDiv;				/**< Peripheral clock divider for timer3 module		*/
	PFEnTimer3Mode			timer3Mode;			/**< Select timer3/counter mode with clock source for counter mode	*/
	PFEnBoolean				interrupt;			/**< To enable or disable timer3 interrupt			*/
}PFCfgTimer3;

/** \brief Pointer to PFCfgTiemr structure		*/
typedef PFCfgTimer3* PFpCfgTimer3;

/**
 * Initialized timer3 with given parameters
 * 
 * \param config Pointer to timer3 configuration structure
 * 
 * \return timer3 initialization status
 */
PFEnStatus pfTimer3Open(PFpCfgTimer3 config);

/**
 * Stops timer3 operation and turns off the timer3 module
 */
void pfTimer3Close(void);

/**
 * Starts timer3 operation
 * 
 * \return timer3 start status
 */
PFEnStatus pfTimer3Start(void);

/**
 * Stops timer3 operation
 * 
 * \return timer3 stop status
 */
PFEnStatus pfTimer3Stop(void);

/**
 * Resets the timer3 operation. Timer3 will start counting from zero again.
 * 
 * \return timer3 reset status
 */
PFEnStatus pfTimer3Reset(void);

/**
 * Writes new value to the match register and enables latch for the match register
 *
 * \param regNum index of match register to be updated
 * \param regVal new value for match register
 *
 * \return match register update status
 */
PFEnStatus pfTimer3UpdateMatchRegister(PFbyte regNum, PFdword regVal);

/**
 * Returns the timer3 count
 * 
 * \param count Pointer to variable where timer3 count will be stored.
 * 
 * \return Timer3 status.
 */
 PFEnStatus pfTimer3ReadCount(PFdword* count);

/**
 * Returns timer3 interrupt status.
 * 
 * \param status Pointer to variable where timer3 interrupt status will be stored.
 * 
 * \return Timer3 status.
 */
 PFEnStatus pfTimer3GetIntStatus(PFdword* status);

/**
 * Clears timer3 interrupt status flags
 * 
 * \param intStatus timer3 interrupts for which flag is to be cleared.
 * 
 * \return Timer3 status.
 */
PFEnStatus pfTimer3ClearIntStatus(PFdword intStatus);

/**
 * Enables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer3IntEnable(void);

/**
 * Disables timer interrupt
 *
 * \return status
 */
PFEnStatus pfTimer3IntDisable(void);

/**
 * Get timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Pointer to variable where timer tick frequency in hertz will be loaded.
 *
 * \return status
 */
PFEnStatus pfTimer3GetTickFreq(PFdword* tickFreq);

/**
 * Set timer tick frequency in hertz. It is the frequency with which timer counter increments.
 *
 * \param tickFreq Timer tick frequency in hertz.
 *
 * \return status
 */
PFEnStatus pfTimer3SetTickFreq(PFdword tickFreq);

/**
 * Updates match action of match register.
 *
 * \param regNum index of match register for which count match action to be updated.
 * \param matchAction match action for match register(regNum). 
 *
 * \return match control register update status
 */
PFEnStatus pfTimer3UpdateMatchControlRegister(PFbyte regNum,PFEnTimer3MatchAction matchAction);

/** @} */
