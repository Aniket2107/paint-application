/**
 * \file        prime_string.h
 * \brief       Prime Framework String Functions.
 * \copyright   Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 *  For licensing information, see the file 'LICENSE' in the root folder of
 *  this software module
 *
 * Review status: NO
 *
 */

#pragma once
/**
 *  \ingroup    core
 *  \defgroup   PF_STRING   STRING API
 *  @{
 *  
 *  \brief      Prime String API
 *  \details    
 */ 

/**
 * Copies the values of \a num bytes from the location pointed by \a src directly to the memory block pointed by \a dest.
 *
 * \param dest Pointer to the destination array where the content is to be copied.
 * \param src Pointer to the source of data to be copied. 
 * \param num Number of bytes to copy.
 *
 * \return Staus for memory copy
 */
PFEnStatus pfMemCopy(void* dest, const void* src, PFdword num);

/**
 * Sets the first \a num bytes of the block of memory pointed by \a ptr to the specified \a value. 
 *
 * \param ptr Pointer to the block of memory to fill.
 * \param value Value to be set. 
 * \param num Number of bytes to be set to the \a value.
 *
 * \return Status for memory set
 */
PFEnStatus pfMemSet(void* ptr, PFbyte value, PFdword num); 

/**
 * Compares the first \a num bytes of the block of memory pointed by \a ptr1 to the first \a num bytes pointed by \a ptr2, 
 * and returns \a enBooleanTrue if all values are equal else \a enBooleanFalse.
 *
 * \param ptr1 Pointer to block of memory.
 * \param ptr2 Pointer to block of memory.
 * \param num Number of bytes to compare.
 *
 * \retval enBooleanTrue if \a num bytes in both the buffers are equal.
 * \retval enBooleanFalse if any one among \a num bytes in both the buffers is not equal.
 */
PFEnBoolean pfMemCompare(const void* ptr1, const void* ptr2, PFdword num);

/**
 * Returns the length of the C string str.
 * The length of a C string is determined by the terminating null-character.
 * A C string is as long as the number of characters between the beginning of the string 
 * and the terminating null character (without including the terminating null character itself).
 *
 * \param str C string.
 *
 * \return Length of the string.
 */
PFdword pfStrLen(const char* str);

/**
 * Copies string from \a src to \a dest buffer.
 * The string copy terminates at null value.
 *
 * \param dest Destination buffer pointer to copy string.
 * \param src Source buffer to copy string from.
 *
 * \return Number of bytes copied.
 */
PFdword pfStrCopy(char* dest, const char* src);

/**
 * Reverses the order of letters in the \a str.
 * The reversed string will be stored in the same string.
 *
 * \param str Sdtring to be reversed.
 *
 * \return Status.
 */
PFEnStatus pfStrReverse(char* str);

/**
 * Function breaks a character string, pointed to by string, into a sequence of tokens.
 * The first time function is called, it returns a pointer to the first token in string.
 * In subsequent calls with str equal to NULL, function returns a pointer to the next token in the string.
 *
 * \param str pointer to the string.
 *
 * \param token tokens in string pointed to by this parameter.
 *
 * \return Returns a pointer to token in string.
 */ 
PFbyte* pfStringTokenize(char* str, const char* token);

/**
 * Function converts the floating-point value to a string.
 *
 * \param x floating-point value to convert in string format.
 * \param p Pointer to buffer where converted string will be loaded.
 *
 * \return Status.
 */
PFEnStatus pfFtoA(PFfloat x, char* p);

/**
 * Function converts the string to a integer value.
 *
 * \param str Number string to convert.
 * \param num Pointer to variable where the converted number will be loaded.
 *
 * \return Status.
 */
PFEnStatus pfAtoI(const char* str, PFdword* num);

/**
 * Function converts the string to a floating-point value.
 *
 * \param str Float number in string format to convert.
 * \param num Pointer to float variable where converted number will be loaded.
 *
 * \return Status.
 */
PFEnStatus pfAtoF(const char* str, PFfloat* num);

/**
 * Function converts the integer value to a string.
 *
 * \param num Integer number to convert in string 
 * \param str Pointer to buffer where converted string will be loaded.
 *
 * \return Status.
 */
PFEnStatus pfItoA(PFsdword num, char* str);

/** @} */

