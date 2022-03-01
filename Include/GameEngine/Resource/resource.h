/**
 *  \file       resource.h
 *  \brief      Resource Manager for Phi Game Engine
 *  Resource Manager manages resources required to design a game.
 *  A Game requires resources like image, sound and text files.
 *    Our Resource manager only support images in bmp format 
 *  stored on the SDcard and a piezo buzzer to play sound.
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

#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

/**Enum to select storage device where required image is stored        */
typedef enum
{
    enSDCard = 0
}EnStorage;

/**Enum to select image format        */
typedef enum
{
    enImageBmpFormat = 0			/**	It only supports 16-bit and 24-bit bitmap images	*/
}EnImageFormat;

/** Configuration structure to specify attributes of an image*/
typedef struct
{
    EnStorage imageSource;            /**< Select storage device where image is stored*/
    EnImageFormat imageFormat;        /**< Format of the image    */
    PFbyte* imagePath;                /**< Path of the image saved on SDcard        */
    PFword* imageBuffer;            /**< pointer to an array where actual image data will be loaded*/
}ImageCfg;

typedef ImageCfg* pImageCfg;

/**
 * This function reads the image file from specified storage location, extracts actual image 
 * data and then saves it in an array.
 *
 * \param imageConfig  Pointer to configuration structure, which contains the attributes of the image.
 *
 * \return return status:
 *  enStatusSucess          - image successfully loaded
 *  enStatusNotSupported    - specified format or mode of storage not supported
 *  enStatusError           - error in loading the image
 *
 * \see ImageCfg
 */
PFEnStatus getImage(pImageCfg imageConfig);

/**
 * This function is used to play the buzzer for a specified duration.
 *
 * \param duration time duration in milliseconds to play the buzzer.
 *
 */
void playBuzzer(PFword duration);

#endif