/**
 *  \file       bitmap.h
 *  \brief      bitmap file provides an interface to access an image in bmp
 *              format stored on the SDcard.
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

#ifndef __BITMAP_H__
#define __BITMAP_H__

/** \brief Configuration structure to define BMP Header        */
typedef struct __attribute__((__packed__))
{
    PFbyte signature[2];
    PFdword fileSize;
    PFdword reserved;
    PFdword offset;
    PFdword headerSize;
    PFdword imageWidth;
    PFdword imageHeight;
    PFword planes;
    PFword pixelBitSize;
}BmpHeader;

typedef union
{
    BmpHeader bmpHeader;
    PFbyte header[32];
}bitmap;

/**
 * This function is used to get bmp image header information.
 *
 * \param fileName path of the bmp image file
 * \param imgHeader pointer to BmpHeader structure to store header information
 *  
 * \return return status:
 *       enStatusSucess - Information loaded successfully
 *       enStatusError  - Error in accessing the file
 *  
 * \see BmpHeader
 */
PFEnStatus bmpGetImageInfo(PFbyte* fileName, BmpHeader* imgHeader);

/**
 * This function is used to draw an image on the LCD screen by directly
 * reading image from the SDcard.
 *
 * \param fileName path of the bmp image file
 * \param x x coordinate on LCD screen to draw the image
 * \param y y coordinate on LCD screen to draw the image
 *  
 * \return return status:
 *       enStatusSucess - Image displayed successfully
 *       enStatusError  - Error in displaying image
 */
PFbyte bmpDrawImage(PFbyte* fileName, PFword x, PFword y);

/**
 * It reads the image file from specified storage location, extract actual image 
 * data and then saves it in an array.
 * 
 * \param fileName path of the bmp image file
 * \param buffer pointer to an array where actual image data will be stored
 *  
 * \return return status:
 *       enStatusSucess - Image data laoded in the array successfully
 *       enStatusError  - Error in accessing the image
 *  
 */
PFEnStatus bmpLoadImage(PFbyte* fileName, PFword* buffer);

/**
 * This function is used to draw an image on LCD screen.
 * It access the imgBuffer array to display image on LCD screen.
 *
 * \param imgBuffer pointer to an array where actual image data is stored
 * \param x x coordinate on LCD screen to draw the image
 * \param y y coordinate on LCD screen to draw the image
 * \param width width of the BMP image
 * \param height height of the BMP image
 */
void bmpDrawLoadedBitmap(PFword* imgBuffer, PFword x, PFword y, PFword width, PFword height);

/**
 * This function is used to read a pixel value(RGB format) of an image stored in SDcard.
 *
 * \param fileName path of the bmp image file
 * \param x x coordinate of the pixel in the image
 * \param y y coordinate of the pixel in the image
 *  
 * \return return pixel color in RGB format.
 *       enStatusError  - error in accessing the image
 *  
 */
PFword bmpPickColor(PFbyte* fileName, PFword x, PFword y);

/**
 * This function is used to read LCD screen and store it as a BMP image.
 * It can be used to take a screen shot of the LCD screen and store it as a 
 * BMP image in SDcard.
 *
 * \param x x coordinate on LCD screen
 * \param y y coordinate on LCD screen
 * \param width width of the window to save as an image
 * \param height height of the window to save as an image
 * \param backgroundData pointer to an array of size equal to (width+1) for internal purpose
 * 
 * \return return status:
 *       enStatusSucess - Image saved successfully
 *       enStatusError  - Error in saving image
 */
PFEnStatus saveImage(PFword x, PFword y, PFword width, PFword height, PFword *backgroundData);

#endif    // __BITMAP_H__