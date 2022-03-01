/**
 *  \file       gameEngine.h
 *  \brief      Header file for Phi Game Engine.
 *  Include this file in your application program to use services provided
 *  by the Game Engine.
 *  
 *  Phi Game Engine is a small-scale Game Engine written in C programming language 
 *  for a Bare Metal system.
 *  It can be be used to build 2D games with less graphics effects.
 *  It uses Prime Framework, a low-level hardware abstraction layer
 *  to interact with the microcontroller.
 *  It uses libraries written over Prime Framework to interact with
 *  hardware devices like LCD controller, touch panel, accelerometer etc.
 *  
 *  Components of Phi Game Engine:
 *  1. Object Manager
 *  2. Input Manager
 *  3. Resource Manager
 *  4. Physics Manager
 *  5. Graphics Manager
 *  6. Renderer Manager
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

#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#include "prime_framework.h"

//Game Engine
#include "gui.h"
#include "object.h"
#include "renderer.h"
#include "gameGraphics.h"
#include "resource.h"

/** return status check        */
#define CHECK_SUCCESS_STATUS    if(status != enStatusSuccess)        return enStatusError;

/**
 * This function is used to initialize the Game Engine.
 * It initializes all components of the Engine.
 * Call this function in your application program before using the services provided
 * by the Game Engine.
 *
 * \return return status:
 *  enStatusSucess  - Game Engine successfully initialized
 *  enStatusInvArgs - Error in the configuration settings
 *  enStatusError   - Error in initializing Game Engine
 */
PFEnStatus gameEngineInit(void);

#endif /* _GAME_ENGINE_H_ */
