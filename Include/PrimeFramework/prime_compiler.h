/**
 * \file        prime_compiler.h
 * \brief       Prime Framework COMPILER DEPENDENT MACROS
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 *
 * \par
 *   For licensing information, see the file 'LICENSE' in the root folder of
 *   this software module
 *
 * Review status: NO
 *
 */
#pragma once
/**
* \ingroup      core
* \defgroup     PF_COMPILER_MACRO   PRIME COMPILER DEPENDENT MACROS
* @{
 *  
 *  \brief      Prime Compiler API
 *  \details    
 */ 
#include "prime_types.h"
#if defined ( __CC_ARM )                    
    #define PF_C_ASM                            __asm                               /**< asm keyword for Keil ARMCC compiler                */
    #define PF_C_INLINE                         __inline                            /**< inline keyword for Keil ARMCC compiler             */
    #define PF_C_STATIC_INLINE                  static __inline                     /**< static inline keyword for Keil ARMCC compiler      */
    #define PF_C_UNUSED_VAR(type,name)          type name __attribute__((unused))   /**< This keyword for Keil ARMCC compiler informs the compiler that you expect a variable to be unused and tells it not issue a warning if it is not used.      */
    #define PF_C_UNUSED_ARG(type,arg)           type arg __attribute__((unused))    /**< This keyword for Keil ARMCC compiler informs the compiler that you expect a variable in function argument to be unused and tells it not issue a warning if it is not used.     */
    #define PF_C_NORETURN                       __declspec(noreturn)                /**< This keyword for Keil ARMCC compiler asserts that a function never returns         */
    #define PF_C_PACKED                         __packed                            /**< This sets the alignment of any valid type to 1 for Keil ARMCC compiler                 */
    #define PF_C_FORMAT(aType,aFmt,aFirst)                                          /**< No keyword is defined Keil ARMCC compiler  */
    #define PF_C_UNLIKELY(x)                    x                                   /**< No keyword is defined Keil ARMCC compiler  */
    #define PF_C_LIKELY(x)                      x                                   /**< No keyword is defined Keil ARMCC compiler  */
    #define PF_C_TYPEOF                         0                                   /**< No keyword is defined Keil ARMCC compiler  */
    #define PF_C_TYPEOF_OR_PGENERIC(type)       PFpgeneric                          /**< This defines PFpgeneric keyword for Keil ARMCC compiler    */
    #define PF_WARNING                          #warning                            /**< warning preprocessor               */
/**  
 *  \brief      No Operation
 *  \details    No Operation does nothing. This instruction can be used for code alignment
 *              purposes.
 */
    #define PF_NOP      __nop

/**  
 * \brief   Wait For Interrupt
 * \details Wait For Interrupt is a hint instruction that suspends execution until 
 *          one of a number of events occurs.
 */
    #define PF_WFI      __wfi

/**
 * \brief   Wait For Event
 * \details Wait For Event is a hint instruction that permits the processor to enter 
 *          a low-power state until one of a number of events occurs.
 */
    #define PF_WFE      __wfe

/**
 * \brief   Send Event
 * \details Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
    #define PF_SEV      __sev

/**
 * \brief   Instruction Synchronization Barrier
 * \details Instruction Synchronization Barrier flushes the pipeline in the processor,
 *              so that all instructions following the ISB are fetched from cache or
 *              memory, after the instruction has been completed.
 */
    #define PF_ISB()    __isb(0xF)

/** 
 * \brief   Data Synchronization Barrier
 * \details This function acts as a special kind of Data Memory Barrier.
 *          It completes when all explicit memory accesses before this instruction complete.
 */
    #define PF_DSB()    __dsb(0xF)

/**
 *  \brief      Data Memory Barrier
 *  \details    This function ensures the apparent order of the explicit memory operations before
 *              and after the instruction, without ensuring their completion.
 */
    #define PF_DMB()    __dmb(0xF)

/**  
 *  \brief      Reverse byte order (32 bit)
 *  \details    This function reverses the byte order in integer value.
 *  
 *  \param [in]    value  Value to reverse
 *  \return               Reversed value
 */
    #define PF_REV      __rev
    
/**
 *  \brief      Reverse byte order (16 bit)
 *  \details    This function reverses the byte order in two unsigned short values.
 *  
 *  \param [in]    value  Value to reverse
 *  \return               Reversed value
 */

    #if (__ARMCC_VERSION < 400677)
        extern PFdword __REV16(PFdword value);
        #else  /* (__ARMCC_VERSION >= 400677)  */
        PF_C_STATIC_INLINE PF_C_ASM PFdword __REV16(PFdword value)
        {
            rev16 r0, r0
            bx lr
        }
    #endif /* __ARMCC_VERSION  */
    
/**
 *  \brief      Reverse byte order in signed short value
 *  \details    This function reverses the byte order in a signed short value with sign extension to integer.
 *  
 *  \param [in]    value  Value to reverse
 *  \return               Reversed value
 */
    #if (__ARMCC_VERSION < 400677)
        extern PFsdword __REVSH(PFsdword value);
    #else  /* (__ARMCC_VERSION >= 400677)  */
        PF_C_STATIC_INLINE PF_C_ASM PFsdword __REVSH(PFsdword value)
    {
      revsh r0, r0
      bx lr
    }
    #endif /* __ARMCC_VERSION  */

#elif defined ( __GNUC__ )
    #define PF_C_ASM                            __asm                                               /**< asm keyword for GNU compiler       */
    #define PF_C_INLINE                         inline                                              /**< inline keyword for GNU compiler        */
    #define PF_C_FORMAT(type,fmt,first)         __attribute__((__format__(type, fmt, first)))       /**< This keyword specifies that a function takes "type" style arguments that should be type-checked against a format string. */
    #define PF_C_UNUSED_VAR(type,name)          __attribute__((__unused__)) type name               /**< This keyword for GNU compiler informs the compiler that you expect a variable to be unused and tells it not issue a warning if it is not used.*/
    #define PF_C_UNUSED_ARG(type,arg)           __attribute__((__unused__)) type arg                /**< This keyword for GNU compiler informs the compiler that you expect a variable in function argument to be unused and tells it not issue a warning if it is not used.*/
    #define PF_C_LIKELY(x)                      __builtin_expect(!!(x), 1)                          /**< This keyword helps optimization in branch prediction by telling GNU compiler that codition is likely to be true. */
    #define PF_C_UNLIKELY(x)                    __builtin_expect(!!(x), 0)                          /**< This keyword helps optimization in branch prediction by telling GNU compiler that codition is likely to be false. */
    #define PF_C_STATIC_INLINE                  static inline __attribute__((__always_inline__))    /**< static inline keyword for GNU compiler     */
    #define PF_C_NORETURN                       __attribute__((__noreturn__))                       /**< This keyword for GNU compiler asserts that a function never returns*/
    #define PF_C_PACKED                         __attribute__((packed))                             /**< This sets the alignment of any valid type to 1 for GNU compiler*/
    #define PF_C_TYPEOF_OR_PGENERIC(type)       typeof(type)                                        /**< This defines typeof keyword for GNU compiler */
    #define PF_WARNING                          #warning                                        /**< warning preprocessor       */

/** 
 *  \brief      No Operation
 *  \details    No Operation does nothing. This instruction can be used for code alignment purposes.   
 */
PF_C_STATIC_INLINE void __NOP(void)
{
  PF_C_ASM volatile ("nop");
}

/** 
 *  \brief      Wait For Interrupt
 *  \details    Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.  
 */
PF_C_STATIC_INLINE void __WFI(void)
{
  PF_C_ASM volatile ("wfi");
}

/**
 *  \brief      Wait For Event
 *  \details    Wait For Event is a hint instruction that permits the processor to enter
 *              a low-power state until one of a number of events occurs.
 */
PF_C_STATIC_INLINE void __WFE(void)
{
  PF_C_ASM volatile ("wfe");
}

/**
 *  \brief      Send Event
 *  \details    Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
PF_C_STATIC_INLINE void __SEV(void)
{
  PF_C_ASM volatile ("sev");
}

/**
 *  \brief      Instruction Synchronization Barrier
 *  \details    Instruction Synchronization Barrier flushes the pipeline in the processor,
 *              so that all instructions following the ISB are fetched from cache or
 *              memory, after the instruction has been completed.
 */
PF_C_STATIC_INLINE void __ISB(void)
{
  PF_C_ASM volatile ("isb");
}

/**
 *  \brief      Data Synchronization Barrier
 *  \details    This function acts as a special kind of Data Memory Barrier.
 *              It completes when all explicit memory accesses before this instruction complete.
 */
PF_C_STATIC_INLINE void __DSB(void)
{
  PF_C_ASM volatile ("dsb");
}

/**
 *  \brief      Data Memory Barrier
 *  \details    This function ensures the apparent order of the explicit memory operations before
 *              and after the instruction, without ensuring their completion.
 */
PF_C_STATIC_INLINE void __DMB(void)
{
  PF_C_ASM volatile ("dmb");
}

/**
 *  \brief      Reverse byte order (32 bit)
 *  \details    This function reverses the byte order in integer value.
 *  
 *  \param [in]    value  Value to reverse
 *  
    \return               Reversed value
 */
PF_C_STATIC_INLINE PFdword __REV(PFdword value)
{
  PFdword result;

  PF_C_ASM volatile ("rev %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

/**
 *  \brief      Reverse byte order (16 bit)
 *  \details    This function reverses the byte order in two unsigned short values.
 *  
 *  \param [in]    value  Value to reverse
 *  \return               Reversed value
 */
PF_C_STATIC_INLINE PFdword __REV16(PFdword value)
{
  PFdword result;

  PF_C_ASM volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

/**
 *  \brief      Reverse byte order in signed short value
 *  \details    This function reverses the byte order in a signed short value with sign extension to integer.
 *  
 *  \param [in]    value  Value to reverse
 *  \return               Reversed value
 */
PF_C_STATIC_INLINE PFsdword __REVSH(PFsdword value)
{
  PFdword result;

  PF_C_ASM volatile ("revsh %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

    
#else
    #error "NO COMPILER SELECTED!!!"
#endif

#ifdef __cplusplus
    #define PF_C99                  1           /**< This defines whether C99 version is supportes or not (boolean). */
#else
    #if defined(__STDC_VERSION__)
        #if (__STDC_VERSION__ >= 199901L)       /* This is GCC */
            #define PF_C99              1       /**< This defines whether C99 version is supportes or not (boolean). */
        #else
            #define PF_C99              0       
        #endif
    #endif
#endif

#if PF_C99
    #ifdef __cplusplus
        #define PF_C_C99INIT(name,val)  name: val       /**< This defines named initializers for C++ */
    #else
        #define PF_C_C99INIT(name,val)  .name = val     /**< This defines named initializers for C */
    #endif
#elif defined(__GNUC__)
    #define PF_C_C99INIT(name,val) name: val            /**< This defines named initializers for GNU compiler */
#elif defined(__CC_ARM)
    #define PF_C_C99INIT(name,val) (val)                /**< This defines named initializers for ARMCC compiler */
#else
    #warning No named initializers. 
    #define PF_C_C99INIT(name,val) (val)                /**< This defines named initializers for unknown compiler */
#endif

#ifdef __cplusplus
    #define PF_EXTERN_C              extern "C"         /**< extern keyword used for function in C++ which has 'C' linkage */
    #define PF_EXTERN_C_BEGIN    extern "C" {           /**< extern keyword with begin parentheses used for function in C++ which has 'C' linkage */
    #define PF_EXTERN_C_END      }                      /**< end parentheses used for function in C++ which has 'C' linkage */
#else
    #define PF_EXTERN_C              extern             /**< This defines extern keyword */
    #define PF_EXTERN_C_BEGIN                           /**< No keyword is required for C compiler */
    #define PF_EXTERN_C_END                             /**< No keyword is required for C compiler */
#endif
    
#define PF_CPP_CHECK(condition)  \
                PF_C_UNUSED_VAR(extern char, PF_CPP_CHECK__[(condition) ? 1 : -1])      /**< Issue a compilation error if the condition is false */

#ifndef PF_CHECK_TYPE_EQUAL
    #define PF_CHECK_TYPE_EQUAL(var1, var2) \
                    do { (void)(&(var1) == &(var2)); } while(0)
#endif

/*
* Claim variable as volatile.
*/
#define PF_ACCESS_SAFE(x) (*(volatile typeof(x) *)&(x))
#ifndef PF_EOF
    #define     PF_EOF   (-1)           /**< This defines end of file */
#endif

/** @}  */

