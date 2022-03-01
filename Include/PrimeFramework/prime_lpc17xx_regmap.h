/**
 * \file		prime_lpc17xx_regmap.h
 * \brief		Discribe the Register MAP of LPC1768.
 * \copyright 	Copyright (c) 2014 <br> PhiRobotics Research Pvt Ltd.
 * 
 * \par			For licensing information, see the file 'LICENSE' in the root folder of	this software module.
 *
 * Review status: NO
 *
 */
#pragma once

#include "prime_compiler.h"
#include "prime_types.h"

/**
 * \ingroup native
 * \defgroup LPCxx Peripherals
 * @{
 * 	
 * 	\brief  LPC1768 Reg Map
 */

 /** Configuration of the Cortex-M3 Processor and Core Peripherals */
#define PF_MPU_PRESENT             	1       /**< MPU present or not                               */
#define PF_NVIC_PRIO_BITS			5       /**< Number of Bits used for Priority Levels          */
#define PF_CM3_SysTickConfig		0		/**< Set to 1 if different SysTick Config is used     */
 
/** \brief IRQ interrupt source definition */
typedef enum 
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  Reset_IRQn                    = -15,      /**< 1 Reset Vector, invoked on PowerUp and warm reset*/
  NonMaskableInt_IRQn           = -14,      /**< 2 Non Maskable Interrupt                         */
  HardFault_IRQn                = -13,      /**< 3  Hard Fault, all classes of Fault              */
  MemoryManagement_IRQn         = -12,      /**< 4 Cortex-M3 Memory Management Interrupt          */
  BusFault_IRQn                 = -11,      /**< 5 Cortex-M3 Bus Fault Interrupt                  */
  UsageFault_IRQn               = -10,      /**< 6 Cortex-M3 Usage Fault Interrupt                */
  SVCall_IRQn                   = -5,       /**< 11 Cortex-M3 SV Call Interrupt                   */
  DebugMonitor_IRQn             = -4,       /**< 12 Cortex-M3 Debug Monitor Interrupt             */
  PendSV_IRQn                   = -2,       /**< 14 Cortex-M3 Pend SV Interrupt                   */
  SysTick_IRQn                  = -1,       /**< 15 Cortex-M3 System Tick Interrupt               */

/******  LPC17xx Specific Interrupt Numbers *******************************************************/
  WDT_IRQn                      = 0,        /**< Watchdog Timer Interrupt                         */
  TIMER0_IRQn                   = 1,        /**< Timer0 Interrupt                                 */
  TIMER1_IRQn                   = 2,        /**< Timer1 Interrupt                                 */
  TIMER2_IRQn                   = 3,        /**< Timer2 Interrupt                                 */
  TIMER3_IRQn                   = 4,        /**< Timer3 Interrupt                                 */
  UART0_IRQn                    = 5,        /**< UART0 Interrupt                                  */
  UART1_IRQn                    = 6,        /**< UART1 Interrupt                                  */
  UART2_IRQn                    = 7,        /**< UART2 Interrupt                                  */
  UART3_IRQn                    = 8,        /**< UART3 Interrupt                                  */
  PWM1_IRQn                     = 9,        /**< PWM1 Interrupt                                   */
  I2C0_IRQn                     = 10,       /**< I2C0 Interrupt                                   */
  I2C1_IRQn                     = 11,       /**< I2C1 Interrupt                                   */
  I2C2_IRQn                     = 12,       /**< I2C2 Interrupt                                   */
  SPI_IRQn                      = 13,       /**< SPI Interrupt                                    */
  SSP0_IRQn                     = 14,       /**< SSP0 Interrupt                                   */
  SSP1_IRQn                     = 15,       /**< SSP1 Interrupt                                   */
  PLL0_IRQn                     = 16,       /**< PLL0 Lock (Main PLL) Interrupt                   */
  RTC_IRQn                      = 17,       /**< Real Time Clock Interrupt                        */
  EINT0_IRQn                    = 18,       /**< External Interrupt 0 Interrupt                   */
  EINT1_IRQn                    = 19,       /**< External Interrupt 1 Interrupt                   */
  EINT2_IRQn                    = 20,       /**< External Interrupt 2 Interrupt                   */
  EINT3_IRQn                    = 21,       /**< External Interrupt 3 Interrupt                   */
  ADC_IRQn                      = 22,       /**< A/D Converter Interrupt                          */
  BOD_IRQn                      = 23,       /**< Brown-Out Detect Interrupt                       */
  USB_IRQn                      = 24,       /**< USB Interrupt                                    */
  CAN_IRQn                      = 25,       /**< CAN Interrupt                                    */
  DMA_IRQn                      = 26,       /**< General Purpose DMA Interrupt                    */
  I2S_IRQn                      = 27,       /**< I2S Interrupt                                    */
  ENET_IRQn                     = 28,       /**< Ethernet Interrupt                               */
  RIT_IRQn                      = 29,       /**< Repetitive Interrupt Timer Interrupt             */
  MCPWM_IRQn                    = 30,       /**< Motor Control PWM Interrupt                      */
  QEI_IRQn                      = 31,       /**< Quadrature Encoder Interface Interrupt           */
  PLL1_IRQn                     = 32,       /**< PLL1 Lock (USB PLL) Interrupt                    */
  USBActivity_IRQn              = 33,       /**< USB Activity Interrupt 						  */
  CANActivity_IRQn              = 34,       /**< CAN Activity Interrupt 						  */
} IRQn_Type;

/**		\brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).	*/
typedef struct
{
  _RW PFdword ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
       PFdword RESERVED0[24];
  _RW PFdword ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
       PFdword RSERVED1[24];
  _RW PFdword ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
       PFdword RESERVED2[24];
  _RW PFdword ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
       PFdword RESERVED3[24];
  _RW PFdword IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
       PFdword RESERVED4[56];
  _RW PFbyte  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
       PFdword RESERVED5[644];
  _W  PFdword STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;

/**	\brief  Structure type to access the System Control Block (SCB).	*/
typedef struct
{
  _R  PFdword CPUID;                   /*!< Offset: 0x000 (R/ )  CPU ID Base Register                                  */
  _RW PFdword ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control State Register                      */
  _RW PFdword VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
  _RW PFdword AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt / Reset Control Register        */
  _RW PFdword SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
  _RW PFdword CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
  _RW PFbyte  SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  _RW PFdword SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
  _RW PFdword CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
  _RW PFdword HFSR;                    /*!< Offset: 0x02C (R/W)  Hard Fault Status Register                            */
  _RW PFdword DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
  _RW PFdword MMFAR;                   /*!< Offset: 0x034 (R/W)  Mem Manage Address Register                           */
  _RW PFdword BFAR;                    /*!< Offset: 0x038 (R/W)  Bus Fault Address Register                            */
  _RW PFdword AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
  _R  PFdword PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
  _R  PFdword DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
  _R  PFdword ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
  _R  PFdword MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
  _R  PFdword ISAR[5];                 /*!< Offset: 0x060 (R/ )  ISA Feature Register                                  */
} SCB_Type;

/** \brief  Structure type to access the System Timer (SysTick).	*/
typedef struct
{
  _RW PFdword CTRL;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  _RW PFdword LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  _RW PFdword VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  _R  PFdword CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

/** \brief  Structure type to access the Instrumentation Trace Macrocell Register (ITM). */
typedef struct
{
  _W  union
  {
    _W  PFbyte    u8;                  /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 8-bit                   */
    _W  PFword   u16;                 /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 16-bit                  */
    _W  PFdword   u32;                 /*!< Offset: 0x000 ( /W)  ITM Stimulus Port 32-bit                  */
  }  PORT [32];                          /*!< Offset: 0x000 ( /W)  ITM Stimulus Port Registers               */
       PFdword RESERVED0[864];
  _RW PFdword TER;                     /*!< Offset:       (R/W)  ITM Trace Enable Register                 */
       PFdword RESERVED1[15];
  _RW PFdword TPR;                     /*!< Offset:       (R/W)  ITM Trace Privilege Register              */
       PFdword RESERVED2[15];
  _RW PFdword TCR;                     /*!< Offset:       (R/W)  ITM Trace Control Register                */
       PFdword RESERVED3[29];
  _RW PFdword IWR;                     /*!< Offset:       (R/W)  ITM Integration Write Register            */
  _RW PFdword IRR;                     /*!< Offset:       (R/W)  ITM Integration Read Register             */
  _RW PFdword IMCR;                    /*!< Offset:       (R/W)  ITM Integration Mode Control Register     */
       PFdword RESERVED4[43];
  _RW PFdword LAR;                     /*!< Offset:       (R/W)  ITM Lock Access Register                  */
  _RW PFdword LSR;                     /*!< Offset:       (R/W)  ITM Lock Status Register                  */
       PFdword RESERVED5[6];
  _R  PFdword PID4;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #4 */
  _R  PFdword PID5;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #5 */
  _R  PFdword PID6;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #6 */
  _R  PFdword PID7;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #7 */
  _R  PFdword PID0;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #0 */
  _R  PFdword PID1;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #1 */
  _R  PFdword PID2;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #2 */
  _R  PFdword PID3;                    /*!< Offset:       (R/ )  ITM Peripheral Identification Register #3 */
  _R  PFdword CID0;                    /*!< Offset:       (R/ )  ITM Component  Identification Register #0 */
  _R  PFdword CID1;                    /*!< Offset:       (R/ )  ITM Component  Identification Register #1 */
  _R  PFdword CID2;                    /*!< Offset:       (R/ )  ITM Component  Identification Register #2 */
  _R  PFdword CID3;                    /*!< Offset:       (R/ )  ITM Component  Identification Register #3 */
} ITM_Type;


/**	\brief  Structure type to access the Interrupt Type Register.	*/
typedef struct
{
       PFdword RESERVED0;
  _R  PFdword ICTR;                    /*!< Offset: 0x004 (R/ )  Interrupt Control Type Register */
#if ((defined __CM3_REV) && (__CM3_REV >= 0x200))
  _RW PFdword ACTLR;                   /*!< Offset: 0x008 (R/W)  Auxiliary Control Register      */
#else
       PFdword RESERVED1;
#endif
} InterruptType_Type;


#if (PF_MPU_PRESENT == 1)
/**	\brief  Structure type to access the Memory Protection Unit (MPU).	*/
typedef struct
{
  _R  PFdword TYPE;                    /*!< Offset: 0x000 (R/ )  MPU Type Register                              */
  _RW PFdword CTRL;                    /*!< Offset: 0x004 (R/W)  MPU Control Register                           */
  _RW PFdword RNR;                     /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register                     */
  _RW PFdword RBAR;                    /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register               */
  _RW PFdword RASR;                    /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register         */
  _RW PFdword RBAR_A1;                 /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register       */
  _RW PFdword RASR_A1;                 /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
  _RW PFdword RBAR_A2;                 /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register       */
  _RW PFdword RASR_A2;                 /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
  _RW PFdword RBAR_A3;                 /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register       */
  _RW PFdword RASR_A3;                 /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} MPU_Type;
#endif

/**	\brief  Structure type to access the Core Debug Register (CoreDebug).	*/
typedef struct
{
  _RW PFdword DHCSR;                   /*!< Offset: 0x000 (R/W)  Debug Halting Control and Status Register    */
  _W  PFdword DCRSR;                   /*!< Offset: 0x004 ( /W)  Debug Core Register Selector Register        */
  _RW PFdword DCRDR;                   /*!< Offset: 0x008 (R/W)  Debug Core Register Data Register            */
  _RW PFdword DEMCR;                   /*!< Offset: 0x00C (R/W)  Debug Exception and Monitor Control Register */
} CoreDebug_Type;

// includeing the core reg map Address Macro
#include "prime_cm3.h"       /* Cortex-M3 processor and core peripherals           */

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/*------------- System Control (SC) ------------------------------------------*/
/** \brief System Control (SC) register structure definition */
typedef struct
{
  _RW PFdword FLASHCFG;               /* Flash Accelerator Module           */
       PFdword RESERVED0[31];
  _RW PFdword PLL0CON;                /* Clocking and Power Control         */
  _RW PFdword PLL0CFG;
  _R  PFdword PLL0STAT;
  _W  PFdword PLL0FEED;
       PFdword RESERVED1[4];
  _RW PFdword PLL1CON;
  _RW PFdword PLL1CFG;
  _R  PFdword PLL1STAT;
  _W  PFdword PLL1FEED;
       PFdword RESERVED2[4];
  _RW PFdword PCON;
  _RW PFdword PCONP;
       PFdword RESERVED3[15];
  _RW PFdword CCLKCFG;
  _RW PFdword USBCLKCFG;
  _RW PFdword CLKSRCSEL;
  _RW PFdword	CANSLEEPCLR;
  _RW PFdword	CANWAKEFLAGS;
       PFdword RESERVED4[10];
  _RW PFdword EXTINT;                 /* External Interrupts                */
       PFdword RESERVED5;
  _RW PFdword EXTMODE;
  _RW PFdword EXTPOLAR;
       PFdword RESERVED6[12];
  _RW PFdword RSID;                   /* Reset                              */
       PFdword RESERVED7[7];
  _RW PFdword SCS;                    /* Syscon Miscellaneous Registers     */
  _RW PFdword IRCTRIM;                /* Clock Dividers                     */
  _RW PFdword PCLKSEL0;
  _RW PFdword PCLKSEL1;
       PFdword RESERVED8[4];
  _RW PFdword USBIntSt;               /* USB Device/OTG Interrupt Register  */
  _RW PFdword DMAREQSEL;
  _RW PFdword CLKOUTCFG;              /* Clock Output Configuration         */
 } SC_TypeDef;

/*------------- Pin Connect Block (PINCON) -----------------------------------*/
/** \brief Pin Connect Block (PINCON) register structure definition */
typedef struct
{
  _RW PFdword PINSEL0;
  _RW PFdword PINSEL1;
  _RW PFdword PINSEL2;
  _RW PFdword PINSEL3;
  _RW PFdword PINSEL4;
  _RW PFdword PINSEL5;
  _RW PFdword PINSEL6;
  _RW PFdword PINSEL7;
  _RW PFdword PINSEL8;
  _RW PFdword PINSEL9;
  _RW PFdword PINSEL10;
       PFdword RESERVED0[5];
  _RW PFdword PINMODE0;
  _RW PFdword PINMODE1;
  _RW PFdword PINMODE2;
  _RW PFdword PINMODE3;
  _RW PFdword PINMODE4;
  _RW PFdword PINMODE5;
  _RW PFdword PINMODE6;
  _RW PFdword PINMODE7;
  _RW PFdword PINMODE8;
  _RW PFdword PINMODE9;
  _RW PFdword PINMODE_OD0;
  _RW PFdword PINMODE_OD1;
  _RW PFdword PINMODE_OD2;
  _RW PFdword PINMODE_OD3;
  _RW PFdword PINMODE_OD4;
  _RW PFdword I2CPADCFG;
} PINCON_TypeDef;

/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** \brief General Purpose Input/Output (GPIO) register structure definition */
typedef struct
{
  union {
    _RW PFdword FIODIR;
    struct {
      _RW PFword FIODIRL;
      _RW PFword FIODIRH;
    };
    struct {
      _RW PFbyte  FIODIR0;
      _RW PFbyte  FIODIR1;
      _RW PFbyte  FIODIR2;
      _RW PFbyte  FIODIR3;
    };
  };
  PFdword RESERVED0[3];
  union {
    _RW PFdword FIOMASK;
    struct {
      _RW PFword FIOMASKL;
      _RW PFword FIOMASKH;
    };
    struct {
      _RW PFbyte  FIOMASK0;
      _RW PFbyte  FIOMASK1;
      _RW PFbyte  FIOMASK2;
      _RW PFbyte  FIOMASK3;
    };
  };
  union {
    _RW PFdword FIOPIN;
    struct {
      _RW PFword FIOPINL;
      _RW PFword FIOPINH;
    };
    struct {
      _RW PFbyte  FIOPIN0;
      _RW PFbyte  FIOPIN1;
      _RW PFbyte  FIOPIN2;
      _RW PFbyte  FIOPIN3;
    };
  };
  union {
    _RW PFdword FIOSET;
    struct {
      _RW PFword FIOSETL;
      _RW PFword FIOSETH;
    };
    struct {
      _RW PFbyte  FIOSET0;
      _RW PFbyte  FIOSET1;
      _RW PFbyte  FIOSET2;
      _RW PFbyte  FIOSET3;
    };
  };
  union {
    _W  PFdword FIOCLR;
    struct {
      _W  PFword FIOCLRL;
      _W  PFword FIOCLRH;
    };
    struct {
      _W  PFbyte  FIOCLR0;
      _W  PFbyte  FIOCLR1;
      _W  PFbyte  FIOCLR2;
      _W  PFbyte  FIOCLR3;
    };
  };
} GPIO_TypeDef;

/** \brief General Purpose Input/Output interrupt (GPIOINT) register structure definition */
typedef struct
{
  _R  PFdword IntStatus;
  _R  PFdword IO0IntStatR;
  _R  PFdword IO0IntStatF;
  _W  PFdword IO0IntClr;
  _RW PFdword IO0IntEnR;
  _RW PFdword IO0IntEnF;
       PFdword RESERVED0[3];
  _R  PFdword IO2IntStatR;
  _R  PFdword IO2IntStatF;
  _W  PFdword IO2IntClr;
  _RW PFdword IO2IntEnR;
  _RW PFdword IO2IntEnF;
} GPIOINT_TypeDef;

/*------------- Timer (TIM) --------------------------------------------------*/
/** \brief Timer (TIM) register structure definition */
typedef struct
{
  _RW PFdword IR;
  _RW PFdword TCR;
  _RW PFdword TC;
  _RW PFdword PR;
  _RW PFdword PC;
  _RW PFdword MCR;
  _RW PFdword MR0;
  _RW PFdword MR1;
  _RW PFdword MR2;
  _RW PFdword MR3;
  _RW PFdword CCR;
  _R  PFdword CR0;
  _R  PFdword CR1;
       PFdword RESERVED0[2];
  _RW PFdword EMR;
       PFdword RESERVED1[12];
  _RW PFdword CTCR;
} TIM_TypeDef;

/*------------- Pulse-Width Modulation (PWM) ---------------------------------*/
/** \brief Pulse-Width Modulation (PWM) register structure definition */
typedef struct
{
  _RW PFdword IR;
  _RW PFdword TCR;
  _RW PFdword TC;
  _RW PFdword PR;
  _RW PFdword PC;
  _RW PFdword MCR;
  _RW PFdword MR0;
  _RW PFdword MR1;
  _RW PFdword MR2;
  _RW PFdword MR3;
  _RW PFdword CCR;
  _R  PFdword CR0;
  _R  PFdword CR1;
  _R  PFdword CR2;
  _R  PFdword CR3;
       PFdword RESERVED0;
  _RW PFdword MR4;
  _RW PFdword MR5;
  _RW PFdword MR6;
  _RW PFdword PCR;
  _RW PFdword LER;
       PFdword RESERVED1[7];
  _RW PFdword CTCR;
} PWM_TypeDef;

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/
/** \brief  Universal Asynchronous Receiver Transmitter (UART) register structure definition */
typedef struct
{
  union {
  _R  PFbyte  RBR;
  _W  PFbyte  THR;
  _RW PFbyte  DLL;
       PFdword RESERVED0;
  };
  union {
  _RW PFbyte  DLM;
  _RW PFdword IER;
  };
  union {
  _R  PFdword IIR;
  _W  PFbyte  FCR;
  };
  _RW PFbyte  LCR;
       PFbyte  RESERVED1[7];
  _R  PFbyte  LSR;
       PFbyte  RESERVED2[7];
  _RW PFbyte  SCR;
       PFbyte  RESERVED3[3];
  _RW PFdword ACR;
  _RW PFbyte  ICR;
       PFbyte  RESERVED4[3];
  _RW PFbyte  FDR;
       PFbyte  RESERVED5[7];
  _RW PFbyte  TER;
} UART_TypeDef;

/** \brief  Universal Asynchronous Receiver Transmitter 1 (UART1) register structure definition */
typedef struct
{
  union {
  _R  PFbyte  RBR;
  _W  PFbyte  THR;
  _RW PFbyte  DLL;
       PFdword RESERVED0;
  };
  union {
  _RW PFbyte  DLM;
  _RW PFdword IER;
  };
  union {
  _R  PFdword IIR;
  _W  PFbyte  FCR;
  };
  _RW PFbyte  LCR;
       PFbyte  RESERVED1[3];
  _RW PFbyte  MCR;
       PFbyte  RESERVED2[3];
  _R  PFbyte  LSR;
       PFbyte  RESERVED3[3];
  _R  PFbyte  MSR;
       PFbyte  RESERVED4[3];
  _RW PFbyte  SCR;
       PFbyte  RESERVED5[3];
  _RW PFdword ACR;
       PFdword RESERVED6;
  _RW PFdword FDR;
       PFdword RESERVED7;
  _RW PFbyte  TER;
       PFbyte  RESERVED8[27];
  _RW PFbyte  RS485CTRL;
       PFbyte  RESERVED9[3];
  _RW PFbyte  ADRMATCH;
       PFbyte  RESERVED10[3];
  _RW PFbyte  RS485DLY;
} UART1_TypeDef;

/*------------- Serial Peripheral Interface (SPI) ----------------------------*/
/** \brief  Serial Peripheral Interface (SPI) register structure definition */
typedef struct
{
  _RW PFdword SPCR;
  _R  PFdword SPSR;
  _RW PFdword SPDR;
  _RW PFdword SPCCR;
       PFdword RESERVED0[3];
  _RW PFdword SPINT;
} SPI_TypeDef;

/*------------- Synchronous Serial Communication (SSP) -----------------------*/
/** \brief  Synchronous Serial Communication (SSP) register structure definition */
typedef struct
{
  _RW PFdword CR0;
  _RW PFdword CR1;
  _RW PFdword DR;
  _R  PFdword SR;
  _RW PFdword CPSR;
  _RW PFdword IMSC;
  _RW PFdword RIS;
  _RW PFdword MIS;
  _RW PFdword ICR;
  _RW PFdword DMACR;
} SSP_TypeDef;

/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/
/** \brief  Inter-Integrated Circuit (I2C) register structure definition */
typedef struct
{
  _RW PFdword I2CONSET;
  _R  PFdword I2STAT;
  _RW PFdword I2DAT;
  _RW PFdword I2ADR0;
  _RW PFdword I2SCLH;
  _RW PFdword I2SCLL;
  _W  PFdword I2CONCLR;
  _RW PFdword MMCTRL;
  _RW PFdword I2ADR1;
  _RW PFdword I2ADR2;
  _RW PFdword I2ADR3;
  _R  PFdword I2DATA_BUFFER;
  _RW PFdword I2MASK0;
  _RW PFdword I2MASK1;
  _RW PFdword I2MASK2;
  _RW PFdword I2MASK3;
} I2C_TypeDef;

/*------------- Inter IC Sound (I2S) -----------------------------------------*/
/** \brief  Inter IC Sound (I2S) register structure definition */
typedef struct
{
  _RW PFdword I2SDAO;
  _RW PFdword I2SDAI;
  _W  PFdword I2STXFIFO;
  _R  PFdword I2SRXFIFO;
  _R  PFdword I2SSTATE;
  _RW PFdword I2SDMA1;
  _RW PFdword I2SDMA2;
  _RW PFdword I2SIRQ;
  _RW PFdword I2STXRATE;
  _RW PFdword I2SRXRATE;
  _RW PFdword I2STXBITRATE;
  _RW PFdword I2SRXBITRATE;
  _RW PFdword I2STXMODE;
  _RW PFdword I2SRXMODE;
} I2S_TypeDef;

/*------------- Repetitive Interrupt Timer (RIT) -----------------------------*/
/** \brief  Repetitive Interrupt Timer (RIT) register structure definition */
typedef struct
{
  _RW PFdword RICOMPVAL;
  _RW PFdword RIMASK;
  _RW PFbyte  RICTRL;
       PFbyte  RESERVED0[3];
  _RW PFdword RICOUNTER;
} RIT_TypeDef;

/*------------- Real-Time Clock (RTC) ----------------------------------------*/
/** \brief  Real-Time Clock (RTC) register structure definition */
typedef struct
{
  _RW PFbyte  ILR;
       PFbyte  RESERVED0[7];
  _RW PFbyte  CCR;
       PFbyte  RESERVED1[3];
  _RW PFbyte  CIIR;
       PFbyte  RESERVED2[3];
  _RW PFbyte  AMR;
       PFbyte  RESERVED3[3];
  _R  PFdword CTIME0;
  _R  PFdword CTIME1;
  _R  PFdword CTIME2;
  _RW PFbyte  SEC;
       PFbyte  RESERVED4[3];
  _RW PFbyte  MIN;
       PFbyte  RESERVED5[3];
  _RW PFbyte  HOUR;
       PFbyte  RESERVED6[3];
  _RW PFbyte  DOM;
       PFbyte  RESERVED7[3];
  _RW PFbyte  DOW;
       PFbyte  RESERVED8[3];
  _RW PFword DOY;
       PFword RESERVED9;
  _RW PFbyte  MONTH;
       PFbyte  RESERVED10[3];
  _RW PFword YEAR;
       PFword RESERVED11;
  _RW PFdword CALIBRATION;
  _RW PFdword GPREG0;
  _RW PFdword GPREG1;
  _RW PFdword GPREG2;
  _RW PFdword GPREG3;
  _RW PFdword GPREG4;
  _RW PFbyte  RTC_AUXEN;
       PFbyte  RESERVED12[3];
  _RW PFbyte  RTC_AUX;
       PFbyte  RESERVED13[3];
  _RW PFbyte  ALSEC;
       PFbyte  RESERVED14[3];
  _RW PFbyte  ALMIN;
       PFbyte  RESERVED15[3];
  _RW PFbyte  ALHOUR;
       PFbyte  RESERVED16[3];
  _RW PFbyte  ALDOM;
       PFbyte  RESERVED17[3];
  _RW PFbyte  ALDOW;
       PFbyte  RESERVED18[3];
  _RW PFword ALDOY;
       PFword RESERVED19;
  _RW PFbyte  ALMON;
       PFbyte  RESERVED20[3];
  _RW PFword ALYEAR;
       PFword RESERVED21;
} RTC_TypeDef;

/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** \brief  Watchdog Timer (WDT) register structure definition */
typedef struct
{
  _RW PFbyte  WDMOD;
       PFbyte  RESERVED0[3];
  _RW PFdword WDTC;
  _W  PFbyte  WDFEED;
       PFbyte  RESERVED1[3];
  _R  PFdword WDTV;
  _RW PFdword WDCLKSEL;
} WDT_TypeDef;

/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** \brief  Analog-to-Digital Converter (ADC) register structure definition */
typedef struct
{
  _RW PFdword ADCR;
  _RW PFdword ADGDR;
       PFdword RESERVED0;
  _RW PFdword ADINTEN;
  _R  PFdword ADDR[8];
/*  _R  PFdword ADDR1;
  _R  PFdword ADDR2;
  _R  PFdword ADDR3;
  _R  PFdword ADDR4;
  _R  PFdword ADDR5;
  _R  PFdword ADDR6;
  _R  PFdword ADDR7;	*/
  _R  PFdword ADSTAT;
  _RW PFdword ADTRM;
} ADC_TypeDef;

/*------------- Digital-to-Analog Converter (DAC) ----------------------------*/
/** \brief  Digital-to-Analog Converter (DAC) register structure definition */
typedef struct
{
  _RW PFdword DACR;
  _RW PFdword DACCTRL;
  _RW PFword DACCNTVAL;
} DAC_TypeDef;

/*------------- Motor Control Pulse-Width Modulation (MCPWM) -----------------*/
/** \brief  Motor Control Pulse-Width Modulation (MCPWM) register structure definition */
typedef struct
{
  _R  PFdword MCCON;
  _W  PFdword MCCON_SET;
  _W  PFdword MCCON_CLR;
  _R  PFdword MCCAPCON;
  _W  PFdword MCCAPCON_SET;
  _W  PFdword MCCAPCON_CLR;
  _RW PFdword MCTIM0;
  _RW PFdword MCTIM1;
  _RW PFdword MCTIM2;
  _RW PFdword MCPER0;
  _RW PFdword MCPER1;
  _RW PFdword MCPER2;
  _RW PFdword MCPW0;
  _RW PFdword MCPW1;
  _RW PFdword MCPW2;
  _RW PFdword MCDEADTIME;
  _RW PFdword MCCCP;
  _RW PFdword MCCR0;
  _RW PFdword MCCR1;
  _RW PFdword MCCR2;
  _R  PFdword MCINTEN;
  _W  PFdword MCINTEN_SET;
  _W  PFdword MCINTEN_CLR;
  _R  PFdword MCCNTCON;
  _W  PFdword MCCNTCON_SET;
  _W  PFdword MCCNTCON_CLR;
  _R  PFdword MCINTFLAG;
  _W  PFdword MCINTFLAG_SET;
  _W  PFdword MCINTFLAG_CLR;
  _W  PFdword MCCAP_CLR;
} MCPWM_TypeDef;

/*------------- Quadrature Encoder Interface (QEI) ---------------------------*/
/** \brief  Quadrature Encoder Interface (QEI) register structure definition */
typedef struct
{
  _W  PFdword QEICON;
  _R  PFdword QEISTAT;
  _RW PFdword QEICONF;
  _R  PFdword QEIPOS;
  _RW PFdword QEIMAXPOS;
  _RW PFdword CMPOS0;
  _RW PFdword CMPOS1;
  _RW PFdword CMPOS2;
  _R  PFdword INXCNT;
  _RW PFdword INXCMP;
  _RW PFdword QEILOAD;
  _R  PFdword QEITIME;
  _R  PFdword QEIVEL;
  _R  PFdword QEICAP;
  _RW PFdword VELCOMP;
  _RW PFdword FILTER;
       PFdword RESERVED0[998];
  _W  PFdword QEIIEC;
  _W  PFdword QEIIES;
  _R  PFdword QEIINTSTAT;
  _R  PFdword QEIIE;
  _W  PFdword QEICLR;
  _W  PFdword QEISET;
} QEI_TypeDef;

/*------------- Controller Area Network (CAN) --------------------------------*/
/** \brief  Controller Area Network Acceptance Filter RAM (CANAF_RAM)structure definition */
typedef struct
{
  _RW PFdword mask[512];              /* ID Masks                           */
} CANAF_RAM_TypeDef;

/** \brief  Controller Area Network Acceptance Filter(CANAF) register structure definition */
typedef struct                          /* Acceptance Filter Registers        */
{
  _RW PFdword AFMR;
  _RW PFdword SFF_sa;
  _RW PFdword SFF_GRP_sa;
  _RW PFdword EFF_sa;
  _RW PFdword EFF_GRP_sa;
  _RW PFdword ENDofTable;
  _R  PFdword LUTerrAd;
  _R  PFdword LUTerr;
  _RW PFdword FCANIE;
  _RW PFdword FCANIC0;
  _RW PFdword FCANIC1;
} CANAF_TypeDef;

/** \brief  Controller Area Network Central (CANCR) register structure definition */
typedef struct                          /* Central Registers                  */
{
  _R  PFdword CANTxSR;
  _R  PFdword CANRxSR;
  _R  PFdword CANMSR;
} CANCR_TypeDef;

/** \brief  Controller Area Network Controller (CAN) register structure definition */
typedef struct                          /* Controller Registers               */
{
  _RW PFdword MOD;
  _W  PFdword CMR;
  _RW PFdword GSR;
  _R  PFdword ICR;
  _RW PFdword IER;
  _RW PFdword BTR;
  _RW PFdword EWL;
  _R  PFdword SR;
  _RW PFdword RFS;
  _RW PFdword RID;
  _RW PFdword RDA;
  _RW PFdword RDB;
  _RW PFdword TFI1;
  _RW PFdword TID1;
  _RW PFdword TDA1;
  _RW PFdword TDB1;
  _RW PFdword TFI2;
  _RW PFdword TID2;
  _RW PFdword TDA2;
  _RW PFdword TDB2;
  _RW PFdword TFI3;
  _RW PFdword TID3;
  _RW PFdword TDA3;
  _RW PFdword TDB3;
} CAN_TypeDef;

/*------------- General Purpose Direct Memory Access (GPDMA) -----------------*/
/** \brief  General Purpose Direct Memory Access (GPDMA) register structure definition */
typedef struct                          /* Common Registers                   */
{
  _R  PFdword DMACIntStat;
  _R  PFdword DMACIntTCStat;
  _W  PFdword DMACIntTCClear;
  _R  PFdword DMACIntErrStat;
  _W  PFdword DMACIntErrClr;
  _R  PFdword DMACRawIntTCStat;
  _R  PFdword DMACRawIntErrStat;
  _R  PFdword DMACEnbldChns;
  _RW PFdword DMACSoftBReq;
  _RW PFdword DMACSoftSReq;
  _RW PFdword DMACSoftLBReq;
  _RW PFdword DMACSoftLSReq;
  _RW PFdword DMACConfig;
  _RW PFdword DMACSync;
} GPDMA_TypeDef;

/** \brief  General Purpose Direct Memory Access Channel (GPDMACH) register structure definition */
typedef struct                          /* Channel Registers                  */
{
  _RW PFdword DMACCSrcAddr;
  _RW PFdword DMACCDestAddr;
  _RW PFdword DMACCLLI;
  _RW PFdword DMACCControl;
  _RW PFdword DMACCConfig;
} GPDMACH_TypeDef;

/*------------- Universal Serial Bus (USB) -----------------------------------*/
/** \brief  Universal Serial Bus (USB) register structure definition */
typedef struct
{
  _R  PFdword HcRevision;             /* USB Host Registers                 */
  _RW PFdword HcControl;
  _RW PFdword HcCommandStatus;
  _RW PFdword HcInterruptStatus;
  _RW PFdword HcInterruptEnable;
  _RW PFdword HcInterruptDisable;
  _RW PFdword HcHCCA;
  _R  PFdword HcPeriodCurrentED;
  _RW PFdword HcControlHeadED;
  _RW PFdword HcControlCurrentED;
  _RW PFdword HcBulkHeadED;
  _RW PFdword HcBulkCurrentED;
  _R  PFdword HcDoneHead;
  _RW PFdword HcFmInterval;
  _R  PFdword HcFmRemaining;
  _R  PFdword HcFmNumber;
  _RW PFdword HcPeriodicStart;
  _RW PFdword HcLSTreshold;
  _RW PFdword HcRhDescriptorA;
  _RW PFdword HcRhDescriptorB;
  _RW PFdword HcRhStatus;
  _RW PFdword HcRhPortStatus1;
  _RW PFdword HcRhPortStatus2;
       PFdword RESERVED0[40];
  _R  PFdword Module_ID;

  _R  PFdword OTGIntSt;               /* USB On-The-Go Registers            */
  _RW PFdword OTGIntEn;
  _W  PFdword OTGIntSet;
  _W  PFdword OTGIntClr;
  _RW PFdword OTGStCtrl;
  _RW PFdword OTGTmr;
       PFdword RESERVED1[58];

  _R  PFdword USBDevIntSt;            /* USB Device Interrupt Registers     */
  _RW PFdword USBDevIntEn;
  _W  PFdword USBDevIntClr;
  _W  PFdword USBDevIntSet;

  _W  PFdword USBCmdCode;             /* USB Device SIE Command Registers   */
  _R  PFdword USBCmdData;

  _R  PFdword USBRxData;              /* USB Device Transfer Registers      */
  _W  PFdword USBTxData;
  _R  PFdword USBRxPLen;
  _W  PFdword USBTxPLen;
  _RW PFdword USBCtrl;
  _W  PFdword USBDevIntPri;

  _R  PFdword USBEpIntSt;             /* USB Device Endpoint Interrupt Regs */
  _RW PFdword USBEpIntEn;
  _W  PFdword USBEpIntClr;
  _W  PFdword USBEpIntSet;
  _W  PFdword USBEpIntPri;

  _RW PFdword USBReEp;                /* USB Device Endpoint Realization Reg*/
  _W  PFdword USBEpInd;
  _RW PFdword USBMaxPSize;

  _R  PFdword USBDMARSt;              /* USB Device DMA Registers           */
  _W  PFdword USBDMARClr;
  _W  PFdword USBDMARSet;
       PFdword RESERVED2[9];
  _RW PFdword USBUDCAH;
  _R  PFdword USBEpDMASt;
  _W  PFdword USBEpDMAEn;
  _W  PFdword USBEpDMADis;
  _R  PFdword USBDMAIntSt;
  _RW PFdword USBDMAIntEn;
       PFdword RESERVED3[2];
  _R  PFdword USBEoTIntSt;
  _W  PFdword USBEoTIntClr;
  _W  PFdword USBEoTIntSet;
  _R  PFdword USBNDDRIntSt;
  _W  PFdword USBNDDRIntClr;
  _W  PFdword USBNDDRIntSet;
  _R  PFdword USBSysErrIntSt;
  _W  PFdword USBSysErrIntClr;
  _W  PFdword USBSysErrIntSet;
       PFdword RESERVED4[15];

  union {
  _R  PFdword I2C_RX;                 /* USB OTG I2C Registers              */
  _W  PFdword I2C_TX;
  };
  _R  PFdword I2C_STS;
  _RW PFdword I2C_CTL;
  _RW PFdword I2C_CLKHI;
  _W  PFdword I2C_CLKLO;
       PFdword RESERVED5[824];

  union {
  _RW PFdword USBClkCtrl;             /* USB Clock Control Registers        */
  _RW PFdword OTGClkCtrl;
  };
  union {
  _R  PFdword USBClkSt;
  _R  PFdword OTGClkSt;
  };
} USB_TypeDef;

/*------------- Ethernet Media Access Controller (EMAC) ----------------------*/
/** \brief  Ethernet Media Access Controller (EMAC) register structure definition */
typedef struct
{
  _RW PFdword MAC1;                   /* MAC Registers                      */
  _RW PFdword MAC2;
  _RW PFdword IPGT;
  _RW PFdword IPGR;
  _RW PFdword CLRT;
  _RW PFdword MAXF;
  _RW PFdword SUPP;
  _RW PFdword TEST;
  _RW PFdword MCFG;
  _RW PFdword MCMD;
  _RW PFdword MADR;
  _W  PFdword MWTD;
  _R  PFdword MRDD;
  _R  PFdword MIND;
       PFdword RESERVED0[2];
  _RW PFdword SA0;
  _RW PFdword SA1;
  _RW PFdword SA2;
       PFdword RESERVED1[45];
  _RW PFdword Command;                /* Control Registers                  */
  _R  PFdword Status;
  _RW PFdword RxDescriptor;
  _RW PFdword RxStatus;
  _RW PFdword RxDescriptorNumber;
  _R  PFdword RxProduceIndex;
  _RW PFdword RxConsumeIndex;
  _RW PFdword TxDescriptor;
  _RW PFdword TxStatus;
  _RW PFdword TxDescriptorNumber;
  _RW PFdword TxProduceIndex;
  _R  PFdword TxConsumeIndex;
       PFdword RESERVED2[10];
  _R  PFdword TSV0;
  _R  PFdword TSV1;
  _R  PFdword RSV;
       PFdword RESERVED3[3];
  _RW PFdword FlowControlCounter;
  _R  PFdword FlowControlStatus;
       PFdword RESERVED4[34];
  _RW PFdword RxFilterCtrl;           /* Rx Filter Registers                */
  _RW PFdword RxFilterWoLStatus;
  _RW PFdword RxFilterWoLClear;
       PFdword RESERVED5;
  _RW PFdword HashFilterL;
  _RW PFdword HashFilterH;
       PFdword RESERVED6[882];
  _R  PFdword IntStatus;              /* Module Control Registers           */
  _RW PFdword IntEnable;
  _W  PFdword IntClear;
  _W  PFdword IntSet;
       PFdword RESERVED7;
  _RW PFdword PowerDown;
       PFdword RESERVED8;
  _RW PFdword Module_ID;
} EMAC_TypeDef;

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif


/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define FLASH_BASE        (0x00000000UL)
#define RAM_BASE          (0x10000000UL)
#ifdef __LPC17XX_REV00
#define AHBRAM0_BASE      (0x20000000UL)
#define AHBRAM1_BASE      (0x20004000UL)
#else
#define AHBRAM0_BASE      (0x2007C000UL)
#define AHBRAM1_BASE      (0x20080000UL)
#endif
#define GPIO_BASE         (0x2009C000UL)
#define APB0_BASE         (0x40000000UL)
#define APB1_BASE         (0x40080000UL)
#define AHB_BASE          (0x50000000UL)
#define CM3_BASE          (0xE0000000UL)

/* APB0 peripherals                                                           */
#define WDT_BASE          (APB0_BASE + 0x00000)
#define TIM0_BASE         (APB0_BASE + 0x04000)
#define TIM1_BASE         (APB0_BASE + 0x08000)
#define UART0_BASE        (APB0_BASE + 0x0C000)
#define UART1_BASE        (APB0_BASE + 0x10000)
#define PWM1_BASE         (APB0_BASE + 0x18000)
#define I2C0_BASE         (APB0_BASE + 0x1C000)
#define SPI_BASE          (APB0_BASE + 0x20000)
#define RTC_BASE          (APB0_BASE + 0x24000)
#define GPIOINT_BASE      (APB0_BASE + 0x28080)
#define PINCON_BASE       (APB0_BASE + 0x2C000)
#define SSP1_BASE         (APB0_BASE + 0x30000)
#define ADC_BASE          (APB0_BASE + 0x34000)
#define CANAF_RAM_BASE    (APB0_BASE + 0x38000)
#define CANAF_BASE        (APB0_BASE + 0x3C000)
#define CANCR_BASE        (APB0_BASE + 0x40000)
#define CAN1_BASE         (APB0_BASE + 0x44000)
#define CAN2_BASE         (APB0_BASE + 0x48000)
#define I2C1_BASE         (APB0_BASE + 0x5C000)

/* APB1 peripherals                                                           */
#define SSP0_BASE         (APB1_BASE + 0x08000)
#define DAC_BASE          (APB1_BASE + 0x0C000)
#define TIM2_BASE         (APB1_BASE + 0x10000)
#define TIM3_BASE         (APB1_BASE + 0x14000)
#define UART2_BASE        (APB1_BASE + 0x18000)
#define UART3_BASE        (APB1_BASE + 0x1C000)
#define I2C2_BASE         (APB1_BASE + 0x20000)
#define I2S_BASE          (APB1_BASE + 0x28000)
#define RIT_BASE          (APB1_BASE + 0x30000)
#define MCPWM_BASE        (APB1_BASE + 0x38000)
#define QEI_BASE          (APB1_BASE + 0x3C000)
#define SC_BASE           (APB1_BASE + 0x7C000)

/* AHB peripherals                                                            */
#define EMAC_BASE         (AHB_BASE  + 0x00000)
#define GPDMA_BASE        (AHB_BASE  + 0x04000)
#define GPDMACH0_BASE     (AHB_BASE  + 0x04100)
#define GPDMACH1_BASE     (AHB_BASE  + 0x04120)
#define GPDMACH2_BASE     (AHB_BASE  + 0x04140)
#define GPDMACH3_BASE     (AHB_BASE  + 0x04160)
#define GPDMACH4_BASE     (AHB_BASE  + 0x04180)
#define GPDMACH5_BASE     (AHB_BASE  + 0x041A0)
#define GPDMACH6_BASE     (AHB_BASE  + 0x041C0)
#define GPDMACH7_BASE     (AHB_BASE  + 0x041E0)
#define USB_BASE          (AHB_BASE  + 0x0C000)

/* GPIOs                                                                      */
#define GPIO0_BASE        (GPIO_BASE + 0x00000)
#define GPIO1_BASE        (GPIO_BASE + 0x00020)
#define GPIO2_BASE        (GPIO_BASE + 0x00040)
#define GPIO3_BASE        (GPIO_BASE + 0x00060)
#define GPIO4_BASE        (GPIO_BASE + 0x00080)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define PERIPH_SC                ((SC_TypeDef        *) SC_BASE       )
#define PERIPH_GPIO0             ((GPIO_TypeDef      *) GPIO0_BASE    )
#define PERIPH_GPIO1             ((GPIO_TypeDef      *) GPIO1_BASE    )
#define PERIPH_GPIO2             ((GPIO_TypeDef      *) GPIO2_BASE    )
#define PERIPH_GPIO3             ((GPIO_TypeDef      *) GPIO3_BASE    )
#define PERIPH_GPIO4             ((GPIO_TypeDef      *) GPIO4_BASE    )
#define PERIPH_WDT               ((WDT_TypeDef       *) WDT_BASE      )
#define PERIPH_TIMER0            ((TIM_TypeDef       *) TIM0_BASE     )
#define PERIPH_TIMER1            ((TIM_TypeDef       *) TIM1_BASE     )
#define PERIPH_TIMER2            ((TIM_TypeDef       *) TIM2_BASE     )
#define PERIPH_TIMER3            ((TIM_TypeDef       *) TIM3_BASE     )
#define PERIPH_RIT               ((RIT_TypeDef       *) RIT_BASE      )
#define PERIPH_UART0             ((UART_TypeDef      *) UART0_BASE    )
#define PERIPH_UART1             ((UART1_TypeDef     *) UART1_BASE    )
#define PERIPH_UART2             ((UART_TypeDef      *) UART2_BASE    )
#define PERIPH_UART3             ((UART_TypeDef      *) UART3_BASE    )
#define PERIPH_PWM1              ((PWM_TypeDef       *) PWM1_BASE     )
#define PERIPH_I2C0              ((I2C_TypeDef       *) I2C0_BASE     )
#define PERIPH_I2C1              ((I2C_TypeDef       *) I2C1_BASE     )
#define PERIPH_I2C2              ((I2C_TypeDef       *) I2C2_BASE     )
#define PERIPH_I2S               ((I2S_TypeDef       *) I2S_BASE      )
#define PERIPH_SPI               ((SPI_TypeDef       *) SPI_BASE      )
#define PERIPH_RTC               ((RTC_TypeDef       *) RTC_BASE      )
#define PERIPH_GPIOINT           ((GPIOINT_TypeDef   *) GPIOINT_BASE  )
#define PERIPH_PINCON            ((PINCON_TypeDef    *) PINCON_BASE   )
#define PERIPH_SSP0              ((SSP_TypeDef       *) SSP0_BASE     )
#define PERIPH_SSP1              ((SSP_TypeDef       *) SSP1_BASE     )
#define PERIPH_ADC               ((ADC_TypeDef       *) ADC_BASE      )
#define PERIPH_DAC               ((DAC_TypeDef       *) DAC_BASE      )
#define PERIPH_CANAF_RAM         ((CANAF_RAM_TypeDef *) CANAF_RAM_BASE)
#define PERIPH_CANAF             ((CANAF_TypeDef     *) CANAF_BASE    )
#define PERIPH_CANCR             ((CANCR_TypeDef     *) CANCR_BASE    )
#define PERIPH_CAN1              ((CAN_TypeDef       *) CAN1_BASE     )
#define PERIPH_CAN2              ((CAN_TypeDef       *) CAN2_BASE     )
#define PERIPH_MCPWM             ((MCPWM_TypeDef     *) MCPWM_BASE    )
#define PERIPH_QEI               ((QEI_TypeDef       *) QEI_BASE      )
#define PERIPH_EMAC              ((EMAC_TypeDef      *) EMAC_BASE     )
#define PERIPH_GPDMA             ((GPDMA_TypeDef     *) GPDMA_BASE    )
#define PERIPH_GPDMACH0          ((GPDMACH_TypeDef   *) GPDMACH0_BASE )
#define PERIPH_GPDMACH1          ((GPDMACH_TypeDef   *) GPDMACH1_BASE )
#define PERIPH_GPDMACH2          ((GPDMACH_TypeDef   *) GPDMACH2_BASE )
#define PERIPH_GPDMACH3          ((GPDMACH_TypeDef   *) GPDMACH3_BASE )
#define PERIPH_GPDMACH4          ((GPDMACH_TypeDef   *) GPDMACH4_BASE )
#define PERIPH_GPDMACH5          ((GPDMACH_TypeDef   *) GPDMACH5_BASE )
#define PERIPH_GPDMACH6          ((GPDMACH_TypeDef   *) GPDMACH6_BASE )
#define PERIPH_GPDMACH7          ((GPDMACH_TypeDef   *) GPDMACH7_BASE )
#define PERIPH_USB               ((USB_TypeDef       *) USB_BASE      )


/** GPIO Port 0 Register addresses.		*/
/** These addresses are used as base addresses and port-wise offset will be added to for each port operation.	*/
#define GPIO_IODIR_BASE				0x2009C000
#define GPIO_MASK_BASE				0x2009C010
#define GPIO_PIN_BASE				0x2009C014
#define GPIO_SET_BASE				0x2009C018
#define GPIO_CLEAR_BASE				0x2009C01C

/** Port-wise offsets to add with base addresses for port read/write operations.		*/
#define GPIO_PORT_OFFSET			0x20
#define GPIO_PORT_0					0x00
#define GPIO_PORT_1					(GPIO_PORT_0 + GPIO_PORT_OFFSET)
#define GPIO_PORT_2					(GPIO_PORT_1 + GPIO_PORT_OFFSET)
#define GPIO_PORT_3					(GPIO_PORT_2 + GPIO_PORT_OFFSET)
#define GPIO_PORT_4					(GPIO_PORT_3 + GPIO_PORT_OFFSET)

/** @} */

