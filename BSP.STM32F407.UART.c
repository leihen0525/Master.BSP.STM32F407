/*
 * BSP.STM32F407.UART.c
 *
 *  Created on: 2019Äê9ÔÂ23ÈÕ
 *      Author: Master.HE
 */
#include "Error.h"
#include "Master.Stdint.h"
#include "STM32F4xx.h"
#include "Machine/Machine.Enum.h"
#include "BSP.STM32F407.UART.h"

int BSP_STM32F407_UART_Init(void)
{
	RCC->APB2ENR=RCC->APB2ENR|RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR=RCC->AHB1ENR|RCC_AHB1ENR_GPIOAEN;

	GPIOA->AFR_BIT.AFRL9=7;
	GPIOA->AFR_BIT.AFRL10=7;

	GPIOA->MODER_BIT.MODER9=2;
	GPIOA->MODER_BIT.MODER10=2;

	GPIOA->OSPEEDR_BIT.OSPEEDR9=2;
	GPIOA->OSPEEDR_BIT.OSPEEDR10=2;

	USART1->CR1_BIT.RE=1;
	USART1->CR1_BIT.TE=1;
	USART1->CR1_BIT.RXNEIE=1;
	USART1->CR1_BIT.TCIE=1;
	USART1->CR1_BIT.UE=1;


	return Error_OK;
}

int BSP_STM32F407_UART_Set_BaudRate(int BaudRate)
{
	float USARTDIV_Mantissa;
	USARTDIV_Mantissa=(float)84000000/((float)16*(float)BaudRate);

	float USARTDIV_Fraction;

	USARTDIV_Fraction=USARTDIV_Mantissa-(int)USARTDIV_Mantissa;

	USARTDIV_Fraction=USARTDIV_Fraction*(float)16;

	USART1->BRR_BIT.DIV_Mantissa=(int)USARTDIV_Mantissa;

	USART1->BRR_BIT.DIV_Fraction=(int)USARTDIV_Fraction;

	return Error_OK;
}

int BSP_STM32F407_UART_Tx_DATA(unsigned char DATA)
{
	if((USART1->SR&USART_SR_TXE)!=0)
	{
		USART1->DR=DATA;
		return Error_OK;
	}
	return Error_Busy;

}

int BSP_STM32F407_UART_Rx_DATA(unsigned char *DATA)
{
	if(DATA==Null)
	{
		return Error_Invalid_Parameter;
	}
	if((USART1->SR&USART_SR_RXNE)!=0)
	{
		*DATA=USART1->DR;
		return Error_OK;
	}
	else
	{
		return Error_Operation_Failed;
	}

}

int BSP_STM32F407_UART_Get_Flag(void)
{
	int SR=USART1->SR;

	int Flag=Machine_Desc_UART_Flag_Null;

	if((SR&USART_SR_TXE)!=0)
	{
		Flag=Flag | Machine_Desc_UART_Flag_Tx_Empty;
	}
	if((SR&USART_SR_TC)!=0)
	{
		Flag=Flag | Machine_Desc_UART_Flag_Tx_Complete;

		USART1->SR=~USART_SR_TC;
	}
	if((SR&USART_SR_RXNE)!=0)
	{
		Flag=Flag | Machine_Desc_UART_Flag_Rx;
	}

	return Flag;
}
