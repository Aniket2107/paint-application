/**
 * \file 	prime_cmInstr.h
 * \brief   CM3 Cortex-M Core Instruction Access Header File
 * \copyright Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 * For licensing information, see the file 'LICENSE' in the root folder of
 * this software module.
 * 
 * Review status: NO
 */

#ifndef PF_CORE_CORTEX_M_H_SPE
#define PF_CORE_CORTEX_M_H_SPE

#if defined ( __CC_ARM )
/* ##########################  Core Instruction Access  ######################### */

/* 
 * \ingroup CM3_CORE
 * \defgroup CM3_Core_InstructionInterface CM3 Core Instruction Interface
  Access to dedicated instructions
  @{
*/

#if(PF_CORTEX_M3 >= 0x03)

/**
 * \brief		Reverse bit order of value
 * \details		This function reverses the bit order of the given value.
 * 
 * \param [in]    value  Value to reverse
 * \return               Reversed value
 */
#define PF_RBIT                            __rbit

/**
 * \brief		LDR Exclusive (8 bit)
 * \details		This function performs a exclusive LDR command for 8 bit value.
 * 
 * \param [in]    ptr  Pointer to data
 * \return             value of type PFbyte at (*ptr)
 */
#define PF_LDREXB(ptr)                     ((PFbyte ) __ldrex(ptr))

/**
 * \brief		LDR Exclusive (16 bit)
 * \details		This function performs a exclusive LDR command for 16 bit values.
 * 
 * \param [in]    ptr  Pointer to data
 * \return        value of type PFword at (*ptr)
 */
#define PF_LDREXH(ptr)                     ((PFword) __ldrex(ptr))

/**
 * \brief		LDR Exclusive (32 bit)
 * \details		This function performs a exclusive LDR command for 32 bit values.
 * 
 * \param [in]    ptr  Pointer to data
 * \return        value of type PFdword at (*ptr)
 */
#define PF_LDREXW(ptr)                     ((PFdword ) __ldrex(ptr))

/**
 * \brief		STR Exclusive (8 bit)
 * \detials		This function performs a exclusive STR command for 8 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
#define PF_STREXB(value, ptr)              __strex(value, ptr)

/**
 * \brief		STR Exclusive (16 bit)
 * \details		This function performs a exclusive STR command for 16 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
#define PF_STREXH(value, ptr)              __strex(value, ptr)

/**
 * \brief		STR Exclusive (32 bit)
 * \details		This function performs a exclusive STR command for 32 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
#define PF_STREXW(value, ptr)              __strex(value, ptr)

/**
 * \brief		Remove the exclusive lock
 * \details		This function removes the exclusive lock which is created by LDREX.
 */
#if (__ARMCC_VERSION < 400000)
extern void __CLREX(void);
#else  /* (__ARMCC_VERSION >= 400000)  */
#define __CLREX                           __clrex
#endif /* __ARMCC_VERSION  */

/**
 * \brief		Signed Saturate
 * \details		This function saturates a signed value.
 * 
 * \param [in]  value  Value to be saturated
 * \param [in]    sat  Bit position to saturate to (1..32)
 * \return             Saturated value
 */
#define PF_SSAT                            __ssat

/**
 * \brief  		Unsigned Saturate
 * \details		This function saturates an unsigned value.
 * 
 * \param [in]  value  Value to be saturated
 * \param [in]    sat  Bit position to saturate to (0..31)
 * \return             Saturated value
 */
#define PF_USAT                            __usat

/**
 * \brief		Count leading zeros
 * \details		This function counts the number of leading zeros of a data value.
 * 
 * \param [in]  value  Value to count the leading zeros
 * \return             number of leading zeros in value
 */
#define PF_CLZ                             __clz

#endif /* (PF_CORTEX_M3 >= 0x03) */

#elif (defined (__GNUC__))					/*------------------ GNU Compiler ---------------------*/	
/* GNU gcc specific functions */

#if       (PF_CORTEX_M3 >= 0x03)

/**
 * \brief		Reverse bit order of value
 * \details		This function reverses the bit order of the given value.
 * 
 * \param [in]    value  Value to reverse
 * \return               Reversed value
 */
PF_C_STATIC_INLINE PFdword PF_RBIT(PFdword value)
{
  PFdword result;

   PF_C_ASM volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
   return(result);
}

/**
 * \brief		LDR Exclusive (8 bit)
 * \details		This function performs a exclusive LDR command for 8 bit value.
 * 
 * \param [in]    ptr  Pointer to data
 * \return             value of type PFbyte at (*ptr)
 */
PF_C_STATIC_INLINE PFbyte PF_LDREXB(volatile PFbyte *addr)
{
    PFbyte result;

   PF_C_ASM volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * \brief		LDR Exclusive (16 bit)
 * \details		This function performs a exclusive LDR command for 16 bit values.
 * 
 * \param [in]    ptr  Pointer to data
 * \return        value of type PFword at (*ptr)
 */
PF_C_STATIC_INLINE PFword PF_LDREXH(volatile PFword *addr)
{
    PFword result;

   PF_C_ASM volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * \brief		LDR Exclusive (32 bit)
 * \details		This function performs a exclusive LDR command for 32 bit values.
 * 
 * \param [in]    ptr  Pointer to data
 * \return        value of type PFdword at (*ptr)
 */
PF_C_STATIC_INLINE PFdword PF_LDREXW(volatile PFdword *addr)
{
    PFdword result;

   PF_C_ASM volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * \brief		STR Exclusive (8 bit)
 * \details		This function performs a exclusive STR command for 8 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
PF_C_STATIC_INLINE PFdword PF_STREXB(PFbyte value, volatile PFbyte *addr)
{
   PFdword result;

   PF_C_ASM volatile ("strexb %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}

/**
 * \brief		STR Exclusive (16 bit)
 * \details		This function performs a exclusive STR command for 16 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
PF_C_STATIC_INLINE PFdword PF_STREXH(PFword value, volatile PFword *addr)
{
   PFdword result;

   PF_C_ASM volatile ("strexh %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}

/**
 * \brief		STR Exclusive (32 bit)
 * \details		This function performs a exclusive STR command for 32 bit values.
 * 
 * \param [in]  value  Value to store
 * \param [in]    ptr  Pointer to location
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
PF_C_STATIC_INLINE PFdword PF_STREXW(PFdword value, volatile PFdword *addr)
{
   PFdword result;

   PF_C_ASM volatile ("strex %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}

/**
 * \brief		Remove the exclusive lock
 * \details		This function removes the exclusive lock which is created by LDREX.
 */
PF_C_STATIC_INLINE void PF_CLREX(void)
{
  PF_C_ASM volatile ("clrex");
}

/**
 * \brief		Signed Saturate
 * \details		This function saturates a signed value.
 * 
 * \param [in]  value  Value to be saturated
 * \param [in]    sat  Bit position to saturate to (1..32)
 * \return             Saturated value
 */
#define PF_SSAT(ARG1,ARG2) \
({                          \
  PFdword __RES, __ARG1 = (ARG1); \
  PF_C_ASM ("ssat %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
  __RES; \
 })

/**
 * \brief		Unsigned Saturate
 * \details		This function saturates an unsigned value.
 * 
 * \param [in]  value  Value to be saturated
 * \param [in]    sat  Bit position to saturate to (0..31)
 * \return             Saturated value
 */
#define PF_USAT(ARG1,ARG2) \
({                          \
  PFdword __RES, __ARG1 = (ARG1); \
  PF_C_ASM ("usat %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) ); \
  __RES; \
 })

/**
 * \brief		Count leading zeros
 * \details		This function counts the number of leading zeros of a data value.
 * 
 * \param [in]  value  Value to count the leading zeros
 * \return             number of leading zeros in value
 */
PF_C_STATIC_INLINE PFbyte PF_CLZ(PFdword value)
{
  PFbyte result;

  PF_C_ASM volatile ("clz %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

#endif /* (PF_CORTEX_M3 >= 0x03) */

#endif

/*@}*/ /* end of group CM3_Core_InstructionInterface */

#endif /* PF_CORE_CORTEX_M_H_SPE */
