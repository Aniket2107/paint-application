/**
 * \file        prime_utils.h
 * \brief       Prime Framework Utils
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
 *  \ingroup    core
 *  \defgroup   PF_Utils    Utilities  API
 *  @{
 *  
 *  \brief      Prime Utilities  API
 *  \details    
 */ 

#include "prime_core.h"
#include "prime_fifo.h"
#include "prime_list.h"
#include "prime_string.h"

/** Macros for ASCII values     */
#define PF_ASCII_BACKSPACE      0x08
#define PF_ASCII_TAB            0x09
#define PF_ASCII_LF             0x0A
#define PF_ASCII_CR             0x0D
#define PF_ASCII_ESCAPE         0x1B


/** Definitions for bit masks       */
#define BIT_MASK_0                  0x00000001      /**< bit mask for bit 0         */
#define BIT_MASK_1                  0x00000002      /**< bit mask for bit 1         */
#define BIT_MASK_2                  0x00000004      /**< bit mask for bit 2         */  
#define BIT_MASK_3                  0x00000008      /**< bit mask for bit 3         */
#define BIT_MASK_4                  0x00000010      /**< bit mask for bit 4         */
#define BIT_MASK_5                  0x00000020      /**< bit mask for bit 5         */
#define BIT_MASK_6                  0x00000040      /**< bit mask for bit 6         */
#define BIT_MASK_7                  0x00000080      /**< bit mask for bit 7         */
#define BIT_MASK_8                  0x00000100      /**< bit mask for bit 8         */
#define BIT_MASK_9                  0x00000200      /**< bit mask for bit 9         */
#define BIT_MASK_10                 0x00000400      /**< bit mask for bit 10        */
#define BIT_MASK_11                 0x00000800      /**< bit mask for bit 11        */
#define BIT_MASK_12                 0x00001000      /**< bit mask for bit 12        */
#define BIT_MASK_13                 0x00002000      /**< bit mask for bit 13        */
#define BIT_MASK_14                 0x00004000      /**< bit mask for bit 14        */
#define BIT_MASK_15                 0x00008000      /**< bit mask for bit 15        */
#define BIT_MASK_16                 0x00010000      /**< bit mask for bit 16        */
#define BIT_MASK_17                 0x00020000      /**< bit mask for bit 17        */
#define BIT_MASK_18                 0x00040000      /**< bit mask for bit 18        */
#define BIT_MASK_19                 0x00080000      /**< bit mask for bit 19        */
#define BIT_MASK_20                 0x00100000      /**< bit mask for bit 20        */
#define BIT_MASK_21                 0x00200000      /**< bit mask for bit 21        */
#define BIT_MASK_22                 0x00400000      /**< bit mask for bit 22        */
#define BIT_MASK_23                 0x00800000      /**< bit mask for bit 23        */
#define BIT_MASK_24                 0x01000000      /**< bit mask for bit 24        */
#define BIT_MASK_25                 0x02000000      /**< bit mask for bit 25        */
#define BIT_MASK_26                 0x04000000      /**< bit mask for bit 26        */
#define BIT_MASK_27                 0x08000000      /**< bit mask for bit 27        */
#define BIT_MASK_28                 0x10000000      /**< bit mask for bit 28        */
#define BIT_MASK_29                 0x20000000      /**< bit mask for bit 29        */
#define BIT_MASK_30                 0x40000000      /**< bit mask for bit 30        */
#define BIT_MASK_31                 0x80000000      /**< bit mask for bit 31        */

#define INV_BIT_MASK_0                  0xFFFFFFFE      /**< Inverted bit mask for bit 0        */
#define INV_BIT_MASK_1                  0xFFFFFFFD      /**< Inverted bit mask for bit 1        */
#define INV_BIT_MASK_2                  0xFFFFFFFB      /**< Inverted bit mask for bit 2        */
#define INV_BIT_MASK_3                  0xFFFFFFF7      /**< Inverted bit mask for bit 3        */
#define INV_BIT_MASK_4                  0xFFFFFFEF      /**< Inverted bit mask for bit 4        */
#define INV_BIT_MASK_5                  0xFFFFFFDF      /**< Inverted bit mask for bit 5        */
#define INV_BIT_MASK_6                  0xFFFFFFBF      /**< Inverted bit mask for bit 6        */
#define INV_BIT_MASK_7                  0xFFFFFF7F      /**< Inverted bit mask for bit 7        */
#define INV_BIT_MASK_8                  0xFFFFFEFF      /**< Inverted bit mask for bit 8        */
#define INV_BIT_MASK_9                  0xFFFFFDFF      /**< Inverted bit mask for bit 9        */
#define INV_BIT_MASK_10                 0xFFFFFBFF      /**< Inverted bit mask for bit 10       */
#define INV_BIT_MASK_11                 0xFFFFF7FF      /**< Inverted bit mask for bit 11       */
#define INV_BIT_MASK_12                 0xFFFFEFFF      /**< Inverted bit mask for bit 12       */
#define INV_BIT_MASK_13                 0xFFFFDFFF      /**< Inverted bit mask for bit 13       */
#define INV_BIT_MASK_14                 0xFFFFBFFF      /**< Inverted bit mask for bit 14       */
#define INV_BIT_MASK_15                 0xFFFF7FFF      /**< Inverted bit mask for bit 15       */
#define INV_BIT_MASK_16                 0xFFFEFFFF      /**< Inverted bit mask for bit 16       */
#define INV_BIT_MASK_17                 0xFFFDFFFF      /**< Inverted bit mask for bit 17       */
#define INV_BIT_MASK_18                 0xFFFBFFFF      /**< Inverted bit mask for bit 18       */
#define INV_BIT_MASK_19                 0xFFF7FFFF      /**< Inverted bit mask for bit 19       */
#define INV_BIT_MASK_20                 0xFFEFFFFF      /**< Inverted bit mask for bit 20       */
#define INV_BIT_MASK_21                 0xFFDFFFFF      /**< Inverted bit mask for bit 21       */
#define INV_BIT_MASK_22                 0xFFBFFFFF      /**< Inverted bit mask for bit 22       */
#define INV_BIT_MASK_23                 0xFF7FFFFF      /**< Inverted bit mask for bit 23       */
#define INV_BIT_MASK_24                 0xFEFFFFFF      /**< Inverted bit mask for bit 24       */
#define INV_BIT_MASK_25                 0xFDFFFFFF      /**< Inverted bit mask for bit 25       */
#define INV_BIT_MASK_26                 0xFBFFFFFF      /**< Inverted bit mask for bit 26       */
#define INV_BIT_MASK_27                 0xF7FFFFFF      /**< Inverted bit mask for bit 27       */
#define INV_BIT_MASK_28                 0xEFFFFFFF      /**< Inverted bit mask for bit 28       */
#define INV_BIT_MASK_29                 0xDFFFFFFF      /**< Inverted bit mask for bit 29       */
#define INV_BIT_MASK_30                 0xBFFFFFFF      /**< Inverted bit mask for bit 30       */
#define INV_BIT_MASK_31                 0x7FFFFFFF      /**< Inverted bit mask for bit 31       */


/** Check if the device is initialised. If not initialized, return error    */
#define CHECK_DEV_INIT(dev)         if(dev != enBooleanTrue){ return enStatusNotConfigured; }
/** Return error if the pointer is null                                     */
#define CHECK_NULL_PTR(ptr)         if(ptr == 0){ return enStatusInvArgs; }
/** Check if the pointer is null                                            */
#define IS_PTR_NULL(ptr)            ((ptr == 0) ? enBooleanTrue : enBooleanFalse)

/** Stringification Macro           */
#define _PF_STRING(str)             #str
#define PF_STRING(str)              _PF_STRING(str)

/** Concatenation Macro             */
#define _PF_CONCAT(X, Y)            X##Y
#define PF_CONCAT(X, Y)             _PF_CONCAT(X, Y)

/** Endianess Macro                 */              
#define PF_LITTLE_ENDIAN            1
#define PF_BIG_ENDIAN               0   

/** 
 * The function checks and returns endianness of the system.
 *
 * \return Endianness of the system.
 */
PFEnEndian pfGetSystemEndian(void);

/**
 * The functions returns a string corresponding to the error code.
 *
 * \param errCode Error code for which string is to returned.
 *
 * \return Pointer to error string.
 */
const PFbyte* pfGetErrorString(PFEnStatus errCode);

///*****************************************************************************///
/* Endian ness macro Defination*/
// #define PF_CO_L_ENDIAN     1234 
// #define PF_CO_B_ENDIAN    4321
// #define PF_CO_ENDIAN_OR   1234

// #if PF_CO_ENDIAN_OR == PF_CO_L_ENDIAN
    // #warning System is Little endian
// #elif PF_CO_ENDIAN_OR == PF_CO_B_ENDIAN
    // #warning System is Big endian
// #else
    // #error endianess not defined
// #endif


// #define IS_BIG_ENDIAN (!(*(unsigned char *)&(uint16_t){1}))

// #ifdef __BYTE_ORDER
    // #error Big
// #else
    // #error Little
// #endif
///*****************************************************************************///

#if (defined(__GNUC__) || defined(__CC_ARM))
    #ifdef PF_BYTE_ORDER
        #if PF_BYTE_ORDER
            #warning LITTLE ENDIAN ARCHITECTURE
            #define pf_htons(x) ((((x) & 0xff) << 8) | (((x) & 0xff00) >> 8))       /**< function for little endian architecture converts the unsigned short integer from host byte order to network byte order. */       
            #define pf_htonl(x) ((((x) & 0xff) << 24) | \
                              (((x) & 0xff00) << 8) | \
                              (((x) & 0xff0000UL) >> 8) | \
                              (((x) & 0xff000000UL) >> 24))                         /**< function for little endian architecture converts the unsigned integer from host byte order to network byte order. */
            #define pf_ntohs(x) pf_htons(x)                                         /**< function for little endian architecture converts the unsigned short integer from network byte order to host byte order. */
            #define pf_ntohl(x) pf_htonl(x)                                         /**< function for little endian architecture converts the unsigned integer from network byte order to host byte order. */
            #define PF_ARCH_LOW_BYTE_FIRST      1                                   /**< defines little endian architecture (least significant byte first). */
            
        #else
            #warning BIG ENDIAN ARCHITECTURE
            #define pf_htons(x) (x)                  /**< function for big endian architecture converts the unsigned short integer from host byte order to network byte order. */       
            #define pf_htonl(x) (x)                  /**< function for big endian architecture converts the unsigned integer from host byte order to network byte order. */
            #define pf_ntohs(x) (x)                  /**< function for big endian architecture converts the unsigned short integer from network byte order to host byte order. */
            #define pf_ntohl(x) (x)                  /**< function for big endian architecture converts the unsigned integer from network byte order to host byte order. */
            #define PF_ARCH_LOW_BYTE_FIRST      0    /**< defines big endian architecture (most significant byte first). */
        #endif  //#if PF_BYTE_ORDER
    #else
        #warning PF_BYTE_ORDER not defined!!!!!
    #endif  //#ifdef PF_BYTE_ORDER
#else
    #error Unsupported compiler! Define htons and htonl!!!
#endif  //#if (defined(__GNUC__) || defined(__CC_ARM))

/**
 * Claim variable as volatile.
 */
#define PF_ACCESS_SAFE(x) (*(volatile typeof(x) *)&(x))
        
#ifndef PF_EOF
#   define    PF_EOF   (-1)             /**< This defines end of file */
#endif


#ifndef PF_CHECK_TYPE_EQUAL
#   define PF_CHECK_TYPE_EQUAL(var1, var2)  \
        do { (void)(&(var1) == &(var2)); } while(0)
#endif

/** @}  */