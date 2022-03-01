/**
 * \file	    prime_fifo.h
 * \brief       Common FIFO API.
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 * 
 * \author      Alexey Gerenkov <alexey.gerenkov@phi-robotics.com>
 * \author      Nick Dolganov <nick.dolganov@phi-robotics.com>
 *
 * Review status: NO
 *
 */
#pragma once

/**
 *  \ingroup    core
 *  \defgroup   PF_FIFO FIFO
 *  @{
 *  
 *  \brief      Prime Fifo Description
 *  \details
 */
 
/** \brief Macro to enable overwriting FIFO when buffer is full */
#define PF_FIFO_OVERWRITE_ENABLE		1 

/** \brief FIFO descriptor */
typedef struct
{
	PFbyte* pBegin; 		    /**< pointer to the beginning of storage buffer */
	PFbyte* volatile pHead; 	/**< pointer to the first element 				*/
	PFbyte* volatile pTail; 	/**< pointer to the last element 				*/
	PFbyte* pEnd;				/**< pointer to the end of storage buffer 		*/
	PFdword size;				/**< fifo buffer size in bytes					*/
	PFdword count;  			/**< count of the elements in buffer 			*/
}PFFifo;

/** \brief Pointer to PFFifo structure		*/
typedef PFFifo *PFpFifo;

/**
 * Initializes FIFO.
 *
 * \param pFifo pointer to FIFO descriptor to initialize.
 * \param pBuf pointer to storage buffer.
 * \param uSize size of storage buffer.
 *
 * \return FIFO initialization status
 */
PFEnStatus pfFifoInit(PFpFifo pFifo, PFbyte* pBuf, PFdword uSize);


/**
 * Returns length of the FIFO.
 *
 * \param pFifo pointer to FIFO descriptor.
 *
 * \return length of the FIFO.
 */
PFdword pfFifoLength(PFpFifo pFifo);

/**
 * This function pushes byte into the FIFO.
 *
 * \param pFifo pointer to FIFO descriptor.
 * \param c byte to be pushed.
 *
 * \note It is not safe to call this function within concurrent environment on the processors like AVRs.
 */
PFEnBoolean pfFifoPush(PFpFifo pFifo, PFbyte c);

/**
 * This function pops a byte from the FIFO.
 *
 * \param pFifo pointer to FIFO descriptor.
 *
 * \return popped byte.
 *
 * \note It is not safe within concurrent environment on the processors like AVRs.
 */
PFbyte pfFifoPop(PFpFifo pFifo);

/**
 * This function empties the FIFO.
 *
 * \param pFifo pointer to FIFO descriptor.
 *
 * \note It is not safe within concurrent environment on the processors like AVRs.
 */
void pfFifoFlush(PFpFifo pFifo);

/**
 * This function checks whether the FIFO is empty.
 *
 * \param pFifo pointer to FIFO descriptor.
 *
 * \return enBooleanTrue if FIFO is empty, otherwise enBooleanFalse.
 *
 * \note It is not safe within concurrent environment on the processors like AVRs.
 */
PFEnBoolean pfFifoIsEmpty(const PFpFifo pFifo);

/**
 * This function checks whether the FIFO is full.
 *
 * \param pFifo pointer to FIFO descriptor.
 *
 * \return enBooleanTrue if FIFO is full, otherwise enBooleanFalse.
 *
 * \note It is not safe within concurrent environment on the processors like AVRs.
 */
PFEnBoolean pfFifoIsFull(const PFpFifo pFifo);


/**@}*/

