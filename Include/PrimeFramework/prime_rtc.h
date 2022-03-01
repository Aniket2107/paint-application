/**
 * \file	prime_rtc.h
 * \brief   RTC Driver Discription for LPC1768.
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
 * \defgroup PF_RTC RTC
 * @{
 * 
 * 	\brief RTC driver
 * 	\details  RTC driver for RTC Peripheral
 */
 
/** \brief Configuration macros for RTC		*/
#define RTC_CH				RTC
#define RTC_CHANNEL			PERIPH(RTC_CH)
#define RTC_INT_HANDLER		INT_HANDLER(RTC_CH) 

 /** \brief	Macros defined for RTC Interrupt selection	*/
#define RTC_INT_SEC			0x00000001		/**< An increment of the Second value generates an interrupt. */
#define RTC_INT_MIN			0x00000002		/**< An increment of the Minute value generates an interrupt. */
#define RTC_INT_HOUR		0x00000004		/**< An increment of the Hour value generates an interrupt. */
#define RTC_INT_DOM			0x00000008		/**< An increment of the Day of Month value generates an interrupt. */
#define RTC_INT_DOW			0x00000010		/**< An increment of the Day of Week value generates an interrupt. */
#define RTC_INT_DOY			0x00000020		/**< An increment of the Day of Year value generates an interrupt. */
#define RTC_INT_MON			0x00000040		/**< An increment of the Month value generates an interrupt. */
#define RTC_INT_YEAR		0x00000080		/**< An increment of the Year value generates an interrupt. */

/**	\brief	Macros defined for RTC Alarm Mask	*/
#define RTC_ALM_SEC			0x00000001  	/**< Alarm mask for Seconds */
#define RTC_ALM_MIN			0x00000002  	/**< Alarm mask for Minutes */
#define RTC_ALM_HOUR		0x00000004  	/**< Alarm mask for Hours */
#define RTC_ALM_DOM			0x00000008  	/**< Alarm mask for Day of Month */
#define RTC_ALM_DOW			0x00000010  	/**< Alarm mask for Day of Week */
#define RTC_ALM_DOY			0x00000020  	/**< Alarm mask for Day of Year */
#define RTC_ALM_MON			0x00000040  	/**< Alarm mask for Month */
#define RTC_ALM_YEAR		0x00000080  	/**< Alarm mask for Year */

 /**	\brief	RTC Time structure			*/
typedef struct
{
	PFdword rtcSec;		/**< Seconds value in the range of 0 to 59 */
	PFdword rtcMin;		/**< Minutes value in the range of 0 to 59 */
	PFdword rtcHour;	/**< Hours value in the range of 0 to 23 */
	PFdword rtcDom;		/**< Day of month value in the range of 1 to 28, 29, 30, or 31 */
	PFdword rtcDow;		/**< Day of week value in the range of 0 to 6*/
	PFdword rtcDoy;		/**< Day of year value in the range of 1 to 365 (366 for leap years) */
	PFdword rtcMon;		/**< Month value in the range of 1 to 12*/
	PFdword rtcYear;	/**< Year value in the range of 0 to 4095 */
	
}PFRtcTime;

/** \brief Pointer to PFRtcTime Structure		*/
typedef PFRtcTime* PFpRtcTime;

/** \brief RTC configuration structure			*/
typedef struct
{
	PFEnBoolean intEnable;			/**< Enable RTC interrupt										*/
	PFEnBoolean alarmIntEnable;		/**< Enable interrupt for alarm									*/
	PFdword countInt;				/**< Set count increment interrupts								*/
	PFcallback callback;			/**< Interrupt callback function, if interrupt is enabled		*/
}PFCfgRtc;

/** \brief Pointer to PFCfgRtc Structure		*/
typedef PFCfgRtc*	PFpCfgRtc;


/**
 * The function initialize RTC registers.
 * 
 * \param config Config structure of type PFpCfgRtc
 * 
 * \return Status
 */
PFEnStatus pfRtcOpen(PFpCfgRtc config);

/**
 * The function initialize RTC registers.
 */
void pfRtcClose(void);

/**
 * Function sets RTC timer value. 
 *
 * \param config The data structure of the RTC time.
 * 
 * \return Status
 */
PFEnStatus pfRtcSetTime(PFpRtcTime config);

/**
 * Function gets RTC timer value. 
 *
 * \param config The data structure of the RTC time.
 * 
 * \return Status
 */
PFEnStatus pfRtcGetTime (PFpRtcTime config);

/**
 * Function sets RTC timer Alarm value. 
 *
 * \param alarm The data structure of the RTC time.
 * 
 * \return Status
 */
PFEnStatus pfRtcSetAlarm(PFpRtcTime alarm);

/**
 * Function sets RTC timer Alarm Mask. 
 *
 * \param rtcAlarmMask RTC Alarm mask setting.
 * 
 * \return Status
 */
PFEnStatus pfRtcSetAlarmMask(PFdword rtcAlarmMask);

/**
 * Function gives the ability to generate an interrupt every time a counter is incremented.
 * Function sets The Counter Increment Interrupt Register.
 *
 * \param rtcInterrupt Selection of counter for which interrupt is to generated for every increment.
 */
PFEnStatus pfRtcIntSelect(PFdword rtcInterrupt);

/**
 * Function sets callback for RTC interrupt.
 *
 * \param callback Callback function for RTC interrupt.
 * 
 * \return Status
 */
PFEnStatus pfRtcSetIRQCallback(PFcallback callback);

/**
 * The function start RTC timer by enabling clock and Interrupt.
 * 
 * \return Status
 */
PFEnStatus pfRtcStart(void);

/**
 * The function stop RTC timer by disabling the RTC clock.
 * 
 * \return Status
 */
PFEnStatus pfRtcStop(void);

/**
 * The function Reset RTC clock tick counter.
 * 
 * \return Status
 */
PFEnStatus pfRtcResetCTC(void);

/** @} */