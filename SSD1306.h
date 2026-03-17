#ifndef SSD1306_H

#define SSD1306_H

#include "stm32g030xx.h"

/*DEFINE COMMAND*/
typedef enum 
{
	/* 1. Set Contrast Control (Double Byte Command) */
  SET_CONTRAST         = 0x81, // Followed by 0x00 to 0xFF (Default 0x7F)

  /* 2. Entire Display ON (A4h or A5h) */
  SET_RESUME_RAM_CONTENT   = 0xA4, // Output follows RAM content (RESET)
  SET_ENTIRE_DISPLAY_ON    = 0xA5, // Output ignores RAM (All pixels ON)

  /* 3. Set Normal/Inverse Display (A6h or A7h) */
  SET_NORMAL_DISPLAY   = 0xA6, // 0 in RAM: OFF, 1 in RAM: ON (RESET)
  SET_INVERSE_DISPLAY  = 0xA7, // 0 in RAM: ON, 1 in RAM: OFF

  /* 4. Set Display ON/OFF (AEh or AFh) */
  SET_DISPLAY_OFF      = 0xAE, // Sleep mode (RESET)
  SET_DISPLAY_ON       = 0xAF, // Normal mode
	
	/* 5. Charge Pump Setting (Double Byte Command) */
  SET_CHARGE_PUMP_SETTING  = 0x8D, // Command to start Charge Pump configuration
  SET_CHARGE_PUMP_DISABLE  = 0x10, // Disable Charge Pump (RESET state)
  SET_CHARGE_PUMP_ENABLE   = 0x14  // Enable Charge Pump (Required to see anything!
	
	
} OLED_CMD_X;



void OLED_COMMAND(OLED_CMD_X OLED_CMD);

void OLED_INIT();




#endif