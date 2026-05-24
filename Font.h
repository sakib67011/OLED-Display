#ifndef FONT_H_

#define FONT_H_

#include "stm32g030xx.h"

void OLED_PRINT(char *STR);

void OLED_PRINT_CHAR(char C);

void OLED_DISPLAY_IMAGE(const uint8_t *image,uint8_t COLUMN_POSITION,uint8_t page_y,uint8_t width,uint8_t height);

#endif