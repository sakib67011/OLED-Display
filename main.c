#include "stm32g030xx.h"

#include "System_RCC.h"

#include "GPIO.h"

#include "I2C_2.h"

int main(void)

{

RCC_CONFIGURE();



GPIO_RCC_CONFIGURE(GPIO_A);

GPIO_CONFIGURE();



I2C_2_RCC_CONFIGURE();

I2C_2_CONFIGURE();



while(1)

{

	I2C_WRITE(0x11);

}

}