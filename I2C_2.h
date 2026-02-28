#ifndef I2C_2_H

#define I2C_2_H

#include "stm32g030xx.h"

void I2C_2_RCC_CONFIGURE();
void I2C_2_CONFIGURE();


void I2C_WRITE(uint8_t I2C_DATA_SEND);

#endif
