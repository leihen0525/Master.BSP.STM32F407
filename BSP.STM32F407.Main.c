/*
 * BSP.STM32F407.Main.c
 *
 *  Created on: 2019Äê9ÔÂ18ÈÕ
 *      Author: Master.HE
 */
#include "Error.h"

#include "STM32F4xx.h"

#include "BSP.STM32F407.Main.h"
#include "BSP.STM32F407.IRQ.h"
#include "BSP.STM32F407.CPU.h"
#include "BSP.STM32F407.Wdog.h"
#include "BSP.STM32F407.Timer.h"
#include "BSP.STM32F407.UART.h"

#include "Machine\Machine.h"


int BSP_STM32F407_Main_Init(void)
{
	return Error_OK;
}





MACHINE_START(STM32F407,"STM32F407")

	.Info="MCU:STM32F407xx Module:BSP Version:0.0.1 "__DATE__" "__TIME__,

	.Init=BSP_STM32F407_Main_Init,

	.Wdog=
	{
		.Enable=BSP_STM32F407_Wdog_Enable,
		.Disable=BSP_STM32F407_Wdog_Disable,
		.Clear=BSP_STM32F407_Wdog_Clear,
	},
	.Timer=
	{
		.IRQ_Index=TIM7_IRQn,
		.Init=BSP_STM32F407_Timer_Init,
		.GET_Flag=BSP_STM32F407_Timer_GET_Flag,
		.Enable=BSP_STM32F407_Timer_Enable,
		.Disable=BSP_STM32F407_Timer_Disable,
	},
	.IRQ=
	{
		.IRQ_Max_Index=IRQn_End,
		.Init=BSP_STM32F407_IRQ_Init,
		.Enable=BSP_STM32F407_IRQ_Enable,
		.Disable=BSP_STM32F407_IRQ_Disable,
		.Set_Priority=BSP_STM32F407_IRQ_Set_Priority,
		.All_Enable=BSP_STM32F407_IRQ_All_Enable,
		.All_Disable=BSP_STM32F407_IRQ_All_Disable,
		.Get_IRQ_Index=BSP_STM32F407_IRQ_Get_IRQ_Index,
		.Clear_IRQ_Flag=BSP_STM32F407_IRQ_Clear_IRQ_Flag,
	},
	.UART=
	{
		.IRQ_Index=USART1_IRQn,
		.BaudRate=115200,
		.Init=BSP_STM32F407_UART_Init,
		.Set_BaudRate=BSP_STM32F407_UART_Set_BaudRate,
		.Tx_DATA=BSP_STM32F407_UART_Tx_DATA,
		.Rx_DATA=BSP_STM32F407_UART_Rx_DATA,
		.Get_Flag=BSP_STM32F407_UART_Get_Flag,
	},
	.CPU=
	{
		.Init=BSP_STM32F407_CPU_Init,
	},

MACHINE_END
