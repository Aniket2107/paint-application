/**
 * \file	prime_pwm.h
 * \brief   PWM 0 Driver Discription for LPC1768.
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
 * \defgroup PF_PWM_API PWM
 * @{
 * 	
 * \brief PWM Driver
 */ 
 
/** \brief Configuration macros for PWM		*/
#define PWM_CH				PWM1
#define PWM_CHANNEL			PERIPH(PWM_CH)
#define PWM_INT_HANDLER		INT_HANDLER(PWM)
 
/** \brief Enumeration for PWM mode		*/ 
typedef enum 
{
	enPwmModePwm = 0,						/**< Enable PWM mode, PWM functionalities will be enabled							*/
	enPwmModeTimer,							/**< Enable timer mode, the PWM module will act as normal timer						*/
	enPwmModeCounterCAP1_0RisingEdge,		/**< Enable counter mode, counter will increment on each rising edge on CAP1.0 pin	*/
	enPwmModeCounterCAP1_0FallingEdge,		/**< Enable counter mode, counter will increment on each falling edge on CAP1.0 pin	*/
	enPwmModeCounterCAP1_0BothEdges,		/**< Enable counter mode, counter will increment on both edges on CAP1.0 pin		*/
	enPwmModeCounterCAP1_1RisingEdge = 6,	/**< Enable counter mode, counter will increment on each rising edge on CAP1.1 pin	*/
	enPwmModeCounterCAP1_1FallingEdge,		/**< Enable counter mode, counter will increment on each falling edge on CAP1.1 pin	*/
	enPwmModeCounterCAP1_1BothEdges,		/**< Enable counter mode, counter will increment on both edges on CAP1.1 pin		*/
}PFEnPwmMode;

/** \brief Enumeration for PWM channel mode		*/
typedef enum
{
	enPwmChannelModeDisable = 0,			/**< Disable PWM channel						*/
	enPwmChannelModeSingleEdge,				/**< PWM single edge mode						*/
	enPwmChannelModeDoubleEdge				/**< PWM double edge mode						*/
}PFEnPwmChannelMode;

/** \brief Enumeration for PWM count match action		*/
typedef enum
{
	enPwmMatchActNone = 0,					/**< Take no action on count match					*/
	enPwmMatchActInterrupt,					/**< Raise interrupt								*/
	enPwmMatchActReset,						/**< Reset the timer								*/
	enPwmMatchActResetInt,					/**< Raise interrupt and reset the timer			*/
	enPwmMatchActStop,						/**< Stop the timer on count match					*/
	enPwmMatchActStopInt,					/**< Stop timer and raise interrupt					*/
	enPwmMatchActStopReset,					/**< Reset and stop the timer						*/
	enPwmMatchActStopResetInt,				/**< Raise interrupt and stop and reset the timer	*/
}PFEnPwmMatchAction;
 
/** \brief PWM configuration structure		*/
typedef struct
{
	PFdword				prescaler;						/**< Prescaler for PWM clock 						*/
	PFEnPclkDivider		clkDiv;							/**< Peripheral clock divider for PWM module		*/
	PFEnPwmMode			mode;							/**< Select mode for PWM: timer, PWM or counter		*/
	PFEnPwmChannelMode	chMode[PWM_MAX_CHANNEL];		/**< Select mode for PWM channels					*/
	PFdword				matchReg[PWM_MAX_MATCH_REG];	/**< Match register values							*/
	PFEnPwmMatchAction	matchAction[PWM_MAX_MATCH_REG];	/**< Compare match action for each match register	*/
	PFEnBoolean			interrupt;						/**< Enable interrupt for PWM module				*/
	PFcallback			callback;						/**< Callback for PWM interrupt						*/
}PFCfgPwm;

/** \brief Pointer to PFCfgPwm structure	*/
typedef PFCfgPwm* PFpCfgPwm;

/**
 * Intialize PWM with given parameters
 * 
 * \param config Pointer to PWM configuration structure
 * 
 * \return PWM intialization status
 */
PFEnStatus pfPwmOpen(PFpCfgPwm config);

/**
 * Stops PWM operation and turns off the PWM module
 */
void pfPwmClose(void);

/**
 * Starts PWM operation
 * 
 * \return PWM start status
 */
PFEnStatus pfPwmStart(void);

/**
 * Stops PWM operation
 * 
 * \return PWM stop status
 */
PFEnStatus pfPwmStop(void);

/**
 * Resets the PWM operation. PWM timer will start counting from zero again.
 * 
 * \return PWM reset status.
 */
PFEnStatus pfPwmReset(void);

/**
 * Returns the count for repetition rate value for PWM
 *
 * \param repRateVal Pointer to variable where repetition count value will be stored.
 *
 * \return PWM repetition rate value.
 */
PFEnStatus pfPwmGetRepititionCount(PFdword* repRateVal);

/**
 * Returns repetition rate in hertz for PWM
 *
 * \param repFreq Pointer to variable where repetition rate value will be stored.
 *
 * \return PWM repetition rate value.
 */
PFEnStatus pfPwmGetRepititionFreq(PFdword* repFreq);

/**
 * Returns PWM tick clock frequency i.e frequency after peripheral clock divider and prescaler
 *
 * \param tickClk Pointer to variable where tick clock frequency will be stored.
 *
 * \return PWM repetition rate value.
 */
PFEnStatus pfPwmGetTickFreq(PFdword* tickClk);

/**
 * Writes new value to the match register and enables latch for the match register.
 *
 * \param regNum index of match register to be updated.
 *
 * \param regVal new value for match register.
 *
 * \return match register update status.
 */
PFEnStatus pfPwmUpdateMatchRegister(PFbyte regNum, PFdword regVal);

/**
 * Return PWM interrupt pending status.
 *
 * \return Interrupt pending status.
 */
PFdword pfPwmGetIntStatus(void);
 
 /** @} */


