#ifndef SYSTEM_RCC_H

#define SYSTEM_RCC_H

#include "stm32g030xx.h"

/*---------------SYSTEM RCC CONFIGURE START---------------*/

void RCC_CONFIGURE(void)

{

	RCC->CR |= RCC_CR_HSION;		//--------HIGH SPEED INTERNAL 16MHZ---------

	

	while((RCC->CR & RCC_CR_HSIRDY)==0);		//-------------STATUS HSI-----------

	

	RCC->CFGR &= ~RCC_CFGR_SW;		//---------HSI AS SYSTEM--------- 	

}

/*---------------SYSTEM RCC CONFIGURE END---------------*/

#endif