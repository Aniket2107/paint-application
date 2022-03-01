/********************************************************************************
* \file    		prime_cmFunc.h													
* \brief    	CM3 Cortex-M Core Function Access Header File
* \copyright 	Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
* 
* \par
* For licensing information, see the file 'LICENSE' in the root folder of
* this software module.
* 
* Review status: NO
******************************************************************************/

#ifndef PF_CORTEX_CM_FUNC_H
#define PF_CORTEX_CM_FUNC_H

/* ###########################  Core Function Access  ########################### */
/*  
 *  \ingroup  CM3_Core_FunctionInterface   
    \defgroup CM3_Core_RegAccFunctions CM3 Core Register Access Functions
  @{
 */

#if defined ( __CC_ARM   ) /*------------------ RealView Compiler ----------------*/
/* ARM armcc specific functions */

/**
 * \brief		Get Control Register
 * \details		This function returns the content of the Control Register.
 * 
 * \return		Control Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_CONTROL(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_CONTROL(void)
{
  register PFdword __regControl         PF_C_ASM("control");
  return(__regControl);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Set Control Register
 * \details		This function writes the given value to the Control Register.
 * 
 * \param [in]  control  Control Register value to set
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_CONTROL(PFdword control);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_CONTROL(PFdword control)
{
  register PFdword __regControl         PF_C_ASM("control");
  __regControl = control;
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Get ISPR Register
 * \details		This function returns the content of the ISPR Register.
 * 
 * \return		ISPR Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_IPSR(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_IPSR(void)
{
  register PFdword __regIPSR          PF_C_ASM("ipsr");
  return(__regIPSR);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief  	Get APSR Register
 * \details	This function returns the content of the APSR Register.
 * 
 * \return               APSR Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_APSR(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_APSR(void)
{
  register PFdword __regAPSR          PF_C_ASM("apsr");
  return(__regAPSR);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Get xPSR Register
 * \details		This function returns the content of the xPSR Register.
 * 
 * \return               xPSR Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_xPSR(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_xPSR(void)
{
  register PFdword __regXPSR          PF_C_ASM("xpsr");
  return(__regXPSR);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief  		Get Process Stack Pointer
 * \details		This function returns the current value of the Process Stack Pointer (PSP).
 * 
 * \return               PSP Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_PSP(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_PSP(void)
{
  register PFdword __regProcessStackPointer  PF_C_ASM("psp");
  return(__regProcessStackPointer);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Set Process Stack Pointer
 * \details		This function assigns the given value to the Process Stack Pointer (PSP).
 * 
 * \param [in]    topOfProcStack  Process Stack Pointer value to set
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_PSP(PFdword topOfProcStack);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_PSP(PFdword topOfProcStack)
{
  register PFdword __regProcessStackPointer  PF_C_ASM("psp");
  __regProcessStackPointer = topOfProcStack;
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Get Main Stack Pointer
 * \details		This function returns the current value of the Main Stack Pointer (MSP).
 * 
 * \return               MSP Register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_MSP(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_MSP(void)
{
  register PFdword __regMainStackPointer     PF_C_ASM("msp");
  return(__regMainStackPointer);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief  		Set Main Stack Pointer
 * \details		This function assigns the given value to the Main Stack Pointer (MSP).
 * 
 * \param [in]    topOfMainStack  Main Stack Pointer value to set
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_MSP(PFdword topOfMainStack);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_MSP(PFdword topOfMainStack)
{
  register PFdword __regMainStackPointer     PF_C_ASM("msp");
  __regMainStackPointer = topOfMainStack;
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief  		Get Priority Mask
 * \details		This function returns the current state of the priority mask bit from the Priority Mask Register.
 * 
 * \return               Priority Mask value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_PRIMASK(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_PRIMASK(void)
{
  register PFdword __regPriMask         PF_C_ASM("primask");
  return(__regPriMask);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Set Priority Mask
 * \details		This function assigns the given value to the Priority Mask Register.
 * 
 * \param [in]    priMask  Priority Mask
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_PRIMASK(PFdword priMask);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_PRIMASK(PFdword priMask)
{
  register PFdword __regPriMask         PF_C_ASM("primask");
  __regPriMask = (priMask);
}
#endif /*  __ARMCC_VERSION  */ 
 
#if       (PF_CORTEX_M3 >= 0x03)

/**
 * \brief		Enable FIQ
 * \details		This function enables FIQ interrupts by clearing the F-bit in the CPSR.
 * 
 * \note 		Can only be executed in Privileged modes.
 */
#define __enable_fault_irq                __enable_fiq

/**
 * \brief		Disable FIQ
 * \details		This function disables FIQ interrupts by setting the F-bit in the CPSR.
 * 
 * \note		Can only be executed in Privileged modes.
 */
#define __disable_fault_irq               __disable_fiq

/**
 * \brief		Get Base Priority
 * \details		This function returns the current value of the Base Priority register.
 * 
 * \return               Base Priority register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_BASEPRI(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword  __get_BASEPRI(void)
{
  register PFdword __regBasePri         PF_C_ASM("basepri");
  return(__regBasePri);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Set Base Priority
 * \details		This function assigns the given value to the Base Priority register.
 * 
 * \param [in]    basePri  Base Priority value to set
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_BASEPRI(PFdword basePri);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_BASEPRI(PFdword basePri)
{
  register PFdword __regBasePri         PF_C_ASM("basepri");
  __regBasePri = (basePri & 0xff);
}
#endif /*  __ARMCC_VERSION  */ 
 
/**
 * \brief		Get Fault Mask
 * \details		This function returns the current value of the Fault Mask register.
 * 
 * \return               Fault Mask register value
 */
#if       (__ARMCC_VERSION <  400000)
extern          PFdword __get_FAULTMASK(void);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE PFdword __get_FAULTMASK(void)
{
  register PFdword __regFaultMask       PF_C_ASM("faultmask");
  return(__regFaultMask);
}
#endif /*  __ARMCC_VERSION  */ 

/**
 * \brief		Set Fault Mask
 * \details		This function assigns the given value to the Fault Mask register.
 * 
 * \param [in]    faultMask  Fault Mask value to set
 */
#if       (__ARMCC_VERSION <  400000)
extern          void __set_FAULTMASK(PFdword faultMask);
#else  /* (__ARMCC_VERSION >= 400000) */
PF_C_STATIC_INLINE void __set_FAULTMASK(PFdword faultMask)
{
  register PFdword __regFaultMask       PF_C_ASM("faultmask");
  __regFaultMask = (faultMask & 1);
}
#endif /*  __ARMCC_VERSION  */ 

#endif /* (PF_CORTEX_M3 >= 0x03) */

#if       (PF_CORTEX_M3 == 0x04)

/**
 * \brief		Get FPSCR
 * \details		This function returns the current value of the Floating Point Status/Control register.
 * 
 * \return               Floating Point Status/Control register value
 */
PF_C_STATIC_INLINE PFdword __get_FPSCR(void)
{
#if (__FPU_PRESENT == 1)
  register PFdword __regfpscr         PF_C_ASM("fpscr");
  return(__regfpscr);
#else
   return(0);
#endif
}

/**
 * \brief		Set FPSCR
 * \details		This function assigns the given value to the Floating Point Status/Control register.
 * 
 * \param [in]    fpscr  Floating Point Status/Control value to set
 */
PF_C_STATIC_INLINE void __set_FPSCR(PFdword fpscr)
{
#if (__FPU_PRESENT == 1)
  register PFdword __regfpscr         PF_C_ASM("fpscr");
  __regfpscr = (fpscr);
#endif
}

#endif /* (PF_CORTEX_M3 == 0x04) */

#elif (defined (__GNUC__)) 							/*------------------ GNU Compiler ---------------------*/
/* GNU gcc specific functions */

/**
 * \brief		Enable IRQ Interrupts
 * \details		This function enables IRQ interrupts by clearing the I-bit in the CPSR.
 * 
 * \note		Can only be executed in Privileged modes.
 */
PF_C_STATIC_INLINE void __enable_irq(void)
{
  PF_C_ASM volatile ("cpsie i");
}

/**
 * \brief		Disable IRQ Interrupts
 * \details		This function disables IRQ interrupts by setting the I-bit in the CPSR.
 * 
 * \note		Can only be executed in Privileged modes.
 */
PF_C_STATIC_INLINE void __disable_irq(void)
{
  PF_C_ASM volatile ("cpsid i");
}

/**
 * \brief		Get Control Register
 * \details		This function returns the content of the Control Register.
 * 
 * \return               Control Register value
 */
PF_C_STATIC_INLINE PFdword __get_CONTROL(void)
{
  PFdword result;

  PF_C_ASM volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}

/**
 * \brief		Set Control Register
 * \details		This function writes the given value to the Control Register.
 * 
 * \param [in]    control  Control Register value to set
 */
PF_C_STATIC_INLINE void __set_CONTROL(PFdword control)
{
  PF_C_ASM volatile ("MSR control, %0" : : "r" (control) );
}

/**
 * \brief  		Get ISPR Register
 * \details		This function returns the content of the ISPR Register.
 * 
 * \return               ISPR Register value
 */
PF_C_STATIC_INLINE PFdword __get_IPSR(void)
{
  PFdword result;

  PF_C_ASM volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}

/**
 * \brief		Get APSR Register
 * \details		This function returns the content of the APSR Register.
 * 
 * \return               APSR Register value
 */
PF_C_STATIC_INLINE PFdword __get_APSR(void)
{
  PFdword result;

  PF_C_ASM volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}

/**
 * \brief  		Get xPSR Register
 * \details		This function returns the content of the xPSR Register.
 * 
 * \return               xPSR Register value
 */
PF_C_STATIC_INLINE PFdword __get_xPSR(void)
{
  PFdword result;

  PF_C_ASM volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}

/**
 * \brief		Get Process Stack Pointer
 * \details		This function returns the current value of the Process Stack Pointer (PSP).
 * 
 * \return               PSP Register value
 */
PF_C_STATIC_INLINE PFdword __get_PSP(void)
{
  register PFdword result;

  PF_C_ASM volatile ("MRS %0, psp\n"  : "=r" (result) );
  return(result);
}
 
/**
 * \brief		Set Process Stack Pointer
 * \details		This function assigns the given value to the Process Stack Pointer (PSP).
 * 
 * \param [in]    topOfProcStack  Process Stack Pointer value to set
 */
PF_C_STATIC_INLINE void __set_PSP(PFdword topOfProcStack)
{
  PF_C_ASM volatile ("MSR psp, %0\n" : : "r" (topOfProcStack) );
}

/**
 * \brief		Get Main Stack Pointer
 * \details		This function returns the current value of the Main Stack Pointer (MSP).
 * 
 * \return               MSP Register value
 */
PF_C_STATIC_INLINE PFdword __get_MSP(void)
{
  register PFdword result;

  PF_C_ASM volatile ("MRS %0, msp\n" : "=r" (result) );
  return(result);
}
 
/**
 * \brief		Set Main Stack Pointer
 * \details		This function assigns the given value to the Main Stack Pointer (MSP).
 * 
 * \param [in]    topOfMainStack  Main Stack Pointer value to set
 */
PF_C_STATIC_INLINE void __set_MSP(PFdword topOfMainStack)
{
  PF_C_ASM volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) );
}

/**
 * \brief  		Get Priority Mask
 * \details		This function returns the current state of the priority mask bit from the Priority Mask Register.
 * 
 * \return               Priority Mask value
 */
PF_C_STATIC_INLINE PFdword __get_PRIMASK(void)
{
  PFdword result;

  PF_C_ASM volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}

/**
 * \brief		Set Priority Mask
 * \details	    This function assigns the given value to the Priority Mask Register.
 * 
 * \param [in]    priMask  Priority Mask
 */
PF_C_STATIC_INLINE void __set_PRIMASK(PFdword priMask)
{
  PF_C_ASM volatile ("MSR primask, %0" : : "r" (priMask) );
}
 
#if       (PF_CORTEX_M3 >= 0x03)

/**
 * \brief  		Enable FIQ
 * \details		This function enables FIQ interrupts by clearing the F-bit in the CPSR.
 * 
 * \note		Can only be executed in Privileged modes.
 */
PF_C_STATIC_INLINE void __enable_fault_irq(void)
{
  PF_C_ASM volatile ("cpsie f");
}

/**
 * \brief		Disable FIQ
 * \details		This function disables FIQ interrupts by setting the F-bit in the CPSR.
 * 
 * \note		Can only be executed in Privileged modes.
 */
PF_C_STATIC_INLINE void __disable_fault_irq(void)
{
  PF_C_ASM volatile ("cpsid f");
}

/**
 * \brief		Get Base Priority
 * \details		This function returns the current value of the Base Priority register.
 * 
 * \return               Base Priority register value
 */
PF_C_STATIC_INLINE PFdword __get_BASEPRI(void)
{
  PFdword result;
  
  PF_C_ASM volatile ("MRS %0, basepri_max" : "=r" (result) );
  return(result);
}

/**
 * \brief		Set Base Priority
 * \details		This function assigns the given value to the Base Priority register.
 * 
 * \param [in]    basePri  Base Priority value to set
 */
PF_C_STATIC_INLINE void __set_BASEPRI(PFdword value)
{
  PF_C_ASM volatile ("MSR basepri, %0" : : "r" (value) );
}

/**
 * \brief		Get Fault Mask
 * \details		This function returns the current value of the Fault Mask register.
 * 
 * \return               Fault Mask register value
 */
PF_C_STATIC_INLINE PFdword __get_FAULTMASK(void)
{
  PFdword result;
  
  PF_C_ASM volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}

/**
 * \brief		Set Fault Mask
 * \details		This function assigns the given value to the Fault Mask register.
 * 
 * \param [in]    faultMask  Fault Mask value to set
 */
PF_C_STATIC_INLINE void __set_FAULTMASK(PFdword faultMask)
{
  PF_C_ASM volatile ("MSR faultmask, %0" : : "r" (faultMask) );
}

#endif /* (PF_CORTEX_M3 >= 0x03) */

#if       (PF_CORTEX_M3 == 0x04)

/**
 * \brief		Get FPSCR
 * \details		This function returns the current value of the Floating Point Status/Control register.
 * 
 * \return               Floating Point Status/Control register value
 */
PF_C_STATIC_INLINE PFdword __get_FPSCR(void)
{
#if (__FPU_PRESENT == 1)
  PFdword result;

  PF_C_ASM volatile ("MRS %0, fpscr" : "=r" (result) );
  return(result);
#else
   return(0);
#endif
}

/**
 * \brief		Set FPSCR
 * \details		This function assigns the given value to the Floating Point Status/Control register.
 * 
 * \param [in]    fpscr  Floating Point Status/Control value to set
 */
PF_C_STATIC_INLINE void __set_FPSCR(PFdword fpscr)
{
#if (__FPU_PRESENT == 1)
  PF_C_ASM volatile ("MSR fpscr, %0" : : "r" (fpscr) );
#endif
}

#endif /* (PF_CORTEX_M3 == 0x04) */

#endif

/*@} end of CM3_Core_RegAccFunctions */

#endif /* PF_CORTEX_CM_FUNC_H */
