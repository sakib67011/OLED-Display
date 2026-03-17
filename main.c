#include "stm32g030xx.h"
#include "System_RCC.h"
#include "GPIO.h"
#include "I2C_2.h"
#include "SSD1306.h"

void delay_ms(uint32_t ms)
	{
		for(uint32_t i=0;i<ms*4000;i++);
	}


int main(void)
{
	RCC_CONFIGURE();
	
	GPIO_RCC_CONFIGURE(GPIO_A);
	GPIO_CONFIGURE();
	
	I2C_2_RCC_CONFIGURE();
	I2C_2_CONFIGURE();
	

	delay_ms(100);
	
	OLED_INIT();
	
	delay_ms(100);
	
	OLED_COMMAND(SET_ENTIRE_DISPLAY_ON);
	
	
	
	while(1)
		{
			OLED_COMMAND(SET_DISPLAY_ON);
			delay_ms(1000);
			OLED_COMMAND(SET_DISPLAY_OFF);
			delay_ms(1000);
        
    }
}
