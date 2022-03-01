 /**
 *  \file mma7660.h
 *  \brief MMA7660 Accelerometer device driver.
 *  Accelerometer device is used to measure acceleration(rate of change of velocity).
 *  The accelerometer is integrated on the EduARM development board which communicates via
 *  I2C protocol.
 *  
 *  When the EduARM board is placed on it's back with LCD screen on top, there is +1g force(earth's gravity) acting on it.
 *  The values of X, Y, and Z axis can be read using the XOUT, YOUT and ZOUT register respectively.
 *  The range of the values is from +31 to -32(+1.5g to -1.5g).
 *  0 value is equivalent to 0.0g force. g force increases as the values moves in the positive direction and the g force
 *  decreases as values moves in the negative direction.
 *  REGISTER VALUE          G FORCE             
 *     31                   +1.45g
 *     22                   +1.03g
 *     0                     0g
 *    -22                   -1.03g
 *    -32                   -1.50g
 *  Refer to data sheet of the MMA7660 device for the table to map register values to appropriate g force values.
 *
 *  The accelerometer device on the EduARM board can be read as follows:
 *  POSITION                   X-Axis        Y-Axis         Z-Axis
 *   Front                       0             0              +1g
 *   Back                        0             0              -1g
 *   Portrait Up                -1g            0               0
 *   Portrait Down              +1g            0               0
 *   Landscape left              0            +1g              0
 *   Landscape right             0            -1g              0
 * 
 *  To use the driver functions call mma7660Open() with the appropriate configuration values in the beginning.
 *  Then, use read functions to get X,Y and Z Axis data of the accelerometer.
 *  Currently, this driver is not tested in Interrupt mode, It works fine in the Polling mode.
 *
 *  \copyright  Copyright (c) 2016 <br> PhiRobotics Research Pvt Ltd
 *
 *  \par
 *   For licensing information, see the file 'LICENSE' in the root folder of
 *   this software module.
 *
 *  Review status: NO
 *
 */
#ifndef _MMA7660_H_
#define _MMA7660_H_

/**  Internal register address            */
#define MMA7660_ADDR             0x98
#define MMA7660_XOUT             0x00
#define MMA7660_YOUT            0x01
#define MMA7660_ZOUT            0x02
#define MMA7660_TILT            0x03
#define MMA7660_SRST            0x04
#define MMA7660_SPCNT           0x05
#define MMA7660_INTSU           0x06
#define MMA7660_MODE            0x07
#define MMA7660_SR              0x08
#define MMA7660_PDET            0x09
#define MMA7660_PD              0x0A

/**  Interrupt Enable address    */
#define FB_INTERRUPT            0x01    /** Front/Back position change interrupt                                    */
#define PL_INTERRUPT            0x02    /** Up/Down/Right/Left position change interrupt                            */
#define PD_INTERRUPT            0x04    /** Tap detection interrupt                                                 */
#define G_INTERRUPT             0x10    /** Interrupt after every measurement                                       */
#define SH_X_INTERRUPT          0x80    /**    Shake detected on the X-axis interrupt and set bit in TILT register  */
#define SH_Y_INTERRUPT          0x40    /**    Shake detected on the Y-axis interrupt and set bit in TILT register  */
#define SH_Z_INTERRUPT          0x20    /**    Shake detected on the Z-axis interrupt and set bit in TILT register  */

/** \brief Enumeration for the sample rate selection   */
typedef enum
{
    en120SamplesPerSecond = 0,
    en64SamplesPerSecond,
    en32SamplesPerSecond,
    en16SamplesPerSecond,
    en8SamplesPerSecond,
    en4SamplesPerSecond,
    en2SamplesPerSecond,
    en1SamplesPerSecond,
}EnSampleRate;

/** \brief Data structure to store accelerometer data       */
typedef struct
{
    EnSampleRate sampleRate;     /**Active mode sample rate of the device     */
    PFEnStatus (*pI2cWrite)(PFbyte* data, PFEnBoolean master, PFbyte slaveAddr, PFEnBoolean busRelease, PFdword size);                        /** Function pointer to i2cWrite function    */
    PFEnStatus (*pI2cRead)(PFbyte* data, PFEnBoolean master, PFbyte slaveAddr, PFEnBoolean busRelease, PFdword size, PFdword* readBytes);     /** Function pointer to i2cRead function    */
    PFbyte interruptStatus;        /** Pass the above define MACROS to generate an interrupt (OR more than 1 interrupts for multiple interrupts)    */
}CfgMma7660;

/** pointer to CfgMma7660 structure            */
typedef CfgMma7660* pCfgMma7660;

/**
 * \brief This function is used to initialize the MMA7660 accelerometer sensor.
 *
 * \param config pointer to MMA7660 config structure to initialize the MMA7660 sensor
 *
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully initialized
 * enStatusInvArgs - Error in the configuration settings
 *
 */
PFEnStatus mma7660Open(pCfgMma7660 config);

/**
 * \brief This function is used to close the MMA7660 sensor.
 *
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully closed
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660Close(void);

/**
 * \brief This function is used to read g-force on the X-Axis(XOUT register).
 * The range of the values is from +31 to -32. 
 *
 * \param accX 8-bit signed value for X-axis data.
 * 
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully read
 * enStatusError - Error in reading the device
 * enStatusInvArgs - Error in arguments
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660ReadX(PFchar* accX);

/**
 * \brief This function is used to read g-force on the Y-Axis(YOUT register).
 * The range of the values is from +31 to -32. 
 *
 * \param accY 8-bit signed value for Y-axis data.
 * 
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully read
 * enStatusError - Error in reading the device
 * enStatusInvArgs - Error in arguments
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660ReadY(PFchar* accY);

/**
 * \brief This function is used to read g-force on the Z-Axis(ZOUT register).
 * The range of the values is from +31 to -32.
 *
 * \param accZ 8-bit signed value for Z-axis data.
 * 
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully read
 * enStatusError - Error in reading the device
 * enStatusInvArgs - Error in arguments
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660ReadZ(PFchar* accZ);

/**
 * \brief This function is used to read g-force on X,Y and Z axis.
 * The range of the values is from +31 to -32.
 *
 * \param accX - 8-bit signed value for X-axis data.
 * \param accY - 8-bit signed value for Y-axis data.
 * \param accZ - 8-bit signed value for Z-axis data.
 * 
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully read
 * enStatusError - Error in reading the device
 * enStatusInvArgs - Error in arguments
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660ReadXYZ(PFchar* accX, PFchar* accY, PFchar* accZ);

/**
 * \brief This function is used to read tilt status of the device.
 *
 * \param backFront - backFront status of the device
 *                    0 - Unknown position
 *                    1 - Front: Device is lying on its front
 *                    2 - Back: Device is lying on its back
 * \param leftRight - Orientation of the device
 *                    0 - Unknown Orientation
 *                    1 - Left: Device is in landscape mode to the left
 *                    2 - Right: Device is in landscape mode to the right
 *                    5 - Down: Device is in Portrait mode in down orientation
 *                    6 - Up: Device is in Portrait mode in up orientation
 * 
 * \return return status:
 * enStatusSuccess - MMA7660 driver successfully read
 * enStatusError - Error in reading the device
 * enStatusInvArgs - Error in arguments
 * enStatusNotConfigured - MMA7660 driver not initialized
 *
 */
PFEnStatus mma7660ReadTilt(PFchar* backFront, PFchar* leftRight);

/**
 * \brief This function is used to read the shake status of the device.
 * It tells the shake status on X,Y and Z axis. It is enabled by interruptStatus field in the config structure.
 * Pass SH_X_INTERRUPT, SH_Y_INTERRUPT, SH_Z_INTERRUPT in interruptStatus field to enable shake detection.
 * OR more than 1 values to enable shake on multiple axis.
 *
 * \return return value:
 * enBooleanFalse - device is not experiencing a shake
 * enStatusTrue - device has experienced a shake
 *
 */
PFEnBoolean mma7660ReadShakeStatus(void);

#endif
