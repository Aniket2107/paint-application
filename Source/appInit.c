/**
 *  \file       appInit.c
 *  \brief      Source file for Initializing the peripherals on the EduARM board.
 *  This file defines the configuration structures of the peripherals with required settings.
 *  Call appInit() function in your application program in the beginning to initialize the peripherals
 *  required in the project.
 *
 *  appInit() function initializes the following peripherals:
 *  1.  System Clock
 *  2.  UART for debugging purpose
 *  3.  RIT timer and Tick module for delay generation
 *  4.  Timer0 for Renderer Manager periodic callback
 *  5.  SPI0 for SDcard and Touch panel
 *  6.  I2C0 for Accelerometer device
 *  7.  Buzzer
 *  8.  LCD
 *  9.  Touch panel
 *  10. Accelerometer(MMA7660) device
 *	11. External interrupt for Touch panel
 *	12. Keypad
 *	13. SDcard
 *	14. Fat file system for storing files on the SDcard
 */

#include "appInit.h"

#define DRIVE_NUM					0

/*
 * \brief External Interrupt callback function. When there is a touch detected on the LCD screen,
 * It generates an external interrupt and this function is called.
 */
void extIntTouchCallback(void);

/*
*  \brief This function is called periodically in Timer0 callback. This function read the commands registered by Graphics
*  Manager and call hardware graphics library functions to display graphics on the LCD screen.
*/
void lcdRenderer(void);

/*********************************Clock Configuration******************************************/
PFCfgClk clkConfig = 
{
	100000000,				// CPU clock(CCLK) set to 100Mhz
	12000000,				// Main Oscillator frequency 12Mhz
	enPllClkSrcMainOSC		// Main oscillator as the PLL0 clock source
};

/*********************************RIT Configuration for Delay generation **********************/
PFCfgRit ritConfig = 
{
	25000,          		// Configure RIT for 1ms
	0x00,					// Compare mask
	pfTickUpdate,			// Tick module callback
	enPclkDiv_4,			// PCLK divider, PCLK_peripheral = CCLK/4
	enBooleanTrue,			// Halt on break
	enBooleanTrue			// Reset on match
};

/*******************************TIMER0 Configuration*******************************************/
PFCfgTimer0 timer0Config =
{
	25,						// Timer clock set to 1Mhz
	{8000,0,0,0},			// Configure timer for 8ms. An interrupt will be generated after every 8ms
	{enTimer0MatchActResetInt,enTimer0MatchActNone,enTimer0MatchActNone,enTimer0MatchActNone}, //Raise interrupt and reset the timer0 on compare match
	{ enTimer0ExtMatchCtrlNone,enTimer0ExtMatchCtrlNone,enTimer0ExtMatchCtrlNone,enTimer0ExtMatchCtrlNone},
	lcdRenderer,			// Renderer Manager periodic callback
	enPclkDiv_4,			// PCLK divider, PCLK_peripheral = CCLK/4
	enTimer0ModeTimer, 	 	// Timer mode
	enBooleanTrue			// Interrupt enable
};

/*******************************UART0 Configuration For Debug messages*************************/
PFCfgUart0 uart0Config = 
{
	enPclkDiv_4, 			// PCLK divider, PCLK_peripheral = CCLK/4
	enUart0Baudrate_9600, 	// 9600 baudrate
	enUart0Databits_8, 		// 8 data bits
	enUart0ParityNone, 		// No parity
	enUart0StopBits_1,		// 1 stop bit
	enUart0IntNone			// No interrupt
};

/*******************************SPI Configuration for SDcard and Touch panel*********************/
PFCfgSpi0 spi0Cfg =
{
	enPclkDiv_4,			// Peripheral clock divider for SPI0 module, PCLK_peripheral = CCLK/4
	enBooleanTrue,			// SPI enable in master mode
	enSpi0Databits_8,		// 8 data bits for SPI0 packet
	enSpi0Mode_0,			// SPI0 mode 0: Phase 0, Polarity 0
	25000000,				// 25Mhz baudrate in bits/second
	enSpi0IntNone			// No interrupt
};

/******************************I2C Configuration for Accelerometer device *********************/
#define 	EDUARM_MMA_I2C_0_SDA_PORT		GPIO_PORT_0
#define 	EDUARM_MMA_I2C_0_SDA_PIN		GPIO_PIN_27

#define 	EDUARM_MMA_I2C_0_SCL_PORT		GPIO_PORT_0
#define 	EDUARM_MMA_I2C_0_SCL_PIN		GPIO_PIN_28

// GPIO configuration
PFCfgGpio eduarmMma7660GpioCfg[2] =
{
	//SDA
	{EDUARM_MMA_I2C_0_SDA_PORT,EDUARM_MMA_I2C_0_SDA_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_27_SDA0},
	//SCL
	{EDUARM_MMA_I2C_0_SCL_PORT,EDUARM_MMA_I2C_0_SCL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_28_SCL0}
};

PFCfgI2c0 i2c0Cfg =
{
		100000,				// set 100Khz baudrate
		enPclkDiv_4,		// PCLK divider, PCLK_peripheral = CCLK/4
		50,					// 50% duty cycle for bus clock
		enBooleanTrue,		// Enable acknowledgement
		enBooleanFalse,		// Disable general call
		{0, 0, 0, 0},		// Own addresses
		{0, 0, 0, 0},		// Address masks
		enBooleanFalse		// Disable interrupt
};

CfgMma7660 accelConfig =
{
	en8SamplesPerSecond,	// Active mode sample rate set to 8 samples per second
	pfI2c0Write,			// I2c0Write function pointer
	pfI2c0Read,				// I2c0Read function pointer
	SH_X_INTERRUPT | SH_Y_INTERRUPT | SH_Z_INTERRUPT	//Set shake status on X,Y and Z axis in Tilt register. Interrupt is disabled
};

/*****************************BUZZER Configuration*****************************************/
#define EDUARM_BUZZER_PORT		GPIO_PORT_1
#define EDUARM_BUZZER_PIN		GPIO_PIN_26

//GPIO configuration
PFCfgGpio eduarmBuzzerGpioCfg =
{
	EDUARM_BUZZER_PORT, EDUARM_BUZZER_PIN, enGpioDirOutput,enGpioPinModeNoPullUpDown, enGpioOpenDrainDisable, GPIO_1_26_GPIO
};

BuzzerCfg buzzerConfig =
{
	{EDUARM_BUZZER_PORT, EDUARM_BUZZER_PIN}			// Buzzer GPIO pin
};

/*****************************LCD Configuration********************************************/
CfgGfx lcdDisplayConfig  = 
{  
	{
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_0},	// Data pin0
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_1},	// Data pin1
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_2},	// Data pin2
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_3},	// Data pin3
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_4},	// Data pin4
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_5},	// Data pin5
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_6},	// Data pin6
		{EDUARM_LCD_DATA_PORT,EDUARM_LCD_DATA_7}   	// Data pin7
	},
	{EDUARM_LCD_CS_PORT,EDUARM_LCD_CS_PIN},         // CS pin
	{EDUARM_LCD_RS_PORT,EDUARM_LCD_RS_PIN},         // RS pin
	{EDUARM_LCD_WR_PORT,EDUARM_LCD_WR_PIN},         // WR pin
	{EDUARM_LCD_RD_PORT,EDUARM_LCD_RD_PIN},         // RD pin
	{EDUARM_LCD_RST_PORT,EDUARM_LCD_RST_PIN},       // Reset pin
	enGfxOrientation_0,								// Screen orientation
	320,											// LCD height
	240												// LCD width
};

/*****************************TOUCH Configuration******************************************/
CfgTouch touchConfig = 
{
	{EDUARM_TOUCH_SSP_0_INT_PORT, EDUARM_TOUCH_SSP_0_INT_PIN},		// Touch interrupt pin
	{EDUARM_TOUCH_SSP_0_BUSY_PORT, EDUARM_TOUCH_SSP_0_BUSY_PIN},	// Touch busy pin
	{EDUARM_TOUCH_SSP_0_SSEL_PORT, EDUARM_TOUCH_SSP_0_SSEL_PIN},	// Touch chip select pin
	enTouchReferenceSelect_Differential,							// Differential reference select
	enTouchPrecision_12bit,											// 12 bit precision
	pfSpi0RegisterDevice,				// Function pointer for SPI register device
	pfSpi0ChipSelect,					// Function pointer for SPI chip select
	pfSpi0Write,						// Function pointer for SPI write
	pfSpi0Read							// Function pointer for SPI read
};

/******************************EINT1(Touch) Configuration**********************************/
PFcallback extInt1CallbackArray[1] = {extIntTouchCallback};
PFCfgEint1 extIntTouchConfig =
{
	extInt1CallbackArray,				// Array of callbacks
	1,									// 1 callback in callback array list
	enEint1ModeFallingEdge				// Falling edge triggered interrupt
};

/*****************************KEYPAD Configuration*****************************************/
PFGpioPortPin keypadKeyPortPin[5] = 
{
	{EDUARM_PUSHBUTTON_PB1_PORT, EDUARM_PUSHBUTTON_PB1_PIN},	// Pushbutton1 GPIO pin
	{EDUARM_PUSHBUTTON_PB2_PORT, EDUARM_PUSHBUTTON_PB2_PIN},	// Pushbutton2 GPIO pin
	{EDUARM_PUSHBUTTON_PB3_PORT, EDUARM_PUSHBUTTON_PB3_PIN},	// Pushbutton3 GPIO pin
	{EDUARM_PUSHBUTTON_PB4_PORT, EDUARM_PUSHBUTTON_PB4_PIN},	// Pushbutton4 GPIO pin
	{EDUARM_PUSHBUTTON_PB5_PORT, EDUARM_PUSHBUTTON_PB5_PIN}		// Pushbutton5 GPIO pin
};

/****************************SD CARD Configuration****************************************/
CfgMmc mmcCfg =
{
	{EDUARM_SDCARD_SSP_0_SSEL_PORT, EDUARM_SDCARD_SSP_0_SSEL_PIN},		// GPIO pin used for SPI chip select
	{EDUARM_SDCARD_SSP_0_SSEL_PORT, EDUARM_SDCARD_SSP_0_SSEL_PIN},		// GPIO pin used for power control
	 {0,0},			                    								// GPIO pin used for device detection
	enBooleanFalse,					    // Power control option for MMC card
	enBooleanFalse,						// Card detect option for MMC card
	pfSpi0RegisterDevice,				// Function pointer to SPI register device
	pfSpi0UnregisterDevice,				// Function pointer to SPI unregister device
	pfSpi0ChipSelect,					// Function pointer to SPI chip select
	pfSpi0ExchangeByte,					// Function pointer to SPI exchange byte
	pfSpi0Write,						// Function pointer to SPI read
	pfSpi0Read							// Function pointer to SPI write
};

/****************************DISKIO  Configuration****************************************/
CfgDisk diskCfg =
{
 (pCfgMmc)&mmcCfg,						// Device configuration structure
	mmcOpen,							// Pointer to device open function
	mmcGetStatus,						// Pointer to device get status function
	mmcRead,							// Pointer to device read function
	mmcWrite,							// Pointer to device write function
	mmcIoCtrl,							// Pointer to device control function
	enBooleanTrue,						// Set device write permission
	enBooleanTrue						// Set device IO control permission
};

/** File system object structure */
static FatFs fat;

void appInit(void)
{
	PFEnStatus status;
	PFbyte diskId;
	
	//CPU clock initialization
	pfSysSetCpuClock(&clkConfig);
	
	//GPIO pins initialization
	status = pfGpioInit(eduarmUart0GpioCfg, 2);		    // For UART0
	status = pfGpioInit(eduarmLcdGpioCfg,6);			// For LCD
	status = pfGpioInit(eduarmTouchGpioCfg,6);			// For Touch
	status = pfGpioInit(&eduarmTouchIntGpioCfg,1);		// For Touch Interrupt
	status = pfGpioInit(eduarmSdcardGpioCfg,4);			// For SDcard
	status = pfGpioInit(eduarmPushButtonGpioCfg,5);	    // For Keypad
	status = pfGpioInit(eduarmMma7660GpioCfg,2);		// For Accelerometer
	status = pfGpioInit(&eduarmBuzzerGpioCfg,1);		// For Buzzer

	// UART0 Peripheral initialization
	status = pfUart0Open(&uart0Config);
	if(status != enStatusSuccess)
	{
		while(1);
	}

	//RIT Peripheral initialization
	status = pfRitOpen(&ritConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nRIT initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nRIT initialized.");
	}		
    pfRitStart();								//Starting RIT timer

    //Initializing tick module. It is used for generating delay in the program.
    //Use pfTickDelayMs(delayMs) function to generate delay in the program. Pass delayMs value in milliseconds.
    pfTickSetTimerPeriod(1);					//Set tick timer period to 1ms
	
	//Timer Peripheral initialization
    status = pfTimer0Open(&timer0Config);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nTimer0 initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nTimer0 initialized.");
	}
	pfTimer0Start();							//Starting Timer0

	//SPI0 initialization
	status = pfSpi0Open((PFpCfgSpi0)&spi0Cfg);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nSPI0 initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nSPI0 initialized.");
	}

	//I2C0 initialization
	status = pfI2c0Open((PFpCfgI2c0)&i2c0Cfg);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nI2C0 initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nI2C0 initialized.");
	}

	//Buzzer initialization
	status = buzzerOpen(&buzzerConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nBuzzer initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nBuzzer initialized.");
	}

	//LCD initialization
	status  = gfxOpen(&lcdDisplayConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nLCD initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nLCD initialized.");
	}
		
	//Touch panel initialization
	status = touchOpen(&touchConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nTouch panel initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nTouch panel initialized.");
	}

	//Accelerometer initialization
	status = mma7660Open(&accelConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nAccelerometer initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nAcceleromter initialized.");
	}

	//External Interrupt initialization
	//External interrupt is initialized but the interrupt is disabled right now.
	//Use pfEint1Enable() function to enable the interrupt. After enabling this interrupt whenever
	//a touch is detected on the touch panel, extIntTouchCallback() function gets called.
	//Call touchAvailable() function in the callback to get touch coordinates.
    status = pfEint1Open(&extIntTouchConfig);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nTouch External interrupt initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nTouch External interrupt initialized.");
	}
	NVIC_SetPriority (EINT1_IRQn, 1);

	//Keypad initialization
    status = keypadKeyOpen(keypadKeyPortPin, 5);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nKeypad initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nKeypad initialized.");
	}

	//SDcard initialization
	status = diskOpen(&diskId, (pCfgDisk)&diskCfg);
	if(status != enStatusSuccess)
	{
		DEBUG_WRITE("\nDiskIO initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nDiskIO initialized.");
	}

	//FAT file system initialization
	status = fsMount(DRIVE_NUM, &fat);
	if(status!= enStatusSuccess)
	{
		DEBUG_WRITE("\nFatFS initialization failed.");
		while(1);
	}
	else
	{
		DEBUG_WRITE("\nFatFS initialized.");
	}
    
	DEBUG_WRITE("\n\nWelcome to Phi Education.\n");
}

//This function gets called when there is a touch detected on the LCD screen and the
//external interrupt is enabled.
void extIntTouchCallback(void)
{
	//DEBUG_WRITE("\nExtTouchInt");
}
