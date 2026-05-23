#include "stm32g030xx.h"
#include "System_RCC.h"
#include "GPIO.h"
#include "I2C_2.h"
#include "SSD1306.h"
#include "Font.h"


void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 4000; i++);
}





int main(void)
{
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
			OLED_SET_COURSOR(0,0);
			OLED_PRINT("Hello World");



    }
}