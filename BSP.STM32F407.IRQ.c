/*
 * BSP.STM32F407.IRQ.c
 *
 *  Created on: 2019Äê9ÔÂ19ÈÕ
 *      Author: Master.HE
 */
#include "Error.h"

#include "STM32F4xx.h"

#include "BSP.STM32F407.IRQ.h"

int BSP_STM32F407_IRQ_Init(void)
{
	return Error_OK;
}

int BSP_STM32F407_IRQ_Enable(int IRQ_Index)
{
	if ((int32_t)(IRQ_Index) >= 0)
	{
		NVIC->ISER[(((uint32_t)IRQ_Index) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQ_Index) & 0x1FUL));

		return Error_OK;
	}
	return Error_Invalid_Parameter;

}
int BSP_STM32F407_IRQ_Disable(int IRQ_Index)
{
	if ((int32_t)(IRQ_Index) >= 0)
	{
		NVIC->ICER[(((uint32_t)IRQ_Index) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQ_Index) & 0x1FUL));
		__DSB();
		__ISB();

		return Error_OK;
	}
	return Error_Invalid_Parameter;

}
int BSP_STM32F407_IRQ_Set_Priority(int IRQ_Index,int Priority)
{
	if ((int32_t)(IRQ_Index) >= 0)
	{
		NVIC->IP[((uint32_t)IRQ_Index)]               = (uint8_t)((Priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	}
	else
	{
		SCB->SHP[(((uint32_t)IRQ_Index) & 0xFUL)-4UL] = (uint8_t)((Priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
	}

	return Error_OK;
}

int BSP_STM32F407_IRQ_All_Enable(void)
{
	asm(" CPSIE i");
	return Error_OK;
}
int BSP_STM32F407_IRQ_All_Disable(void)
{
	asm(" CPSID i");
	return Error_OK;
}

int BSP_STM32F407_IRQ_Get_IRQ_Index(void)
{
	int IRQ_Index=0;

	asm("mrs %0,ipsr"
				: "+r"(IRQ_Index)
					);
	IRQ_Index=(IRQ_Index&0xFF)-16;

	return IRQ_Index;
}
int BSP_STM32F407_IRQ_Clear_IRQ_Flag(int IRQ_Index)
{
	return Error_OK;
}
