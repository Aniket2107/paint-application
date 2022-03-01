/**
 *
 *                              Copyright (c) 2014
 *                         PhiRobotics Research Pvt Ltd
 *
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 *
 * \brief Prime Framework LCD Display Driver
 *
 * Review status: NO
 *
 */
#pragma once
/**
 * \defgroup LCD_DRIVER_API LCD Driver API
 * @{
 */

#include "prime_gpio.h" 
 
#define DATA_PORT_WIDTH      8    /** Macro for defining the width of the data port of LCD Display        */
#define BLACK           0x0000    /**    Macro for BLACK Color    */
#define BLUE            0x001F    /**    Macro for BLUE Color    */
#define RED             0xF800    /**    Macro for RED Color    */
#define GREEN           0x07E0    /**    Macro for GREEN Color    */
#define CYAN            0x07FF    /**    Macro for CYAN Color    */
#define MAGENTA         0xF81F    /**    Macro for MAGENTA Color    */
#define YELLOW          0xFFE0    /**    Macro for YELLOW Color    */
#define WHITE           0xFFFF    /**    Macro for WHITE Color    */

/**        Enumeration for the orientation of the LCD Display Driver        */
 typedef enum{
    enGfxOrientation_0 = 0,
    enGfxOrientation_90,
    enGfxOrientation_180,
    enGfxOrientation_270    
}EnGfxOrientation;

/** LCD Configuration structure */
typedef struct{
    PFGpioPortPin gpioData[DATA_PORT_WIDTH];
    PFGpioPortPin gpioChipSelect;                 /**< port select for CS */
    PFGpioPortPin gpioRegSelect;                /**< port select for RS */
    PFGpioPortPin gpioWrite;                     /**< port select for WR */
    PFGpioPortPin gpioRead;                        /**< port select for RD */
    PFGpioPortPin gpioReset;                    /**< port select for RESET */
    EnGfxOrientation orientation;               /**< Screen Orientation     */
    PFword height;                                /**< DISPLAY X MAX */    
    PFword width;                                /**< DISPLAy Y MAX */  
}CfgGfx;

/** pointer to structure CfgGfx */
typedef CfgGfx* pCfgGfx;

/** Enumeration for the font type        */
typedef enum{
    enGfxFont_8X8=0,    /**< FONT SIZE 8x8            */
    enGfxFont_8X16,        /**< FONT SIZE 8x16            */
    enGfxFont_16X24,    /**< FONT SIZE 16x24        */
}EnGfxFonts;

/**    Enumeration for the Quadrant of the graphic Driver         */
typedef enum 
{
    enGfxQuadrant_I=0,      /**< Quadrant I            */
    enGfxQuadrant_II,        /**< Quadrant II        */
    enGfxQuadrant_III,         /**< Quadrant III        */
    enGfxQuadrant_IV        /**< Quadrant IV        */
}EnGfxQuadrant;

/** Enumeration for the drawing style of graphic driver        */
typedef enum 
{
    enGfxLineStyleSolid=0,    /**<   Solid drawing style      */
    enGfxLineStyleDotted,      /**<     Dotted drawing style    */
    enGfxLineStyleDashDot      /**<   Dash drawing style        */
}EnGfxLineStyle;

/**
 * To initialize LCD Display module
 *
 * \param gfxConfig pointer to structure containing configuration for LCD Module
 *
 * \return status whether LCD is initialized or not.
 * 
 */
PFEnStatus gfxOpen(pCfgGfx gfxConfig);

/**
 * To close LCD display driver
 *
 * \return status whether LCD is closed or not
 * 
 */
PFEnStatus gfxClose(void);

/**
 * To set GRAM Address of LCD Display module
 *
 * \return status whether GRAM address is set or not
 * 
 */
PFEnStatus gfxHome(void);

/**
 * To write a command to display LCD controller
 *
 * \param    reg        address of register on which data has to be written
 *
 * \param    data    data to be written on the reg
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxCommand(PFword reg, PFword data);

/*
 * To write a command to display LCD controller
 *
 * \param  reg    address of register on which data has to be written
 *
 * \return status whether command is written or not
 * 
 */
PFEnStatus gfxWriteCmd(PFword reg);


/*
 * To write data to display LCD controller
 *
 * \param data    data to be written on the register
 *
 * \return status whether data is written or not
 * 
 */
PFEnStatus gfxWriteData(PFword data);

/**
 * To Set Window for LCD Display module
 *
 * \param    x1    X-coordinates of left-top pixel of window to be set
 * \param    y1    Y-coordinates of left-top pixel of window to be set 
 * \param    x2    X-coordinates of right-bottom pixel of window to be set
 * \param    y2    Y-coordinates of right-bottom pixel of window to be set
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxSetWindow(PFword x1, PFword y1, PFword x2, PFword y2);

/**
 * To Set Cursor at given position for LCD Display module
 *
 * \param    x    X-coordinate of pixel where cursor is to be set
 * \param    y    Y-coordinate of pixel where cursor is to be set
 *
 * \return status of whether cursor is set or not
 * 
 */
PFEnStatus gfxSetCursor(PFword x, PFword y);

/**
 *    This function fills complete display of LCD with the given color . 
 *
 * \param  data    Color code of a color to be filled represented in 16-bit high color mode
 *
 * \return status whether display is filled with color or not
 * 
 */
PFEnStatus gfxFillRGB(PFword data);

/**
 * This function fills a pixel at given co-ordinates on LCD with a specific color.
 *
 * \param  x        X-coordinate of the pixel to be filled
 * \param  y        Y-coordinate of the pixel to be filled
 * \param  color    color code of a color to be filled represented in 16-bit high color mode
 *
 * \return status     whether pixel has been filled with specified color or not
 * 
 */
PFEnStatus gfxDrawPixel(PFword x, PFword y, PFword color);

/**
 * This function reads a pixel value at given co-ordinates on LCD
 *
 * \param  x            X-coordinate of the pixel to be read
 * \param  y            Y-coordinate of the pixel to be read
 * \param  pixelValue    pointer to PFword(16 bit)type variable to save pixel value after reading
 *
 * \return status         return status of the function
 *
 */
PFEnStatus gfxReadPixel(PFword x, PFword y, PFword* pixelValue);

/**
 * To set complete LCD screen area for further operation.
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxSetAreaMax(void);
 
/**
 * To fill a rectangular region specified by left top co-ordinates and right bottom co-ordinates with color specified.
 *
 * \param    xStart    X-coordinate of left-top pixel of rectangular region to be filled.
 * \param    yStart    Y-coordinate of left-top pixel of rectangular region to be filled.
 * \param    xEnd    X-coordinate of right-bottom top pixel of rectangular region to be filled.
 * \param    yEnd    Y-coordinate of right-bottom top pixel of rectangular region to be filled.
 * \param    color    color code of a color to be filled represented in 16-bit high color mode
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxFillArea(PFword xStart, PFword yStart, PFword xEnd, PFword yEnd, PFword color);

/**
 * To set the orientation of the LCD Display
 *
 * \param    orient    value of orientation from enum EnGfxOrientation.
 *
 * \return     status whether orientation is set or not
 * 
 */
PFEnStatus gfxSetOrientation(EnGfxOrientation orient);

/**
 * To get the current orientation of the LCD Display
 *
 * \param    orient    pointer to variable containing value of orientation
 *
 * \return     status whether orientation is received successfully or not
 * 
 */
PFEnStatus gfxGetOrientation(EnGfxOrientation*  orient);

/**
 * To get the width of the LCD Display
 *
 * \param    xOld    value of old X axis coordinate
 * \param    yOld    value of old Y axis coordinate
 * \param    xNew    pointer  to variable containing new value X axis coordinate
 * \param    yNew    pointer  to variable containing new value Y axis coordinate 
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxMapPoints(PFword xOld, PFword yOld, PFword *xNew, PFword *yNew);

/**
 * To scroll the screen of LCD Display
 *
 * \param    lines    Number of lines to scroll
 *
 * \return status whether lcd screen is scrolled or not
 * 
 */
PFEnStatus gfxScroll(PFsdword lines);

/**
 * To get the height of the LCD Display
 *
 * \param    height    pointer to the variable that stores height of LCD Display
 *
 * \return status whether window is set or not
 * 
 */
PFEnStatus gfxGetHeight(PFword *height);

/**
 * To get the width of the LCD Display
 *
 * \param    width    pointer to the variable that stores width of LCD Display
 *
 * \return status of whether is window is set or not
 * 
 */
PFEnStatus gfxGetWidth(PFword *width);

/**
 * To set the Pen Size of the graphic display driver    
 *
 * \param size    Size of the pen for graphic display driver
 *
 * \return status whether pen size is set or not
 * 
 */
PFEnStatus gfxSetPenSize(const PFdword size);

/**

 * To get the pen size from the graphic display driver
 *
 * \param    size    Variable address to store the value of pen size.
 *
 * \return    status whether user got the pen size 
 * 
 */
PFEnStatus gfxGetPenSize(PFword *size);

/**

 * To set the color in graphic display driver which is used for further operations.
 *
 * \param    color    color code of a color to be set represented in 16-bit high color mode
 *
 * \return status of whether is color is set or not
 * 
 */
PFEnStatus gfxSetColor(const PFdword color);

/**
 * To get the color from graphic display driver
 *
 * \param color colorNumber pointer to a variable containing color code represented in 16-bit high color mode
 *
 * \return status whether user got current color from graphic display driver or not.
 * 
 */
PFEnStatus gfxGetColor( PFword *color);

/**
 * To set the pixel on the LCD Display
 *
 * \param    xPos    X-Cordinate of the pixel to be set
 * \param    yPos    Y-Cordinate of the pixel to be set
 * \param    size    Size of the pixel 
 * \param     color    color code of a color to be set represented in 16-bit high color mode
 *
 * \return status of whether pixel is set or not
 * 
 */
PFEnStatus gfxPixels(const PFdword xPos, const PFdword yPos, const PFdword size, PFword color);

/**
 *
 * To Draw the pixel on the LCD Display
 *
 * \param     xPos    X-Cordinate of the pixel to be set
 * \param    yPos    Y-Cordinate of the pixel to be set
 *
 * \return status whether pixel is drawn or not
 * 
 */
PFEnStatus gfxDrawPixels(const PFdword xPos, const PFdword yPos);

/**

 * To Draw rectangle on the LCD Display
  *
 * \param    x1    X-Coordinate of the left-top pixel of rectangle
 * \param    y1    Y-Coordinate of the left-top pixel of rectangle
 * \param    x2    X-Coordinate of the right-bottom pixel of rectangle
 * \param    y2    Y-Coordinate of the right-bottom pixel of rectangle
 *
 * \return status whether rectangle is drawn or not
 * 
 */
PFEnStatus gfxDrawRectangle(const PFdword x1, const PFdword y1, const PFdword x2, const PFdword y2);

/**
 * To Draw solid circle on the LCD Display
 *
 * \param    xc     X-Coordinate of the centre of the circle
 * \param     yc     Y-Coordinate of the centre of the circle
 * \param     radius    Radius of the circle
 * \param     color    color code of a color with which circle is to be filled represented in 16-bit high color mode
 *
 * \return status whether solid circle is drawn or not
 * 
 */
PFEnStatus gfxDrawSolidCircle(const PFsdword xc, const PFsdword yc, PFsdword radius, const PFsdword color);

/**
 * To Draw solid rectangle  on the LCD Display
 *
 * \param x1 X Coordinate of the first vertex
 * \param y1 Y Coordinate of the first vertex
 * \param x2 X Coordinate of the second vertex
 * \param y2 Y Coordinate of the second vertex
 * \param color Color of the solid rectangle
 *
 * \return status of whether solid rectangle is drawn or not
 * 
 */
PFEnStatus gfxDrawSolidRectangle(const PFdword x1, const PFdword y1, const PFdword x2, const PFdword y2, const PFdword color);

/**
 * To Draw solid quarter circle on the LCD Display
 *
 * \param xc X Coordinate of the center of the circle
 * \param yc Y Coordinate of the center of the circle
 * \param radius Radius of the quarter circle
 * \param quadrant Quadrant of the quarter circle
 * \param color Color of the solid quarter circle
 *
 * \return status of whether solid quarter circle is drawn or not
 * 
 */
PFEnStatus gfxDrawSolidQuarterCircle(const PFsdword xc, const PFsdword yc, PFsdword radius, const EnGfxQuadrant quadrant, const PFsdword color);

/**
 * To Draw solid round rectangle on the LCD Display
 *
 * \param x1 X Coordinate of the first vertex 
 * \param y1 Y Coordinate of the first vertex 
 * \param x2 X Coordinate of the second vertex
 * \param y2 Y Coordinate of the second vertex
 * \param radius Radius of the edge of the round rectangle
 * \param color Color of the solid round rectangle 
 *
 * \return status of whether solid round rectangle is drawn or not
 * 
 */
PFEnStatus gfxDrawSolidRoundRectangle(const PFdword x1, const PFdword y1, const PFdword x2, const PFdword y2, PFdword radius, const PFdword color);

/**
 * To Draw Bresenham line on the LCD Display
 *
 * \param x1 X Coordinate of the one end of the line
 * \param y1 Y Coordinate of the one end of the line
 * \param x2 X Coordinate of the other end of the line
 * \param y2 Y Coordinate of the other end of the line
 *
 * \return status of whether bresenham line is drawn or not
 * 
 */
PFEnStatus gfxDrawLine( PFsdword x1, PFsdword y1, const PFsdword x2, const PFsdword y2);

/**
 * To Draw Bresenham circle on the LCD Display
 *
 * \param xc X Coordinate of the center of the circle
 * \param yc Y Coordinate of the center of the circle
 * \param radius Radius of the quarter circle
 *
 * \return status of whether quarter circle is drawn or not
 * 
 */
PFEnStatus gfxDrawCircle(const PFsdword xc, const PFsdword yc, PFsdword radius);

/**
 * To Draw quarter circle on the LCD Display
 *
 * \param xc X Coordinate of the center of the circle
 * \param yc Y Coordinate of the center of the circle
 * \param radius Radius of the quarter circle
 * \param quad Quadrant of the quarter circle
 *
 * \return status of whether quarter circle is drawn or not
 * 
 */
PFEnStatus gfxDrawQCircle(const PFsdword xc, const PFsdword yc, PFsdword radius, EnGfxQuadrant quad);

/**
 * To Draw polygon on the LCD Display
 *
 * \param xArray     ptr to Array of the X Coordinate of the polygon
 * \param yArray     ptr to Array of the Y Coordinate of the polygon    
 * \param num        Number of the sides in the polygon 
 *
 * \return status of whether polygon is drawn or not
 * 
 */
PFEnStatus gfxDrawPolygon(const PFdword *xArray, const PFdword *yArray, const PFdword num);

/**
 * To Draw solid ellipse on the LCD Display
 *
 * \param  xc X Coordinate of the ellipse
 * \param  yc Y Coordinate of the ellipse
 * \param  a Constants of the solid ellipse (a)
 * \param  b Constants of the solid ellipse (b)
 * \param  color color of the solid ellipse
 *
 * \return status of whether solid ellipse is drawn or not
 * 
 */
PFEnStatus gfxDrawSolidEllipse(const PFsdword xc, const PFsdword yc, const PFsdword a, const PFsdword b, const PFsdword color);

/**

 * To Draw circular bresenham lines on the LCD Display
 * 
 * \param      xc         X Coordinate of the bresenham circular lines
 * \param      yc         Y Coordinate of the bresenham circular lines
 * \param     radius    Radius of the bresenham circular lines
 * \param     num     Numbers of the lines to be drawn
 *
 * \return status of whether circular bresenham lines are drawn or not
 * 
 */
PFEnStatus gfxDrawCircularLines(const PFdword xc, const PFdword yc,const PFdword radius, const PFdword num);

/**
 * To write string on the LCD display
 *
 * \param x            X Coordinate of the char to be written to the LCD Display
 * \param y            Y Coordinate of the char to be written to the LCD Display
 * \param character    character to be written on the LCD display
 * \param fontType     Font Type of the char to be written
 * \param fontColor    Font Color of the char to be written
 * \param backColor    Background color of the LCD display 
 *
 * \return status of whether char is written or not
 * 
 */
PFEnStatus gfxDrawChar(PFdword x, PFdword y, PFchar character, EnGfxFonts fontType, PFdword fontColor, PFdword backColor);

/**
 * To write string on the LCD display
 *
 * \param x            X Coordinate of the char to be written to the LCD Display
 * \param y            Y Coordinate of the char to be written to the LCD Display
 * \param character    char to be written on the LCD display
 * \param fontColor    Font Color of the char to be written
 * \param backColor    Background color of the LCD display 
 *
 * \return status of whether char is written or not
 * 
 */
PFEnStatus gfxDrawChar16x24(PFdword x, PFdword y, PFchar character, PFdword fontColor, PFdword backColor);

/**
 * To write string on the LCD display
 *
 * \param x            X Coordinate of the string to be written to the LCD Display
 * \param y            Y Coordinate of the string to be written to the LCD Display
 * \param string    String to be written on the LCD display
 * \param fontType     Font Type of the string to be written
 * \param fontColor    Font Color of the string to be written
 * \param backColor    Background color of the LCD display 
 *
 * \return status of whether string is written or not
 * 
 */
PFEnStatus gfxDrawString(PFdword x, PFdword y, const char *string,EnGfxFonts fontType, PFdword fontColor, PFdword backColor);

/**
 * To Draw the arc on the LCD Display
 *
 * \param xc            X Coordinate of the center of the arc to be drawn on LCD display
 * \param yc            Y Coordinate of the center of the arc to be drawn on LCD display
 * \param radius        Radius of the arc to be drawn on the LCD display
 * \param startAngle    Start angle of the arc
 * \param extent        Extent of the arc
 *
 * \return status of whether arc is drawn or not
 * 
 */
PFEnStatus gfxDrawArc(const PFsdword xc, const PFsdword yc, const PFsdword radius, PFsdword startAngle, PFsdword extent);

/**
 * To Draw styled bresenham line on the LCD Display
 *
 * \param    x1        X Coordinate of the one end of the bresenham line
 * \param    y1        Y Coordinate of the one end of the bresenham line
 * \param    x2        X Coordinate of the other end of the bresenham line
 * \param    y2        Y Coordinate of the other end of the bresenham line
 * \param     style    Drawing style of the line
 * \param     penSize    Pen size of the line    
 * \param     color    Color of the line to be drawn 
 *
 * \return status of whether bresenham styled line is drawn or not
 * 
 */
PFEnStatus gfxDrawStyledLine(PFsdword x1, PFsdword y1, const PFsdword x2, const PFsdword y2, const EnGfxLineStyle style, PFchar penSize, const PFsdword color);

/**
 * To draw fine quadratic bezier bresenham line 
 *
 * \param    x1        X Coordinates of the line
 * \param    y1        Y Coordinates of the line
 * \param    x2        X Coordinates of the line
 * \param    y2        Y Coordinates of the line
 * \param    x3        X Coordinates of the line
 * \param    y3        Y Coordinates of the line
 *
 * \return status of whether fine quadratic bezier bresenham line is drawn or not
 * 
 */
PFEnStatus gfxDrawFineQuadBezier(PFsdword x1, PFsdword y1, const PFsdword x2, const PFsdword y2, const PFsdword x3, const PFsdword y3);

/**
 * To Draw Cuboid on the LCD Display
 *
 * \param x11    X Coordinate of the one vertex of the first rectangle
 * \param y11    Y Coordinate of the one vertex of the first rectangle
 * \param x12    X Coordinate of the other vertex of the first rectangle
 * \param y12    Y Coordinate of the other vertex of the first rectangle
 * \param x21    X Coordinate of the one vertex of the second rectangle
 * \param y21    Y Coordinate of the one vertex of the second rectangle
 * \param x22    X Coordinate of the other vertex of the second rectangle
 * \param y22    Y Coordinate of the other vertex of the second rectangle
 *
 * \return status of whether cuboid is drawn or not
 * 
 */
PFEnStatus gfxDrawCuboid(PFdword x11, PFdword y11, PFdword x12, PFdword y12, PFdword x21, PFdword y21, PFdword x22, PFdword y22);

/**

 * To Draw parallelogram of the LCD Display
 *
 * \param x11    X Coordinate of the one of the parallel line
 * \param y11    Y Coordinate of the one of the parallel line
 * \param x12    X Coordinate of the one of the other parallel line
 * \param y12    Y Coordinate of the one of the other parallel line
 * \param len    Length of the parallel line
 *
 * \return status of whether parallelogram is drawn or not
 * 
 */
PFEnStatus gfxDrawParallelogram(PFdword x1, PFdword y1, PFdword x2, PFdword y2, PFdword len);

/**
 * To Draw parallelepiped on the LCD Display
 *
 * \param x11    X Coordinate of the one of the parallel line of first parallelogram
 * \param y11    Y Coordinate of the one of the parallel line of first parallelogram
 * \param x12    X Coordinate of the one of the other parallel line of first parallelogram
 * \param y12    Y Coordinate of the one of the other parallel line of first parallelogram
 * \param l1    Length of the parallel lines of first parallelogram
 * 
 * \param x21    X Coordinate of the one of the parallel line of second parallelogram
 * \param y21    Y Coordinate of the one of the parallel line of second parallelogram
 * \param x22    X Coordinate of the one of the other parallel line of second parallelogram
 * \param y22    Y Coordinate of the one of the other parallel line of second parallelogram
 * \param l2    Length of the parallel lines of second parallelogram
 *
 * \return status of whether  parallellepiped  is drawns or not
 * 
 */
PFEnStatus gfxDrawParallelepiped(PFdword x11, PFdword  y11, PFdword  x12, PFdword  y12, PFbyte l1, PFdword  x21, PFdword  y21, PFdword  x22, PFdword y22, PFbyte l2);

/**
 * To Draw filled Lines on the LCD Display
 *
 * \param xc    X Coordinate of Center
 * \param yc    Y Coordinate of Center
 * 
 * \param x1    X Coordinate of One end of the line    
 * \param y1    Y Coordinate of One end of the line    
 * 
 * \param x2    X Coordinate of other end of the line
 * \param y2    Y Coordinate of other end of the line
 *
 * \param yRef  Y Reference point of the line 
 *
 * \return status of whether triangle is  drawn or not
 * 
 */
PFEnStatus gfxDrawFilledLines(const PFsdword xc, const PFsdword yc, const PFsdword x1, const PFsdword y1, const PFsdword x2, const PFsdword y2, const PFsdword yRef);

/**
 * To Draw filled triangle on the LCD Display
 *
 * \param x1    X Coordinate of first vertex
 * \param y1    Y Coordinate of first vertex
 * \param x2    X Coordinate of second vertex
 * \param y2    Y Coordinate of second vertex
 * \param x3    X Coordinate of third vertex
 * \param y3    Y Coordinate of third vertex
 *
 * \return status of whether triangle is  drawn or not
 * 
 */
PFEnStatus gfxDrawFilledTriangle(const PFsdword x1, const PFsdword y1, const PFsdword x2, const PFsdword y2, const PFsdword x3, const PFsdword y3);

/**
 * To Draw filled Polygon on the LCD Display
 * 
 * \param xArray     ptr to Array of the X Coordinate of the polygon
 * \param yArray     ptr to Array of the Y Coordinate of the polygon    
 * \param num    Number of sides in the polygon
 *
 * \return status of whether Polygon is  drawn or not
 * 
 */
PFEnStatus gfxDrawFilledPolygon(const PFsdword *xArray, const PFsdword *yArray, const PFsdword num);

/**
 * To Draw Plot circle on the LCD Display
 *
 * \param xm    X Coordinate of centre
 * \param ym    Y Coordinate of centre
 * \param r radius of the centre
 * \param bcolor background color of the circle
 * \param fcolor front color of the circle
 *
 * \return status of whether Circle is  drawn or not
 * 
 */
PFEnStatus gfxPlotCircle(PFdword xm, PFdword ym, PFdword r,PFdword bColor, PFdword fColor);

/**

 * To set LCD Debug Print Configuration  on the LCD Display
 *
 * \param dfont Font of the character
 *
 * \param dFontClr Font Color
 *
 * \param dFontBackClr Font Background color
 *
 * \return status of whether Configuration is set or not
 * 
 */
PFEnStatus gfxDebugSetPrintConfig(EnGfxFonts dFont, PFdword dFontClr, PFdword dFontBackClr);

/**
 * To scroll down the debug line on the LCD Display
 * 
 * \return status
 * 
 */
PFEnStatus gfxDebugNewLine(void);

/**

 * To Debug a character on the LCD Display
 *
 * \param data character to be debugged
 *
 * \return status of whether character is debugged or not
 * 
 */
PFEnStatus gfxDebugDrawChar(PFbyte data);

/**

 * To Debug a string on the LCD Display
 *
 * \param str string to be debugged
 *
 * \return status of whether string is debugged or not
 * 
 */
PFEnStatus gfxDebugString(PFbyte* str);

/**

 * To scroll up the debug line on the LCD Display
 *
 * \param lines Number of lines
 *
 * \return status of whether  scrolling is done or not
 * 
 */
PFEnStatus gfxDebugScrollUp(PFword lines);

/**

 * To scroll down the debug line on the LCD Display
 *
 * \param lines Number of lines
 *
 * \return status of whether  scrolling is done or not
 * 
 */
PFEnStatus gfxDebugScrollDown(PFword lines);

/**
 * \brief This function is used to read the background(RGB value of pixels) and stores
 * the data in an array.
 * 
 * \param xValue x coordinate of the window
 * \param yValue y coordinate of the window
 * \param width width of the window
 * \param height height of the window
 * \param backgroundData pointer to an array to store pixel values
 * \param size size of the array
 *
 * \return returns status:
            enStatusSuccess - background read successfully.
            enStatusNoMem   - size of the array is smaller than window size
 */
PFEnStatus readBackground(PFword xValue, PFword yValue, PFword width, PFword height, PFword *backgroundData, PFword size);

/**
 * \brief This function is to retrieve back the background data stored by readBackground() API.
 * 
 * \param xValue x coordinate of the window
 * \param yValue y coordinate of the window
 * \param width width of the window
 * \param height height of the window
 * \param backgroundData pointer to an array of pixel values to draw on LCD
 * \param size size of the array
 *
 * \return returns status:
            enStatusSuccess - background retrieve back successfully.
            enStatusNoMem   - size of the array is smaller than window size
 */
PFEnStatus retrieveBackground(PFword xValue, PFword yValue, PFword width, PFword height, PFword *backgroundData, PFword size);

/**
 * \brief This function is used to convert a pixel value from 16-bit BGR format to 
 * 16-bit RGB format
 * 
 * \param color pixel value in BGR format(16-bit).

 * \return returns converted pixel value (RGB format).
 */
PFword bgrToRgb(PFword color);

/** } */
