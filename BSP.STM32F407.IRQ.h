/*
 * BSP.STM32F407.IRQ.h
 *
 *  Created on: 2019Äê9ÔÂ19ÈÕ
 *      Author: Master.HE
 */

#ifndef BSP_STM32F407_IRQ_H_
#define BSP_STM32F407_IRQ_H_

int BSP_STM32F407_IRQ_Init(void);
int BSP_STM32F407_IRQ_Enable(int IRQ_Index);
int BSP_STM32F407_IRQ_Disable(int IRQ_Index);
int BSP_STM32F407_IRQ_Set_Priority(int IRQ_Index,int Priority);
int BSP_STM32F407_IRQ_All_Enable(void);
int BSP_STM32F407_IRQ_All_Disable(void);
int BSP_STM32F407_IRQ_Get_IRQ_Index(void);
int BSP_STM32F407_IRQ_Clear_IRQ_Flag(int IRQ_Index);

#endif /* BSP_STM32F407_IRQ_H_ */
