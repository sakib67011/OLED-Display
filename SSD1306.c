#include "stm32g030xx.h"
#include "I2C_2.h"
#include "SSD1306.h"

void OLED_FUN_CMD(OLED_FUN_CMD_X FUN_CMD_X)
{
	I2C2_WRITE_CMD(FUN_CMD_X);
}

void OLED_ADDRESSING_CMD(OLED_ADDRESSING_CMD_X ADDR_CMD_X)

{
	I2C2_WRITE_CMD(ADDR_CMD_X);
}

void OLED_ADDRESSING_CMD_DATA(OLED_ADDRESSING_CMD_DATA_X ADDR_DATA_X)
{
	I2C2_WRITE_CMD(ADDR_DATA_X);
}


void OLED_STARTING_PAGE(OLED_PAGE_X PAGE_X)
{
	I2C2_WRITE_CMD(PAGE_X);
}

void OLED_SET_COURSOR(uint8_t X, uint8_t Y)
{
	uint8_t Y_axis = Y/8;
	uint8_t X_axis = X;
	
	
	if((Y_axis >=0)&&(Y_axis<8))
		
		{
		I2C2_WRITE_CMD(0xB0 + Y_axis);
	
		I2C2_WRITE_CMD(0x00 | (X_axis & 0x0F));
		I2C2_WRITE_CMD(0x10 | ((X_axis >>4) & 0x0F));
		
		}
		
}

void OLED_DISPLAY_CLEAR()
{
	for(uint8_t page = 0; page <8; page++)
	{
		OLED_STARTING_PAGE(OLED_SET_PAGE_0 + page);
		
		I2C2_WRITE_CMD(0x00);   
    I2C2_WRITE_CMD(0x10);
		
		for(uint8_t column = 0; column <128; column++)
		{
			I2C2_WRITE_DATA(0x00);
		}		
		
	}
}

