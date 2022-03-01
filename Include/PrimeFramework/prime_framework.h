/**
 * \file        prime_framework.h
 * \brief       Prime Framework Base Header File.
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 *
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: No.
 *
 */
#pragma once

#ifdef MCU_CHIP_lpc1768
    #warning LPC17XX MCU FAMILY
    #include "prime_lpc17xx_arch.h"
#elif defined (MCU_CHIP_atmega2560)
    #warning AVR_ATMEGA MCU FAMILY
    #include "prime_atmega2560_arch.h"
#elif defined (MCU_CHIP_at90can128)
    #warning AVR_AT90 MCU FAMILY
    #include "prime_at90can128_arch.h"
#endif


#include "prime_core.h"
#include <stdio.h>
#include <stdlib.h>
#include "prime_config.h"
