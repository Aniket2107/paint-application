/**
 *  \file       appInit.h
 *  \brief      Header file for peripheral initialization.
 *  This file includes peripheral header files required in the project.
 *  Include this file in the application program in the beginning. This file provides a DEBUG_WRITE MACRO which
 *  can be used to print debug messages over UART channel.
 *  Set PRIME_DEBUG MACRO equal to 1 in the project's makefile to use the DEBUG_WRITE MACRO.
 *
 */

#pragma once

#include "prime_framework.h"
#include "prime_sysClk.h"
#include "prime_gpio.h"
#include "prime_tick.h"
#include "prime_uart0.h"
#include "prime_rit.h"
#include "prime_timer0.h"
#include "prime_spi0.h"
#include "prime_i2c0.h"
#include "prime_eint1.h"
#include "graphics.h"
#include "touch.h"
#include "keypad.h"
#include "mma7660.h"
#include "buzzer.h"
#include "diskIo.h"
#include "mmc.h"
#include "fatFs.h"

#include "eduarmBoardDefs.h"
#include "eduarmBoardConfig.h"

#ifdef PRIME_DEBUG
	#define DEBUG_WRITE(x) pfUart0WriteString(x) 
#else
	#define DEBUG_WRITE(x)
#endif

/** 
  * \brief This function initializes all the peripherals needed in the application.
  * 
  * \param none 
  * \return none
  */
void appInit(void);
