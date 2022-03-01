/**
 *  \file       object.h
 *  \brief      Object Manager for Phi Game Engine
 *  A Game object is the smallest entity in a game in a game that a player can see and interact with.
 *  The character itself, enemies, weapons, bullets, background objects such as trees,
 *  clouds are all game objects.
 *  The game logic is written around the Game objects and other Managers perform tasks
 *  on these objects.
 *  There are 2 types of Game objects:
 *  1.    Static Object  - The objects that are fixed at one position throughout the Game.
 *  2.    Dynamic Object - The objects that can move around in a Game.
 *  The state of an object at any given time can be defined by its attributes.
 *  For example, state of the ball in the Arkanoid game is described by its
 *  position(x,y) on the screen and its velocity (speed and direction of travel).
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

#ifndef _OBJECT_MANAGER_H_
#define _OBJECT_MANAGER_H_

/** \brief Maximum number of objects supported            */
#define MAX_OBJECT_NUM                         20

/** Enumeration for the Shape of a 2D object            */
typedef enum
{
    enLine,
    enCircle,
    enRectangle,
    enTriangle,
    enImage
}EnObjectShape;

/** Properties structure for Object of Image type      */
typedef struct
{
    Coordinate    topLeft;
    Dimension    size;
    PFword        *image;
}ImageProperties;

/** Properties structure for Object of Line shape      */
typedef struct
{
    Coordinate    point1;
    Coordinate    point2;
}LineProperties;

/** Properties structure for Object of Rectangle shape        */
typedef struct
{
    Coordinate    topLeft;
    Dimension    size;
}RectangleProperties;

/** Properties structure for Object of Circle shape      */
typedef struct
{
    Coordinate    center;
    PFword        radius;
}CircleProperties;

/** Properties structure for Object of Triangle shape      */
typedef struct
{
    Coordinate    vertexA;
    Coordinate    vertexB;
    Coordinate    vertexC;
}TriangleProperties;

/** Enumeration for Object Visibility       */
typedef enum
{
    enStateVisible = 0,
    enStateInvisible,
}EnObjectVisibility;

/** Enumeration for Object Type     */
typedef enum
{
    enStatic,
    enDynamic
}EnObjectType;

/**        Enumeration for direction of the Object     */
typedef enum
{
    enNorth,
    enSouth,
    enWest,
    enEast,
    enNorthWest,
    enNorthEast,
    enSouthWest,
    enSouthEast
}EnDirection;

/** Configuration structure for Dynamic type of object */
typedef struct
{
    void        *prevObjProperties;       /** Pointer to store previous co-ordinates of an object. It is updated and used by the Game Engine.
                                               Pass pointer of the Properties structure according to the shape of the object    */
    PFbyte      speed;                    /**  Field to maintain speed of an object     */
    EnDirection direction;                /**  Field to maintain the direction of the movement of an object    */
}DynamicObjectCfg;

/**    Configuration structure to define an object     */
typedef struct
{
    PFchar*             name;               /** Name of an object       */
    EnObjectShape       objShape;           /** Shape of an object      */
    void                *objProperties;     /** Pointer to store current position of an object. User will use this field to update current position
                                                of the object. Pass pointer of the Properties structure according to the shape of the object.        */
    PFword              color;              /** Color of an object      */
    PFEnBoolean         colorFill;          /** Pass enBooleanTrue to fill color inside an object(Solid type), Pass enBooleanFalse for no color fill.    */
    EnObjectVisibility  visible;            /** Visibility of the object on the LCD screen      */
    EnObjectType        type;               /** Type of object: Static or Dynamic               */
    DynamicObjectCfg    *dynamicCfg;        /** Pointer to Dynamic configuration structure for a dynamic type of object. Pass NULL in case of static
                                                type of object.                                 */
}ObjectCfg;

typedef ObjectCfg* pObjectCfg;

/**
 * This function can be used by the application program to create an object. User will define the object
 * configuration structure (allocate memory) in its application program and will pass its address to register the object.
 * On successful creation of an object it will return an Id. This Id can be used to access the object.
 *
 * \param id Pointer of id, an Id will be returned on successful creation of the object.
 * \param config Pointer of the objectCfg structure to be registered.
 *  
 * \return return status:
 *       enStatusSuccess - Object successfully created.
 *       enStatusInvArgs - Error in the configuration settings of the object.
 *       enStatusNoMem   - Not enough memory to create an object.
 *  
 * \see ObjectCfg
 */
PFEnStatus createObject(PFbyte *id, pObjectCfg config);

/**
 * This function is used to destroy an object. It will deregister the object whose Id is passed as the parameter.
 * After destroying an object it's Id is free and can be assigned to a new object.
 *
 * \param id Id of the object to be destroyed
 *
 * \return return status:
 *       enStatusSucess  - object is successfully destroyed.
 */
PFEnStatus destroyObject(PFbyte id);

/**
 * This function is used to get the pointer to the object's configuration structure whose Id is passed as the parameter.
 * This pointer can be used to read and update attributes of an object.
 *
 * \param id Id of the object to be accessed
 *
 * \return pointer to object's configuration structure
 */
pObjectCfg getObject(PFbyte id);

/**
 * This function is used to get the count of the objects created by the application program.
 *
 * \return count of the total objects created by the application program.
 */
PFbyte getObjectCount(void);

#endif    // _OBJECT_MANAGER_H_