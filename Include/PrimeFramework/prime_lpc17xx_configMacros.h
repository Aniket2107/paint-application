#pragma once


#define _PCLK_DIV(x)				PCLK_DIV_##x
#define _PWR(x)						PWR_##x
#define _INT_HANDLER(x)				x##_IRQHandler
#define _IRQ_NUM(x)					x##_IRQn
#define _PERIPH(x)					PERIPH_##x
#define _EINT(x)					EINT_##x


#define PCLK_DIV(x)					_PCLK_DIV(x)
#define PWR(x)						_PWR(x)
#define INT_HANDLER(x)				_INT_HANDLER(x)
#define IRQ_NUM(x)					_IRQ_NUM(x)
#define PERIPH(x)					_PERIPH(x)
#define EINT_CH(x)					_EINT_CH(x)

/** Macros for turning peripheral power on and off		*/
#define _POWER_ON(PERIPHERAL)		PERIPH_SC->PCONP |= PERIPHERAL
#define _POWER_OFF(PERIPHERAL)		PERIPH_SC->PCONP &= ~(PERIPHERAL)

#define POWER_ON(PERIPHERAL)		_POWER_ON(PWR(PERIPHERAL))
#define POWER_OFF(PERIPHERAL)		_POWER_OFF(PWR(PERIPHERAL))










