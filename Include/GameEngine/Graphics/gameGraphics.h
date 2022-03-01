/**
 *  \file       gameGraphics.h
 *  \brief      Graphics Manager for Phi Game Engine
 *  Graphics manager in the Game Engine is responsible for handling graphics in a Game.
 *  It creates graphics according to different shapes of an object such as circle or rectangle.
 *  For example, to create a motion effect for an object and move the ball along the X axis, Graphics manager will perform the following steps:
 *    1. Draw a circle at position (X, Y) on the LCD screen.
 *    2. Draw a circle of same radius with background color at (X, Y).
 *    3. Draw the circle at new position (X+1, Y).

 *  \copyright  Copyright (c) 2016 <br> PhiRobotics Research Pvt Ltd
 *  
 *  \par
 *   For licensing information, see the file 'LICENSE' in the root folder of
 *   this software module.
 * 
 *  Review status: NO
 *
 */
 
#ifndef __GAME_GRAPHICS_H__
#define __GAME_GRAPHICS_H__

/**
 * This function is used to initialize the Graphics Manager. This function
 * should be called in the beginning before using the services
 * provided by the Graphics Manager.
 * gameEngineInit() function will call this function to initialize the Graphics Manager.
 *
 * \return return status:
 *       enStatusSucess - Graphics Manager is initialized.
 */
PFEnStatus gameGraphicsInit(void);

/**
 * This function is used to draw all the objects one by one in a loop 
 * according to the attributes in their respective configuration structure.
 * Call this function in the begining of the Game to draw all the objects.
 * It issues the commands with Renderer Manager for actual drawing on the LCD screen.
 * Call renderFrame() provided by Renderer Manager to trigger the renderer to draw the new Frame.
 *
 * \return return status:
 *       enStatusSuccess - If all the commands are successfully registered with 
 *                        the renderer.
 *       enStatusError   - If there is an error in registering the commands
 *                         with renderer.
 */
PFEnStatus drawAllObjects(void);

/**
 * This function is used to redraw an object specified by the Id according to the attributes in their respective configuration structure
 * in the next Frame. This function will register a command to the Renderer Manager to display an object on the LCD screen.
 * Frame refers to whatever we see on LCD screen at any given time. On the basis of time, we can have a current frame and a next frame.
 * Current frame is the frame that is currently displayed on the LCD screen. Next frame is the frame to be displayed next.
 * 
 * Let’s take an example to understand current frame and next frame:
 * Consider a scenario in which there is 1 brick, whose position(x, y) is fixed throughout the game (static object) and 1 ball
 * which is moving randomly (dynamic object). Now, after the creation of all the objects using the createObject() function,
 * call the drawAllObjects() function to draw all the objects. This function will register the commands to the Renderer to draw the objects.
 * Then, call the renderFrame() function to display the objects at their initial position on the LCD screen.
 * Now, in the next frame the position(x, y) of the brick is fixed, but the position of the ball has changed to (x+1, y+1).
 * To draw the next frame, call the updateObject() function with the ball ID as the argument followed by a call to the renderFrame() function.
 * Hence, in the new frame, the brick is still at its original position but the ball has been redrawn to a new position.
 * Continue this process throughout the game to create a motion effect for the ball.
 *
 * \param id Id of the object to draw in the next frame
 * \return return status:
 *       enStatusSuccess - If all the commands are successfully registered with 
 *                         the renderer.
 *       enStatusError   - If there is an error in registering the commands
 *                         with renderer.
 */
PFEnStatus updateObject(PFbyte id);

/**
 * This function is used to set the background color. Then, call renderFrame() function provided by Renderer Manager to trigger
 * the Renderer to set the background color.
 *
 * \param color background color. There are some commonly used colors defined
 *        in the graphics header file(graphics.h). You can also set a custom color(16 bit RGB format).
 *
 * \return return status
 */
PFEnStatus setBackgroundColor(PFword color);

/**
 * This function is used to get the current background color(16 bit RGB format).
 *
 * \return background color
 */
PFword getBackgoundColor(void);

#endif
