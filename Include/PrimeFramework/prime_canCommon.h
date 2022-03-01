/**
 * \file	prime_canCommon.h
 * \brief   CAN Driver Discription for LPC1768.
 * \copyright Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module.
 * 
 * Review status: NO
 *
 */
#pragma once

/**
 * \ingroup PF_CAN
 * \defgroup PF_CANCOMMON CAN COMMON
 * @{
 * 	
 * 	\brief CAN common driver
 * 	\details  CAN common driver for onchip CAN Peripheral
 */


/** \brief Enumeration for CAN frame format		*/
typedef enum
{
	enCanFrameStandard = 0,				/**< CAN standard frame	with 11 bit ID	*/
	enCanFrameExtended					/**< CAN extended frame	with 29 bit ID	*/
}PFEnCanFrameFormat;

/**	\brief Enumeration for CAN callback types		*/
typedef enum
{
	enCanBuff1TxCallback = 0,		/**< Can Buffer 1 transmission complete interrupt callback	*/
	enCanBuff2TxCallback,			/**< Can Buffer 2 transmission complete interrupt callback	*/
	enCanBuff3TxCallback,			/**< Can Buffer 3 transmission complete interrupt callback	*/
	enCanRxCallback,				/**< Can message received interrupt callback				*/
	enCanErrCallback,				/**< Can Error passive interrupt callback					*/
}PFEnCanCallbackType;

/** \brief CAN message structure		*/
typedef struct
{
	PFdword id;							/**< CAN message ID													*/
	PFbyte length;						/**< CAN message length in number of bytes. Length should be less than or equal to 8	*/
	PFEnCanFrameFormat frameFormat;		/**< Choose between extended frame or standard frame				*/
	PFEnBoolean remoteFrame;			/**< Choose between normal transmission or remote frame request		*/
	PFbyte data[8];						/**< CAN packet data. Data can be of maximum 8 bytes.				*/	
}PFCanMessage;

/** \brief Pointer to PFCanMessage structure		*/
typedef PFCanMessage* PFpCanMessage;

/** \brief CAN message Header structure		*/
typedef struct
{
	PFdword id;							/**< CAN message ID													*/
	PFEnCanFrameFormat frameFormat;		/**< Choose between extended frame or standard frame				*/
	PFEnBoolean remoteFrame;			/**< Choose between normal transmission or remote frame request		*/
}PFCanMsgHeader;

/** \brief Pointer to PFCanMsgHeader structure		*/
typedef PFCanMsgHeader* PFpCanMsgHeader;


/**
 * Adds message filter in CAN acceptance filter.
 * 
 * \param canController CAN controller channel.
 * \param msgId Message Id to accept.
 * \param frameFormat Frame format for message to accpet.
 */
void pfCanWriteAccFilter(PFbyte canController, PFdword msgId, PFEnCanFrameFormat frameFormat);

/**
 * Sets callback for \a callbackType in the CAN callback list. 
 * 
 * \param canController CAN controller channel for which callback to be set.
 * \param callbackType Type of interrupt to set callback.
 * \param callback Callback function.
 * \return Add callback status.
 */
PFEnStatus pfCanSetCallback(PFbyte canController, PFEnCanCallbackType callbackType, PFcallback callback);

/**
 * Removes a callback function for \a callbackType
 * 
 * \param canController CAN controller channel for which callback to be removed.
 * \param callbackType Type of interrupt to remove the callback
 * \return Remove callback status.
 */
PFEnStatus pfCanRemoveCallback(PFbyte canController, PFEnCanCallbackType callbackType);

/**
 * This function sets active/init status of CAN channel.
 * 
 * \param channel CAN controller channel no. for which status to be updated.
 * \param status status of CAN channel.
 * \return Set Channel status.
 */
PFEnStatus pfCanSetChannelStatus(PFbyte channel, PFEnBoolean status);

/** @} */