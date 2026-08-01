#include "ADC1_CH1.h"
void USART_Init(void)
{
	GPIOA_MODER &= ~( 3 << 4 );
	GPIOA_MODER &= ~( 3 << 6 );
	//ALTERNATE FUNCTIONamk
	GPIOA_MODER |= (2 << 4);
	GPIOA_MODER |= (2 << 6);
	GPIOA_AFRL	&= ~(0xF << 8);
	GPIOA_AFRL &= ~(0xF << 12);
	GPIOA_AFRL	|= (7 << 8);
	GPIOA_AFRL |= (7 << 12);
	// SET BAUD RATE  BASED ON PERIFEREL BUS FREQ AND OVER SAMPLING BY 8 OR 16 AND REQUIERD BAUD RATE
		USART_BRR = 0x0683;
		//BIT LENGTH AND STOPBIT
		USART_CR1 &= ~(1 << 15);	//over8  oversampling by  16

		USART_CR1 &= ~(1 << 12);	//M = 0 DATA BITS 8
		USART_CR1 |= (1 << 3);	//TE set for transmit enable
		USART_CR1 |= (1 << 2);	//RE SET for receive enable
		USART_CR1 |= (1 << 13);	//UE  uart enable
		//USART_CR1 |= (1 << 5);
}
void USART_Send_data(char * str){
	while(*str){
		while (!(USART_SR & (1 << 7)));
		USART_DR = *str;
		str++;
		USART_SR &= ~(1 << 1);
	}
}
