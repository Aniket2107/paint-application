/**
 *  \file       eduarmBoardConfig.h
 *  \brief      Header file contains GPIO configuration structure declaration for the peripherals on EduARM board.
 *
 */

#pragma once
#ifdef MCU_CHIP_lpc1768

extern PFCfgGpio eduarmLedGpioCfg[3];			/** LED gpio pin configuration 	*/
extern PFCfgGpio eduarmPushButtonGpioCfg[5];	/** PUSHBUTTON gpio pin configuration */

extern PFCfgGpio eduarmUart0GpioCfg[2];			/** UART0 gpio pin configuration */
extern PFCfgGpio eduarmUart2GpioCfg[2];			/** UART2 gpio pin configuration */
extern PFCfgGpio eduarmUart3GpioCfg[2];			/** UART3 gpio pin configuration */

extern PFCfgGpio eduarmEint3GpioCfg;			/** EINT3 gpio pin configuration */
extern PFCfgGpio eduarmMma7660IntGpioCfg;		/** MMA7660  INT gpio pin configuration */
extern PFCfgGpio eduarmTouchIntGpioCfg;			/** Touch INT gpio pin configuration */

extern PFCfgGpio eduarmAdc0GpioCfg;             /** ADC0 gpio pin configuration */
extern PFCfgGpio eduarmAdc1GpioCfg;             /** ADC1 gpio pin configuration */
extern PFCfgGpio eduarmAdc2GpioCfg;             /** ADC2 gpio pin configuration */
extern PFCfgGpio eduarmAdc3GpioCfg;             /** ADC3 gpio pin configuration */
extern PFCfgGpio eduarmAdc4GpioCfg;             /** ADC4 gpio pin configuration */
extern PFCfgGpio eduarmAdc5GpioCfg;             /** ADC5 gpio pin configuration */

extern PFCfgGpio eduarmI2c1GpioCfg[2];          /** I2C1 gpio pin configuration */
extern PFCfgGpio eduarmI2c2GpioCfg[2];          /** I2C2 gpio pin configuration */


extern PFCfgGpio eduarmSsp0GpioCfg[4];          /** SSP0 gpio pin configuration */
extern PFCfgGpio eduarmTouchGpioCfg[6];			/** Touch gpio pin configuration */
extern PFCfgGpio eduarmSdcardGpioCfg[4];		/** SD Card gpio pin configuration */
extern PFCfgGpio eduarmLcdGpioCfg [6];			/** LCD gpio pin configuration */

extern PFCfgGpio eduarmCan1GpioCfg[2];          /** CAN1 gpio pin configuration */
extern PFCfgGpio eduarmCan2GpioCfg[2];          /** CAN2 gpio pin configuration */


extern PFCfgGpio eduarmPwm1GpioCfg;             /** PWM1 gpio pin configuration */
extern PFCfgGpio eduarmPwm2GpioCfg;             /** PWM2 gpio pin configuration */
extern PFCfgGpio eduarmPwm3GpioCfg;             /** PWM3 gpio pin configuration */
extern PFCfgGpio eduarmPwm4GpioCfg;             /** PWM4 gpio pin configuration */
extern PFCfgGpio eduarmPwm5GpioCfg;             /** PWM5 gpio pin configuration */

extern PFCfgGpio eduarmTimer0Cap1GpioCfg;		/** TIMER0CAP gpio pin configuration */
extern PFCfgGpio eduarmTimer3Cap0GpioCfg;		/** TIMER3CAP gpio pin configuration */

extern PFCfgGpio eduarmTimer1MatGpioCfg[2];		/** TIMER1MAT gpio pin configuration */

extern PFCfgGpio eduarmI2sGpioCfg[5];			/** I2S gpio pin configuration */

#endif	// #ifdef MCU_CHIP_lpc1768
