/**
 * \file     	prime_cm3.h															
 * \brief    	Cortex-M3 Core Peripheral Access Layer Header File
 * \copyright	Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd
 * 
 * \par
 * For licensing information, see the file 'LICENSE' in the root folder of
 * this software module.
 * 
 * Review status: NO
 */

#ifdef __cplusplus
 extern "C" {
#endif

#ifndef PF_CORE_CORTEX_M3_H_GENERIC
#define PF_CORE_CORTEX_M3_H_GENERIC

#define PF_CORTEX_M3                (0x03)   /*!< Cortex core                    */

#include "prime_compiler.h"
#include "prime_types.h"                /*!< standard types definitions                      */
#include "prime_cmInstr.h"              /*!< Core Instruction Access                         */
#include "prime_cmFunc.h"               /*!< Core Function Access                            */

#endif /* PF_CORE_CORTEX_M3_H_GENERIC */


#ifndef PF_CORTEX_M3_GENERIC

#ifndef PF_CORE_CORTEX_M3_H_DEP
#define PF_CORE_CORTEX_M3_H_DEP

/* SCB CPUID Register Definitions */
#define SCB_CPUID_IMPLEMENTER_Pos          24                                             /*!< SCB CPUID: IMPLEMENTER Position */
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFUL << SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER Mask */

#define SCB_CPUID_VARIANT_Pos              20                                             /*!< SCB CPUID: VARIANT Position */
#define SCB_CPUID_VARIANT_Msk              (0xFUL << SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT Mask */

#define SCB_CPUID_PARTNO_Pos                4                                             /*!< SCB CPUID: PARTNO Position */
#define SCB_CPUID_PARTNO_Msk               (0xFFFUL << SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO Mask */

#define SCB_CPUID_REVISION_Pos              0                                             /*!< SCB CPUID: REVISION Position */
#define SCB_CPUID_REVISION_Msk             (0xFUL << SCB_CPUID_REVISION_Pos)              /*!< SCB CPUID: REVISION Mask */

/* SCB Interrupt Control State Register Definitions */
#define SCB_ICSR_NMIPENDSET_Pos            31                                             /*!< SCB ICSR: NMIPENDSET Position */
#define SCB_ICSR_NMIPENDSET_Msk            (1UL << SCB_ICSR_NMIPENDSET_Pos)               /*!< SCB ICSR: NMIPENDSET Mask */

#define SCB_ICSR_PENDSVSET_Pos             28                                             /*!< SCB ICSR: PENDSVSET Position */
#define SCB_ICSR_PENDSVSET_Msk             (1UL << SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET Mask */

#define SCB_ICSR_PENDSVCLR_Pos             27                                             /*!< SCB ICSR: PENDSVCLR Position */
#define SCB_ICSR_PENDSVCLR_Msk             (1UL << SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR Mask */

#define SCB_ICSR_PENDSTSET_Pos             26                                             /*!< SCB ICSR: PENDSTSET Position */
#define SCB_ICSR_PENDSTSET_Msk             (1UL << SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET Mask */

#define SCB_ICSR_PENDSTCLR_Pos             25                                             /*!< SCB ICSR: PENDSTCLR Position */
#define SCB_ICSR_PENDSTCLR_Msk             (1UL << SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR Mask */

#define SCB_ICSR_ISRPREEMPT_Pos            23                                             /*!< SCB ICSR: ISRPREEMPT Position */
#define SCB_ICSR_ISRPREEMPT_Msk            (1UL << SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT Mask */

#define SCB_ICSR_ISRPENDING_Pos            22                                             /*!< SCB ICSR: ISRPENDING Position */
#define SCB_ICSR_ISRPENDING_Msk            (1UL << SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING Mask */

#define SCB_ICSR_VECTPENDING_Pos           12                                             /*!< SCB ICSR: VECTPENDING Position */
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFUL << SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING Mask */

#define SCB_ICSR_RETTOBASE_Pos             11                                             /*!< SCB ICSR: RETTOBASE Position */
#define SCB_ICSR_RETTOBASE_Msk             (1UL << SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE Mask */

#define SCB_ICSR_VECTACTIVE_Pos             0                                             /*!< SCB ICSR: VECTACTIVE Position */
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFUL << SCB_ICSR_VECTACTIVE_Pos)           /*!< SCB ICSR: VECTACTIVE Mask */

/* SCB Interrupt Control State Register Definitions */
#define SCB_VTOR_TBLBASE_Pos               29                                             /*!< SCB VTOR: TBLBASE Position */
#define SCB_VTOR_TBLBASE_Msk               (1UL << SCB_VTOR_TBLBASE_Pos)                  /*!< SCB VTOR: TBLBASE Mask */

#define SCB_VTOR_TBLOFF_Pos                 7                                             /*!< SCB VTOR: TBLOFF Position */
#define SCB_VTOR_TBLOFF_Msk                (0x3FFFFFUL << SCB_VTOR_TBLOFF_Pos)            /*!< SCB VTOR: TBLOFF Mask */

/* SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16                                             /*!< SCB AIRCR: VECTKEY Position */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */

#define SCB_AIRCR_VECTKEYSTAT_Pos          16                                             /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */

#define SCB_AIRCR_ENDIANESS_Pos            15                                             /*!< SCB AIRCR: ENDIANESS Position */
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */

#define SCB_AIRCR_PRIGROUP_Pos              8                                             /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */

#define SCB_AIRCR_SYSRESETREQ_Pos           2                                             /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1                                             /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */

#define SCB_AIRCR_VECTRESET_Pos             0                                             /*!< SCB AIRCR: VECTRESET Position */
#define SCB_AIRCR_VECTRESET_Msk            (1UL << SCB_AIRCR_VECTRESET_Pos)               /*!< SCB AIRCR: VECTRESET Mask */

/* SCB System Control Register Definitions */
#define SCB_SCR_SEVONPEND_Pos               4                                             /*!< SCB SCR: SEVONPEND Position */
#define SCB_SCR_SEVONPEND_Msk              (1UL << SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND Mask */

#define SCB_SCR_SLEEPDEEP_Pos               2                                             /*!< SCB SCR: SLEEPDEEP Position */
#define SCB_SCR_SLEEPDEEP_Msk              (1UL << SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP Mask */

#define SCB_SCR_SLEEPONEXIT_Pos             1                                             /*!< SCB SCR: SLEEPONEXIT Position */
#define SCB_SCR_SLEEPONEXIT_Msk            (1UL << SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT Mask */

/* SCB Configuration Control Register Definitions */
#define SCB_CCR_STKALIGN_Pos                9                                             /*!< SCB CCR: STKALIGN Position */
#define SCB_CCR_STKALIGN_Msk               (1UL << SCB_CCR_STKALIGN_Pos)                  /*!< SCB CCR: STKALIGN Mask */

#define SCB_CCR_BFHFNMIGN_Pos               8                                             /*!< SCB CCR: BFHFNMIGN Position */
#define SCB_CCR_BFHFNMIGN_Msk              (1UL << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN Mask */

#define SCB_CCR_DIV_0_TRP_Pos               4                                             /*!< SCB CCR: DIV_0_TRP Position */
#define SCB_CCR_DIV_0_TRP_Msk              (1UL << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP Mask */

#define SCB_CCR_UNALIGN_TRP_Pos             3                                             /*!< SCB CCR: UNALIGN_TRP Position */
#define SCB_CCR_UNALIGN_TRP_Msk            (1UL << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP Mask */

#define SCB_CCR_USERSETMPEND_Pos            1                                             /*!< SCB CCR: USERSETMPEND Position */
#define SCB_CCR_USERSETMPEND_Msk           (1UL << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND Mask */

#define SCB_CCR_NONBASETHRDENA_Pos          0                                             /*!< SCB CCR: NONBASETHRDENA Position */
#define SCB_CCR_NONBASETHRDENA_Msk         (1UL << SCB_CCR_NONBASETHRDENA_Pos)            /*!< SCB CCR: NONBASETHRDENA Mask */

/* SCB System Handler Control and State Register Definitions */
#define SCB_SHCSR_USGFAULTENA_Pos          18                                             /*!< SCB SHCSR: USGFAULTENA Position */
#define SCB_SHCSR_USGFAULTENA_Msk          (1UL << SCB_SHCSR_USGFAULTENA_Pos)             /*!< SCB SHCSR: USGFAULTENA Mask */

#define SCB_SHCSR_BUSFAULTENA_Pos          17                                             /*!< SCB SHCSR: BUSFAULTENA Position */
#define SCB_SHCSR_BUSFAULTENA_Msk          (1UL << SCB_SHCSR_BUSFAULTENA_Pos)             /*!< SCB SHCSR: BUSFAULTENA Mask */

#define SCB_SHCSR_MEMFAULTENA_Pos          16                                             /*!< SCB SHCSR: MEMFAULTENA Position */
#define SCB_SHCSR_MEMFAULTENA_Msk          (1UL << SCB_SHCSR_MEMFAULTENA_Pos)             /*!< SCB SHCSR: MEMFAULTENA Mask */

#define SCB_SHCSR_SVCALLPENDED_Pos         15                                             /*!< SCB SHCSR: SVCALLPENDED Position */
#define SCB_SHCSR_SVCALLPENDED_Msk         (1UL << SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED Mask */

#define SCB_SHCSR_BUSFAULTPENDED_Pos       14                                             /*!< SCB SHCSR: BUSFAULTPENDED Position */
#define SCB_SHCSR_BUSFAULTPENDED_Msk       (1UL << SCB_SHCSR_BUSFAULTPENDED_Pos)          /*!< SCB SHCSR: BUSFAULTPENDED Mask */

#define SCB_SHCSR_MEMFAULTPENDED_Pos       13                                             /*!< SCB SHCSR: MEMFAULTPENDED Position */
#define SCB_SHCSR_MEMFAULTPENDED_Msk       (1UL << SCB_SHCSR_MEMFAULTPENDED_Pos)          /*!< SCB SHCSR: MEMFAULTPENDED Mask */

#define SCB_SHCSR_USGFAULTPENDED_Pos       12                                             /*!< SCB SHCSR: USGFAULTPENDED Position */
#define SCB_SHCSR_USGFAULTPENDED_Msk       (1UL << SCB_SHCSR_USGFAULTPENDED_Pos)          /*!< SCB SHCSR: USGFAULTPENDED Mask */

#define SCB_SHCSR_SYSTICKACT_Pos           11                                             /*!< SCB SHCSR: SYSTICKACT Position */
#define SCB_SHCSR_SYSTICKACT_Msk           (1UL << SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT Mask */

#define SCB_SHCSR_PENDSVACT_Pos            10                                             /*!< SCB SHCSR: PENDSVACT Position */
#define SCB_SHCSR_PENDSVACT_Msk            (1UL << SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT Mask */

#define SCB_SHCSR_MONITORACT_Pos            8                                             /*!< SCB SHCSR: MONITORACT Position */
#define SCB_SHCSR_MONITORACT_Msk           (1UL << SCB_SHCSR_MONITORACT_Pos)              /*!< SCB SHCSR: MONITORACT Mask */

#define SCB_SHCSR_SVCALLACT_Pos             7                                             /*!< SCB SHCSR: SVCALLACT Position */
#define SCB_SHCSR_SVCALLACT_Msk            (1UL << SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT Mask */

#define SCB_SHCSR_USGFAULTACT_Pos           3                                             /*!< SCB SHCSR: USGFAULTACT Position */
#define SCB_SHCSR_USGFAULTACT_Msk          (1UL << SCB_SHCSR_USGFAULTACT_Pos)             /*!< SCB SHCSR: USGFAULTACT Mask */

#define SCB_SHCSR_BUSFAULTACT_Pos           1                                             /*!< SCB SHCSR: BUSFAULTACT Position */
#define SCB_SHCSR_BUSFAULTACT_Msk          (1UL << SCB_SHCSR_BUSFAULTACT_Pos)             /*!< SCB SHCSR: BUSFAULTACT Mask */

#define SCB_SHCSR_MEMFAULTACT_Pos           0                                             /*!< SCB SHCSR: MEMFAULTACT Position */
#define SCB_SHCSR_MEMFAULTACT_Msk          (1UL << SCB_SHCSR_MEMFAULTACT_Pos)             /*!< SCB SHCSR: MEMFAULTACT Mask */

/* SCB Configurable Fault Status Registers Definitions */
#define SCB_CFSR_USGFAULTSR_Pos            16                                             /*!< SCB CFSR: Usage Fault Status Register Position */
#define SCB_CFSR_USGFAULTSR_Msk            (0xFFFFUL << SCB_CFSR_USGFAULTSR_Pos)          /*!< SCB CFSR: Usage Fault Status Register Mask */

#define SCB_CFSR_BUSFAULTSR_Pos             8                                             /*!< SCB CFSR: Bus Fault Status Register Position */
#define SCB_CFSR_BUSFAULTSR_Msk            (0xFFUL << SCB_CFSR_BUSFAULTSR_Pos)            /*!< SCB CFSR: Bus Fault Status Register Mask */

#define SCB_CFSR_MEMFAULTSR_Pos             0                                             /*!< SCB CFSR: Memory Manage Fault Status Register Position */
#define SCB_CFSR_MEMFAULTSR_Msk            (0xFFUL << SCB_CFSR_MEMFAULTSR_Pos)            /*!< SCB CFSR: Memory Manage Fault Status Register Mask */

/* SCB Hard Fault Status Registers Definitions */
#define SCB_HFSR_DEBUGEVT_Pos              31                                             /*!< SCB HFSR: DEBUGEVT Position */
#define SCB_HFSR_DEBUGEVT_Msk              (1UL << SCB_HFSR_DEBUGEVT_Pos)                 /*!< SCB HFSR: DEBUGEVT Mask */

#define SCB_HFSR_FORCED_Pos                30                                             /*!< SCB HFSR: FORCED Position */
#define SCB_HFSR_FORCED_Msk                (1UL << SCB_HFSR_FORCED_Pos)                   /*!< SCB HFSR: FORCED Mask */

#define SCB_HFSR_VECTTBL_Pos                1                                             /*!< SCB HFSR: VECTTBL Position */
#define SCB_HFSR_VECTTBL_Msk               (1UL << SCB_HFSR_VECTTBL_Pos)                  /*!< SCB HFSR: VECTTBL Mask */

/* SCB Debug Fault Status Register Definitions */
#define SCB_DFSR_EXTERNAL_Pos               4                                             /*!< SCB DFSR: EXTERNAL Position */
#define SCB_DFSR_EXTERNAL_Msk              (1UL << SCB_DFSR_EXTERNAL_Pos)                 /*!< SCB DFSR: EXTERNAL Mask */

#define SCB_DFSR_VCATCH_Pos                 3                                             /*!< SCB DFSR: VCATCH Position */
#define SCB_DFSR_VCATCH_Msk                (1UL << SCB_DFSR_VCATCH_Pos)                   /*!< SCB DFSR: VCATCH Mask */

#define SCB_DFSR_DWTTRAP_Pos                2                                             /*!< SCB DFSR: DWTTRAP Position */
#define SCB_DFSR_DWTTRAP_Msk               (1UL << SCB_DFSR_DWTTRAP_Pos)                  /*!< SCB DFSR: DWTTRAP Mask */

#define SCB_DFSR_BKPT_Pos                   1                                             /*!< SCB DFSR: BKPT Position */
#define SCB_DFSR_BKPT_Msk                  (1UL << SCB_DFSR_BKPT_Pos)                     /*!< SCB DFSR: BKPT Mask */

#define SCB_DFSR_HALTED_Pos                 0                                             /*!< SCB DFSR: HALTED Position */
#define SCB_DFSR_HALTED_Msk                (1UL << SCB_DFSR_HALTED_Pos)                   /*!< SCB DFSR: HALTED Mask */

/* SysTick Control / Status Register Definitions Macro */
#define SysTick_CTRL_COUNTFLAG_Pos         16                                             /*!< SysTick CTRL: COUNTFLAG Position */
#define SysTick_CTRL_COUNTFLAG_Msk         (1UL << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG Mask */

#define SysTick_CTRL_CLKSOURCE_Pos          2                                             /*!< SysTick CTRL: CLKSOURCE Position */
#define SysTick_CTRL_CLKSOURCE_Msk         (1UL << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE Mask */

#define SysTick_CTRL_TICKINT_Pos            1                                             /*!< SysTick CTRL: TICKINT Position */
#define SysTick_CTRL_TICKINT_Msk           (1UL << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT Mask */

#define SysTick_CTRL_ENABLE_Pos             0                                             /*!< SysTick CTRL: ENABLE Position */
#define SysTick_CTRL_ENABLE_Msk            (1UL << SysTick_CTRL_ENABLE_Pos)               /*!< SysTick CTRL: ENABLE Mask */

/* SysTick Reload Register Definitions */
#define SysTick_LOAD_RELOAD_Pos             0                                             /*!< SysTick LOAD: RELOAD Position */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFUL << SysTick_LOAD_RELOAD_Pos)        /*!< SysTick LOAD: RELOAD Mask */

/* SysTick Current Register Definitions */
#define SysTick_VAL_CURRENT_Pos             0                                             /*!< SysTick VAL: CURRENT Position */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFUL << SysTick_VAL_CURRENT_Pos)        /*!< SysTick VAL: CURRENT Mask */

/* SysTick Calibration Register Definitions */
#define SysTick_CALIB_NOREF_Pos            31                                             /*!< SysTick CALIB: NOREF Position */
#define SysTick_CALIB_NOREF_Msk            (1UL << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF Mask */

#define SysTick_CALIB_SKEW_Pos             30                                             /*!< SysTick CALIB: SKEW Position */
#define SysTick_CALIB_SKEW_Msk             (1UL << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW Mask */

#define SysTick_CALIB_TENMS_Pos             0                                             /*!< SysTick CALIB: TENMS Position */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFUL << SysTick_VAL_CURRENT_Pos)        /*!< SysTick CALIB: TENMS Mask */

/* ITM Trace Privilege Register Definitions  Macro */
#define ITM_TPR_PRIVMASK_Pos                0                                             /*!< ITM TPR: PRIVMASK Position */
#define ITM_TPR_PRIVMASK_Msk               (0xFUL << ITM_TPR_PRIVMASK_Pos)                /*!< ITM TPR: PRIVMASK Mask */

/* ITM Trace Control Register Definitions */
#define ITM_TCR_BUSY_Pos                   23                                             /*!< ITM TCR: BUSY Position */
#define ITM_TCR_BUSY_Msk                   (1UL << ITM_TCR_BUSY_Pos)                      /*!< ITM TCR: BUSY Mask */

#define ITM_TCR_ATBID_Pos                  16                                             /*!< ITM TCR: ATBID Position */
#define ITM_TCR_ATBID_Msk                  (0x7FUL << ITM_TCR_ATBID_Pos)                  /*!< ITM TCR: ATBID Mask */

#define ITM_TCR_TSPrescale_Pos              8                                             /*!< ITM TCR: TSPrescale Position */
#define ITM_TCR_TSPrescale_Msk             (3UL << ITM_TCR_TSPrescale_Pos)                /*!< ITM TCR: TSPrescale Mask */

#define ITM_TCR_SWOENA_Pos                  4                                             /*!< ITM TCR: SWOENA Position */
#define ITM_TCR_SWOENA_Msk                 (1UL << ITM_TCR_SWOENA_Pos)                    /*!< ITM TCR: SWOENA Mask */

#define ITM_TCR_DWTENA_Pos                  3                                             /*!< ITM TCR: DWTENA Position */
#define ITM_TCR_DWTENA_Msk                 (1UL << ITM_TCR_DWTENA_Pos)                    /*!< ITM TCR: DWTENA Mask */

#define ITM_TCR_SYNCENA_Pos                 2                                             /*!< ITM TCR: SYNCENA Position */
#define ITM_TCR_SYNCENA_Msk                (1UL << ITM_TCR_SYNCENA_Pos)                   /*!< ITM TCR: SYNCENA Mask */

#define ITM_TCR_TSENA_Pos                   1                                             /*!< ITM TCR: TSENA Position */
#define ITM_TCR_TSENA_Msk                  (1UL << ITM_TCR_TSENA_Pos)                     /*!< ITM TCR: TSENA Mask */

#define ITM_TCR_ITMENA_Pos                  0                                             /*!< ITM TCR: ITM Enable bit Position */
#define ITM_TCR_ITMENA_Msk                 (1UL << ITM_TCR_ITMENA_Pos)                    /*!< ITM TCR: ITM Enable bit Mask */

/* ITM Integration Write Register Definitions */
#define ITM_IWR_ATVALIDM_Pos                0                                             /*!< ITM IWR: ATVALIDM Position */
#define ITM_IWR_ATVALIDM_Msk               (1UL << ITM_IWR_ATVALIDM_Pos)                  /*!< ITM IWR: ATVALIDM Mask */

/* ITM Integration Read Register Definitions */
#define ITM_IRR_ATREADYM_Pos                0                                             /*!< ITM IRR: ATREADYM Position */
#define ITM_IRR_ATREADYM_Msk               (1UL << ITM_IRR_ATREADYM_Pos)                  /*!< ITM IRR: ATREADYM Mask */

/* ITM Integration Mode Control Register Definitions */
#define ITM_IMCR_INTEGRATION_Pos            0                                             /*!< ITM IMCR: INTEGRATION Position */
#define ITM_IMCR_INTEGRATION_Msk           (1UL << ITM_IMCR_INTEGRATION_Pos)              /*!< ITM IMCR: INTEGRATION Mask */

/* ITM Lock Status Register Definitions */
#define ITM_LSR_ByteAcc_Pos                 2                                             /*!< ITM LSR: ByteAcc Position */
#define ITM_LSR_ByteAcc_Msk                (1UL << ITM_LSR_ByteAcc_Pos)                   /*!< ITM LSR: ByteAcc Mask */

#define ITM_LSR_Access_Pos                  1                                             /*!< ITM LSR: Access Position */
#define ITM_LSR_Access_Msk                 (1UL << ITM_LSR_Access_Pos)                    /*!< ITM LSR: Access Mask */

#define ITM_LSR_Present_Pos                 0                                             /*!< ITM LSR: Present Position */
#define ITM_LSR_Present_Msk                (1UL << ITM_LSR_Present_Pos)                   /*!< ITM LSR: Present Mask */

/* Interrupt Controller Type Register Definitions */
#define IntType_ICTR_INTLINESNUM_Pos  0                                                   /*!< InterruptType ICTR: INTLINESNUM Position */
#define IntType_ICTR_INTLINESNUM_Msk (0x1FUL << IntType_ICTR_INTLINESNUM_Pos)             /*!< InterruptType ICTR: INTLINESNUM Mask */

/* Auxiliary Control Register Definitions */
#define IntType_ACTLR_DISFOLD_Pos     2                                                   /*!< InterruptType ACTLR: DISFOLD Position */
#define IntType_ACTLR_DISFOLD_Msk    (1UL << IntType_ACTLR_DISFOLD_Pos)                   /*!< InterruptType ACTLR: DISFOLD Mask */

#define IntType_ACTLR_DISDEFWBUF_Pos  1                                                   /*!< InterruptType ACTLR: DISDEFWBUF Position */
#define IntType_ACTLR_DISDEFWBUF_Msk (1UL << IntType_ACTLR_DISDEFWBUF_Pos)                /*!< InterruptType ACTLR: DISDEFWBUF Mask */

#define IntType_ACTLR_DISMCYCINT_Pos  0                                                   /*!< InterruptType ACTLR: DISMCYCINT Position */
#define IntType_ACTLR_DISMCYCINT_Msk (1UL << IntType_ACTLR_DISMCYCINT_Pos)                /*!< InterruptType ACTLR: DISMCYCINT Mask */

#if (PF_MPU_PRESENT == 1)
	
/* MPU Type Register */
#define MPU_TYPE_IREGION_Pos               16                                             /*!< MPU TYPE: IREGION Position */
#define MPU_TYPE_IREGION_Msk               (0xFFUL << MPU_TYPE_IREGION_Pos)               /*!< MPU TYPE: IREGION Mask */

#define MPU_TYPE_DREGION_Pos                8                                             /*!< MPU TYPE: DREGION Position */
#define MPU_TYPE_DREGION_Msk               (0xFFUL << MPU_TYPE_DREGION_Pos)               /*!< MPU TYPE: DREGION Mask */

#define MPU_TYPE_SEPARATE_Pos               0                                             /*!< MPU TYPE: SEPARATE Position */
#define MPU_TYPE_SEPARATE_Msk              (1UL << MPU_TYPE_SEPARATE_Pos)                 /*!< MPU TYPE: SEPARATE Mask */

/* MPU Control Register */
#define MPU_CTRL_PRIVDEFENA_Pos             2                                             /*!< MPU CTRL: PRIVDEFENA Position */
#define MPU_CTRL_PRIVDEFENA_Msk            (1UL << MPU_CTRL_PRIVDEFENA_Pos)               /*!< MPU CTRL: PRIVDEFENA Mask */

#define MPU_CTRL_HFNMIENA_Pos               1                                             /*!< MPU CTRL: HFNMIENA Position */
#define MPU_CTRL_HFNMIENA_Msk              (1UL << MPU_CTRL_HFNMIENA_Pos)                 /*!< MPU CTRL: HFNMIENA Mask */

#define MPU_CTRL_ENABLE_Pos                 0                                             /*!< MPU CTRL: ENABLE Position */
#define MPU_CTRL_ENABLE_Msk                (1UL << MPU_CTRL_ENABLE_Pos)                   /*!< MPU CTRL: ENABLE Mask */

/* MPU Region Number Register */
#define MPU_RNR_REGION_Pos                  0                                             /*!< MPU RNR: REGION Position */
#define MPU_RNR_REGION_Msk                 (0xFFUL << MPU_RNR_REGION_Pos)                 /*!< MPU RNR: REGION Mask */

/* MPU Region Base Address Register */
#define MPU_RBAR_ADDR_Pos                   5                                             /*!< MPU RBAR: ADDR Position */
#define MPU_RBAR_ADDR_Msk                  (0x7FFFFFFUL << MPU_RBAR_ADDR_Pos)             /*!< MPU RBAR: ADDR Mask */

#define MPU_RBAR_VALID_Pos                  4                                             /*!< MPU RBAR: VALID Position */
#define MPU_RBAR_VALID_Msk                 (1UL << MPU_RBAR_VALID_Pos)                    /*!< MPU RBAR: VALID Mask */

#define MPU_RBAR_REGION_Pos                 0                                             /*!< MPU RBAR: REGION Position */
#define MPU_RBAR_REGION_Msk                (0xFUL << MPU_RBAR_REGION_Pos)                 /*!< MPU RBAR: REGION Mask */

/* MPU Region Attribute and Size Register */
#define MPU_RASR_XN_Pos                    28                                             /*!< MPU RASR: XN Position */
#define MPU_RASR_XN_Msk                    (1UL << MPU_RASR_XN_Pos)                       /*!< MPU RASR: XN Mask */

#define MPU_RASR_AP_Pos                    24                                             /*!< MPU RASR: AP Position */
#define MPU_RASR_AP_Msk                    (7UL << MPU_RASR_AP_Pos)                       /*!< MPU RASR: AP Mask */

#define MPU_RASR_TEX_Pos                   19                                             /*!< MPU RASR: TEX Position */
#define MPU_RASR_TEX_Msk                   (7UL << MPU_RASR_TEX_Pos)                      /*!< MPU RASR: TEX Mask */

#define MPU_RASR_S_Pos                     18                                             /*!< MPU RASR: Shareable bit Position */
#define MPU_RASR_S_Msk                     (1UL << MPU_RASR_S_Pos)                        /*!< MPU RASR: Shareable bit Mask */

#define MPU_RASR_C_Pos                     17                                             /*!< MPU RASR: Cacheable bit Position */
#define MPU_RASR_C_Msk                     (1UL << MPU_RASR_C_Pos)                        /*!< MPU RASR: Cacheable bit Mask */

#define MPU_RASR_B_Pos                     16                                             /*!< MPU RASR: Bufferable bit Position */
#define MPU_RASR_B_Msk                     (1UL << MPU_RASR_B_Pos)                        /*!< MPU RASR: Bufferable bit Mask */

#define MPU_RASR_SRD_Pos                    8                                             /*!< MPU RASR: Sub-Region Disable Position */
#define MPU_RASR_SRD_Msk                   (0xFFUL << MPU_RASR_SRD_Pos)                   /*!< MPU RASR: Sub-Region Disable Mask */

#define MPU_RASR_SIZE_Pos                   1                                             /*!< MPU RASR: Region Size Field Position */
#define MPU_RASR_SIZE_Msk                  (0x1FUL << MPU_RASR_SIZE_Pos)                  /*!< MPU RASR: Region Size Field Mask */

#define MPU_RASR_ENA_Pos                     0                                            /*!< MPU RASR: Region enable bit Position */
#define MPU_RASR_ENA_Msk                    (0x1UL << MPU_RASR_ENA_Pos)                   /*!< MPU RASR: Region enable bit Disable Mask */

/* @}*/ /* end of group CM3_MPU */
#endif

/* Debug Halting Control and Status Register */
#define CoreDebug_DHCSR_DBGKEY_Pos         16                                             /*!< CoreDebug DHCSR: DBGKEY Position */
#define CoreDebug_DHCSR_DBGKEY_Msk         (0xFFFFUL << CoreDebug_DHCSR_DBGKEY_Pos)       /*!< CoreDebug DHCSR: DBGKEY Mask */

#define CoreDebug_DHCSR_S_RESET_ST_Pos     25                                             /*!< CoreDebug DHCSR: S_RESET_ST Position */
#define CoreDebug_DHCSR_S_RESET_ST_Msk     (1UL << CoreDebug_DHCSR_S_RESET_ST_Pos)        /*!< CoreDebug DHCSR: S_RESET_ST Mask */

#define CoreDebug_DHCSR_S_RETIRE_ST_Pos    24                                             /*!< CoreDebug DHCSR: S_RETIRE_ST Position */
#define CoreDebug_DHCSR_S_RETIRE_ST_Msk    (1UL << CoreDebug_DHCSR_S_RETIRE_ST_Pos)       /*!< CoreDebug DHCSR: S_RETIRE_ST Mask */

#define CoreDebug_DHCSR_S_LOCKUP_Pos       19                                             /*!< CoreDebug DHCSR: S_LOCKUP Position */
#define CoreDebug_DHCSR_S_LOCKUP_Msk       (1UL << CoreDebug_DHCSR_S_LOCKUP_Pos)          /*!< CoreDebug DHCSR: S_LOCKUP Mask */

#define CoreDebug_DHCSR_S_SLEEP_Pos        18                                             /*!< CoreDebug DHCSR: S_SLEEP Position */
#define CoreDebug_DHCSR_S_SLEEP_Msk        (1UL << CoreDebug_DHCSR_S_SLEEP_Pos)           /*!< CoreDebug DHCSR: S_SLEEP Mask */

#define CoreDebug_DHCSR_S_HALT_Pos         17                                             /*!< CoreDebug DHCSR: S_HALT Position */
#define CoreDebug_DHCSR_S_HALT_Msk         (1UL << CoreDebug_DHCSR_S_HALT_Pos)            /*!< CoreDebug DHCSR: S_HALT Mask */

#define CoreDebug_DHCSR_S_REGRDY_Pos       16                                             /*!< CoreDebug DHCSR: S_REGRDY Position */
#define CoreDebug_DHCSR_S_REGRDY_Msk       (1UL << CoreDebug_DHCSR_S_REGRDY_Pos)          /*!< CoreDebug DHCSR: S_REGRDY Mask */

#define CoreDebug_DHCSR_C_SNAPSTALL_Pos     5                                             /*!< CoreDebug DHCSR: C_SNAPSTALL Position */
#define CoreDebug_DHCSR_C_SNAPSTALL_Msk    (1UL << CoreDebug_DHCSR_C_SNAPSTALL_Pos)       /*!< CoreDebug DHCSR: C_SNAPSTALL Mask */

#define CoreDebug_DHCSR_C_MASKINTS_Pos      3                                             /*!< CoreDebug DHCSR: C_MASKINTS Position */
#define CoreDebug_DHCSR_C_MASKINTS_Msk     (1UL << CoreDebug_DHCSR_C_MASKINTS_Pos)        /*!< CoreDebug DHCSR: C_MASKINTS Mask */

#define CoreDebug_DHCSR_C_STEP_Pos          2                                             /*!< CoreDebug DHCSR: C_STEP Position */
#define CoreDebug_DHCSR_C_STEP_Msk         (1UL << CoreDebug_DHCSR_C_STEP_Pos)            /*!< CoreDebug DHCSR: C_STEP Mask */

#define CoreDebug_DHCSR_C_HALT_Pos          1                                             /*!< CoreDebug DHCSR: C_HALT Position */
#define CoreDebug_DHCSR_C_HALT_Msk         (1UL << CoreDebug_DHCSR_C_HALT_Pos)            /*!< CoreDebug DHCSR: C_HALT Mask */

#define CoreDebug_DHCSR_C_DEBUGEN_Pos       0                                             /*!< CoreDebug DHCSR: C_DEBUGEN Position */
#define CoreDebug_DHCSR_C_DEBUGEN_Msk      (1UL << CoreDebug_DHCSR_C_DEBUGEN_Pos)         /*!< CoreDebug DHCSR: C_DEBUGEN Mask */

/* Debug Core Register Selector Register */
#define CoreDebug_DCRSR_REGWnR_Pos         16                                             /*!< CoreDebug DCRSR: REGWnR Position */
#define CoreDebug_DCRSR_REGWnR_Msk         (1UL << CoreDebug_DCRSR_REGWnR_Pos)            /*!< CoreDebug DCRSR: REGWnR Mask */

#define CoreDebug_DCRSR_REGSEL_Pos          0                                             /*!< CoreDebug DCRSR: REGSEL Position */
#define CoreDebug_DCRSR_REGSEL_Msk         (0x1FUL << CoreDebug_DCRSR_REGSEL_Pos)         /*!< CoreDebug DCRSR: REGSEL Mask */

/* Debug Exception and Monitor Control Register */
#define CoreDebug_DEMCR_TRCENA_Pos         24                                             /*!< CoreDebug DEMCR: TRCENA Position */
#define CoreDebug_DEMCR_TRCENA_Msk         (1UL << CoreDebug_DEMCR_TRCENA_Pos)            /*!< CoreDebug DEMCR: TRCENA Mask */

#define CoreDebug_DEMCR_MON_REQ_Pos        19                                             /*!< CoreDebug DEMCR: MON_REQ Position */
#define CoreDebug_DEMCR_MON_REQ_Msk        (1UL << CoreDebug_DEMCR_MON_REQ_Pos)           /*!< CoreDebug DEMCR: MON_REQ Mask */

#define CoreDebug_DEMCR_MON_STEP_Pos       18                                             /*!< CoreDebug DEMCR: MON_STEP Position */
#define CoreDebug_DEMCR_MON_STEP_Msk       (1UL << CoreDebug_DEMCR_MON_STEP_Pos)          /*!< CoreDebug DEMCR: MON_STEP Mask */

#define CoreDebug_DEMCR_MON_PEND_Pos       17                                             /*!< CoreDebug DEMCR: MON_PEND Position */
#define CoreDebug_DEMCR_MON_PEND_Msk       (1UL << CoreDebug_DEMCR_MON_PEND_Pos)          /*!< CoreDebug DEMCR: MON_PEND Mask */

#define CoreDebug_DEMCR_MON_EN_Pos         16                                             /*!< CoreDebug DEMCR: MON_EN Position */
#define CoreDebug_DEMCR_MON_EN_Msk         (1UL << CoreDebug_DEMCR_MON_EN_Pos)            /*!< CoreDebug DEMCR: MON_EN Mask */

#define CoreDebug_DEMCR_VC_HARDERR_Pos     10                                             /*!< CoreDebug DEMCR: VC_HARDERR Position */
#define CoreDebug_DEMCR_VC_HARDERR_Msk     (1UL << CoreDebug_DEMCR_VC_HARDERR_Pos)        /*!< CoreDebug DEMCR: VC_HARDERR Mask */

#define CoreDebug_DEMCR_VC_INTERR_Pos       9                                             /*!< CoreDebug DEMCR: VC_INTERR Position */
#define CoreDebug_DEMCR_VC_INTERR_Msk      (1UL << CoreDebug_DEMCR_VC_INTERR_Pos)         /*!< CoreDebug DEMCR: VC_INTERR Mask */

#define CoreDebug_DEMCR_VC_BUSERR_Pos       8                                             /*!< CoreDebug DEMCR: VC_BUSERR Position */
#define CoreDebug_DEMCR_VC_BUSERR_Msk      (1UL << CoreDebug_DEMCR_VC_BUSERR_Pos)         /*!< CoreDebug DEMCR: VC_BUSERR Mask */

#define CoreDebug_DEMCR_VC_STATERR_Pos      7                                             /*!< CoreDebug DEMCR: VC_STATERR Position */
#define CoreDebug_DEMCR_VC_STATERR_Msk     (1UL << CoreDebug_DEMCR_VC_STATERR_Pos)        /*!< CoreDebug DEMCR: VC_STATERR Mask */

#define CoreDebug_DEMCR_VC_CHKERR_Pos       6                                             /*!< CoreDebug DEMCR: VC_CHKERR Position */
#define CoreDebug_DEMCR_VC_CHKERR_Msk      (1UL << CoreDebug_DEMCR_VC_CHKERR_Pos)         /*!< CoreDebug DEMCR: VC_CHKERR Mask */

#define CoreDebug_DEMCR_VC_NOCPERR_Pos      5                                             /*!< CoreDebug DEMCR: VC_NOCPERR Position */
#define CoreDebug_DEMCR_VC_NOCPERR_Msk     (1UL << CoreDebug_DEMCR_VC_NOCPERR_Pos)        /*!< CoreDebug DEMCR: VC_NOCPERR Mask */

#define CoreDebug_DEMCR_VC_MMERR_Pos        4                                             /*!< CoreDebug DEMCR: VC_MMERR Position */
#define CoreDebug_DEMCR_VC_MMERR_Msk       (1UL << CoreDebug_DEMCR_VC_MMERR_Pos)          /*!< CoreDebug DEMCR: VC_MMERR Mask */

#define CoreDebug_DEMCR_VC_CORERESET_Pos    0                                             /*!< CoreDebug DEMCR: VC_CORERESET Position */
#define CoreDebug_DEMCR_VC_CORERESET_Msk   (1UL << CoreDebug_DEMCR_VC_CORERESET_Pos)      /*!< CoreDebug DEMCR: VC_CORERESET Mask */

/* \brief CM3 Core Register Macro */
/* Memory mapping of Cortex-M3 Hardware */
#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define ITM_BASE            (0xE0000000UL)                            /*!< ITM Base Address                  */
#define CoreDebug_BASE      (0xE000EDF0UL)                            /*!< Core Debug Base Address           */
#define SysTick_BASE        (SCS_BASE +  0x0010UL)                    /*!< SysTick Base Address              */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address                 */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                    /*!< System Control Block Base Address */

#define InterruptType       ((InterruptType_Type *) SCS_BASE)         /*!< Interrupt Type Register           */
#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct          */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */
#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct         */
#define ITM                 ((ITM_Type *)           ITM_BASE)         /*!< ITM configuration struct          */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< Core Debug configuration struct   */

#if (PF_MPU_PRESENT == 1)
  #define MPU_BASE          (SCS_BASE +  0x0D90UL)                    /*!< Memory Protection Unit            */
  #define MPU               ((MPU_Type*)            MPU_BASE)         /*!< Memory Protection Unit            */
#endif

/**
 * \brief  		Set Priority Grouping
 * 
 * \details		
 *  This function sets the priority grouping field using the required unlock sequence.
 *  The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
 * 	Only values from 0..7 are used.
 * 	In case of a conflict between priority grouping and available
 *  priority bits (PF_NVIC_PRIO_BITS) the smallest possible priority group is set.
 * 
 * \param [in]      PriorityGroup  Priority grouping field
 */
PF_C_STATIC_INLINE void NVIC_SetPriorityGrouping(PFdword PriorityGroup)
{
  PFdword reg_value;
  PFdword PriorityGroupTmp = (PriorityGroup & 0x07);                         /* only values 0..7 are used          */

  reg_value  =  SCB->AIRCR;                                                  /* read old register configuration    */
  reg_value &= ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk);            /* clear bits to change               */
  reg_value  =  (reg_value                       |
                (0x5FA << SCB_AIRCR_VECTKEY_Pos) |
                (PriorityGroupTmp << 8));                                    /* Insert write key and priorty group */
  SCB->AIRCR =  reg_value;
}

/**
 * \brief		Get Priority Grouping
 * \details		
 * This function gets the priority grouping from NVIC Interrupt Controller.
 * Priority grouping is SCB->AIRCR [10:8] PRIGROUP field.
 * 
 * \return                Priority grouping field
 */
PF_C_STATIC_INLINE PFdword NVIC_GetPriorityGrouping(void)
{
  return ((SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos);   /* read priority grouping field */
}

/**
 * \brief  Enable External Interrupt
 * \details
 * This function enables a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 * 
 * \param [in]      IRQn  Number of the external interrupt to enable
 */
PF_C_STATIC_INLINE void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[((PFdword)(IRQn) >> 5)] = (1 << ((PFdword)(IRQn) & 0x1F)); /* enable interrupt */
}

/**
 * \brief  Disable External Interrupt
 * \details
 * This function disables a device specific interupt in the NVIC interrupt controller.
 * The interrupt number cannot be a negative value.
 * 
 * \param [in]      IRQn  Number of the external interrupt to disable
 */
PF_C_STATIC_INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((PFdword)(IRQn) >> 5)] = (1 << ((PFdword)(IRQn) & 0x1F)); /* disable interrupt */
}

/**
 * \brief  Get Pending Interrupt
 * \details
 * This function reads the pending register in the NVIC and returns the pending bit
 * for the specified interrupt.
 * 
 * \param [in]      IRQn  Number of the interrupt for get pending
 * \return             0  Interrupt status is not pending
 * \return             1  Interrupt status is pending
 */
PF_C_STATIC_INLINE PFdword NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((PFdword) ((NVIC->ISPR[(PFdword)(IRQn) >> 5] & (1 << ((PFdword)(IRQn) & 0x1F)))?1:0)); /* Return 1 if pending else 0 */
}

/**
 * \brief  Set Pending Interrupt
 * \details
 * This function sets the pending bit for the specified interrupt.
 * The interrupt number cannot be a negative value.
 * 
 * \param [in]      IRQn  Number of the interrupt for set pending
 */
PF_C_STATIC_INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[((PFdword)(IRQn) >> 5)] = (1 << ((PFdword)(IRQn) & 0x1F)); /* set interrupt pending */
}

/**
 * \brief  Clear Pending Interrupt
 * \details
 * This function clears the pending bit for the specified interrupt.
 * The interrupt number cannot be a negative value.
 * 
 * \param [in]      IRQn  Number of the interrupt for clear pending
 */
PF_C_STATIC_INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((PFdword)(IRQn) >> 5)] = (1 << ((PFdword)(IRQn) & 0x1F)); /* Clear pending interrupt */
}

/**
 * \brief  Get Active Interrupt
 * \details
 * This function reads the active register in NVIC and returns the active bit.
 * 
 * \param [in]      IRQn  Number of the interrupt for get active
 * \return             0  Interrupt status is not active
 * \return             1  Interrupt status is active
 */
PF_C_STATIC_INLINE PFdword NVIC_GetActive(IRQn_Type IRQn)
{
  return((PFdword)((NVIC->IABR[(PFdword)(IRQn) >> 5] & (1 << ((PFdword)(IRQn) & 0x1F)))?1:0)); /* Return 1 if active else 0 */
}

/**
 * \brief  Set Interrupt Priority
 * \details
 * This function sets the priority for the specified interrupt. The interrupt
 * number can be positive to specify an external (device specific)
 * interrupt, or negative to specify an internal (core) interrupt.
 * 
 * \param [in]      IRQn  Number of the interrupt for set priority
 * \param [in]  priority  Priority to set
 * 
 * \note The priority cannot be set for every core interrupt.
 */
PF_C_STATIC_INLINE void NVIC_SetPriority(IRQn_Type IRQn, PFdword priority)
{
  if(IRQn < 0) {
    SCB->SHP[((PFdword)(IRQn) & 0xF)-4] = ((priority << (8 - PF_NVIC_PRIO_BITS)) & 0xff); } /* set Priority for Cortex-M  System Interrupts */
  else {
    NVIC->IP[(PFdword)(IRQn)] = ((priority << (8 - PF_NVIC_PRIO_BITS)) & 0xff);    }        /* set Priority for device specific Interrupts  */
}

/**
 * \brief  Get Interrupt Priority
 * \details
 * This function reads the priority for the specified interrupt. The interrupt
 * number can be positive to specify an external (device specific) interrupt, or negative to specify an internal (core) interrupt.
 * 
 * The returned priority value is automatically aligned to the implemented priority bits of the microcontroller.
 * 
 * \param [in]   IRQn  Number of the interrupt for get priority
 * \return             Interrupt Priority
 */
PF_C_STATIC_INLINE PFdword NVIC_GetPriority(IRQn_Type IRQn)
{
  if(IRQn < 0) {
    return((PFdword)(SCB->SHP[((PFdword)(IRQn) & 0xF)-4] >> (8 - PF_NVIC_PRIO_BITS)));  } /* get priority for Cortex-M  system interrupts */
  else {
    return((PFdword)(NVIC->IP[(PFdword)(IRQn)]           >> (8 - PF_NVIC_PRIO_BITS)));  } /* get priority for device specific interrupts  */
}

/**
 * \brief  Encode Priority
 * \details
 * This function encodes the priority for an interrupt with the given priority group,
 * preemptive priority value and sub priority value.
 * In case of a conflict between priority grouping and available priority bits (PF_NVIC_PRIO_BITS) the samllest possible priority group is set.
 * The returned priority value can be used for NVIC_SetPriority(...) function
 * 
 * \param [in]     PriorityGroup  Used priority group
 * \param [in]   PreemptPriority  Preemptive priority value (starting from 0)
 * \param [in]       SubPriority  Sub priority value (starting from 0)
 * \return                        Encoded priority for the interrupt
 */
PF_C_STATIC_INLINE PFdword NVIC_EncodePriority (PFdword PriorityGroup, PFdword PreemptPriority, PFdword SubPriority)
{
  PFdword PriorityGroupTmp = (PriorityGroup & 0x07);          /* only values 0..7 are used          */
  PFdword PreemptPriorityBits;
  PFdword SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > PF_NVIC_PRIO_BITS) ? PF_NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + PF_NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + PF_NVIC_PRIO_BITS;

  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}

/**
 * \brief  Decode Priority
 * \details
 * This function decodes an interrupt priority value with the given priority group to preemptive priority value and sub priority value.
 * In case of a conflict between priority grouping and available priority bits (PF_NVIC_PRIO_BITS) the samllest possible priority group is set.
 * The priority value can be retrieved with NVIC_GetPriority(...) function
 * 
 * \param [in]         Priority   Priority value
 * \param [in]     PriorityGroup  Used priority group
 * \param [out] pPreemptPriority  Preemptive priority value (starting from 0)
 * \param [out]     pSubPriority  Sub priority value (starting from 0)
 */
PF_C_STATIC_INLINE void NVIC_DecodePriority (PFdword Priority, PFdword PriorityGroup, PFdword* pPreemptPriority, PFdword* pSubPriority)
{
  PFdword PriorityGroupTmp = (PriorityGroup & 0x07);          /* only values 0..7 are used          */
  PFdword PreemptPriorityBits;
  PFdword SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > PF_NVIC_PRIO_BITS) ? PF_NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + PF_NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + PF_NVIC_PRIO_BITS;

  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}

/**
 * \brief		System Reset
 * \details		This function initiate a system reset request to reset the MCU.
 */
PF_C_STATIC_INLINE void NVIC_SystemReset(void)
{
  __DSB();                                                     /* Ensure all outstanding memory accesses included
                                                                  buffered write are completed before reset */
  SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      |
                 (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |
                 SCB_AIRCR_SYSRESETREQ_Msk);                   /* Keep priority group unchanged */
  __DSB();                                                     /* Ensure completion of memory access */
  while(1);                                                    /* wait until reset */
}

#if (PF_CM3_SysTickConfig == 0)

/**
 * \brief  System Tick Configuration
 * \details
 * This function initialises the system tick timer and its interrupt and start the system tick timer.
 * Counter is in free running mode to generate periodical interrupts.
 * 
 * \param [in]  ticks  Number of ticks between two interrupts
 * \return          0  Function succeeded
 * \return          1  Function failed
 */
PF_C_STATIC_INLINE PFdword SysTick_Config(PFdword ticks)
{
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* Reload value impossible */

  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1<<PF_NVIC_PRIO_BITS) - 1);  /* set Priority for Cortex-M0 System Interrupts */
  SysTick->VAL   = 0;                                          /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick IRQ and SysTick Timer */
  return (0);                                                  /* Function successful */
}

#endif

extern volatile PFsdword ITM_RxBuffer;                    /*!< external variable to receive characters                    */
#define                 ITM_RXBUFFER_EMPTY    0x5AA55AA5 /*!< value identifying ITM_RxBuffer is ready for next character */

/**
 * \brief  ITM Send Character
 * \details
 * This function transmits a character via the ITM channel 0.
 * It just returns when no debugger is connected that has booked the output.
 * It is blocking when a debugger is connected, but the previous character send is not transmitted.
 * 
 * \param [in]     ch  Character to transmit
 * \return             Character to transmit
 */
PF_C_STATIC_INLINE PFdword ITM_SendChar (PFdword ch)
{
  if ((CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)  &&      /* Trace enabled */
      (ITM->TCR & ITM_TCR_ITMENA_Msk)                  &&      /* ITM enabled */
      (ITM->TER & (1UL << 0)        )                    )     /* ITM Port #0 enabled */
  {
    while (ITM->PORT[0].u32 == 0);
    ITM->PORT[0].u8 = (PFbyte) ch;
  }
  return (ch);
}

/**
 * \brief  ITM Receive Character
 * \details
 * This function inputs a character via external variable ITM_RxBuffer.
 * It just returns when no debugger is connected that has booked the output.
 * It is blocking when a debugger is connected, but the previous character send is not transmitted.
 * 
 * \return             Received character
 * \return         -1  No character received
 */
PF_C_STATIC_INLINE PFsdword ITM_ReceiveChar (void) {
  PFsdword ch = -1;                           /* no character available */

  if (ITM_RxBuffer != ITM_RXBUFFER_EMPTY) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ITM_RXBUFFER_EMPTY;       /* ready for next character */
  }
  return (ch);
}

/**
 * \brief  ITM Check Character
 * \details
 * This function checks external variable ITM_RxBuffer whether a character is available or not.
 * It returns '1' if a character is available and '0' if no character is available.
 * 
 * \return          0  No character available
 * \return          1  Character available
 */
PF_C_STATIC_INLINE PFsdword ITM_CheckChar (void) {

  if (ITM_RxBuffer == ITM_RXBUFFER_EMPTY) {
    return (0);                                 /* no character available */
  } else {
    return (1);                                 /*    character available */
  }
}

#endif /* PF_CORE_CORTEX_M3_H_DEP */

#endif /* PF_CORTEX_M3_GENERIC */

#ifdef __cplusplus
}
#endif

/*lint -restore */
