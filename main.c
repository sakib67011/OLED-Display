#include "stm32g030xx.h"
#include "System_RCC.h"
#include "GPIO.h"
#include "I2C_2.h"
#include "SSD1306.h"
#include "Font.h"
#include <stdio.h>


void delay_ms(uint32_t ms)
{
	for(uint32_t i = 0; i < ms * 4000; i++);
}


int main(void)
{
	char counter_buffer[50];
	uint32_t counter = 0;
	
    RCC_CONFIGURE();

    GPIO_RCC_CONFIGURE(GPIO_A);
    GPIO_CONFIGURE();

    I2C_2_RCC_CONFIGURE();
    I2C_2_CONFIGURE();

    delay_ms(100);


    OLED_FUN_CMD(OLED_SET_DISPLAY_OFF);


    OLED_FUN_CMD(OLED_SET_CHARGE_PUMP_SETTING);
    OLED_FUN_CMD(OLED_SET_CHARGE_PUMP_ENABLE);

   
    OLED_ADDRESSING_CMD(OLED_SET_MEMORY_ADDRESSING_MODE);
    OLED_ADDRESSING_CMD_DATA(OLED_SET_HORIZONTAL_ADDRESSING_DATA);


    OLED_FUN_CMD(OLED_SET_DISPLAY_RAM);
    OLED_FUN_CMD(OLED_SET_NORMAL_DISPLAY);
		
		OLED_DISPLAY_CLEAR();
		
    OLED_FUN_CMD(OLED_SET_DISPLAY_ON);
    delay_ms(10);
		

    while(1)
    {
			OLED_DISPLAY_CLEAR();

			for(counter = 0; counter <1000; counter++)
			{
				OLED_SET_COURSOR(0,0);
				sprintf(counter_buffer,"%u",counter);
				
				OLED_PRINT(counter_buffer);
				
				//delay_ms(10);
				
			}
			counter = 0;



    }
}