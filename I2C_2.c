#include "stm32g030xx.h"
#include "I2C_2.h"



#define  I2C_TRUE       1
#define  I2C_FALSE      0
#define  I2C_ACKED      1
#define  I2C_NACKED     0
#define  I2C_READ    		1
#define  I2C_WRITE   		0

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

void I2C2_WRITE_CMD(uint8_t I2C_CMD_SEND)

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
	I2C2->CR2 |= (2<< I2C_CR2_NBYTES_Pos);
	
	//---AUTO END MODE
	
	I2C2->CR2 &=~ I2C_CR2_AUTOEND_Msk;
	I2C2->CR2 |= (1<< I2C_CR2_AUTOEND_Pos);
	
	//---I2C START
	
	I2C2->CR2 &=~ I2C_CR2_START_Msk;
	I2C2->CR2 |= I2C_CR2_START;
	
	//---TRANSFER BUFFER EMPTY CHECK
	
	while(!(I2C2->ISR & I2C_ISR_TXIS))
	{
		if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		
		//---DATA TRANSFERING >>> CONTROL BYTE_COMMAND
		
	I2C2->TXDR = 0x00;
		
	while(!(I2C2->ISR & I2C_ISR_TXIS))
		{
			if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		
	I2C2->TXDR = I2C_CMD_SEND;
	
	
	//---CHECK STOP FLAG
	
	while(!(I2C2->ISR & I2C_ISR_STOPF));
	
	//--- CLEAR STOP FLAG
	
	I2C2->ICR  |= I2C_ICR_STOPCF;	

}




void I2C2_WRITE_DATA(uint8_t I2C_DATA_SEND)

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
	I2C2->CR2 |= (2<< I2C_CR2_NBYTES_Pos);
	
	//---AUTO END MODE
	
	I2C2->CR2 &=~ I2C_CR2_AUTOEND_Msk;
	I2C2->CR2 |= (1<< I2C_CR2_AUTOEND_Pos);
	
	//---I2C START
	
	I2C2->CR2 &=~ I2C_CR2_START_Msk;
	I2C2->CR2 |= I2C_CR2_START;
	
	//---TRANSFER BUFFER EMPTY CHECK
	
	while(!(I2C2->ISR & I2C_ISR_TXIS))
	{
		if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		
		//---DATA TRANSFERING >>> CONTROL BYTE_DATA
		
	I2C2->TXDR = 0x40;
		
	while(!(I2C2->ISR & I2C_ISR_TXIS))
		{
			if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		I2C2->TXDR = I2C_DATA_SEND;
	
	
	while(!(I2C2->ISR & I2C_ISR_STOPF));
	
	//--- CLEAR STOP FLAG
	
	I2C2->ICR  |= I2C_ICR_STOPCF;	

}

//==================================font print========================//


void I2C2_WRITE_FONT(const uint8_t *I2C_FONT_DATA)

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
	I2C2->CR2 |= ((6+1)<< I2C_CR2_NBYTES_Pos);
	
	//---AUTO END MODE
	
	I2C2->CR2 &=~ I2C_CR2_AUTOEND_Msk;
	I2C2->CR2 |= (1<< I2C_CR2_AUTOEND_Pos);
	
	//---I2C START
	
	I2C2->CR2 &=~ I2C_CR2_START_Msk;
	I2C2->CR2 |= I2C_CR2_START;
	
	//---TRANSFER BUFFER EMPTY CHECK
	
	while(!(I2C2->ISR & I2C_ISR_TXIS))
	{
		if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		
		//---DATA TRANSFERING >>> CONTROL BYTE_DATA
		
	I2C2->TXDR = 0x40;
	
	for(uint8_t i = 0; i<6;i++)
	{
		while(!(I2C2->ISR & I2C_ISR_TXIS))
		{
			if((I2C2->ISR & I2C_ISR_NACKF))
		{
			I2C2->ICR |= I2C_ICR_NACKCF;

			return ;
		}
	}
		I2C2->TXDR = I2C_FONT_DATA[i];
		
	}
		
	
	
	
	while(!(I2C2->ISR & I2C_ISR_STOPF));
	
	//--- CLEAR STOP FLAG
	
	I2C2->ICR  |= I2C_ICR_STOPCF;	

}

void I2C2_WRITE_IMAGE_PAGE(const uint8_t *page_data, uint8_t SIZE)
{
    while((I2C2->ISR & I2C_ISR_BUSY));

    I2C2->CR2 = 0;

    I2C2->CR2 &=~ I2C_CR2_ADD10_Msk;

    I2C2->CR2 |= (0x3C << 1);

    I2C2->CR2 &= ~I2C_CR2_RD_WRN_Msk;

    I2C2->CR2 &=~ I2C_CR2_NBYTES_Msk;
    I2C2->CR2 |= ((SIZE + 1) << I2C_CR2_NBYTES_Pos);

    I2C2->CR2 |= I2C_CR2_AUTOEND;

    I2C2->CR2 |= I2C_CR2_START;

    while(!(I2C2->ISR & I2C_ISR_TXIS));

    /* Control byte */
    I2C2->TXDR = 0x40;

    for(uint8_t i = 0; i < SIZE; i++)
    {
        while(!(I2C2->ISR & I2C_ISR_TXIS));
        I2C2->TXDR = page_data[i];
    }

    while(!(I2C2->ISR & I2C_ISR_STOPF));

    I2C2->ICR |= I2C_ICR_STOPCF;
}

/*-------------------I2C WRITE END--------------------------*/

