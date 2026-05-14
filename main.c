#include "stm32g030xx.h"
#include "System_RCC.h"
#include "GPIO.h"
#include "I2C_2.h"
#include "SSD1306.h"

void delay_ms(uint32_t ms){
	for(uint32_t i = 0; i < ms * 4000; i++);
}

void OLED_CLEAR(void)
{
    for(uint8_t page = 0; page < 8; page++)
    {
        OLED_STARTING_PAGE(OLED_SET_PAGE_0 + page);

        I2C2_WRITE_CMD(0x00);
        I2C2_WRITE_CMD(0x10);

        for(uint8_t col = 0; col < 128; col++)
        {
            I2C2_WRITE_DATA(0x00);

        }
    }
}

void OLED_GLOW(void)
{
    for(uint8_t page = 0; page < 8; page++)
    {
        /* page select */
        OLED_STARTING_PAGE(OLED_SET_PAGE_0 + page);

        /* col reset — COL0 */
        I2C2_WRITE_CMD(0x00);   // lower col  = 0
        I2C2_WRITE_CMD(0x10);   // higher col = 0

        /* 128 bytes = 0x00 ? ?? pixel OFF */
        for(uint8_t col = 0; col < 128; col++)
        {
            I2C2_WRITE_DATA(0x01);
					delay_ms(10);
					OLED_FUN_CMD(OLED_SET_DISPLAY_ON);
					
					
        }
    }
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
    OLED_ADDRESSING_CMD_DATA(OLED_SET_PAGE_ADDRESSING_DATA);

    OLED_FUN_CMD(OLED_SET_DISPLAY_RAM);    
    OLED_FUN_CMD(OLED_SET_NORMAL_DISPLAY); 
		
		delay_ms(100);
		
		OLED_CLEAR();
		
		OLED_GLOW();
		
		delay_ms(100);
		

    while(1)
{


}
			
}