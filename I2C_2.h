#ifndef I2C_2_H

#define I2C_2_H

#include "stm32g030xx.h"

/*-------------------I2C_2 RCC CONFIGURE START-----------------*/

void I2C_2_RCC_CONFIGURE()

{

RCC ->APBENR1 |= RCC_APBENR1_I2C2EN;

}

/*-------------------I2C_2 RCC CONFIGURE END-----------------*/

/*-------------------I2C_2 CONFIGURE START-----------------*/

void I2C_2_CONFIGURE()

{

	//T_I2C_CLK = 1/16MHz



	//T_PRESC = (PRESC + 1)*T_I2C_CLK



	//T_SCLH = (SCLH + 1)*T_I2C_CLK



	//T_SCLL = (SCLL + 1)*T_I2C_CLK



	//T_SCL = (SCLH + 1 + SCLL + 1)*T_PRESC



	//T_SCLDEL = (SCLDEL + 1)*T_PRESC



	//T_SDADEL = (SDADEL + 1)*T_PRESC



	/*TIMINGR = (0x00 << 28) |(0x03 << 20) | (0x00 << 16) | (0x50 << 8) | (0x51 << 0)*/





	I2C2->CR1 &= ~(I2C_CR1_PE); //----------------I2C DISABLE



	I2C2->CR1 |= I2C_CR1_ANFOFF; //---------------I2C ANALOG FILTER DISABLE



	I2C2->CR1 &= ~I2C_CR1_DNF; //---------------I2C DIGITAL FILTER DISABLE



	I2C2->TIMINGR &= ~I2C_TIMINGR_PRESC;

	I2C2->TIMINGR |= (0x3 << I2C_TIMINGR_PRESC_Pos); //-------------PRESCALE TO 0----> 16MHz or 62.5ns



	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLDEL;

	I2C2->TIMINGR |= (0x4<<I2C_TIMINGR_SCLDEL_Pos);



	I2C2->TIMINGR &= ~I2C_TIMINGR_SDADEL;

	I2C2->TIMINGR |= (0x2<<I2C_TIMINGR_SDADEL_Pos);



	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLH;

	I2C2->TIMINGR |= (0xC3<<I2C_TIMINGR_SCLH_Pos);



	

	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLL;

	I2C2->TIMINGR |= (0xC7<<I2C_TIMINGR_SCLL_Pos);



	I2C2->CR1 |= (I2C_CR1_PE); //----------------I2C ENABLE

}

/*-------------------I2C_2 CONFIGURE END-----------------*/

/*-------------------I2C WRITE START--------------------------*/

void I2C_WRITE(uint8_t I2C_DATA_SEND)

{

	I2C2->CR2 &=~I2C_CR2_ADD10; //-----------------7-BIT ADDRESSING MODE



	I2C2->CR2 &=~I2C_CR2_NBYTES;

	I2C2->CR2 |= (1<<I2C_CR2_NBYTES_Pos); //-----------------1-BYTE DATA TRANSFER 



	I2C2->CR2 &= ~I2C_CR2_SADD;

	I2C2->CR2 |= (0x3C <<1); //---------------------OLED DISPLAY ADDRESS



	I2C2->CR2 &= ~I2C_CR2_RD_WRN; //----------------WRITE OPERATION



	I2C2->CR2 |= I2C_CR2_START; //-----------------I2C START



	while(!((I2C2->ISR) & (I2C_ISR_TXIS))); //---------WAIT FOR EMPTY TXDR



	I2C2->TXDR = I2C_DATA_SEND;



	while(!((I2C2->ISR) & (I2C_ISR_TC))); //---------WAIT FOR DATA SEND



	I2C2->CR2 |= I2C_CR2_STOP; //-----------------I2C STOP

}

/*-------------------I2C WRITE END--------------------------*/

#endif
