/*
 * BSP.STM32F407.UART.h
 *
 *  Created on: 2019Äê9ÔÂ23ÈÕ
 *      Author: Master.HE
 */

#ifndef BSP_STM32F407_UART_H_
#define BSP_STM32F407_UART_H_

int BSP_STM32F407_UART_Init(void);

int BSP_STM32F407_UART_Set_BaudRate(int BaudRate);

int BSP_STM32F407_UART_Tx_DATA(unsigned char DATA);

int BSP_STM32F407_UART_Rx_DATA(unsigned char *DATA);

int BSP_STM32F407_UART_Get_Flag(void);

#endif /* BSP_STM32F407_UART_H_ */
