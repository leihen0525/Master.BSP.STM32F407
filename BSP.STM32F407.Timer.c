/*
 * BSP.STM32F407.Timer.c
 *
 *  Created on: 2019年9月19日
 *      Author: Master.HE
 */
#include "Error.h"

#include "STM32F4xx.h"

#include "BSP.STM32F407.Timer.h"



int BSP_STM32F407_Timer_Init(void)
{
	RCC->APB1ENR |= (1<<5); //打开TIM7时钟

	TIM7->PSC = 8399; //对时钟84M进行8400分频，使得计数频率为10k

	TIM7->ARR = 9;  //定时1MS

	TIM7->CNT = 0;  //清空计数器

	TIM7->CR1 |= (1<<7); //自动重装载预装载使能

	TIM7->DIER |= 1; //使能中断

	//NVIC->IP[55] = 0x80;

	//NVIC->ISER[1] |= (1<<(55-32));


	//RCC->AHB1ENR=RCC->AHB1ENR|0x00000020;

	//GPIOF->MODER=0x00010000;


	return Error_OK;
}


int BSP_STM32F407_Timer_GET_Flag(void)
{
	if(TIM7->SR)
	{

		TIM7->SR &= ~(0x0001);

		//GPIOF->ODR_BIT.ODR8=~GPIOF->ODR_BIT.ODR8;

		return Error_OK;
	}
	return Error_Dissatisfy;
}

int BSP_STM32F407_Timer_Enable(void)
{
	TIM7->CR1 |= 1; //开始计时
	return Error_OK;
}
int BSP_STM32F407_Timer_Disable(void)
{
	TIM7->CR1 &= 0xFFFE; //停止计时
	return Error_OK;
}
