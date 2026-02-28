#include "stm32g030xx.h"
#include "System_RCC.h"

/*---------------SYSTEM RCC CONFIGURE START---------------*/

void RCC_CONFIGURE(void)

{
	//---HIGH SPEED INTERNAL 16MHZ

	RCC->CR |= RCC_CR_HSION;

	//---CHECK STATUS HSI	
	
	while((RCC->CR & RCC_CR_HSIRDY)==0);		
	
	//---HSI AS SYSTEM	

	RCC->CFGR &= ~RCC_CFGR_SW;		

}

/*---------------SYSTEM RCC CONFIGURE END---------------*/

