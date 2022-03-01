/**
 *  \file       eduarmBoardDefs.h
 *  \brief      Header file contains GPIO configuration MACROS on EduARM board.
 *
 */

#pragma once
#ifdef MCU_CHIP_lpc1768
/** Convention: Jumper_Pin number_Periph_Name of the pin_port/pin */

/** LED configuration macros */

#define		EDUARM_LED_UL1_PORT					GPIO_PORT_1
#define 	EDUARM_LED_UL1_PIN					GPIO_PIN_8

#define		EDUARM_LED_UL2_PORT					GPIO_PORT_1
#define 	EDUARM_LED_UL2_PIN					GPIO_PIN_9

#define 	EDUARM_LED_UL3_PORT					GPIO_PORT_1
#define		EDUARM_LED_UL3_PIN					GPIO_PIN_10


/** Pushbutton configuration macros */

#define		EDUARM_PUSHBUTTON_PB1_PORT			GPIO_PORT_1
#define		EDUARM_PUSHBUTTON_PB1_PIN		    GPIO_PIN_14

#define 	EDUARM_PUSHBUTTON_PB2_PORT 	        GPIO_PORT_1
#define		EDUARM_PUSHBUTTON_PB2_PIN		    GPIO_PIN_15

#define 	EDUARM_PUSHBUTTON_PB3_PORT 	        GPIO_PORT_1
#define		EDUARM_PUSHBUTTON_PB3_PIN		    GPIO_PIN_4

#define 	EDUARM_PUSHBUTTON_PB4_PORT 	        GPIO_PORT_1
#define		EDUARM_PUSHBUTTON_PB4_PIN		    GPIO_PIN_0

#define 	EDUARM_PUSHBUTTON_PB5_PORT 	        GPIO_PORT_1
#define		EDUARM_PUSHBUTTON_PB5_PIN		    GPIO_PIN_1


/** UART configuration macros */

/** UART 0 */
#define 	EDUARM_UART_0_TX_PORT		        GPIO_PORT_0
#define 	EDUARM_UART_0_TX_PIN			    GPIO_PIN_2

#define 	EDUARM_UART_0_RX_PORT		        GPIO_PORT_0
#define		EDUARM_UART_0_RX_PIN			    GPIO_PIN_3

/** UART2 */
#define	EDUARM_J2_15_UART_2_TX_PORT				GPIO_PORT_2
#define	EDUARM_J2_15_UART_2_TX_PIN				GPIO_PIN_8

#define	EDUARM_J2_14_UART_2_RX_PORT				GPIO_PORT_2
#define	EDUARM_J2_14_UART_2_RX_PIN				GPIO_PIN_9

/** UART3 */
#define	EDUARM_J1_23_UART_3_TX_PORT				GPIO_PORT_0
#define	EDUARM_J1_23_UART_3_TX_PIN 				GPIO_PIN_0

#define	EDUARM_J1_25_UART_3_RX_PORT				GPIO_PORT_0
#define	EDUARM_J1_25_UART_3_RX_PIN				GPIO_PIN_1

/** External Interrupt configuration macros */

/** EINT 3 */
#define		EDUARM_J2_13_EINT_3_PORT		    GPIO_PORT_2
#define		EDUARM_J2_13_EINT_3_PIN			    GPIO_PIN_13

/** EINT 2 */
#define 	EDUARM_MMA_INT_PORT					GPIO_PORT_2
#define 	EDUARM_MMA_INT_PIN					GPIO_PIN_12

/** EINT 1 */
#define 	EDUARM_TOUCH_INT_PORT				GPIO_PORT_2
#define 	EDUARM_TOUCH_INT_PIN				GPIO_PIN_11

/** ADC Channel configuration macros */
	
/** ADC 0 */
#define		EDUARM_J2_4_ADC_0_PORT				GPIO_PORT_0
#define		EDUARM_J2_4_ADC_0_PIN 				GPIO_PIN_23

/** ADC 1 */
#define		EDUARM_VBAT_ADC_1_PORT				GPIO_PORT_0
#define		EDUARM_VBAT_ADC_1_PIN				GPIO_PIN_24

/** ADC 2 */
#define		EDUARM_J2_3_ADC_2_PORT				GPIO_PORT_0
#define		EDUARM_J2_3_ADC_2_PIN				GPIO_PIN_25

/** ADC 3 */
#define		EDUARM_J2_1_ADC_3_PORT				GPIO_PORT_0
#define		EDUARM_J2_1_ADC_3_PIN				GPIO_PIN_26

/** ADC 4 */
#define		EDUARM_J2_6_ADC_4_PORT				GPIO_PORT_1
#define		EDUARM_J2_6_ADC_4_PIN				GPIO_PIN_30

/** ADC 5 */
#define		EDUARM_J6_5_ADC_5_PORT				GPIO_PORT_1
#define		EDUARM_J6_5_ADC_5_PIN				GPIO_PIN_31

/** I2C configuration macros */

/** I2C 0 used for SGTL5000 as well as MMA7660 accelerometer */

/** I2C 1 */
#define 	EDUARM_J1_23_I2C_1_SDA_PORT			GPIO_PORT_0
#define 	EDUARM_J1_23_I2C_1_SDA_PIN			GPIO_PIN_0

#define 	EDUARM_J1_25_I2C_1_SCL_PORT			GPIO_PORT_0
#define 	EDUARM_J1_25_I2C_1_SCL_PIN			GPIO_PIN_1

/** I2C 2 */
#define 	EDUARM_J1_24_I2C_2_SDA_PORT			GPIO_PORT_0
#define 	EDUARM_J1_24_I2C_2_SDA_PIN			GPIO_PIN_10

#define 	EDUARM_J1_26_I2C_2_SCL_PORT			GPIO_PORT_0
#define 	EDUARM_J1_26_I2C_2_SCL_PIN		  	GPIO_PIN_11


/** SPI configuration macros */

/** SSP 0 */
#define 	EDUARM_J1_38_SSP_0_MOSI_PORT		 GPIO_PORT_1
#define 	EDUARM_J1_38_SSP_0_MOSI_PIN		     GPIO_PIN_24

#define 	EDUARM_J1_37_SSP_0_MISO_PORT		 GPIO_PORT_1
#define 	EDUARM_J1_37_SSP_0_MISO_PIN		     GPIO_PIN_23

#define 	EDUARM_J1_34_SSP_0_SCK_PORT		   	 GPIO_PORT_1
#define 	EDUARM_J1_34_SSP_0_SCK_PIN			 GPIO_PIN_20

#define 	EDUARM_J1_35_SSP_0_SSEL_PORT		 GPIO_PORT_1
#define 	EDUARM_J1_35_SSP_0_SSEL_PIN		     GPIO_PIN_21


/** Touch Screen Interface configuration macros */
#define 	EDUARM_TOUCH_SSP0_MOSI_PORT		     GPIO_PORT_0
#define 	EDUARM_TOUCH_SSP0_MOSI_PIN		     GPIO_PIN_18

#define 	EDUARM_TOUCH_SSP_0_MISO_PORT		 GPIO_PORT_0
#define 	EDUARM_TOUCH_SSP_0_MISO_PIN		     GPIO_PIN_17

#define 	EDUARM_TOUCH_SSP_0_SCK_PORT		   	 GPIO_PORT_0
#define 	EDUARM_TOUCH_SSP_0_SCK_PIN			 GPIO_PIN_15

#define 	EDUARM_TOUCH_SSP_0_SSEL_PORT		 GPIO_PORT_0
#define 	EDUARM_TOUCH_SSP_0_SSEL_PIN		     GPIO_PIN_20

#define 	EDUARM_TOUCH_SSP_0_INT_PORT			GPIO_PORT_2
#define 	EDUARM_TOUCH_SSP_0_INT_PIN			GPIO_PIN_11

#define 	EDUARM_TOUCH_SSP_0_BUSY_PORT        GPIO_PORT_0
#define 	EDUARM_TOUCH_SSP_0_BUSY_PIN			GPIO_PIN_19


/** SD Card Interface configuration macros */
#define 	EDUARM_SDCARD_SSP0_MOSI_PORT		 GPIO_PORT_0
#define 	EDUARM_SDCARD_SSP0_MOSI_PIN		     GPIO_PIN_18

#define 	EDUARM_SDCARD_SSP_0_MISO_PORT		 GPIO_PORT_0
#define 	EDUARM_SDCARD_SSP_0_MISO_PIN		 GPIO_PIN_17

#define 	EDUARM_SDCARD_SSP_0_SSEL_PORT		 GPIO_PORT_0
#define 	EDUARM_SDCARD_SSP_0_SSEL_PIN		 GPIO_PIN_16

#define 	EDUARM_SDCARD_SSP_0_SCK_PORT		 GPIO_PORT_0
#define 	EDUARM_SDCARD_SSP_0_SCK_PIN			 GPIO_PIN_15

/** SPI configuration macros */

/** LCD data pins */

#define 	EDUARM_LCD_DATA_PORT				GPIO_PORT_2
#define 	EDUARM_LCD_DATA_0					GPIO_PIN_0
#define 	EDUARM_LCD_DATA_1					GPIO_PIN_1
#define 	EDUARM_LCD_DATA_2					GPIO_PIN_2
#define 	EDUARM_LCD_DATA_3					GPIO_PIN_3
#define 	EDUARM_LCD_DATA_4					GPIO_PIN_4
#define 	EDUARM_LCD_DATA_5					GPIO_PIN_5
#define 	EDUARM_LCD_DATA_6					GPIO_PIN_6
#define 	EDUARM_LCD_DATA_7					GPIO_PIN_7

/** LCD CS pin */
#define 	EDUARM_LCD_CS_PORT					GPIO_PORT_1
#define 	EDUARM_LCD_CS_PIN					GPIO_PIN_29
	
/** LCD WR pin */	
#define 	EDUARM_LCD_WR_PORT					GPIO_PORT_0
#define 	EDUARM_LCD_WR_PIN					GPIO_PIN_22 
	
/** LCD RD pin */	
#define 	EDUARM_LCD_RD_PORT					GPIO_PORT_0
#define 	EDUARM_LCD_RD_PIN					GPIO_PIN_21
	
/** LCD RS pin */	
#define 	EDUARM_LCD_RS_PORT					GPIO_PORT_4
#define 	EDUARM_LCD_RS_PIN					GPIO_PIN_29

/** LCD RST pin */
#define 	EDUARM_LCD_RST_PORT					GPIO_PORT_1
#define 	EDUARM_LCD_RST_PIN					GPIO_PIN_28

/** CAN configuration macros */

/** CAN 1 */
#define 	EDUARM_J1_23_CAN_1_RD_1_PORT	    GPIO_PORT_0
#define		EDUARM_J1_23_CAN_1_RD_1_PIN		    GPIO_PIN_0

#define 	EDUARM_J1_25_CAN_1_TD_1_PORT	    GPIO_PORT_0
#define		EDUARM_J1_25_CAN_1_TD_1_PIN		    GPIO_PIN_1

/** CAN 2 */
#define 	EDUARM_CAN_2_RD_2_PORT	    		GPIO_PORT_0
#define		EDUARM_CAN_2_RD_2_PIN		    	GPIO_PIN_4

#define 	EDUARM_CAN_2_TD_2_PORT	    		GPIO_PORT_0
#define		EDUARM_CAN_2_TD_2_PIN		    	GPIO_PIN_5

/** PWM configuration macros */

/** Output from PWM channels (1-5) */
#define		EDUARM_J2_18_PWM_CH_1_PORT		    GPIO_PORT_1
#define		EDUARM_J2_18_PWM_CH_1_PIN		    GPIO_PIN_18

#define		EDUARM_J1_5_PWM_CH_2_PORT		    GPIO_PORT_1
#define		EDUARM_J1_5_PWM_CH_2_PIN		    GPIO_PIN_20

#define 	EDUARM_J1_4_PWM_CH_3_PORT		    GPIO_PORT_1
#define		EDUARM_J1_4_PWM_CH_3_PIN		    GPIO_PIN_21

#define		EDUARM_J1_7_PWM_CH_4_PORT		    GPIO_PORT_1
#define		EDUARM_J1_7_PWM_CH_4_PIN		    GPIO_PIN_23

#define		EDUARM_J1_9_PWM_CH_5_PORT		    GPIO_PORT_1
#define		EDUARM_J1_9_PWM_CH_5_PIN		    GPIO_PIN_24

/** Timer 0/1/2/3 configuration macros */

/** Input Capture Signals */

/** Timer 0 */
#define		EDUARM_J2_12_TIMER_0_CAP_1_PORT	    GPIO_PORT_1
#define		EDUARM_J2_12_TIMER_0_CAP_1_PIN	    GPIO_PIN_27

/** Timer 3 */
#define		EDUARM_J2_4_TIMER_3_CAP_0_PORT	    GPIO_PORT_0
#define		EDUARM_J2_4_TIMER_3_CAP_0_PIN	    GPIO_PIN_23

/** External Match Output pins */
#define		EDUARM_J1_13_TIMER_1_MAT_0_PORT	    GPIO_PORT_1
#define		EDUARM_J1_13_TIMER_1_MAT_0_PIN		GPIO_PIN_22

#define		EDUARM_J1_14_TIMER_1_MAT_1_PORT	    GPIO_PORT_1
#define		EDUARM_J1_14_TIMER_1_MAT_1_PIN		GPIO_PIN_25

/** I2S Configuration macros */

#define		EDUARM_I2S_TX_SDA_PORT				GPIO_PORT_0
#define		EDUARM_I2S_TX_SDA_PIN				GPIO_PIN_9

#define 	EDUARM_I2S_TX_WS_PORT				GPIO_PORT_0
#define		EDUARM_I2S_TX_WS_PIN				GPIO_PIN_8

#define		EDUARM_I2S_TX_CLK_PORT				GPIO_PORT_0
#define		EDUARM_I2S_TX_CLK_PIN				GPIO_PIN_7

#define		EDUARM_I2S_RX_SDA_PORT				GPIO_PORT_0
#define		EDUARM_I2S_RX_SDA_PIN				GPIO_PIN_6

#define		EDUARM_I2S_RX_MCLK_PORT				GPIO_PORT_4
#define		EDUARM_I2S_RX_MCLK_PIN				GPIO_PIN_28

#endif	// #ifdef MCU_CHIP_lpc1768
