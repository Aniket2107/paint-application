/**
 * \file        prime_config.h
 * \brief       Prime Framework Configuration macro defination
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: NO
 *
 */

 // These macros control which peripheral/devices to be included in the output binary.
// To save memory usage, user can disable the peripherals/devices that are not in use
#define PF_USE_ADC          1

#define PF_USE_EEPROM       1

#define PF_USE_EINT         1
#if(PF_USE_EINT == 1)
    #define PF_USE_EINT0        1
    #define PF_USE_EINT1        1
    #define PF_USE_EINT2        1
    #define PF_USE_EINT3        1
    #define PF_USE_EINT4        1
    #define PF_USE_EINT5        1
    #define PF_USE_EINT6        1
    #define PF_USE_EINT7        1
#endif  // #if(PF_USE_EINT == 1)

#define PF_USE_UART         1
#if(PF_USE_UART == 1)
    #define PF_USE_UART0    1
    #define PF_USE_UART1    1
    #define PF_USE_UART2    1
    #define PF_USE_UART3    1
#endif  // #if(PF_USE_UART == 1)

#define PF_USE_SPI      1
#if(PF_USE_SPI == 1)
    #define PF_USE_SPI0     1
    #define PF_USE_SPI1     1
#endif  // #if(PF_USE_SPI == 1)

#define PF_USE_I2C      1
#if(PF_USE_I2C == 1)
    #define PF_USE_I2C0     1
    #define PF_USE_I2C1     1
    #define PF_USE_I2C2     1
#endif  // #if(PF_USE_I2C == 1)

#define PF_USE_CAN      1
#if(PF_USE_CAN == 1)
    #define PF_USE_CAN1     1
    #define PF_USE_CAN2     1
#endif  // #if(PF_USE_CAN == 1)

#define PF_USE_TIMER        1
#if(PF_USE_TIMER == 1)
    #define PF_USE_TIMER0       1
    #define PF_USE_TIMER1       1
    #define PF_USE_TIMER2       1
    #define PF_USE_TIMER3       1
    #define PF_USE_TIMER4       1
    #define PF_USE_TIMER5       1

#endif  // #if(PF_USE_TIMER == 1)

#define PF_USE_I2S      1

#define PF_USE_PWM      1
#if(PF_USE_PWM == 1)
    #define PF_USE_PWM0     1
    #define PF_USE_PWM2     1

#endif  // #if(PF_USE_PWM == 1)
#define PF_USE_RIT      1

#define PF_USE_RTC      1

#define PF_USE_PCINT        1

#define PF_USE_SYSTICK      1

#define PF_USE_WDT          1

#define PF_USE_IAP          1

#define PF_USE_WARNING      0

#if (PF_USE_WARNING == 1)
#define PF_WARN(X)      PF_WARNING X
#else
#define PF_WARN(X)      void
#endif
