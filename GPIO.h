
#ifndef GPIO_H

#define GPIO_H

#include "stm32g030xx.h"

typedef enum

{ GPIO_A, 
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F

} GPIO_X;

void GPIO_RCC_CONFIGURE(GPIO_X PORT);


#endif




