/**
 * \file	prime_gpio.h
 * \brief   GPIO Driver Discription for LPC1768.
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
 * \defgroup PF_GPIO GPIO
 * @{
 * 
 * 	\brief GPIO driver
 * 	\details  GPIO driver for GPIO Peripheral
 */

/**
 * Pin number definitions. 
 * 
 * \note Pin number should be passed to any function/macro in bit shifted format.
 *		 For ease of use, all the pin numbers are defined here in the same format.
 */
#define GPIO_PIN_0					0x00000001		/**< gpio pin 0			*/
#define GPIO_PIN_1					0x00000002		/**< gpio pin 1			*/
#define GPIO_PIN_2					0x00000004		/**< gpio pin 2			*/	
#define GPIO_PIN_3					0x00000008		/**< gpio pin 3			*/
#define GPIO_PIN_4					0x00000010		/**< gpio pin 4			*/
#define GPIO_PIN_5					0x00000020		/**< gpio pin 5			*/
#define GPIO_PIN_6					0x00000040		/**< gpio pin 6			*/
#define GPIO_PIN_7					0x00000080		/**< gpio pin 7			*/
#define GPIO_PIN_8					0x00000100		/**< gpio pin 8			*/
#define GPIO_PIN_9					0x00000200		/**< gpio pin 9			*/
#define GPIO_PIN_10					0x00000400		/**< gpio pin 10		*/
#define GPIO_PIN_11					0x00000800		/**< gpio pin 11		*/
#define GPIO_PIN_12					0x00001000		/**< gpio pin 12		*/
#define GPIO_PIN_13					0x00002000		/**< gpio pin 13		*/
#define GPIO_PIN_14					0x00004000		/**< gpio pin 14		*/
#define GPIO_PIN_15					0x00008000		/**< gpio pin 15		*/
#define GPIO_PIN_16					0x00010000		/**< gpio pin 16		*/
#define GPIO_PIN_17					0x00020000		/**< gpio pin 17		*/
#define GPIO_PIN_18					0x00040000		/**< gpio pin 18		*/
#define GPIO_PIN_19					0x00080000		/**< gpio pin 19		*/
#define GPIO_PIN_20					0x00100000		/**< gpio pin 20		*/
#define GPIO_PIN_21					0x00200000		/**< gpio pin 21		*/
#define GPIO_PIN_22					0x00400000		/**< gpio pin 22		*/
#define GPIO_PIN_23					0x00800000		/**< gpio pin 23		*/
#define GPIO_PIN_24					0x01000000		/**< gpio pin 24		*/
#define GPIO_PIN_25					0x02000000		/**< gpio pin 25		*/
#define GPIO_PIN_26					0x04000000		/**< gpio pin 26		*/
#define GPIO_PIN_27					0x08000000		/**< gpio pin 27		*/
#define GPIO_PIN_28					0x10000000		/**< gpio pin 28		*/
#define GPIO_PIN_29					0x20000000		/**< gpio pin 29		*/
#define GPIO_PIN_30					0x40000000		/**< gpio pin 30		*/
#define GPIO_PIN_31					0x80000000		/**< gpio pin 31		*/

/**
 * Defines for multiplexed functionalities for each pin
 *
 * \note 	These defines are for user's convenience. 
 * 			So that, user does not need to refer datasheet for pin function configuration.
 */
#define GPIO_0_0_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.0				*/	
#define GPIO_0_0_RD1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.0		*/
#define GPIO_0_0_TXD3				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.0		*/
#define GPIO_0_0_SDA1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.0		*/

#define GPIO_0_1_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.1				*/
#define GPIO_0_1_TD1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.1		*/
#define GPIO_0_1_RXD3				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.1		*/
#define GPIO_0_1_SCL1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.1		*/

#define GPIO_0_2_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.2				*/
#define GPIO_0_2_TXD0				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.2		*/
#define GPIO_0_2_ADC7				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.2		*/
#define GPIO_0_2_RES				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.2		*/

#define GPIO_0_3_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.3				*/
#define GPIO_0_3_RXD0				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.3		*/
#define GPIO_0_3_ADC6				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.3		*/
#define GPIO_0_3_RES				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.3		*/

#define GPIO_0_4_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.4				*/
#define GPIO_0_4_I2SRX_CLK			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.4		*/
#define GPIO_0_4_RD2				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.4		*/
#define GPIO_0_4_CAP2_0				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.4		*/

#define GPIO_0_5_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.5				*/
#define GPIO_0_5_I2SRX_WS			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.5		*/
#define GPIO_0_5_TD2				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.5		*/
#define GPIO_0_5_CAP2_1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.5		*/

#define GPIO_0_6_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.6				*/
#define GPIO_0_6_I2SRX_SDA			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.6		*/
#define GPIO_0_6_SSEL1				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.6		*/
#define GPIO_0_6_MAT2_0				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.6		*/

#define GPIO_0_7_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.7				*/
#define GPIO_0_7_I2STX_SDA			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.7		*/
#define GPIO_0_7_SCK1				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.7		*/
#define GPIO_0_7_MAT2_1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.7		*/

#define GPIO_0_8_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.8				*/
#define GPIO_0_8_I2STX_WS			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.8		*/
#define GPIO_0_8_MISO1				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.8		*/
#define GPIO_0_8_MAT2_2				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.8		*/

#define GPIO_0_9_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.9				*/
#define GPIO_0_9_I2STX_SDA			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.9		*/
#define GPIO_0_9_MOSI1				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.9		*/
#define GPIO_0_9_MAT2_3				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.9		*/

#define GPIO_0_10_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.10				*/
#define GPIO_0_10_TXD2				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.10		*/
#define GPIO_0_10_SDA2				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.10		*/
#define GPIO_0_10_MAT3_0			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.10		*/

#define GPIO_0_11_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.11				*/
#define GPIO_0_11_RXD2				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.11		*/
#define GPIO_0_11_SCL2				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.11		*/
#define GPIO_0_11_MAT3_1			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.11		*/

// Pins P0.12 - P0.14 are reserved

#define GPIO_0_15_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.15				*/
#define GPIO_0_15_TXD1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.15		*/
#define GPIO_0_15_SCK0				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.15		*/
#define GPIO_0_15_SCK				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.15		*/

#define GPIO_0_16_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.16				*/
#define GPIO_0_16_RXD1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.16		*/
#define GPIO_0_16_SSEL0				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.16		*/
#define GPIO_0_16_SSEL				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.16		*/

#define GPIO_0_17_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.17				*/
#define GPIO_0_17_CTS1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.17		*/
#define GPIO_0_17_MISO0				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.17		*/
#define GPIO_0_17_MISO				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.17		*/

#define GPIO_0_18_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.18				*/
#define GPIO_0_18_DCD1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.18		*/
#define GPIO_0_18_MOSI0				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.18		*/
#define GPIO_0_18_MOSI				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.18		*/

#define GPIO_0_19_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.19				*/
#define GPIO_0_19_DSR1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.19		*/
#define GPIO_0_19_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.19		*/
#define GPIO_0_19_SDA1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.19		*/

#define GPIO_0_20_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.20				*/
#define GPIO_0_20_DTR1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.20		*/
#define GPIO_0_20_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.20		*/
#define GPIO_0_20_SCL1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.20		*/

#define GPIO_0_21_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.21				*/
#define GPIO_0_21_RI1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.21		*/
#define GPIO_0_21_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.21		*/
#define GPIO_0_21_RD1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.21		*/

#define GPIO_0_22_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.22				*/
#define GPIO_0_22_RTS1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.22		*/
#define GPIO_0_22_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.22		*/
#define GPIO_0_22_TD1				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.22		*/

#define GPIO_0_23_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.23				*/
#define GPIO_0_23_ADC0				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.23		*/
#define GPIO_0_23_I2SRX_CLK			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.23		*/
#define GPIO_0_23_CAP3_0			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.23		*/

#define GPIO_0_24_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.24				*/
#define GPIO_0_24_ADC1				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.24		*/
#define GPIO_0_24_I2SRX_WS			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.24		*/
#define GPIO_0_24_CAP3_1			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.24		*/

#define GPIO_0_25_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.25				*/
#define GPIO_0_25_ADC2				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.25		*/
#define GPIO_0_25_I2SRX_SDA			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.25		*/
#define GPIO_0_25_TXD3				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.25		*/

#define GPIO_0_26_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.26				*/
#define GPIO_0_26_ADC3				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.26		*/
#define GPIO_0_26_AOUT				enGpioFunctionAlt2		/**< alternate function 2 for pin 0.26		*/
#define GPIO_0_26_RXD3				enGpioFunctionAlt3		/**< alternate function 3 for pin 0.26		*/

#define GPIO_0_27_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.27				*/
#define GPIO_0_27_SDA0				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.27		*/
#define GPIO_0_27_USB_SDA			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.27		*/
#define GPIO_0_27_RESERVED			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.27		*/

#define GPIO_0_28_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.28				*/
#define GPIO_0_28_SCL0				enGpioFunctionAlt1		/**< alternate function 1 for pin 0.28		*/
#define GPIO_0_28_USB_SCL			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.28		*/
#define GPIO_0_28_RESERVED			enGpioFunctionAlt3		/**< alternate function 3 for pin 0.28		*/

#define GPIO_0_29_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.29				*/
#define GPIO_0_29_USB_D_P			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.29		*/
#define GPIO_0_29_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.29		*/
//#define GPIO_0_29_RESERVED		enGpioFunctionAlt3		/**< alternate function 3 for pin 0.29		*/

#define GPIO_0_30_GPIO				enGpioFunctionGpio		/**< GPIO function for pin 0.30				*/
#define GPIO_0_30_USB_D_N			enGpioFunctionAlt1		/**< alternate function 1 for pin 0.30		*/
#define GPIO_0_30_RESERVED			enGpioFunctionAlt2		/**< alternate function 2 for pin 0.30		*/
//#define GPIO_0_30_RESERVED		enGpioFunctionAlt3		/**< alternate function 3 for pin 0.30		*/

#define GPIO_1_0_GPIO				enGpioFunctionGpio
#define GPIO_1_0_ENET_TXD0          enGpioFunctionAlt1
#define GPIO_1_0_RESERVED           enGpioFunctionAlt2
//#define GPIO_1_0_RESERVED         enGpioFunctionAlt3

#define GPIO_1_1_GPIO				enGpioFunctionGpio
#define GPIO_1_1_ENET_TXD1          enGpioFunctionAlt1
#define GPIO_1_1_RESERVED           enGpioFunctionAlt2
//#define GPIO_1_1_RESERVED         enGpioFunctionAlt3

	// P1.2, P1.3 not available
	
#define GPIO_1_4_GPIO				enGpioFunctionGpio
#define GPIO_1_4_ENET_TX_EN         enGpioFunctionAlt1
#define GPIO_1_4_RESERVED           enGpioFunctionAlt2
//#define GPIO_1_4_RESERVED         enGpioFunctionAlt3

	// P1.5 - P1.7 not available

#define GPIO_1_8_GPIO				enGpioFunctionGpio
#define GPIO_1_8_ENET_CRS           enGpioFunctionAlt1
#define GPIO_1_8_RESERVED           enGpioFunctionAlt2
//#define GPIO_1_8_RESERVED         enGpioFunctionAlt3

#define GPIO_1_9_GPIO				enGpioFunctionGpio
#define GPIO_1_9_ENET_RXD0          enGpioFunctionAlt1
#define GPIO_1_9_RESERVED           enGpioFunctionAlt2
//#define GPIO_1_9_RESERVED         enGpioFunctionAlt3

#define GPIO_1_10_GPIO				enGpioFunctionGpio
#define GPIO_1_10_ENET_RDX1         enGpioFunctionAlt1
#define GPIO_1_10_RESERVED          enGpioFunctionAlt2
//#define GPIO_1_10_RESERVED        enGpioFunctionAlt3

	// P1.11-P1.13 not available

#define GPIO_1_14_GPIO				enGpioFunctionGpio
#define GPIO_1_14_ENET_RX_ER        enGpioFunctionAlt1
#define GPIO_1_14_RESERVED          enGpioFunctionAlt2
//#define GPIO_1_14_RESERVED        enGpioFunctionAlt3

#define GPIO_1_15_GPIO				enGpioFunctionGpio
#define GPIO_1_15_ENET_REF_CLK      enGpioFunctionAlt1
#define GPIO_1_15_RESERVED          enGpioFunctionAlt2
//#define GPIO_1_15_RESERVED        enGpioFunctionAlt3

#define GPIO_1_16_GPIO				enGpioFunctionGpio
#define GPIO_1_16_ENET_MDC          enGpioFunctionAlt1
#define GPIO_1_16_RESERVED          enGpioFunctionAlt2
//#define GPIO_1_16_RESERVED        enGpioFunctionAlt3

#define GPIO_1_17_GPIO				enGpioFunctionGpio
#define GPIO_1_17_ENET_MDIO         enGpioFunctionAlt1
#define GPIO_1_17_RESERVED          enGpioFunctionAlt2
//#define GPIO_1_17_RESERVED        enGpioFunctionAlt3

#define GPIO_1_18_GPIO				enGpioFunctionGpio
#define GPIO_1_18_USB_UP_LED        enGpioFunctionAlt1
#define GPIO_1_18_PWM1_1            enGpioFunctionAlt2
#define GPIO_1_18_CAP1_0            enGpioFunctionAlt3

#define GPIO_1_19_GPIO				enGpioFunctionGpio
#define GPIO_1_19_MCOA0             enGpioFunctionAlt1
#define GPIO_1_19_USB_PPWR          enGpioFunctionAlt2
#define GPIO_1_19_CAP1_1            enGpioFunctionAlt3

#define GPIO_1_20_GPIO				enGpioFunctionGpio
#define GPIO_1_20_MCI0				enGpioFunctionAlt1
#define GPIO_1_20_PWM1_2			enGpioFunctionAlt2
#define GPIO_1_20_SCK0				enGpioFunctionAlt3

#define GPIO_1_21_GPIO				enGpioFunctionGpio
#define GPIO_1_21_MCABORT			enGpioFunctionAlt1
#define GPIO_1_21_PWM1_3			enGpioFunctionAlt2
#define GPIO_1_21_SSEL0				enGpioFunctionAlt3

#define GPIO_1_22_GPIO				enGpioFunctionGpio
#define GPIO_1_22_MCOB0				enGpioFunctionAlt1
#define GPIO_1_22_USB_PWRD			enGpioFunctionAlt2
#define GPIO_1_22_MAT1_0			enGpioFunctionAlt3

#define GPIO_1_23_GPIO				enGpioFunctionGpio
#define GPIO_1_23_MCI1				enGpioFunctionAlt1
#define GPIO_1_23_PWM1_4			enGpioFunctionAlt2
#define GPIO_1_23_MISO0             enGpioFunctionAlt3

#define GPIO_1_24_GPIO				enGpioFunctionGpio	
#define GPIO_1_24_MCI2				enGpioFunctionAlt1
#define GPIO_1_24_PWM1_5			enGpioFunctionAlt2
#define GPIO_1_24_MOSI0			    enGpioFunctionAlt3

#define GPIO_1_25_GPIO				enGpioFunctionGpio
#define GPIO_1_25_MCOA1             enGpioFunctionAlt1
#define GPIO_1_25_RESERVED          enGpioFunctionAlt2
#define GPIO_1_25_MAT1_1            enGpioFunctionAlt3

#define GPIO_1_26_GPIO				enGpioFunctionGpio
#define GPIO_1_26_MCOB1             enGpioFunctionAlt1
#define GPIO_1_26_PWM1_6            enGpioFunctionAlt2
#define GPIO_1_26_CAP0_0            enGpioFunctionAlt3

#define GPIO_1_27_GPIO				enGpioFunctionGpio
#define GPIO_1_27_CLKOUT            enGpioFunctionAlt1
#define GPIO_1_27_USB_OVRCR         enGpioFunctionAlt2
#define GPIO_1_27_CAP0_1            enGpioFunctionAlt3

#define GPIO_1_28_GPIO				enGpioFunctionGpio
#define GPIO_1_28_MCOA2             enGpioFunctionAlt1
#define GPIO_1_28_PCAP1_0           enGpioFunctionAlt2
#define GPIO_1_28_MAT0_0            enGpioFunctionAlt3

#define GPIO_1_29_GPIO				enGpioFunctionGpio
#define GPIO_1_29_MCOB2             enGpioFunctionAlt1
#define GPIO_1_29_PCAP1_1           enGpioFunctionAlt2
#define GPIO_1_29_MAT0_1            enGpioFunctionAlt3

#define GPIO_1_30_GPIO				enGpioFunctionGpio
#define GPIO_1_30_RESERVED          enGpioFunctionAlt1
#define GPIO_1_30_VBUS              enGpioFunctionAlt2
#define GPIO_1_30_ADC4             	enGpioFunctionAlt3

#define GPIO_1_31_GPIO				enGpioFunctionGpio
#define GPIO_1_31_RESERVED          enGpioFunctionAlt1
#define GPIO_1_31_SCK1              enGpioFunctionAlt2
#define GPIO_1_31_ADC5	            enGpioFunctionAlt3

#define GPIO_2_0_GPIO				enGpioFunctionGpio
#define GPIO_2_0_PWM1_1				enGpioFunctionAlt1
#define GPIO_2_0_TXD1				enGpioFunctionAlt2
#define GPIO_2_0_RESERVED			enGpioFunctionAlt3

#define GPIO_2_1_GPIO				enGpioFunctionGpio
#define GPIO_2_1_PWM1_2				enGpioFunctionAlt1
#define GPIO_2_1_RXD1				enGpioFunctionAlt2
#define GPIO_2_1_RESERVED			enGpioFunctionAlt3

#define GPIO_2_2_GPIO				enGpioFunctionGpio
#define GPIO_2_2_PWM1_3				enGpioFunctionAlt1
#define GPIO_2_2_CTS1				enGpioFunctionAlt2
#define GPIO_2_2_RESERVED			enGpioFunctionAlt3

#define GPIO_2_3_GPIO				enGpioFunctionGpio
#define GPIO_2_3_PWM1_4				enGpioFunctionAlt1
#define GPIO_2_3_DCD1				enGpioFunctionAlt2
#define GPIO_2_3_RESERVED			enGpioFunctionAlt3

#define GPIO_2_4_GPIO				enGpioFunctionGpio
#define GPIO_2_4_PWM1_5				enGpioFunctionAlt1
#define GPIO_2_4_DSR1				enGpioFunctionAlt2
#define GPIO_2_4_RESERVED			enGpioFunctionAlt3

#define GPIO_2_5_GPIO				enGpioFunctionGpio
#define GPIO_2_5_PWM1_6				enGpioFunctionAlt1
#define GPIO_2_5_DTR1				enGpioFunctionAlt2
#define GPIO_2_5_RESERVED			enGpioFunctionAlt3

#define GPIO_2_6_GPIO				enGpioFunctionGpio
#define GPIO_2_6_PCAP1_0            enGpioFunctionAlt1
#define GPIO_2_6_RI1                enGpioFunctionAlt2
#define GPIO_2_6_RESERVED           enGpioFunctionAlt3

#define GPIO_2_7_GPIO				enGpioFunctionGpio
#define GPIO_2_7_RD2                enGpioFunctionAlt1
#define GPIO_2_7_RTS1               enGpioFunctionAlt2
#define GPIO_2_7_RESERVED           enGpioFunctionAlt3

#define GPIO_2_8_GPIO				enGpioFunctionGpio
#define GPIO_2_8_TD2                enGpioFunctionAlt1
#define GPIO_2_8_TXD2               enGpioFunctionAlt2
#define GPIO_2_8_ENET_MDC           enGpioFunctionAlt3

#define GPIO_2_9_GPIO				enGpioFunctionGpio
#define GPIO_2_9_USB_CONNECT        enGpioFunctionAlt1
#define GPIO_2_9_RXD2               enGpioFunctionAlt2
#define GPIO_2_9_ENET_MDIO          enGpioFunctionAlt3

#define GPIO_2_10_GPIO				enGpioFunctionGpio
#define GPIO_2_10_EINT0             enGpioFunctionAlt1
#define GPIO_2_10_NMI               enGpioFunctionAlt2
#define GPIO_2_10_RESERVED          enGpioFunctionAlt3

#define GPIO_2_11_GPIO				enGpioFunctionGpio
#define GPIO_2_11_EINT1             enGpioFunctionAlt1
#define GPIO_2_11_RESERVED          enGpioFunctionAlt2
#define GPIO_2_11_I2STX_CLK         enGpioFunctionAlt3
	
#define GPIO_2_12_GPIO				enGpioFunctionGpio
#define GPIO_2_12_EINT2             enGpioFunctionAlt1
#define GPIO_2_12_RESERVED          enGpioFunctionAlt2
#define GPIO_2_12_I2STX_WS          enGpioFunctionAlt3

#define GPIO_2_13_GPIO				enGpioFunctionGpio
#define GPIO_2_13_EINT3             enGpioFunctionAlt1
#define GPIO_2_13_RESERVED          enGpioFunctionAlt2
#define GPIO_2_13_I2STX_SDA         enGpioFunctionAlt3

	// P2.14 - P2.31 not available

	// P3.0-P3.24 not available
	
#define GPIO_3_25_GPIO				enGpioFunctionGpio
#define GPIO_3_25_RESERVED          enGpioFunctionAlt1
#define GPIO_3_25_MAT0_0            enGpioFunctionAlt2
#define GPIO_3_25_PWM1_2            enGpioFunctionAlt3

#define GPIO_3_26_GPIO				enGpioFunctionGpio
#define GPIO_3_26_STCLK             enGpioFunctionAlt1
#define GPIO_3_26_MAT0_0            enGpioFunctionAlt2
#define GPIO_3_26_PWM1_3            enGpioFunctionAlt3

	// P3.27-P3.31 not available
	
	// P4.0-P4.27 not available
	
#define GPIO_4_28_GPIO				enGpioFunctionGpio
#define GPIO_4_28_RX_MCLK           enGpioFunctionAlt1
#define GPIO_4_28_MAT2_0            enGpioFunctionAlt2
#define GPIO_4_28_TXD3              enGpioFunctionAlt3

#define GPIO_4_29_GPIO				enGpioFunctionGpio
#define GPIO_4_29_TX_MCLK           enGpioFunctionAlt1
#define GPIO_4_29_MAT2_1            enGpioFunctionAlt2
#define GPIO_4_29_RXD3              enGpioFunctionAlt3
	
	// P4.30-P4.31 not available


/**
 * Enumeration for multiplexed functionalities for each pin
 */
 typedef enum
 {
	enPin0_0_GPIO	= 0x000000,							/**< GPIO function for pin 0.0				*/	
	enPin0_0_RD1	= 0x000001,							/**< alternate function 1 for pin 0.0		*/
	enPin0_0_TXD3 = 0x000002,							/**< alternate function 2 for pin 0.0		*/
	enPin0_0_SDA1 = 0x000003,							/**< alternate function 3 for pin 0.0		*/

	enPin0_1_GPIO = 0x000000,							/**< GPIO function for pin 0.1				*/
	enPin0_1_TD1 = 0x000001,							/**< alternate function 1 for pin 0.1		*/
	enPin0_1_RXD3 = 0x000002,							/**< alternate function 2 for pin 0.1		*/
	enPin0_1_SCL1 = 0x000003,							/**< alternate function 3 for pin 0.1		*/
						
	enPin0_2_GPIO = 0x000000,							/**< GPIO function for pin 0.2				*/
	enPin0_2_TXD0 = 0x000001,							/**< alternate function 1 for pin 0.2		*/
	enPin0_2_ADC7 = 0x000002,							/**< alternate function 2 for pin 0.2		*/
	enPin0_2_RES = 0x000003,							/**< alternate function 3 for pin 0.2		*/
						
	enPin0_3_GPIO = 0x000000,							/**< GPIO function for pin 0.3				*/
	enPin0_3_RXD0 = 0x000001,							/**< alternate function 1 for pin 0.3		*/
	enPin0_3_ADC6 = 0x000002,							/**< alternate function 2 for pin 0.3		*/
	enPin0_3_RES = 0x000003,							/**< alternate function 3 for pin 0.3		*/
						
	enPin0_4_GPIO = 0x000000,							/**< GPIO function for pin 0.4				*/
	enPin0_4_I2SRX_CLK = 0x000001,						/**< alternate function 1 for pin 0.4		*/
	enPin0_4_RD2 = 0x000002,							/**< alternate function 2 for pin 0.4		*/
	enPin0_4_CAP2_0 = 0x000003,							/**< alternate function 3 for pin 0.4		*/
						
	enPin0_5_GPIO = 0x000000,							/**< GPIO function for pin 0.5				*/
	enPin0_5_I2SRX_WS = 0x000001,						/**< alternate function 1 for pin 0.5		*/
	enPin0_5_TD2 = 0x000002,							/**< alternate function 2 for pin 0.5		*/
	enPin0_5_CAP2_1 = 0x000003,							/**< alternate function 3 for pin 0.5		*/
						
	enPin0_6_GPIO = 0x000000,							/**< GPIO function for pin 0.6				*/
	enPin0_6_I2SRX_SDA = 0x000001,						/**< alternate function 1 for pin 0.6		*/
	enPin0_6_SSEL1 = 0x000002,							/**< alternate function 2 for pin 0.6		*/
	enPin0_6_MAT2_0 = 0x000003,							/**< alternate function 3 for pin 0.6		*/

	enPin0_7_GPIO = 0x000000,							/**< GPIO function for pin 0.7				*/
	enPin0_7_I2STX_SDA = 0x000001,						/**< alternate function 1 for pin 0.7		*/
	enPin0_7_SCK1 = 0x000002,							/**< alternate function 2 for pin 0.7		*/
	enPin0_7_MAT2_1 = 0x000003,							/**< alternate function 3 for pin 0.7		*/

	enPin0_8_GPIO = 0x000000,							/**< GPIO function for pin 0.8				*/
	enPin0_8_I2STX_WS = 0x000001,						/**< alternate function 1 for pin 0.8		*/
	enPin0_8_MISO1 = 0x000002,							/**< alternate function 2 for pin 0.8		*/
	enPin0_8_MAT2_2 = 0x000003,							/**< alternate function 3 for pin 0.8		*/

	enPin0_9_GPIO = 0x000000,							/**< GPIO function for pin 0.9				*/
	enPin0_9_I2STX_SDA = 0x000001,						/**< alternate function 1 for pin 0.9		*/
	enPin0_9_M0SI1 = 0x000002,							/**< alternate function 2 for pin 0.9		*/
	enPin0_9_MAT2_3 = 0x000003,							/**< alternate function 3 for pin 0.9		*/

	enPin0_10_GPIO = 0x000000,							/**< GPIO function for pin 0.10				*/
	enPin0_10_TXD2 = 0x000001,							/**< alternate function 1 for pin 0.10		*/
	enPin0_10_SDA2 = 0x000002,							/**< alternate function 2 for pin 0.10		*/
	enPin0_10_MAT3_0 = 0x000003,						/**< alternate function 3 for pin 0.10		*/

	enPin0_11_GPIO = 0x000000,							/**< GPIO function for pin 0.11				*/
	enPin0_11_RXD2 = 0x000001,							/**< alternate function 1 for pin 0.11		*/
	enPin0_11_SCL2 = 0x000002,							/**< alternate function 2 for pin 0.11		*/
	enPin0_11_MAT3_1 = 0x000003,						/**< alternate function 3 for pin 0.11		*/

	// Pins P0.12 - P0.14 are reserved

	enPin0_15_GPIO = 0x000000,							/**< GPIO function for pin 0.15				*/
	enPin0_15_TXD1 = 0x000001,							/**< alternate function 1 for pin 0.15		*/
	enPin0_15_SCK1 = 0x000002,							/**< alternate function 2 for pin 0.15		*/
	enPin0_15_SCK = 0x000003,							/**< alternate function 3 for pin 0.15		*/

	enPin0_16_GPIO = 0x000000,							/**< GPIO function for pin 0.16				*/
	enPin0_16_RXD1 = 0x000001,							/**< alternate function 1 for pin 0.16		*/
	enPin0_16_SSEL0 = 0x000002,							/**< alternate function 2 for pin 0.16		*/
	enPin0_16_SSEL = 0x000003,							/**< alternate function 3 for pin 0.16		*/

	enPin0_17_GPIO = 0x000000,							/**< GPIO function for pin 0.17				*/
	enPin0_17_CTS1 = 0x000001,							/**< alternate function 1 for pin 0.17		*/
	enPin0_17_MISO0 = 0x000002,							/**< alternate function 2 for pin 0.17		*/
	enPin0_17_MISO = 0x000003,							/**< alternate function 3 for pin 0.17		*/

	enPin0_18_GPIO = 0x000000,							/**< GPIO function for pin 0.18				*/
	enPin0_18_DCD1 = 0x000001,							/**< alternate function 1 for pin 0.18		*/
	enPin0_18_MOSI0 = 0x000002,							/**< alternate function 2 for pin 0.18		*/
	enPin0_18_MOSI = 0x000003,							/**< alternate function 3 for pin 0.18		*/

	enPin0_19_GPIO = 0x000000,							/**< GPIO function for pin 0.19				*/
	enPin0_19_DSR1 = 0x000001,							/**< alternate function 1 for pin 0.19		*/
	enPin0_19_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.19		*/
	enPin0_19_SDA1 = 0x000003,							/**< alternate function 3 for pin 0.19		*/

	enPin0_20_GPIO = 0x000000,							/**< GPIO function for pin 0.20				*/
	enPin0_20_DTR1 = 0x000001,							/**< alternate function 1 for pin 0.20		*/
	enPin0_20_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.20		*/
	enPin0_20_SCL1 = 0x000003,							/**< alternate function 3 for pin 0.20		*/

	enPin0_21_GPIO = 0x000000,							/**< GPIO function for pin 0.21				*/
	enPin0_21_RI1 = 0x000001,							/**< alternate function 1 for pin 0.21		*/
	enPin0_21_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.21		*/
	enPin0_21_RD1 = 0x000003,							/**< alternate function 3 for pin 0.21		*/

	enPin0_22_GPIO = 0x000000,							/**< GPIO function for pin 0.22				*/
	enPin0_22_RTS1 = 0x000001,							/**< alternate function 1 for pin 0.22		*/
	enPin0_22_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.22		*/
	enPin0_22_TD1 = 0x000003,							/**< alternate function 3 for pin 0.22		*/

	enPin0_23_GPIO = 0x000000,							/**< GPIO function for pin 0.23				*/
	enPin0_23_ADC0 = 0x000001,							/**< alternate function 1 for pin 0.23		*/
	enPin0_23_I2SRX_CLK = 0x000002,						/**< alternate function 2 for pin 0.23		*/
	enPin0_23_CAP3_0 = 0x000003,						/**< alternate function 3 for pin 0.23		*/

	enPin0_24_GPIO = 0x000000,							/**< GPIO function for pin 0.24				*/
	enPin0_24_ADC1 = 0x000001,							/**< alternate function 1 for pin 0.24		*/
	enPin0_24_I2SRX_WS = 0x000002,						/**< alternate function 2 for pin 0.24		*/
	enPin0_24_CAP3_1 = 0x000003,						/**< alternate function 3 for pin 0.24		*/
	
	enPin0_25_GPIO = 0x000000,							/**< GPIO function for pin 0.25				*/
	enPin0_25_ADC2 = 0x000001,							/**< alternate function 1 for pin 0.25		*/
	enPin0_25_I2SRX_SDA = 0x000002,						/**< alternate function 2 for pin 0.25		*/
	enPin0_25_TXD3 = 0x000003,							/**< alternate function 3 for pin 0.25		*/
	
	enPin0_26_GPIO = 0x000000,							/**< GPIO function for pin 0.26				*/
	enPin0_26_ADC3 = 0x000001,							/**< alternate function 1 for pin 0.26		*/
	enPin0_26_AOUT = 0x000002,							/**< alternate function 2 for pin 0.26		*/
	enPin0_26_RXD3 = 0x000003,							/**< alternate function 3 for pin 0.26		*/
	
	enPin0_27_GPIO = 0x000000,							/**< GPIO function for pin 0.27				*/
	enPin0_27_SDA0 = 0x000001,							/**< alternate function 1 for pin 0.27		*/
	enPin0_27_USB_SDA = 0x000002,						/**< alternate function 2 for pin 0.27		*/
	enPin0_27_RESERVED = 0x000003,						/**< alternate function 3 for pin 0.27		*/
	
	enPin0_28_GPIO = 0x000000,							/**< GPIO function for pin 0.28				*/
	enPin0_28_SCL0 = 0x000001,							/**< alternate function 1 for pin 0.28		*/
	enPin0_28_USB_SCL = 0x000002,						/**< alternate function 2 for pin 0.28		*/
	enPin0_28_RESERVED = 0x000003,						/**< alternate function 3 for pin 0.28		*/
	
	enPin0_29_GPIO = 0x000000,							/**< GPIO function for pin 0.29				*/
	enPin0_29_USB_D_P = 0x000001,						/**< alternate function 1 for pin 0.29		*/
	enPin0_29_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.29		*/
	//enPin0_29_RESERVED = 0x000003,					/**< alternate function 3 for pin 0.29		*/
	
	enPin0_30_GPIO = 0x000000,							/**< GPIO function for pin 0.30				*/
	enPin0_30_USB_D_N = 0x000001,						/**< alternate function 1 for pin 0.30		*/
	enPin0_30_RESERVED = 0x000002,						/**< alternate function 2 for pin 0.30		*/
	//enPin0_30_RESERVED = 0x000003,					/**< alternate function 3 for pin 0.30		*/
	
// Note: 	The pin function define list is not yet complete.
//			The list will continue for all the available pins.
}PFEnPinFunction;


/** Enumeration for pin direction						*/
typedef enum
{
	enGpioDirInput = 0,				/**< GPIO direction input							*/
	enGpioDirOutput					/**< GPIO direction output							*/
}PFEnDirection;

/** Enumeration for pin mode							*/
typedef enum
{
	enGpioPinModePullUp = 0,		/**< GPIO pull-up enable							*/
	enGpioPinModeRepeater,			/**< GPIO repeater mode enable						*/
	enGpioPinModeNoPullUpDown,		/**< GPIO no pull-up or pull-down					*/
	enGpioPinModePullDown			/**< GPIO pull-down enable							*/
}PFEnGpioPinMode;

/** Enumeration for open drain settings					*/
typedef enum
{
	enGpioOpenDrainDisable = 0,		/**< GPIO open drain disable						*/
	enGpioOpenDrainEnable 			/**< GPIO open drain enable							*/
}PFEnOpenDrain;

/** Enumeration for multiplexed pin functionality		*/
typedef enum
{
	enGpioFunctionGpio = 0,			/**< configure pin as GPIO							*/
	enGpioFunctionAlt1,				/**< configure pin for alternate function 1			*/
	enGpioFunctionAlt2,				/**< configure pin for alternate function 2			*/
	enGpioFunctionAlt3				/**< configure pin for alternate function 3			*/
}PFEnAltFunction;

/** Structure to define a pin from a port				*/
typedef struct
{
	PFdword port;					/**< Port number for GPIO. Predefine d port numbers should be used.				*/
	PFdword pin;					/**< Pin number																	*/
}PFGpioPortPin;

/** Pointer to PFGpioPortPin structure	 */
typedef PFGpioPortPin* PFpGpioPortPin;

/** GPIO configuration structure.						*/
typedef struct
{
	PFdword				port;			/**< Port number for GPIO. Predefine d port numbers should be used.			*/
	PFdword 			pins;			/**< Pins to initialize. Pins should be mentioned in bit-shifted format.	*/
	PFEnDirection 		direction;		/**< Pin I/O direction														*/
	PFEnGpioPinMode		mode;			/**< Pin pull up/down mode													*/
	PFEnOpenDrain		openDrain;		/**< Pin Open Drain on/off													*/
	PFEnAltFunction 	altFuction;		/**< Select one of the multiplexed pin functionality.						*/
}PFCfgGpio;

/**
 * \brief pointer to PFCfgGpio structure
 */
typedef PFCfgGpio* PFpCfgGpio;

/**
 * The macro is used to set one or more pins on a particular port.
 *
 * \param port Port number on which pins to be set. Port numbers defined in primeGpio.h should be used.
 * \param pin Pins to set. The pins should be mentioned in bit shifted format. Pin numbers defined in primeGpio.h can be used.
 *			Multiple pins should be ORed together to set multiple pins on the same port.
 *
 * \note This macro will not affect all the pins on the port. It will affect only the pins selected by user.
 */
#define PF_GPIO_PINS_SET(port, pin)							*((PFpreg32)(GPIO_SET_BASE + port)) = pin

/**
 * The macro is used to clear one or more pins on a particular port.
 *
 * \param port Port number on which pins to be set. Port numbers defined in primeGpio.h should be used.
 * \param pin Pins to set. The pins should be mentioned in bit shifted format. Pin numbers defined in primeGpio.h can be used.
 *			Multiple pins should be ORed together to clear multiple pins on the same port.
 *
 * \note This macro will not affect all the pins on the port. It will affect only the pins selected by user.
 */
#define PF_GPIO_PINS_CLEAR(port, pin)							*((PFpreg32)(GPIO_CLEAR_BASE + port)) = pin

/**
 * The macro is used to write 32 bit data to a particular port. 
 *
 * \param port Port number to write. Port numbers defined in primeGpio.h should be used.
 * \param data Data to write on port. The pins should be mentioned in bit shifted format. Pin numbers defined in primeGpio.h can be used.
 *
 * \note This macro will affect all the pins on the port.
 */
#define PF_GPIO_PORT_WRITE(port, data)							*((PFpreg32)(GPIO_PIN_BASE + port)) = data

/**
 * The macro is used to write 16 bit data to a particular port. 
 *
 * \param port Port number to write. Port numbers defined in primeGpio.h should be used.
 * \param data Data to write on port. The pins should be mentioned in bit shifted format. Pin numbers defined in primeGpio.h can be used.
 * \param halfword 0 to write lower half, 1 to write upper half.
 *
 * \note This macro will affect all the pins on the port.
 */
#define PF_GPIO_PORT_WRITE_HALF_WORD(port, data, halfword)		*((PFpreg16)(GPIO_PIN_BASE + port + (halfword * 2))) = data

/**
 *The macro is used to write 8 bit data to a particular port. 
 *
 * \param port Port number to write. Port numbers defined in primeGpio.h should be used.
 * \param data Data to write on port. The pins should be mentioned in bit shifted format. Pin numbers defined in primeGpio.h can be used.
 * \param byte Byte number to read (0-3).
 *
 * \note This macro will affect all the pins on the port.
 */
#define PF_GPIO_PORT_WRITE_BYTE(port, data, byte)				*((PFpreg8)(GPIO_PIN_BASE + port + byte)) = data

/**
 * The macro is used to read 32 bit data from a particular port. 
 *
 * \param port Port number to read. Port numbers defined in primeGpio.h should be used.
 */
#define PF_GPIO_PORT_READ(port)								*((PFpreg32)(GPIO_PIN_BASE + port))

/**
 * The macro is used to read 16 bit data from a particular port. 
 * 
 * \param port Port number to read. Port numbers defined in primeGpio.h should be used.
 * \param halfword 0 to read lower half, 1 to read upper half.
 */
#define PF_GPIO_PORT_READ_HALF_WORD(port, halfword)				*((PFpreg16)(GPIO_PIN_BASE + port + (halfword * 2)))

/**
 * The macro is used to read 8 bit data from a particular port. 
 *
 * \param port Port number to read. Port numbers defined in primeGpio.h should be used.
 * \param byte Byte number to read (0-3).
 */
#define PF_GPIO_PORT_READ_BYTE(port, byte)							*((PFpreg8)(GPIO_PIN_BASE + port + byte))

/**
 * The macro is used to Set Direction of a particular port.
 *
 * \param port	Port number to set direction. Port numbers defined in primeGpio.h should be used.
 * \param pin	Pin or Pins of the Port for setting the direction. Should be in bit shifted format.
 * \param dir	direction of the pin or Pins. should be enGpioDirOutput or enGpioDirInput
 */
#define PF_GPIO_SET_DIR(port, pin, dir )  dir ? 	\
										(*((PFdword*)(GPIO_IODIR_BASE + port)) |= pin) : \
										(*((PFdword*)(GPIO_IODIR_BASE + port)) &= ~pin )
										
/**
 * The function configures one or more gpio pins on one or more ports for different modes
 *
 * \param config gpioConfig structure array, which contains array port numbers, pin numbers and port settings to configure for these pins.
 * \param count number of elements in the config array.
 *
 * \return gpio initialization status. 
 */
PFEnStatus pfGpioInit(PFpCfgGpio config, PFdword count);

/**
 * The function configures one or more gpio pins on a port for different modes
 *
 * \param config gpioConfig structure, which contains port number, pin numbers and port settings to configure for these pins.
 *
 * \return gpio initialization status. 
 */
PFEnStatus pfGpioPinConfig(PFpCfgGpio config);


/** @} */
