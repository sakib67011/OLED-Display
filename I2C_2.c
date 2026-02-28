#include "stm32g030xx.h"
#include "I2C_2.h"


/*-------------------I2C_2 RCC CONFIGURE START-----------------*/

void I2C_2_RCC_CONFIGURE()

{

	RCC ->APBENR1 |= RCC_APBENR1_I2C2EN;

}

/*-------------------I2C_2 RCC CONFIGURE END-----------------*/

/*-------------------I2C_2 CONFIGURE START-----------------*/

void I2C_2_CONFIGURE()

{
	//---I2C DISABLE
	
	I2C2->CR1 &= ~(I2C_CR1_PE); 
	
	//---PRESCALE TO 3
	
	I2C2->TIMINGR &= ~I2C_TIMINGR_PRESC;
	I2C2->TIMINGR |= (0x3 << I2C_TIMINGR_PRESC_Pos);
	
	//---DELAY FOR SCL START
	
	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLDEL;
	I2C2->TIMINGR |= (0x4<<I2C_TIMINGR_SCLDEL_Pos);
	
	//---DATA HOLD TIME
	
	I2C2->TIMINGR &= ~I2C_TIMINGR_SDADEL;
	I2C2->TIMINGR |= (0x2<<I2C_TIMINGR_SDADEL_Pos);
	
	//---SCL HIGH TIME
	
	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLH;
	I2C2->TIMINGR |= (0xC3<<I2C_TIMINGR_SCLH_Pos);
	
	//---SCL LOW TIME
	
	I2C2->TIMINGR &= ~I2C_TIMINGR_SCLL;
	I2C2->TIMINGR |= (0xC7<<I2C_TIMINGR_SCLL_Pos);
	
	//---I2C ANALOG FILTER DISABLE
	
	I2C2->CR1 |= I2C_CR1_ANFOFF;
	
	//---I2C DIGITAL FILTER DISABLE	
	
	I2C2->CR1 &= ~I2C_CR1_DNF; 
	
	//---I2C ENABLE
	
	I2C2->CR1 |=  I2C_CR1_PE;  
}

/*-------------------I2C_2 CONFIGURE END-----------------*/

/*-------------------I2C WRITE START--------------------------*/

void I2C_WRITE(uint8_t I2C_DATA_SEND)

{
	//---CHECKING I2C BUSY or NOT
	
	while((I2C2->ISR & I2C_ISR_BUSY));
	
	//---CLEAR CR2
	
	I2C2->CR2 = 0;
	
	//---7-BIT ADDRESSING MODE
	
	I2C2->CR2 &=~ I2C_CR2_ADD10_Msk;
	
	//---7-BIT SLAVE ADDRESS ASSIGNED
	
	I2C2->CR2 |= (0x3C << 1);
	
	//---I2C WRITE CONFIGURE
	
	I2C2->CR2 &= ~I2C_CR2_RD_WRN_Msk;
	
	//---NUMBER OF BYTE
	
	I2C2->CR2 &=~ I2C_CR2_NBYTES_Msk;
	I2C2->CR2 |= (1<< I2C_CR2_NBYTES_Pos);
	
	//---I2C START
	
	I2C2->CR2 &=~ I2C_CR2_START_Msk;
	I2C2->CR2 |= (1<< I2C_CR2_START_Pos);
	
	//---TRANSFER BUFFER EMPTY CHECK
	
	while(!(I2C2->ISR & I2C_ISR_TXIS));
	
	//---DATA TRANSFERING
	
	I2C2->TXDR = I2C_DATA_SEND;
	
	//---CHECK TRANSFER COMPLETE
	
	while(!(I2C2->ISR & I2C_ISR_TC));
	
	//---I2C STOP
	
	I2C2->CR2 |= (1<< I2C_CR2_STOP_Pos);
	
	//---CHECK STOP FLAG
	
	while(!(I2C2->ISR & I2C_ISR_STOPF));
	
	//--- CLEAR STOP FLAG
	
	I2C2->ICR  = I2C_ICR_STOPCF;
	
}


/*-------------------I2C WRITE END--------------------------*/

