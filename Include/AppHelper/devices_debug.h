/**
 * \file    devices_debug.h
 * \brief Devices Debuggiing definitions.
 * \copyright Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: NO
 *
 */
#pragma once

#if (LOP_DEBUG_BUILD == 1)
    #define DEVICE_DEBUG    1
    #warning DEVICE_DEBUG 
#endif
/**
 * \ingroup devices
 * \defgroup DEVICE_DEBUG DEBUG
 * @{
 */
// Device driver debug macros

#define A3977_DEBUG                 DEVICE_DEBUG    /**< A3977 debug macros */
#define L6470_DEBUG                 DEVICE_DEBUG    /**< L6470 debug macros */
#define CHEETAH_DEBUG               DEVICE_DEBUG    /**< CHEETAH debug macros */
#define LS7366_DEBUG                DEVICE_DEBUG    /**< LS7366 debug macros */
#define GP2Y0A02_DEBUG              DEVICE_DEBUG    /**< GP2Y0A02 debug macros */
#define GP2Y0A21_DEBUG              DEVICE_DEBUG    /**< GP2Y0A21 debug macros */
#define GP2Y0A710_DEBUG             DEVICE_DEBUG    /**< GP2Y0A710 debug macros */
#define GPS_DEBUG                   DEVICE_DEBUG    /**< GPS debug macros */
#define ULTRASONIC_DEBUG            DEVICE_DEBUG    /**< ULTRASONIC debug macros */
#define VCNL4000_DEBUG              DEVICE_DEBUG    /**< VCNL4000 debug macros */
#define MPU6050_DEBUG               DEVICE_DEBUG    /**< MPU6050 debug macros */
#define MMA7660_DEBUG               DEVICE_DEBUG    /**< MMA7660 debug macros */
#define LSM303_DEBUG                DEVICE_DEBUG    /**< LSM303 debug macros */
#define BLUETOOTH_DEBUG             DEVICE_DEBUG    /**< BLUETOOTH debug macros */
#define BUZZER_DEBUG                DEVICE_DEBUG    /**< BUZZER debug macros */
#define BITMAP_DEBUG                DEVICE_DEBUG    /**< BITMAP debug macros */
#define TCS230_DEBUG                DEVICE_DEBUG    /**< TCS230 debug macros */
#define MCP2515_DEBUG               DEVICE_DEBUG    /**< MCP2515 debug macros */
#define SGTL5000_DEBUG              DEVICE_DEBUG    /**< SGTL5000 debug macros */
#define NRF905_DEBUG                DEVICE_DEBUG    /**< NRF905 debug macros */
#define TOUCH_DEBUG                 DEVICE_DEBUG    /**< TOUCH debug macros */
#define KEYPAD_DEBUG                DEVICE_DEBUG    /**< Keypad debug macros */
#define FS_DEBUG                    DEVICE_DEBUG    /**< FS debug macros */
#define GFX_DEBUG                   DEVICE_DEBUG    /**< GFX debug macros */
#define SERVO_DEBUG                 DEVICE_DEBUG    /**< SERVO debug macros */
#define TCS230COLOURSENSOR_DEBUG    DEVICE_DEBUG    /**< TCS230COLOURSENSOR debug macros */