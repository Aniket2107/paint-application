/**
 * \file        prime_types.h
 * \brief       Standard Prime Framework types for FW development
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 * 
 * \author Alexey Gerenkov <alexey.gerenkov@phi-robotics.com>
 * Review status: NO
 *
 */
#ifndef __PRIME_TYPES_H__
#define __PRIME_TYPES_H__

#include <stddef.h>

/**
 *  \ingroup     core
 *  \defgroup    PF_COMMON_TYPES    Prime Common Types
 *  @{
 *  
 *  \brief      Prime DataTypes API
 *  \details    
 */ 

/** Pointer to any constant data */
typedef const void*     PFpfxgeneric;
/** Pointer to any data */
typedef void*           PFpgeneric;

/* For C99 library, just include proper header, it will already have needed types */
#if __STDC_VERSION__ == 199901L
#   include <stdint.h>
//#else
#endif
/** Architecture independent signed 8-bit integer type */
typedef signed char         PFint8;
/** Architecture independent unsigned 8-bit integer type */
typedef unsigned char       PFuint8;
/** Architecture independent unsigned 16-bit integer type */
typedef unsigned short      PFuint16;
/** Architecture independent signed 16-bit integer type */
typedef short               PFint16;
/** Architecture independent unsigned 32-bit integer type */
typedef unsigned long       PFuint32;
/** Architecture independent signed 32-bit integer type */
typedef long                PFint32;
/** Architecture independent signed 64-bit integer type */
typedef long long           PFint64;
/** Architecture independent unsigned 64-bit integer type */
typedef unsigned long long  PFuint64;
//#endif

/** Architecture independent signed 8-bit integer type */
typedef signed char         PFchar;
/** Architecture independent unsigned 8-bit integer type */
typedef unsigned char       PFbyte;
/** Architecture independent signed 16-bit integer type */
typedef short               PFsword;
/** Architecture independent unsigned 16-bit integer type */
typedef unsigned short      PFword;
/** Architecture independent signed 32-bit integer type */
typedef long                PFsdword;
/** Architecture independent unsigned 32-bit integer type */
typedef unsigned long       PFdword;
/** Architecture independent signed 64-bit integer type */
typedef long long           PFsqword;
/** Architecture independent unsigned 64-bit integer type */
typedef unsigned long long  PFqword;

/** Pointer to architecture independent unsigned 8-bit integer type */
typedef PFuint8*        PFpuint8;
/** Architecture independent unsigned 8-bit integer constant type */
typedef const PFuint8   PFfxuint8;
/** Constant pointer to architecture independent unsigned 8-bit integer type */
typedef const PFpuint8      PFfxpuint8;
/** Pointer to architecture independent unsigned 8-bit integer constant type */
typedef const PFuint8*      PFpfxuint8;

/** Pointer to architecture independent signed 8-bit integer type */
typedef PFint8*             PFpint8;
/** Architecture independent signed 8-bit integer constant type */
typedef const PFint8    PFfxint8;
/** Pointer to architecture independent signed 8-bit integer constant type */
typedef const PFint8*       PFpfxint8;

/** Architecture dependent signed integer type */
typedef int                 PFint;
/** Pointer to architecture dependent signed integer type */
typedef PFint*              PFpint;
/** Architecture dependent constant signed integer type */
typedef const PFint         PFfxint;
/** Pointer to architecture dependent signed integer constant type */
typedef const PFint*        PFpfxint;

/** Architecture dependent unsigned integer type */
typedef unsigned int        PFuint;
/** Pointer to architecture dependent unsigned integer type */
typedef PFuint*             PFpuint;
/** Architecture dependent constant unsigned integer type */
typedef const PFuint    PFfxuint;
/** Pointer to architecture dependent unsigned integer constant type */
typedef const PFuint*       PFpfxuint;

/** Pointer to architecture independent unsigned 16-bit integer type */
typedef PFuint16*       PFpuint16;
/** Architecture independent unsigned 16-bit integer constant type */
typedef const PFuint16      PFfxuint16;
/** Pointer to architecture independent unsigned 16-bit integer constant value */
typedef const PFuint16*     PFpfxuint16;

/** Pointer to architecture independent signed 16-bit integer type */
typedef PFint16*        PFpint16;
/** Architecture independent signed 16-bit integer constant type */
typedef const PFint16   PFfxint16;
/** Constant pointer to architecture independent signed 16-bit integer value */
typedef const PFpint16      PFfxpint16;

/** Pointer to architecture independent unsigned 32-bit integer type */
typedef PFuint32*       PFpuint32;
/** Architecture independent unsigned 32-bit integer constant type */
typedef const PFuint32      PFfxuint32;
/** Constant pointer to architecture independent unsigned 32-bit integer value */
typedef const PFpuint32     PFfxpuint32;

/** Pointer to architecture independent signed 32-bit integer type */
typedef PFint32*        PFpint32;
/** Architecture independent signed 32-bit integer constant type */
typedef const PFint32   PFfxint32;
/** Constant pointer to architecture independent signed 32-bit integer value */
typedef const PFpint32      PFfxpint32;

/** Pointer to architecture independent signed 64-bit integer type */
typedef PFint64*        PFpint64;
/** Architecture independent signed 64-bit integer constant type */
typedef const PFint64   PFfxint64;
/** Constant pointer to architecture independent signed 64-bit integer value */
typedef const PFpint64  PFfxpint64;

/** Pointer to architecture independent unsigned 64-bit integer type */
typedef PFuint64*       PFpuint64;
/** Architecture independent unsigned 64-bit integer constant type */
typedef const PFuint64      PFfxuint64;
/** Constant pointer to architecture independent unsigned 64-bit integer value */
typedef const PFpuint64     PFfxpuint64;

/** Type representing architecture independent unsigned 8-bit integer register value */
typedef volatile PFuint8    PFreg8;
/** Type representing architecture independent unsigned 16-bit integer register value */
typedef volatile PFuint16   PFreg16;
/** Type representing architecture independent unsigned 32-bit integer register value */
typedef volatile PFuint32   PFreg32;

/** Architecture independent normal precision floating point type */
typedef float               PFfloat;
/** Pointer to architecture independent normal precision floating point type */
typedef PFfloat*            PFpfloat;
/** Architecture independent normal precision floating point constant type */
typedef const PFfloat       PFfxfloat;
/** Constant pointer to architecture independent normal precision floating point value type */
typedef const PFpfloat      PFfxpfloat;

/** Architecture independent double precision floating point type */
typedef double              PFdouble;
/** Pointer to architecture independent double precision floating point type */
typedef PFdouble*           PFpdouble;
/** Architecture independent double precision floating point constant type */
typedef const PFdouble      PFfxdouble;
/** Constant pointer to architecture independent double precision floating point value type */
typedef const PFpdouble     PFfxpdouble;

/** The type representing system time */
typedef unsigned long       PFtime;

/** Pointer to the value representing system time type */
typedef PFpuint32           PFptime;
/** The type representing system time constant */
typedef PFfxuint32          PFfxtime;
/** Constant pointer to the value representing system time type */
typedef PFfxpuint32         PFfxptime;

/** The type representing signal bit */
typedef PFuint8             PFsignalBit;
/** The type representing signal mask */
typedef PFuint8             PFsignalMask;

/**
 * Signal structure
 */
typedef struct phiSignal_s
{
    PFsignalMask    uWaitMask;    /**< Signals the task is waiting for */
    PFsignalMask    uRecvMask;    /**< Received signals */
} PFphiSignal;

/** The type representing the size in memory */
typedef size_t              PFsize;
/** The type representing pointer to the size in memory */
typedef size_t*             PFpsize;
/** The type representing size in memory constant */
typedef const size_t        PFfxsize;
/** The type representing pointer to the size in memory constant */
typedef const size_t*       PFpfxsize;

/** The type representing the helper for accessing two byte entities in memory */
typedef union
{
    /** Per-byte access field */
    PFuint8  collection[2];
    /** Access as to two byte number */
    PFuint16 uData;
} PFtwoByte, *PFptwoByte;
/** The type representing helper for accessing constant two byte entities */
typedef const PFtwoByte     PFfxtwoByte;
/** The type representing pointer to helper for accessing constant two byte entities */
typedef const PFptwoByte    PFfxptwoByte;

/** Helper for accessing four byte entities in memory */
typedef union
{
    /** Per-byte access field */
    PFuint8 collection[4];
    /** Access as to four byte number */
    PFuint32 uData;
} PFfourByte, *PFpfourByte;
/** The type representing helper for accessing constant four byte entities */
typedef const PFfourByte    PFfxfourByte;
/** The type representing pointer to helper for accessing constant four byte entities */
typedef const PFpfourByte PFfxpfourByte;

/** The type representing endieness of the system   */
typedef enum
{
    enEndianLittle = 0,         /**< Little endian system       */
    enEndianBig                 /**< Big endian system          */
}PFEnEndian;

/** The type representing status codes which indicate
 * to user the result of requested operation. */
typedef enum
{
    enStatusSuccess = 0,        /**< success                                    */
    enStatusError,              /**< generic error                              */
    enStatusInvArgs,            /**< invalid arguments                          */
    enStatusInvState,           /**< invalid state                              */
    enStatusNotSupported,       /**< requested functionality is not supported   */
    enStatusNotConfigured,      /**< device is not configured                   */
    enStatusBusy,               /**< requested resource is busy                 */
    enStatusNoMem,              /**< no enough memory                           */
    enStatusTimeout,            /**< operation has timed out                    */
    enStatusConfigConflict,     /**< configuration conflict is detected         */
    enStatusAborted,            /**< operation aborted                          */
    enStatusNotExist,           /**< requested resource does not exist          */
    enStatusUnknown,            /**< any error not mentioned in this list       */
    enStatusBoardErr,           /**< board is in error state        */
    /* File system codes */
    enStatusDiskError,          /**< error i ndisk operation                    */
    enStatusInternalError,      /**< fileystem internal error                   */
    enStatusDiskNotReady,       /**< disk is not ready                          */
    enStatusNoFile,             /**< file not found                             */
    enStatusNoPath,             /**< path not found                             */
    enStatusInvalidName,        /**< invalid name                               */
    enStatusAccessDenied,       /**< access denied                              */
    enStatusFileAlreadyExist,   /**< file already exist                         */
    enStatusInvalidObject,      /**< invalid object                             */
    enStatusWriteProtected,     /**< disk is write protected                    */
    enStatusInvalidDrive,       /**< invalid drive number                       */
    enStatusNotEnabled,         /**< functionality not enabled                  */
    enStatusNoFilesystem,       /**< no filesystem found on the device          */
    enStatusMkfsAborted,        /**< MKFS operation aborted                     */
    /* Network codes */
    enStatusNetNoRouteFound,    /**< network route no found */
    enStatusCrcError,           /**< CRC Error occurred */
    enStatusNetNoService,       /**< no network service found */
    enStatusNetDgramRejected,   /**< datagram rejected by peer */
} PFEnStatus;
/** The type representing constant status code */
typedef const PFEnStatus PFFXENStatus;

/** The type representing boolean value */
typedef enum
{
    enBooleanFalse  = 0, /**< false value */
    enBooleanTrue   = 1  /**< true value */
} PFEnBoolean;
/** The type representing pointer to boolean value */
typedef const PFEnBoolean*  PPFEnBoolean;
/** The type representing constant boolean value */
typedef const PFEnBoolean   PFFXEnBoolean;

/** Types defined to access the peripheral registers in different manner (32 bit, 16 bit, 8 bit)    */
typedef PFreg8*             PFpreg8;
typedef PFreg16*            PFpreg16;
typedef PFreg32*            PFpreg32;

/** Macros defined for defining register read/write access                                          */
#define _RW                 volatile
#define _R                  volatile const
#define _W                  volatile

/** The type representing function pointer for callback which has void argument and returns void    */
typedef void (*PFcallback)(void);

/** NULL pointer */
#define PF_NULL_PTR     ((PFpgeneric)0)

/** NULL value  */
#define PF_NULL         0


/**@}*/


#endif  // __PRIME_TYPES_H__
