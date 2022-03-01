/**
 * \file	prime_iap.h
 * \brief   IAP Driver Discription for LPC1768.
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
 * \ingroup native
 * \defgroup PF_IAP IAP
 * @{
 * 	
 * \brief IAP driver
 * \details  IAP driver for onchip IAP Peripheral
 */ 
 

/** \brief IAP entry location */
#define PF_IAP_ADDR              (0x1FFF1FF1UL)


/**
 * \brief IAP command code definitions
 */
typedef enum
{
    enIapCmdPrepare = 50,    		/**< Prepare sector(s) for write operation		*/
    enIapCmdCopyRamToFlash = 51,    /**< Copy RAM to Flash							*/
    enIapCmdErase = 52,             /**< Erase sector(s)							*/
    enIapCmdBlankCheck = 53,        /**< Blank check sector(s)						*/
    enIapCmdReadPartId = 54,       	/**< Read chip part ID							*/
    enIapCmdReadBootVersion = 55,   /**< Read chip boot code version				*/
    enIapCmdCompare = 56,           /**< pfIapCompare memory areas						*/
    enIapCmdReinvokeIsp = 57,       /**< Reinvoke ISP								*/
    enIapCmdReadSerialNum = 58, 	/**< Read serial number							*/
}PFEnIapCmd;//  IAP_COMMAND_CODE;

/**
 * \brief IAP status code definitions
 */
typedef enum
{
    enIapStatusCmdSuccess = 0,    				/**< Command is executed successfully.		*/
    enIapStatusInvCmd,             				/**< Invalid command.		*/
    enIapStatusSrcAddrErr,        				/**< Source address is not on a word boundary.		*/
    enIapStatusDstAddrErr,        				/**< Destination address is not on a correct boundary.		*/
    enIapStatusSrcAddrNotMapped, 				/**< Source address is not mapped in the memory map.		*/
    enIapStatusDstAddrNotMapped,   				/**< Destination address is not mapped in the memory map.		*/
    enIapStatusCountErr,          				/**< Byte count is not multiple of 4 or is not a permitted value.		*/
    enIapStatusInvSector,     					/**< Sector number is invalid.		*/
    enIapStatusSectorNotBlank,    				/**< Sector is not blank.		*/
    enIapStatusSectorNotReady,					/**< Command to prepare sector for write operation was not executed.		*/
    enIapStatusCompareErr,         				/**< Source and destination data is not same.		*/
	enIapStatusBusy,              				/**< Flash programming hardware interface is busy.		*/
}PFEnIapStatus;// PFEnIapStatus;

/**
 * \brief IAP write length definitions
 */
typedef enum {
  enIapWriteSize256  = 256,
  enIapWriteSize512  = 512,
  enIapWriteSize1024 = 1024,
  enIapWriteSize4096 = 4096,
} PFEnIapWriteSize;//PFEnIapWriteSize;

/**
 * \brief IAP command structure
 */
typedef struct {
    PFdword cmd;   			// Command
    PFdword param[4];      	// Parameters
    PFdword status;        	// status code
    PFdword result[4];     	// Result
}PFIapCommand;

/**
 * Function initializes the software resources required for IAP block
 */
void pfIapOpen(void);

/**
 * Function clears the software resources required for IAP block
 */
void pfIapClose(void);

/** 
 * Get sector number of an address
 * 
 * \param adr Sector Address
 * 
 * \return PFdword  Sector Number
 */
PFdword pfIapGetSecNum (PFdword adr);

/** 
 * Prepare sector(s) for write operation
 * 
 * \param start_sec  	The number of start sector
 * \param end_sec 		The number of end sector
 * 
 * \return PFEnIapStatus enIapStatusCmdSuccess/BUSY/INVALID_SECTOR.
 */
PFEnIapStatus pfIapPrepareSector(PFdword start_sec, PFdword end_sec);

/** 
 *  Copy RAM to Flash
 * 
 * \param dest 		destination buffer (in Flash memory).
 * \param source 	source buffer (in RAM).
 * \param size 		the write size.
 * 
 * \return PFEnIapStatus  Discription
 */
PFEnIapStatus pfIapCopyRamToFlash(PFbyte * dest, PFbyte* source, PFEnIapWriteSize size);

/** 
 * Erase sector(s)
 * 
 * \param start_sec 	The number of start sector
 * \param end_sec 		The number of end sector
 * 
 * \return PFdword  Status
 */
PFEnIapStatus pfIapEraseSector(PFdword start_sec, PFdword end_sec);

/** 
 * Blank check sectors
 * 
 * \param start_sec 		The number of start sector
 * \param end_sec 			The number of end sector
 * \param first_nblank_loc 	The offset of the first non-blank word
 * \param first_nblank_val 	The value of the first non-blank word
 * 
 * \return PFEnIapStatus  Status
 */
PFEnIapStatus pfIapBlankCheckSector(PFdword start_sec, PFdword end_sec, PFdword *first_nblank_loc, PFdword *first_nblank_val);

/** 
 * Read part identification number
 * 
 * \param partID Part ID
 * 
 * \return PFEnIapStatus  Status
 */
PFEnIapStatus pfIapReadPartId(PFdword *partID);

/** 
 * Read boot code version
 * 
 * \param major The major
 * \param minor The minor
 * 
 * \return PFEnIapStatus  Status
 */
PFEnIapStatus pfIapReadBootCodeVer(PFbyte *major, PFbyte* minor);

/** 
 * Read Device serial number
 * 
 * \param uid Serial number.
 * 
 * \return PFEnIapStatus  Status
 */
PFEnIapStatus pfIapReadDeviceSerialNum(PFdword *uid);

/** 
 * compare the memory contents at two locations.
 * 
 * \param addr1 The address of the 1st buffer (in RAM/Flash).
 * \param addr2 The address of the 2nd buffer (in RAM/Flash).
 * \param size 	Number of bytes to be compared; should be a multiple of 4.
 * 
 * \return PFEnIapStatus  Status
 */
PFEnIapStatus pfIapCompare(PFbyte *addr1, PFbyte *addr2, PFdword size);

/**
 * Invoke ISP
 * 
 * \return void
 *
 */
void pfIapInvokeIsp(void);
/** @} */
