/**
 *  \file       eduarmBoardConfig.c
 *  \brief      Source file contains GPIO configuration structure for the peripherals on EduARM board.
 *
 */

#include "prime_framework.h"

#ifdef MCU_CHIP_lpc1768
#include "prime_gpio.h"
#include "eduarmBoardConfig.h"
#include "eduarmBoardDefs.h"


PFCfgGpio eduarmLedGpioCfg[3] = 
{
    // LED UL1
    {EDUARM_LED_UL1_PORT, EDUARM_LED_UL1_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // LED UL2
    {EDUARM_LED_UL2_PORT, EDUARM_LED_UL2_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // LED UL3
    {EDUARM_LED_UL3_PORT, EDUARM_LED_UL3_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio}
};

PFCfgGpio eduarmPushButtonGpioCfg[5] =
{    
    // PB1
    {EDUARM_PUSHBUTTON_PB1_PORT, EDUARM_PUSHBUTTON_PB1_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // PB2
    {EDUARM_PUSHBUTTON_PB2_PORT, EDUARM_PUSHBUTTON_PB2_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // PB3
    {EDUARM_PUSHBUTTON_PB3_PORT, EDUARM_PUSHBUTTON_PB3_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // PB4
    {EDUARM_PUSHBUTTON_PB4_PORT, EDUARM_PUSHBUTTON_PB4_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // PB5
    {EDUARM_PUSHBUTTON_PB5_PORT, EDUARM_PUSHBUTTON_PB5_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio}
};

PFCfgGpio eduarmUart0GpioCfg[2] = 
{
    // TX0
    {EDUARM_UART_0_TX_PORT,EDUARM_UART_0_TX_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_2_TXD0},
    // RX0
    {EDUARM_UART_0_RX_PORT,EDUARM_UART_0_RX_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_3_RXD0}
};

PFCfgGpio eduarmUart2GpioCfg[2] = 
{
    // TX2
    {EDUARM_J2_15_UART_2_TX_PORT,EDUARM_J2_15_UART_2_TX_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_2_8_TXD2},
    // RX2
    {EDUARM_J2_14_UART_2_RX_PORT,EDUARM_J2_14_UART_2_RX_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_2_9_RXD2}
};

PFCfgGpio eduarmUart3GpioCfg[2] = 
{
    // TX3
    {EDUARM_J1_23_UART_3_TX_PORT,EDUARM_J1_23_UART_3_TX_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_0_TXD3},
    // RX3
    {EDUARM_J1_25_UART_3_RX_PORT,EDUARM_J1_25_UART_3_RX_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_1_RXD3}
};

PFCfgGpio eduarmEint3GpioCfg = {EDUARM_J2_13_EINT_3_PORT,EDUARM_J2_13_EINT_3_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_2_13_EINT3};
PFCfgGpio eduarmMma7660IntGpioCfg = {EDUARM_MMA_INT_PORT,EDUARM_MMA_INT_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_2_12_EINT2};
PFCfgGpio eduarmTouchIntGpioCfg = {EDUARM_TOUCH_INT_PORT,EDUARM_TOUCH_INT_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_2_11_EINT1};

PFCfgGpio eduarmAdc0GpioCfg = {EDUARM_J2_4_ADC_0_PORT,EDUARM_J2_4_ADC_0_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_23_ADC0};
PFCfgGpio eduarmAdc1GpioCfg = {EDUARM_VBAT_ADC_1_PORT,EDUARM_VBAT_ADC_1_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_24_ADC1};
PFCfgGpio eduarmAdc2GpioCfg = {EDUARM_J2_3_ADC_2_PORT,EDUARM_J2_3_ADC_2_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_25_ADC2};
PFCfgGpio eduarmAdc3GpioCfg = {EDUARM_J2_1_ADC_3_PORT,EDUARM_J2_1_ADC_3_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_26_ADC3};
PFCfgGpio eduarmAdc4GpioCfg = {EDUARM_J2_6_ADC_4_PORT,EDUARM_J2_6_ADC_4_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_30_ADC4};
PFCfgGpio eduarmAdc5GpioCfg = {EDUARM_J6_5_ADC_5_PORT,EDUARM_J6_5_ADC_5_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_31_ADC5};


PFCfgGpio eduarmI2c1GpioCfg[2] = 
{    
    // SDA
    {EDUARM_J1_23_I2C_1_SDA_PORT,EDUARM_J1_23_I2C_1_SDA_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_0_SDA1},
    // SCL
    {EDUARM_J1_25_I2C_1_SCL_PORT,EDUARM_J1_25_I2C_1_SCL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_1_SCL1}
};

PFCfgGpio eduarmI2c2GpioCfg[2] =
{
    // SDA
    {EDUARM_J1_24_I2C_2_SDA_PORT,EDUARM_J1_24_I2C_2_SDA_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_10_SDA2},
    // SCL
    {EDUARM_J1_26_I2C_2_SCL_PORT,EDUARM_J1_26_I2C_2_SCL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_11_SCL2}
};

PFCfgGpio eduarmSsp0GpioCfg[4] =
{
    // MISO0
    {EDUARM_J1_37_SSP_0_MISO_PORT,EDUARM_J1_37_SSP_0_MISO_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_23_MISO0},
    // MOSI0
    {EDUARM_J1_38_SSP_0_MOSI_PORT,EDUARM_J1_38_SSP_0_MOSI_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_24_MOSI0},
    // SCK0
    {EDUARM_J1_34_SSP_0_SCK_PORT,EDUARM_J1_34_SSP_0_SCK_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_20_SCK0},
    // SSEL0
    {EDUARM_J1_35_SSP_0_SSEL_PORT,EDUARM_J1_35_SSP_0_SSEL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_21_SSEL0}
};

 PFCfgGpio eduarmTouchGpioCfg[6] =
{
    // MISO0
    {EDUARM_TOUCH_SSP_0_MISO_PORT,EDUARM_TOUCH_SSP_0_MISO_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_17_MISO0},
    // MOSI0
    {EDUARM_TOUCH_SSP0_MOSI_PORT,EDUARM_TOUCH_SSP0_MOSI_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_18_MOSI0},
    // SCK0
    {EDUARM_TOUCH_SSP_0_SCK_PORT,EDUARM_TOUCH_SSP_0_SCK_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_15_SCK0},
    // SSEL0
    {EDUARM_TOUCH_SSP_0_SSEL_PORT,EDUARM_TOUCH_SSP_0_SSEL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_20_GPIO},
    // Interrupt
    {EDUARM_TOUCH_SSP_0_INT_PORT, EDUARM_TOUCH_SSP_0_INT_PIN, enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    // busy
    {EDUARM_TOUCH_SSP_0_BUSY_PORT, EDUARM_TOUCH_SSP_0_BUSY_PIN, enGpioDirInput, enGpioPinModePullDown, enGpioOpenDrainDisable, enGpioFunctionGpio},
};


 PFCfgGpio eduarmSdcardGpioCfg[4] =
{
    // MISO0
    {EDUARM_SDCARD_SSP_0_MISO_PORT,EDUARM_SDCARD_SSP_0_MISO_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_17_MISO0},
    // MOSI0
    {EDUARM_SDCARD_SSP0_MOSI_PORT,EDUARM_SDCARD_SSP0_MOSI_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_18_MOSI0},
    // SCK0
    {EDUARM_SDCARD_SSP_0_SCK_PORT,EDUARM_SDCARD_SSP_0_SCK_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_15_SCK0},
    // SSEL0
    {EDUARM_SDCARD_SSP_0_SSEL_PORT,EDUARM_SDCARD_SSP_0_SSEL_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_16_SSEL0}
};

PFCfgGpio eduarmLcdGpioCfg [6] =
{
    // Data pins
    { EDUARM_LCD_DATA_PORT,(EDUARM_LCD_DATA_0 | EDUARM_LCD_DATA_1 | EDUARM_LCD_DATA_2 | EDUARM_LCD_DATA_3 | EDUARM_LCD_DATA_4 | EDUARM_LCD_DATA_5 | EDUARM_LCD_DATA_6 | EDUARM_LCD_DATA_7  ), enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},
    
    // LCD RS pin
    { EDUARM_LCD_RS_PORT, EDUARM_LCD_RS_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},

    // LCD WR pin
    {EDUARM_LCD_WR_PORT, EDUARM_LCD_WR_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},

    // LCD RD pin
    { EDUARM_LCD_RD_PORT , EDUARM_LCD_RD_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},

    // LCD CS pin
    { EDUARM_LCD_CS_PORT, EDUARM_LCD_CS_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},

    // LCD RST pin
    { EDUARM_LCD_RST_PORT, EDUARM_LCD_RST_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionGpio},

 };
PFCfgGpio eduarmCan1GpioCfg[2] =    
{
    // RD1
    {EDUARM_J1_23_CAN_1_RD_1_PORT,EDUARM_J1_23_CAN_1_RD_1_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_0_RD1},
    // TD1
    {EDUARM_J1_25_CAN_1_TD_1_PORT,EDUARM_J1_25_CAN_1_TD_1_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_1_TD1}
};

PFCfgGpio eduarmCan2GpioCfg[2] =    
{
    // RD2
    {EDUARM_CAN_2_RD_2_PORT,EDUARM_CAN_2_RD_2_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_4_RD2},
    // TD1
    {EDUARM_CAN_2_TD_2_PORT,EDUARM_CAN_2_TD_2_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_5_TD2}
};


PFCfgGpio eduarmPwm1GpioCfg = {EDUARM_J2_18_PWM_CH_1_PORT,EDUARM_J2_18_PWM_CH_1_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_18_PWM1_1};
PFCfgGpio eduarmPwm2GpioCfg = {EDUARM_J1_5_PWM_CH_2_PORT,EDUARM_J1_5_PWM_CH_2_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_20_PWM1_2};
PFCfgGpio eduarmPwm3GpioCfg = {EDUARM_J1_4_PWM_CH_3_PORT,EDUARM_J1_4_PWM_CH_3_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_21_PWM1_3};
PFCfgGpio eduarmPwm4GpioCfg = {EDUARM_J1_7_PWM_CH_4_PORT,EDUARM_J1_7_PWM_CH_4_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_23_PWM1_4};
PFCfgGpio eduarmPwm5GpioCfg = {EDUARM_J1_9_PWM_CH_5_PORT,EDUARM_J1_9_PWM_CH_5_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_24_PWM1_5};

PFCfgGpio eduarmTimer0Cap1GpioCfg = {EDUARM_J2_12_TIMER_0_CAP_1_PORT,EDUARM_J2_12_TIMER_0_CAP_1_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_27_CAP0_1};    
PFCfgGpio eduarmTimer3Cap0GpioCfg = {EDUARM_J2_12_TIMER_0_CAP_1_PORT,EDUARM_J2_12_TIMER_0_CAP_1_PIN,enGpioDirInput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_0_23_CAP3_0};    
    
PFCfgGpio eduarmTimer1MatGpioCfg [2] = 
{
    {EDUARM_J1_13_TIMER_1_MAT_0_PORT,EDUARM_J1_13_TIMER_1_MAT_0_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_22_MAT1_0},
    {EDUARM_J1_14_TIMER_1_MAT_1_PORT,EDUARM_J1_14_TIMER_1_MAT_1_PIN,enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, GPIO_1_25_MAT1_1}
};
    
PFCfgGpio eduarmI2sGpioCfg[5] =
{
    {EDUARM_I2S_RX_SDA_PORT, EDUARM_I2S_RX_SDA_PIN,  enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionAlt1},
    {EDUARM_I2S_TX_CLK_PORT, EDUARM_I2S_TX_CLK_PIN,  enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionAlt1},
    {EDUARM_I2S_TX_WS_PORT, EDUARM_I2S_TX_WS_PIN,  enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionAlt1},
    {EDUARM_I2S_TX_SDA_PORT, EDUARM_I2S_TX_SDA_PIN,  enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionAlt1},
    {EDUARM_I2S_RX_MCLK_PORT, EDUARM_I2S_RX_MCLK_PIN, enGpioDirOutput, enGpioPinModePullUp, enGpioOpenDrainDisable, enGpioFunctionAlt1}
};
#endif    // #ifdef MCU_CHIP_lpc1768
