/**
 * \file	prime_adc.h
 * \brief   ADC Driver Discription for LPC1768.
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
 * \defgroup PF_ADC ADC
 * @{
 * 
 * 	\brief ADC driver
 * 	\details  ADC driver for onchip ADC Peripheral
 */

/** \brief ADC configuration MACRO */
#define ADC_CH				ADC
#define ADC_CHANNEL			PERIPH(ADC_CH)
#define ADC_INT_HANDLER		INT_HANDLER(ADC_CH) 

/**	\brief 	Marcro for ADC Channel */
#define ADC_CHANNEL_0		0x01			/**< Select ADC channel 0			*/
#define ADC_CHANNEL_1		0x02			/**< Select ADC channel 1			*/
#define ADC_CHANNEL_2		0x04			/**< Select ADC channel 2			*/
#define ADC_CHANNEL_3		0x08			/**< Select ADC channel 3			*/
#define ADC_CHANNEL_4		0x10			/**< Select ADC channel 4			*/
#define ADC_CHANNEL_5		0x20			/**< Select ADC channel 5			*/
#define ADC_CHANNEL_6		0x40			/**< Select ADC channel 6			*/
#define ADC_CHANNEL_7		0x80			/**< Select ADC channel 7			*/

/** \brief	Enumeration for ADC Channel source*/
typedef enum
{
	enAdcChannel0 = 0,						/**< ADC channel 0		*/
	enAdcChannel1,							/**< ADC channel 1		*/
	enAdcChannel2,							/**< ADC channel 2		*/
	enAdcChannel3,							/**< ADC channel 3		*/
	enAdcChannel4,							/**< ADC channel 4		*/
	enAdcChannel5,							/**< ADC channel 5		*/
	enAdcChannel6,							/**< ADC channel 6		*/
	enAdcChannel7,							/**< ADC channel 7		*/
}PFEnAdcChannel;
 
/** \brief	Enumeration for ADC start mode			*/
typedef enum
{
	enAdcStartNone = 0x00,					/**< Stop ADC conversion										*/
	enAdcStartNow,							/**< Start ADC for single conversion							*/
	enAdcStartNMIPinRisingEdge,				/**< Start ADC conversion on rising edge on NMI (P2.10) pin		*/
	enAdcStartCLKOUTPinRisingEdge,			/**< Start ADC conversion on rising edge on CLKOUT (P1.27) pin	*/
	enAdcStartMAT01PinRisingEdge,			/**< Start ADC conversion on rising edge on MAT0.1 pin			*/
	enAdcStartMAT03PinRisingEdge,			/**< Start ADC conversion on rising edge on MAT0.3 pin			*/
	enAdcStartMAT10PinRisingEdge,			/**< Start ADC conversion on rising edge on MAT1.0 pin			*/
	enAdcStartMAT11PinRisingEdge,			/**< Start ADC conversion on rising edge on MAT1.1 pin			*/
	enAdcStartNMIPinFallingEdge = 0x0A,		/**< Start ADC conversion on falling edge on NMI (P2.10) pin	*/
	enAdcStartCLKOUTPinFallingEdge,         /**< Start ADC conversion on falling edge on CLKOUT (P1.27) pin	*/
	enAdcStartMAT01PinFallingEdge,          /**< Start ADC conversion on falling edge on MAT0.1 pin			*/
	enAdcStartMAT03PinFallingEdge,          /**< Start ADC conversion on falling edge on MAT0.3 pin			*/
	enAdcStartMAT10PinFallingEdge,          /**< Start ADC conversion on falling edge on MAT1.0 pin			*/
	enAdcStartMAT11PinFallingEdge,          /**< Start ADC conversion on falling edge on MAT1.1 pin			*/
}PFEnAdcStart;


/**	\brief ADC configure Structure	*/
typedef struct
{
	PFbyte clkDiv;						/**< Peripheral clock divider for ADC											*/
	PFbyte prescaler;					/**< Prescaler for ADC clock													*/
	PFbyte burstModeChannels;			/**< Select channels to scan if burst mode is used. Use bitshift format			*/
	PFEnAdcChannel singleModeChannel;	/**< Select channel to scan if single conversion mode is used					*/
	PFcallback callback;				/**< Set callback for ADC interrupt												*/
	PFbyte chInterrupt;					/**< Select channel interrupts to enable in bitshift format						*/
	PFEnBoolean burstMode;				/**< Enable or disable burst mode. If enabled, it will override conversionMode	*/
	PFEnAdcStart conversionMode;		/**< Set conversion mode for ADC												*/
}PFCfgAdc;

/**
 * \brief pointer to PFCfgAdc structure
 */
typedef PFCfgAdc* PFpCfgAdc;

/**
 * \brief The function configures ADC with given settings.
 *
 * \param config Pointer to configuration structure which contains the settings for the ADC to be used.
 *
 * \return ADC initialization status.
 */
PFEnStatus pfAdcOpen(PFpCfgAdc config);

/**
 * \brief The function enables or disables ADC power down mode.
 *
 * \param mode enBooleanTrue to enable power down mode, enBooleanFalse to disable power down mode.
 *
 * \return Power down mode setting status.
 */
PFEnStatus pfAdcPowerDown(PFEnBoolean mode);

/**
 * \brief The function enables ADC channel interrupts.
 *
 * \param channel channel number to enable interrupt.
 *
 * \return Interrupt enable status.
 */
PFEnStatus pfAdcEnableChInterrupt(PFEnAdcChannel channel);

/**
 * \brief The function disaables ADC channel interrupts.
 *
 * \param channel channel number to disable interrupt.
 *
 * \return Interrupt disable status.
 */
PFEnStatus pfAdcDisableChInterrupt(PFEnAdcChannel channel);

/**
 * \brief The function returns the status of interrupt for particular channel if it is enabled or not.
 *
 * \param channel channel number to get interrupt enable status
 *
 * \return enBooleanTrue if interrupt is enabled for given channel else enBooleanFalse.
 */
PFEnBoolean pfAdcIsIntEnabled(PFEnAdcChannel channel);

/**
 * \brief The function starts ADC conversion in burst (free running) mode.
 * 
 * \param channel Channel number to start burst conversion.
 *
 * \return Conversion mode setting status.
 */
PFEnStatus pfAdcStartBurstConversion(PFbyte channel);

/**
 * \brief The function starts single conversion immediately and returns conversion value.
 * 
 * \param channel Channel number to start conversion for
 * \param value Pointer to PFword data to which the ADC converted value will be written.
 *
 * \return conversion status.
 */
PFEnStatus pfAdcSingleConversion(PFEnAdcChannel channel, PFword* value);

/**
 * \brief The function starts single conversion immediately and returns conversion value in milliVolts.
 * 
 * \param channel Channel number to start conversion for
 * \param milliVolt Pointer to PFdword data to which the ADC converted value will be written.
 *
 * \return conversion status.
 */
PFEnStatus pfAdcGetVoltageSingleConversion(PFbyte channel, PFdword* milliVolt);

/**
 * \brief The function sets conversion start mode (conversion trigger source)
 * 
 * \param mode ADC conversion start mode
 *
 * \return ADC conversion mode set status
 */
PFword pfAdcSetConversionMode(PFEnAdcStart mode);

/**
 * \brief The function returns last conversion valueof the specified channel.
 * 
 * \param channel channel number to get conversion value.
 * \param value pointer to PFword data to which the ADC last value will be written.
 *
 * \return Last value read status.
 */
PFEnStatus pfAdcGetLastChValue(PFbyte channel, PFword* value);

/**
 * \brief The function returns last conversion value from global data register.
 * 
 * \param value pointer to PFword data to which the ADC last value will be written.
 *
 * \return Last value read status.
 */
PFEnStatus pfAdcGetLastGlobalValue(PFword* value);

/**
 * \brief The function disables ADC module.
 *
 * \return ADC disable status.
 */
PFEnStatus pfAdcClose(void);


/** @} */
