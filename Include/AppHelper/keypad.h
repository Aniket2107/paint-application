/**
 *
 *                              Copyright (c) 2014
 *                         PhiRobotics Research Pvt Ltd
 *
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 *
 * \brief Prime Framework Keypad Driver
 *
 * Review status: NO
 *
 */
 
#pragma once
/**
 * \defgroup KEYPAD_API KEYPAD API
 * @{
 */

/** Number of keys available on keypad*/
#define MAX_KEY_COUNT    5 

/** Values for keyCode from keypadGetKeyCode function on key press. */
#define KEY_1            0x00000001
#define KEY_2            0x00000002
#define KEY_3            0x00000004
#define KEY_4            0x00000008
#define KEY_5            0x00000010
 
/**
 * \brief This function intializes key or keys
 *
 * \param keyConfig location pointer to load gpio for key configuration
 * \param keyCount number of keys to initialize
 * \return returns status of key initialize
 */
PFEnStatus keypadKeyOpen(PFGpioPortPin* keyConfig, PFbyte keyCount);

/**
 * \brief This function close a key
 *
 * \param keyCount key to close
 * \return returns status of key close
 */
PFEnStatus keypadKeyClose(PFbyte keyNumber);

/**
 * \brief This function copies key number into pointer on true value
 *
 * \param keyCode location pointer to store key press value. On key press will contain single KEY_# or ORing
 *  of values if multiple key press at a time.
 * \return returns true or false value
 */
PFEnBoolean keypadGetKeyCode(PFdword* keyCode);

/**
 * \brief This function checks if the specified key number is pressed or not
 *
 * \param keyNum Key number to check (range 1 to MAX_KEY_COUNT)
 * \return returns true or false value
 */
PFEnBoolean keypadIsKeyPressed(PFbyte keyNum);

/** @} */
