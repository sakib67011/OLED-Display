#ifndef SSD1306_H

#define SSD1306_H

#include "stm32g030xx.h"


typedef enum {
	
	OLED_SET_CHARGE_PUMP_SETTING 	= 0x8D,
	OLED_SET_CHARGE_PUMP_ENABLE 		= 0x14,
	OLED_SET_CHARGE_PUMP_DISABLE 	= 0x10,
	
	
	OLED_SET_CONTRAST        			= 0x81,
	OLED_SET_CONTRAST_MIN    			= 0x00,
	OLED_SET_CONTRAST_RESET  			= 0x7F,
	OLED_SET_CONTRAST_MAX    			= 0xFF,
	OLED_SET_DISPLAY_RAM     			= 0xA4,   // X0 	= 0b (RESET)
	OLED_SET_ENTIRE_DISPLAY_ON  	= 0xA5,   // X0 	= 1b
	OLED_SET_NORMAL_DISPLAY  			= 0xA6,   // X[0] = 0b (RESET)
	OLED_SET_INVERSE_DISPLAY 			= 0xA7,   // X[0] = 1b
	OLED_SET_DISPLAY_OFF     			= 0xAE,   // X[0] = 0b, sleep (RESET)
	OLED_SET_DISPLAY_ON      			= 0xAF,   // X[0] = 1b, normal
	
} OLED_FUN_CMD_X;

void OLED_FUN_CMD(OLED_FUN_CMD_X FUN_CMD_X);

//////////////////////////////////////////////


typedef enum
{
	OLED_SET_MEMORY_ADDRESSING_MODE 		= 0x20,
	OLED_SET_COLUMN_ADDRESSING_MODE 		= 0x21,
	OLED_SET_PAGE_ADDRESSING_MODE 			= 0x22,
	

} OLED_ADDRESSING_CMD_X;

void OLED_ADDRESSING_CMD(OLED_ADDRESSING_CMD_X ADDR_CMD_X);


//////////////////////////////////////////////////////////

typedef enum
{
	OLED_SET_HORIZONTAL_ADDRESSING_DATA 	= 0x00,
	OLED_SET_VERTICAL_ADDRESSING_DATA 		= 0x01,
	OLED_SET_PAGE_ADDRESSING_DATA					= 0x02,
	

} OLED_ADDRESSING_CMD_DATA_X;

void OLED_ADDRESSING_CMD_DATA(OLED_ADDRESSING_CMD_DATA_X ADDR_DATA_X);

//////////////////////////////////////////////////////////////////

typedef enum
{
    OLED_SET_PAGE_0 = 0xB0,
    OLED_SET_PAGE_1,
    OLED_SET_PAGE_2,
    OLED_SET_PAGE_3,
    OLED_SET_PAGE_4,
    OLED_SET_PAGE_5,
    OLED_SET_PAGE_6,
    OLED_SET_PAGE_7

} OLED_PAGE_X;

void OLED_STARTING_PAGE(OLED_PAGE_X PAGE_X);



#endif