#include<stdio.h>
#include<stdint.h>
#include "ADC1_CH1.h"
void RCC_Init(){
	RCC_AHB1ENR |= (1 << 0);
	RCC_APB2ENR |= (1 << 8);	//POTENTIOMETER
	RCC_APB1ENR |= (1 << 17); 	//enable uart2
}
void GPIOA_Init(void){
	GPIOA_MODER &= ~(3U << 2);
	GPIOA_MODER |= (3U << 2);
}
void ADC1_CH1_Init(void){
	// SAMPLING BY 15 CYCLE
	ADC_SMPR2 &= ~(7 << 3);
	ADC_SMPR2 |= (1 << 3);
	//FOR ONE CONVERSATION
	ADC_SQR1 &= ~(0xF << 20);
	//FOR SEQUENCE
	ADC_SQR3 &= ~(0x1F << 0);
	ADC_SQR3 |= (0x01 << 0);
	//ENABLE ADC
	ADC_CR2 |= (1 << 0);
}
uint16_t Read_ADC_Data(void){
	ADC_CR2 |= (1 << 30);
	while (!(ADC_SR & (1 << 1)));
	uint16_t data;
	data = ADC_DR;
	ADC_SR &= ~(1<<1);
	return data;
}
