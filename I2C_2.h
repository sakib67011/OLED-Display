#ifndef I2C_2_H_

#define I2C_2_H_

#include "stm32g030xx.h"

void I2C_2_RCC_CONFIGURE();
void I2C_2_CONFIGURE();


void I2C2_WRITE_CMD(uint8_t I2C_CMD_SEND);
void I2C2_WRITE_DATA(uint8_t I2C_DATA_SEND);

void I2C2_WRITE_FONT(const uint8_t *I2C_FONT_DATA);
void I2C2_WRITE_IMAGE_PAGE(const uint8_t *page_data, uint8_t SIZE);
void OLED_SPACE (void);


#endif
