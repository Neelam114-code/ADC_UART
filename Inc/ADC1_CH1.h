#include<stdio.h>
#include<stdint.h>
#ifndef ADC1_CH1_H_
#define ADC1_CH1_H_
//adc1_ch1 alternate mode of pa1 potentiometer middel variable shaft is conneceted to pa1, one is to vcc 3.3 and one to ground
#define RCC_BASE 0x40023800
#define RCC_AHB1ENR	(*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_APB2ENR	(*(volatile uint32_t *)(RCC_BASE + 0x44))
#define RCC_APB1ENR (*(volatile uint32_t *)(0x40023800 + 0x40))
#define USART2_BASE	0x40004400
#define GPIOA_BASE	0x40020000
#define GPIOA_MODER (*(volatile uint32_t *)(0x40020000 + 0x00))
#define ADC1_BASE 0x40012000
#define ADC_CR1		(*(volatile uint32_t *)(ADC1_BASE + 0x04))
#define ADC_CR2		(*(volatile uint32_t *)(ADC1_BASE + 0x08))
#define ADC_SR		(*(volatile uint32_t *)(ADC1_BASE + 0x00))
#define ADC_DR		(*(volatile uint32_t *)(ADC1_BASE + 0x4C))
#define ADC_SQR1	(*(volatile uint32_t *)(ADC1_BASE + 0x2C))
#define ADC_SQR3	(*(volatile uint32_t *)(ADC1_BASE + 0x34))
#define ADC_SMPR2	(*(volatile uint32_t *)(ADC1_BASE + 0x10))
#define GPIOA_AFRL (*(volatile uint32_t *)(GPIOA_BASE + 0x20))
#define USART_BRR	(*(volatile uint32_t *)(USART2_BASE + 0x08))
#define USART_DR	(*(volatile uint32_t *)(USART2_BASE + 0x04))
#define USART_SR	(*(volatile uint32_t *)(USART2_BASE + 0x00))
#define USART_CR1 	(*(volatile uint32_t *)(USART2_BASE + 0x0C))
void RCC_Init();
void GPIOA_Init();
void ADC1_CH1_Init();
void USART_Init();
uint16_t Read_ADC_Data(void);
void USART_Send_data(char * buf);
#endif /* ADC1_CH1_H_ */
