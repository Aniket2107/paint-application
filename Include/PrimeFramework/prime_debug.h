/**
 * \file        prime_debug.h
 * \brief       Common DEBUG API.
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: NO
 *
 */
#pragma once

/**
 *  \ingroup     core
 *  \defgroup    PF_DEBUG    DEBUG
 *  @{
 *  
 *  \brief      Debuging Macros
 *  \details    Macro's Related to debugging purpose
 */

//#define PRIME_DEBUG           1





#define PF_ADC_DEBUG   PRIME_DEBUG  /**< ADC debug macros */

#define PF_EINT_DEBUG   PRIME_DEBUG /**< EINT debug macros */
    #define PF_EINT0_DEBUG   PF_EINT_DEBUG  /**< EINT 0 debug macros */
    #define PF_EINT1_DEBUG   PF_EINT_DEBUG  /**< EINT 1 debug macros */
    #define PF_EINT2_DEBUG   PF_EINT_DEBUG  /**< EINT 2 debug macros */
    #define PF_EINT3_DEBUG   PF_EINT_DEBUG  /**< EINT 3 debug macros */
    #define PF_EINT4_DEBUG   PF_EINT_DEBUG  /**< EINT 4 debug macros */
    #define PF_EINT5_DEBUG   PF_EINT_DEBUG  /**< EINT 5 debug macros */
    #define PF_EINT6_DEBUG   PF_EINT_DEBUG  /**< EINT 6 debug macros */
    #define PF_EINT7_DEBUG   PF_EINT_DEBUG  /**< EINT 7 debug macros */


#define PF_EEPROM_DEBUG PRIME_DEBUG /**< EEPROM debug macros */

#define PF_UART_DEBUG   PRIME_DEBUG /**< UART debug macros */
    #define PF_UART0_DEBUG   PF_UART_DEBUG  /**< UART 0  debug macros */
    #define PF_UART1_DEBUG   PF_UART_DEBUG  /**< UART 1  debug macros */
    #define PF_UART2_DEBUG   PF_UART_DEBUG  /**< UART 2  debug macros */
    #define PF_UART3_DEBUG   PF_UART_DEBUG  /**< UART 3  debug macros */
    
#define PF_SPI_DEBUG    PRIME_DEBUG /**< SPI  debug macros */
    #define PF_SPI0_DEBUG   PF_SPI_DEBUG    /**< SPI 0  debug macros */
    #define PF_SPI1_DEBUG   PF_SPI_DEBUG    /**< SPI 1  debug macros */

#define PF_I2C_DEBUG    PRIME_DEBUG /**< I2C  debug macros */
    #define PF_I2C0_DEBUG   PF_I2C_DEBUG    /**< I2C 0 debug macros */
    #define PF_I2C1_DEBUG   PF_I2C_DEBUG    /**< I2C 1 debug macros */
    #define PF_I2C2_DEBUG   PF_I2C_DEBUG    /**< I2C 2 debug macros */


#define PF_CAN_DEBUG   PRIME_DEBUG  /**< CAN debug macros */
    #define PF_CAN1_DEBUG   PF_CAN_DEBUG    /**< CAN 0 debug macros */
    #define PF_CAN2_DEBUG   PF_CAN_DEBUG    /**< CAN 1 debug macros */

#define PF_TIMER_DEBUG  PRIME_DEBUG /**< TIMER debug macros */
    #define PF_TIMER0_DEBUG   PF_TIMER_DEBUG    /**< TIMER 0 debug macros */
    #define PF_TIMER1_DEBUG   PF_TIMER_DEBUG    /**< TIMER 1 debug macros */
    #define PF_TIMER2_DEBUG   PF_TIMER_DEBUG    /**< TIMER 2 debug macros */
    #define PF_TIMER3_DEBUG   PF_TIMER_DEBUG    /**< TIMER 3 debug macros */
    #define PF_TIMER4_DEBUG   PF_TIMER_DEBUG    /**< TIMER 4 debug macros */
    #define PF_TIMER5_DEBUG   PF_TIMER_DEBUG    /**< TIMER 5 debug macros */

#define PF_PWM_DEBUG        PRIME_DEBUG /**< PWM debug macros */
    #define PF_PWM0_DEBUG   PF_PWM_DEBUG    /**< PWM 0 debug macros */
    #define PF_PWM1_DEBUG   PF_PWM_DEBUG    /**< PWM 1 debug macros */
    #define PF_PWM2_DEBUG   PF_PWM_DEBUG    /**< PWM 2 debug macros */

    
#define PF_I2S_DEBUG        PRIME_DEBUG /**< I2S debug macros */
#define PF_WDT_DEBUG        PRIME_DEBUG /**< WDT debug macros */
#define PF_RIT_DEBUG        PRIME_DEBUG /**< RIT debug macros */
#define PF_RTC_DEBUG        PRIME_DEBUG /**< RTC debug macros */
#define PF_SYSCLK_DEBUG     PRIME_DEBUG /**< SYSCLK debug macros */
#define PF_SYSTICK_DEBUG    PRIME_DEBUG /**< SYCTICK debug macros */
#define PF_PCINT_DEBUG      PRIME_DEBUG /**< PCINT debug macros */

#define PF_GPIO_DEBUG       PRIME_DEBUG /**< GPIO debug macros */

#define PF_IAP_DEBUG        PRIME_DEBUG /**< IAP debug macros */
    
// Other debug macros
#define PF_UTILS_DEBUG      PRIME_DEBUG /**< UTILS debug macros */

#define PF_LIST_DEBUG       PRIME_DEBUG /**< LIST debug macros */



#define PF_USE_DEBUG_ASSERT     PRIME_DEBUG     /**< defines whether to use assert functions (boolean). */
#define PF_USE_DEBUG_PRINT      PRIME_DEBUG     /**< defines whether to print debug information (boolean). */
#define PF_PRINTF_BUFFER_SIZE   64              /**< defines size of pfPrintf process buffer used for string conversion */

#if(PF_USE_DEBUG_PRINT == 1)
    #define PF_PRINTF(...)      pfPrintf(__VA_ARGS__)       /**< defines function to call printf like function for debugging purpose */
    #define PF_PRINTF_INIT(X)   pfPrintfInit(x)
#else
    #define PF_PRINTF(...)      do{}while(0)                /** defines function which will not print any debug information */
#define PF_PRINTF_INIT(X)       do{}while(0)
#endif

#if(PF_USE_DEBUG_ASSERT == 1)
/** function to check condition.If condition holds true then the program execution will continue otherwise it will be terminated with return value 
and an error message with filename and function name will be printed */    
#define PF_ASSERT_RET(_e_, _r_) \
    if(!(_e_)) \
    { \
        PF_PRINTF((const PFchar *)"ASSERTION FAILED at %s:%s!", __FILE__, __FUNCTION__); \
        return (_r_); \
    }
/** function to check condition.If condition holds true then the program execution will continue otherwise it will be stopped 
and an error message with filename and function name will be printed */    
#define PF_ASSERT(_e_) \
    if(!(_e_)) \
    { \
        PF_PRINTF((const PFchar *)"ASSERTION FAILED at %s:%s!", __FILE__, __FUNCTION__); \
        while(1); \
    }
/** function to check whether pointer is valid or not.If pointer is valid then the program execution will continue otherwise it will be stopped 
and an error message with filename and function name will be printed */    
#define PF_ASSERT_PTR(_p_) \
    if((_p_) == PF_NULL_PTR) \
    { \
        PF_PRINTF((const PFchar *)"PTR ASSERTION FAILED at %s:%s!", __FILE__, __FUNCTION__); \
        while(1); \
    }
#else 
/** defines function which will not check any condition.  */   
#define PF_ASSERT_RET(_e_, _r_)     do{}while(0)
/** defines function which will not check any condition.  */   
#define PF_ASSERT(_e_)              do{}while(0)
/** defines function which will not check pointer  */       
#define PF_ASSERT_PTR(_p_)          do{}while(0)
#endif  // #if (PF_USE_DEBUG_ASSERT == 1)


/**
 *  Function prototype for writing one byte to output media.
 *  
 *  \param      data    8 bit data to write.
 *  
 *  \return     write status.
 *  \see    PFEnStatus
 */
typedef PFEnStatus (*PFprintfWriteByteFn)(PFbyte data); 

/**
 *  This function initializes pfPrintf.
 *  
 *  \param      writeByte   Pointer to function for writing one byte to output media For example "pfUart0WriteByte".
 *  
 *  \return     pfPrintf initialization status.
 *  \see    PFEnStatus
*/
PFEnStatus pfPrintfInit(PFprintfWriteByteFn writeByte);

/**
 *  This function writes formatted output from the format string FORMAT.
 *  
 *  \return   If successful, the total number of characters written is returned.On failure, a negative number(-1) is returned.
 *  \see    PFEnStatus
*/
#if(PF_USE_DEBUG_PRINT == 1)
PFdword pfPrintf(const PFchar * format, ...);
#endif  // #if(PF_USE_DEBUG_PRINT == 1)

/**
 *  This function writes formatted output to buffer from the format string FMT.
 *  
 *  \return     If successful, the total number of characters written is returned.On failure, a negative number(-1) is returned.
 *  \see    PFEnStatus
*/
PFdword pfSprintf(PFchar* outstr,const PFchar *fmt, ...);


/**@}*/
