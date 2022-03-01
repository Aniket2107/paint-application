/**
 *  \file       renderer.h
 *  \brief      Renderer Manager for Phi Game Engine
 *  Rendering is the final process of displaying the actual image or animation
 *  on the LCD screen. Renderer Manager interacts with the LCD controller to render graphics on the
 *  LCD screen.
 *  It uses hardware specific graphics library to draw graphics on the LCD screen.
 *  Some of the hardware specific(native) graphics library functions are:
 *      gfxDrawPixel()
 *      gfxReadPixel()
 *      gfxDrawCircle()
 *  
 *  Graphics Manager registers commands with Renderer Manager for actual drawing of graphics on the screen.
 *  Renderer Manager stores the commands issued by the Graphics Manager in an array.
 *  After updating all the objects, application program trigger the Renderer using
 *  renderFrame() function. Then, Renderer reads that array and call native graphics library functions
 *  to draw graphics on the LCD screen.
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

#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "gameGraphics.h"

/** EduARM LCD specification MACROS. */
#define LCD_TOP_LEFT_X                0            //LCD Top Left X Coordinate
#define LCD_TOP_LEFT_Y                0            //LCD Top Left Y Coordinate
#define LCD_BOTTOM_RIGHT_X            239            //LCD Bottom Right X Coordinate
#define LCD_BOTTOM_RIGHT_Y            319            //LCD Bottom Right Y Coordinate

/**    Enumeration for the command number to be issued to Renderer       
 *  This Union is used by the Engine and the user has nothing to do with it.    */
typedef enum
{
    enDrawLine,
    enDrawCircle,
    enDrawSolidCircle,
    enDrawRectangle,
    enDrawSolidRectangle,
    enDrawTriangle,
    enDrawImage,
    enFillRGB,
    enDrawString,
    enFillArea
}EnGfxWrapper;

/** Maximum number of commands supported by Renderer Manager for 1 Frame     */
#define RENDERER_COMMAND_INSTANCES        20

/**
 * This function is used to initialize the Renderer Manager. This function
 * should be called in the beginning before using the services
 * provided by the Renderer Manager.
 * gameEngineInit() function will call this function to initialize the Renderer Manager.
 *
 * \return return status:
 *       enStatusSucess - Renderer Manager is initialized.
 *       enStatusError  - Error in initializing Renderer Manager
 */
PFEnStatus rendererInit(void);

/**
 * \brief This function is called by the application program to trigger the Renderer after
 * updating the Frame.
 *
*/ 
void renderFrame(void);    

/**
 * \brief This function is used to check if the last frame is rendered or not.
 * This function is called by the application program before updating objects for the next Frame 
 * using updateObject() function.
 * \note For example: To update an object with object1 Id.
 *       while(1)
 *       {
 *          if(lastFrameRendered() == enBooleanTrue)
 *          {
 *              updateObject(object1);
 *              break;
 *          }
 *          else
 *              continue;
 *       }
 * \return return value:
    enBooleanTrue  - last Frame displayed on LCD screen
    enBooleanFalse - last Frame not yet displayed on LCD screen
*/
PFEnBoolean lastFrameRendered(void);

#endif /* RENDERER_H_ */
