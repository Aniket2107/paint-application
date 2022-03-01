/**
 *  \file    gui.h
 *  \brief    GUI Library for Phi Game Engine.
 *  \copyright Copyright (c) 2015 <br> PhiRobotics Research Pvt Ltd
 *    
 *  GUI library contains 4 type of elements -> Window, Canvas, Widget, PopUp.
 *  config structure of each element -> WindowCfg, CanvasCfg, WidgetCfg.
 *  There is 1 common structure -> commAttributes which is included in all of the above structures.
 *  A Window is the starting point of a GUI application. It is the top level window which
 *  contains graphical elements such as Canvas and Widgets. There can be many Windows in an application.
 *  Canvas is the drawing area of a Window in which we can draw something or display some text.
 *  Widgets (or button) allows the user to interact with the application. It is a simple way
 *  to trigger an event.
 *  We can assign a handler (callback function) to a Canvas and Widget, 
 *  so if there is a touch event in it’s region, corresponding handler will be executed.
 *  Widget and Canvas are linked to a Window.
 *
 *  PopUp is used to display notification messages.
 *
 *  \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 * 
 * Review status: NO
 */

#ifndef _GUI_H_
#define _GUI_H_
 
#include "graphics.h"
#include "gameEngine.h"

/** \brief Structure for a Coordinate(x,y) on LCD screen          */
typedef struct
{
    PFword xValue;
    PFword yValue;
}Coordinate;

/** \brief Structure for the Dimensions of window          */
typedef struct
{
    PFword width;
    PFword height;
}Dimension;

 /** GUI configuration MACROS */
#define MAX_WINDOWS                 10       /** Maximum no. of Windows in an application    */
#define MAX_CANVAS_PER_WINDOW       10       /** Maximum no. of Canvas in  a Window          */
#define MAX_WIDGETS_PER_WINDOW      15      /** Maximum no. of Widgets in a Window          */
#define MAX_NO_OF_POP_UPS           5       /** Maximum no. of PopUps                       */

#define READ_BG_BUFFER_SIZE         3000    /** Size of the PFword type buffer to store pixel data   */

typedef struct commAttributes commAttributes;
typedef struct WindowCfg WindowCfg;
typedef struct CanvasCfg CanvasCfg;
typedef struct WidgetCfg WidgetCfg;
typedef struct PopUpCfg PopUpCfg;

 /** 
 *  Structure to define common properties in a Window, Canvas and Widget.
 *  This structure is embedded in the Config structures of the Window, Canvas and Widget.
 */
struct commAttributes
{
    char* name;                     /** Name of a Window, Canvas or a Widget                 */
    Coordinate topLeft;             /** Top Left Coordinate of a Window, Canvas or a Widget     */
    Dimension size;                 /** Width and Height of a Window, Canvas or a Widget        */
    PFword backgroundColor;         /** Background color of a Window, Canvas or a Widget        */
    PFEnBoolean border;             /** To draw border for a Window, Canvas or a Widget         */
};

 /** 
 *  Window configuration structure for GUI
 */
struct WindowCfg
{
    commAttributes windowAttr;        /** Attributes of a Window        */
    PFcallback oneShotHandler;        /** To be called at the loading time of the Window.It is called only 1 time by setWindow() API    */
};

 /** 
 *  Canvas config structure for GUI
 */
struct CanvasCfg
{
    commAttributes canvasAttr;      /** Attributes of a Canvas                                                  */
    PFcallback eventHandler;        /** To be called every time there is an event with in the Canvas region     */
                                    /** For eg. If a touch is detected in the Canvas region                     */
    char* displayString;            /** String to be displayed on the the Canvas                                */
    EnGfxFonts font;                /** Font of the text                                                        */
    PFword fontColor;               /** FontColor of the text                                                   */
    PFword* image1;                 /** Image to be displayed for a Canvas(optional)                            */
};

 /** 
 *  Widget config structure for GUI
 */
struct WidgetCfg
{
    commAttributes widgetAttr;      /** Attributes of a Widget                                                  */
    PFcallback eventHandler;        /** To be called every time there is an event with in the Widget region     */
                                    /** For eg. If a touch is detected in the Widget region                     */
    char* displayString;            /** String to be displayed on the Widget(optional)                          */
    EnGfxFonts font;                /** Font of the text                                                        */
    PFword fontColor;               /** FontColor of the text                                                   */
    PFword* image1;                 /** Image to be displayed for a Widget(optional)                            */
};

 /** 
 *  PopUp config structure for GUI
 */
struct PopUpCfg
{
    commAttributes popUpAttr;       /** Attributes of a PopUp           */
};

/** Configuration structure to display a message on LCD screen.        */
typedef struct
{
    Coordinate topLeft;             /** Top left Coordinate of the starting point of the message    */
    char *message;                  /** Message to be displayed                                     */
    EnGfxFonts fontType;
    PFdword fontColor;
    PFdword backColor;
}MsgConfig;

/**
 * \brief This function should be called in the beginning by the application program to
 * create a Window.
 *
 * \param windowId pointer of id, an id for the Window will be returned
 * \param config pointer of the WindowCfg structure to be registered

 * \return returns the status, if the window is created or not.
 * \see WindowCfg
 */
PFEnStatus createWindow(PFbyte *windowId, WindowCfg *config);

/**
 * \brief This function should be called in the beginning by the application program to
 * create a Canvas.
 *
 * \param windowId Id of the Window to which the Canvas will be associated
 * \param canvasId pointer of id, an id of the Canvas will be returned
 * \param config pointer of the CanvasCfg structure to be registered

 * \return returns the status, if the canvas is created or not.
 * \see CanvasCfg
 */
PFEnStatus createCanvas(PFbyte windowId, PFbyte *canvasId, CanvasCfg *config);

/**
 * \brief This function should be called in the beginning by the main() function of the application to
 * create a Widget.
 *
 * \param windowId Id of the Window to which the Widget will be associated
 * \param widgetId pointer of id, an id of the Widget will be returned
 * \param config pointer of the WidgetCfg structure to be registered

 * \return returns the status, if the Widget is created or not.
 * \see WidgetCfg
 */
PFEnStatus createWidget(PFbyte windowId, PFbyte *widgetId, WidgetCfg *config);

/**
 * \brief This function should be called in the beginning by the main() function of the application to
 * create a PopUp window. drawPopUp() is used display a PopUp message.
 *
 * \param popUpId Id of the PopUp will be returned
 * \param config pointer of the PopUpCfg structure to be registered
 
 * \return returns the status, if the PopUp is created or not.
 * \see PopUpCfg
 */
PFEnStatus createPopUp(PFbyte *popUpId, PopUpCfg *config);

/**
 * \brief This function sets/load the Window.This function must be called after all components (Window, Canvas etc.) has been created.
 *  This function will draw canvas, toolbars and widgets associated with the Window.
 * drawWindow() function is called. oneShotHandlers() of Canvas and Widgets are also called.
 * 
 * \param windowId Id of the Window to be set or loaded.

 * \return returns the status, if the Window has been set or not
 */
void setWindow(PFbyte windowId);

/**
 * \brief This function is called by the eventHandler(touchHandler, cursorHandler) of the application.
 * This functions checks in which region, point(eg. touch, mouse) is detected and then calls the respective handler.
 *
 * \param windowId windowId of the Window
 * \param pointX x Coordinate
 * \param pointY y Coordinate
 *
 */
void windowEventHandler(PFbyte windowId, PFword pointX, PFword pointY);

/**
 * \brief This function is called by setWindow() to draw the Window as per the properties defined in
 * the WindowCfg structure.This function also call drawCanvas() and drawToolbars().
 *
 * \param windowId windowId of the Window to draw.
 *
 * \return returns the status, if the Window has been drawn or not
 */
PFEnStatus drawWindow(PFbyte windowId);

/**
 * \brief This function is called by drawWindow() to draw the Canvas as per the properties defined in
 * the CanvasCfg structure.
 *
 * \param windowId windowId of the Canvas to draw.
 * \param canvasId CanvasId of the canvas to draw.
 * \return returns the status, if the Canvas has been drawn or not
 */
PFEnStatus drawCanvas(PFbyte windowId, PFbyte canvasId);

/**
 * This function is used to draw a message.Then, call renderFrame() function to display the message on the 
 * the LCD screen.
 *
 * \param msgAttributes pointer to the message config structure to define attributes of the message.
 * \return return status
 *
 */
PFEnStatus drawMessage(MsgConfig* msgAttributes);

/**
 * \brief This function is used to draw the Widget as per the properties defined in
 * the WidgetCfg structure.
 * 
 * \param windowId windowId of the Widget to draw.
 * \param widgetId widgetId of the Widget to draw.
 *
 * \return returns the status, if the Widget has been drawn or not
 */
PFEnStatus drawWidget(PFbyte windowId, PFbyte widgetId);

/**
 * \brief This function is used to display a PopUp. The function will first read the previous background, draw the
 * Popup and then retrieve back the orignal background.
 * There is 1 buffer of size defined by "READ_BG_BUFFER_SIZE" MACRO to store the background data. The size(width * height) of the PopUp 
   should not exceed size of this buffer.
 * displayString length(8 * no.of characters) must not exceed size of this buffer.
 * It uses tick driver for delay generation.
 * 
 * \param popUpId Id returned by create PopUp
 * \param displayString Notification message to be displayed
 * \param duration Duration of the PopUp message
 * \param fontType Font type of the message string
 * \param fontColor Font color of the message string
 *
 * \return return status
 * enStatusSuccess - PopUp successfully drawn
 * enStatusNoMem   - 1. Size of the the PopUp window is greater than the buffer defined by "READ_BG_BUFFER_SIZE" MACRO.
 *                   2. Size of the string is greater than the size of the PopUp window.
 */
PFEnStatus drawPopUp(PFbyte popUpId, char* displayString, PFword duration, PFword fontType, PFword fontColor);

/**
 * \brief This function is used to disable a Canvas.
 * A canvas is enabled by default after it is created.
 * If a canvas is disabled, it will not be drawn when the Window is
 * set or loaded using setWindow() API.
 * Also, it's handler will not be called even if there is any touch detected in 
 * it's region.
 *
 * \param windowId windowId of the window to which the canvas is associated.
 * \param canvasId id of the canvas to disable.
 *
 * \return return status:
 *        enStatusSuccess - on successful disabling the canvas.
 */
PFEnStatus disableCanvas(PFbyte windowId, PFbyte canvasId);

/**
 * \brief This function is used to disable a Widget.
 * A Widget is enabled by default after it is created.
 * If a Widget is disabled, it will not be drawn when the Window
 * is set or loaded using setWindow() API.
 * Also, it's handler will not be called even if there is any touch detected in 
 * it's region.
 * 
 * \param windowId windowId of the window to which the widget is associated.
 * \param widgetId id of the widget to disable.
 *
 * \return return status:
 *        enStatusSuccess - on successful disabling the widget.
 */
PFEnStatus disableWidget(PFbyte windowId, PFbyte widgetId);

/**
 * \brief This function is used to enable a Canvas.
 * A canvas is enabled by default after it is created.
 * If a canvas is disabled, it will not be drawn when the Window
 * is set or loaded using setWindow() API.
 * Also, it's handler will not be called even if there is any touch detected in 
 * it's region.
 * 
 * \param windowId windowId of the window to which the canvas is associated.
 * \param canvasId id of the canvas to enable.
 *
 * \return return status:
 *         enStatusSuccess - on successful enabling the canvas.
 */
PFEnStatus enableCanvas(PFbyte windowId, PFbyte canvasId);

/**
 * \brief This function is used to enable a Widget.
 * A widget is enabled by default after it is created.
 * If a widget is disabled, it will not be drawn when the Window
 * is set or loaded using setWindow() API.
 * Also, it's handler will not be called even if there is any touch detected in 
 * it's region.
 * 
 * \param windowId windowId of the window to which the widget is associated.
 * \param widgetId id of the widget to enable.
 *
 * \return return status:
 *  enStatusSuccess - on successful enabling the widget.
 */
PFEnStatus enableWidget(PFbyte windowId,PFbyte widgetId);

#endif
