/*-----------------------------------------------------------------------
/  Low level disk interface modlue include file   (C)ChaN, 2012
/-----------------------------------------------------------------------*/

#pragma once

#include "prime_gpio.h"
#include "mmc.h"

/** Maximum disks supported for file system		*/
#define MAX_DISK_SUPPORTED				4

/** Disk configuration structure			*/
typedef struct
{
	void* devConfig;																	/**< Device configuration structure			*/
	PFEnStatus (*devOpen)(PFbyte* deviceId, pCfgMmc cfg);										/**< Pointer to device open function		*/
	PFEnStatus (*devGetStatus)(PFbyte deviceId);												/**< Pointer to device get status function	*/
	PFEnStatus (*devRead)(PFbyte deviceId, PFbyte* data, PFdword sector, PFbyte count);		/**< Pointer to device read function		*/
	PFEnStatus (*devWrite)(PFbyte deviceId, const PFbyte* data, PFdword sector, PFbyte count);	/**< Pointer to device write function		*/
	PFEnStatus (*devIoCtrl)(PFbyte deviceId, PFbyte cmd, void* arg);							/**< Pointer to device control function		*/
	PFEnBoolean allowWrite;																/**< Set device write permission			*/
	PFEnBoolean allowIoCtrl;															/**< Set device IO control permission		*/
}CfgDisk;

/** Pointer to CfgDisk structure		*/
typedef CfgDisk*	pCfgDisk;


/*---------------------------------------*/
/* Prototypes for disk control functions */
/**
 * Initialized the disk
 *
 * \param drive Pointer to variable where physical drive number will be loaded.
 * \param config Pointer to disk configuration structure.
 *
 * \return status
 */
PFEnStatus diskOpen(PFbyte* drive, pCfgDisk config);

/**
 * Initialized the disk
 *
 * \param drv Physical drive number (0, ...)
 *
 * \return status
 */
PFEnStatus diskInit(PFbyte drive);

/**
 * Reads the disk status
 *
 * \param drv Physical drive number (0, ...)
 *
 * \return status
 */
PFEnStatus diskGetStatus(PFbyte drive);

/**
 * Reads data from disk
 *
 * \param drive Physical drive number (0, ...)
 * \param buff Data buffer to store read data
 * \param sector Sector address (LBA)
 * \param count Number of sectors to read (1..128) 
 *
 * \return status
 */
PFEnStatus diskRead(PFbyte drive, PFbyte* buff, PFdword sector, PFbyte count);

/**
 * Writes data to disk
 *
 * \param drive Physical drive number (0, ...)
 * \param buff Data to write
 * \param sector Sector address (LBA)
 * \param count Number of sectors to write (1..128) 
 *
 * \return status
 */
PFEnStatus diskWrite(PFbyte drive, const PFbyte *buff, PFdword sector, PFbyte count);

/**
 * Disk configuration control
 * \param drive	Physical drive number (0..)
 * \param cmd Control command
 * \param buff Buffer to send/receive control data
 *
 * \return status
 */
PFEnStatus diskIoCtrl(PFbyte drive, PFbyte cmd, void* buff);


/* Command code for disk_ioctrl function */
#define CTRL_SYNC			0	/* Mandatory for write functions */
#define GET_SECTOR_COUNT	1	/* Mandatory for only f_mkfs() */
#define GET_SECTOR_SIZE		2
#define GET_BLOCK_SIZE		3	/* Mandatory for only f_mkfs() */
#define CTRL_POWER			4
#define CTRL_LOCK			5
#define CTRL_EJECT			6
#define CTRL_GET_STATE      7
#define CTRL_DISK_INIT      8
/* MMC/SDC command */
#define MMC_GET_TYPE		10
#define MMC_GET_CSD			11
#define MMC_GET_CID			12
#define MMC_GET_OCR			13
#define MMC_GET_SDSTAT		14


/* MMC/SDC specific ioctl command */
#define MMC_GET_TYPE		10	/* Get card type */
#define MMC_GET_CSD			11	/* Get CSD */
#define MMC_GET_CID			12	/* Get CID */
#define MMC_GET_OCR			13	/* Get OCR */
#define MMC_GET_SDSTAT		14	/* Get SD status */

/* ATA/CF specific ioctl command */
#define ATA_GET_REV			20	/* Get F/W revision */
#define ATA_GET_MODEL		21	/* Get model name */
#define ATA_GET_SN			22	/* Get serial number */

/* MMC card type flags (MMC_GET_TYPE) */
#define CT_MMC		0x01		/* MMC ver 3 */
#define CT_SD1		0x02		/* SD ver 1 */
#define CT_SD2		0x04		/* SD ver 2 */
#define CT_SDC		(CT_SD1|CT_SD2)	/* SD */
#define CT_BLOCK	0x08		/* Block addressing */


