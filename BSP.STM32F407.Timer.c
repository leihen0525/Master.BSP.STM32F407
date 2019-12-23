/*
 * BSP.STM32F407.Timer.c
 *
 *  Created on: 2019��9��19��
 *      Author: Master.HE
 */
#include "Error.h"

#include "STM32F4xx.h"

#include "BSP.STM32F407.Timer.h"



int BSP_STM32F407_Timer_Init(void)
{
	RCC->APB1ENR |= (1<<5); //��TIM7ʱ��

	TIM7->PSC = 8399; //��ʱ��84M����8400��Ƶ��ʹ�ü���Ƶ��Ϊ10k

	TIM7->ARR = 9;  //��ʱ1MS

	TIM7->CNT = 0;  //��ռ�����

	TIM7->CR1 |= (1<<7); //�Զ���װ��Ԥװ��ʹ��

	TIM7->DIER |= 1; //ʹ���ж�

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
	TIM7->CR1 |= 1; //��ʼ��ʱ
	return Error_OK;
}
int BSP_STM32F407_Timer_Disable(void)
{
	TIM7->CR1 &= 0xFFFE; //ֹͣ��ʱ
	return Error_OK;
}
