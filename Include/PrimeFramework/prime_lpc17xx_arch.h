#pragma once

#include "prime_lpc17xx_regmap.h"
#include "prime_lpc17xx_regdefs.h"
#include "prime_lpc17xx_configMacros.h"
#include "prime_vectors.h"

#define PF_BYTE_ORDER				PF_LITTLE_ENDIAN

/*		GPIO config macros										*/
/** \brief Maximum ports available for GPIO module				*/
#define GPIO_MAX_PORT				5


/*		UART config macros										*/
/** \brief Maximum channels available for UART module			*/
#define	UART_MAX_CHANNELS			4
/** \brief Maximum baudrate supported by UART module			*/
#define UART0_MAX_BAUDRATE			115200
#define UART1_MAX_BAUDRATE			115200
#define UART2_MAX_BAUDRATE			115200
#define UART3_MAX_BAUDRATE			115200

/*		PWM config macros										*/
/** \brief Maximum match registers available for PWM module		*/
#define PWM_MAX_MATCH_REG			7
/** \brief Maximum channels available for PWM module			*/
#define PWM_MAX_CHANNEL				6

/*		SPI config macros										*/
/** \brief Maximum channels available for SPI module			*/
#define SPI_MAX_CHANNEL				2
/** \brief Maximum baudrate supported by UART module			*/
#define SPI0_MAX_BAUDRATE			25000000
#define SPI1_MAX_BAUDRATE			25000000
/** \brief Maximum devices supported on a single SPI bus		*/
#define SPI0_MAX_DEVICE_SUPPORTED	8
#define SPI1_MAX_DEVICE_SUPPORTED	8

/*		I2C config macros										*/
/** \brief Maximum channels available for I2C module			*/
#define I2C_MAX_CHANNEL				3
/** \brief Maximum baudrate supported by UART module			*/
#define I2C0_MAX_BAUDRATE			400000
#define I2C1_MAX_BAUDRATE			400000
#define I2C2_MAX_BAUDRATE			400000

/*		CAN config macros										*/
/** \brief Maximum channels available for CAN module			*/
#define CAN_MAX_CHANNEL				2
/** \brief Maximum baudrate supported by UART module			*/
#define CAN1_MAX_BAUDRATE			1000000
#define CAN2_MAX_BAUDRATE			1000000

/*		EXT INT config macros									*/
/** \brief Maximum External Interrupts available 				*/
#define EXT_INT_MAX_CHANNEL			4
/** \brief Maximum callbacks allowed for a single interrupt		*/
#define EINT0_MAX_CALLBACK		8
#define EINT1_MAX_CALLBACK		8
#define EINT2_MAX_CALLBACK		8
#define EINT3_MAX_CALLBACK		8

/** GPIO interrupt configuration macros 		*/
#define GPIO_INT_CH				3
#define GPIO_INT_CHANNEL		EINT3
#define GPIO_MAX_INTERRUPTS		45

/*		 ADC Config Macors										*/
// ADC resolution in bits
#define PF_ADC_BIT_RESOLUTION				12
// ADC maximum conversion value
#define PF_ADC_MAX_VALUE					(1 << PF_ADC_BIT_RESOLUTION)
// ADC reference voltage in millivolts
#define PF_ADC_REF_VTG						3300
// Scaling factor for ADC value to voltage conversion to avoid truncation
#define PF_ADC_SCALING_FACTOR				1000
// Conversion factor for ADC value to voltage conversion
#define PF_ADC_CONVERSION_FACTOR(REF_VTG)	((REF_VTG * PF_ADC_SCALING_FACTOR) / PF_ADC_MAX_VALUE)
// Convert ADc value in millivolts
#define PF_ADC_CALC_VTG(ADC_VAL)	((ADC_VAL * PF_ADC_CONVERSION_FACTOR(REF_VTG)) / PF_ADC_SCALING_FACTOR)



