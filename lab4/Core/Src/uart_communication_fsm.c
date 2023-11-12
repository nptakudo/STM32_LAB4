///*
// * uart_communication_fsm.c
// *
// *  Created on: Nov 5, 2023
// *      Author: takudo
// */
//#include "main.h"
//#include "software_timer.h"
//#include "command_parser_fsm.h"
//#include <string.h>
//#include <stdio.h>
//#include <uart_communication_fsm.h>
//
//#define RESENDING_TIME 3000
//
//enum uart_communication_fsm_state
//{
//	WAITING,
//	CHECKING_COMMAND,
//	RESEND
//};
//enum uart_communication_fsm_state communication_state = WAITING;
//
//uint32_t ADC_value = 0;
//int resend_flag = 0;
//char str[10];
//char *request = "RST";
//char *ok = "OK";
//char *led7seg = "7SEG:";
//
//void uart_communiation_fsm(void)
//{
//	switch (communication_state)
//	{
//	case WAITING:
//		if (command_flag)
//			communication_state = CHECKING_COMMAND;
//		break;
//	case CHECKING_COMMAND:
//		if (strcmp(command_data, request) == 0)
//		{
//			char str[10];
//			ADC_value = HAL_ADC_GetValue(&hadc1);
//			ADC_value = ADC_value * 5 / 4095;
//			HAL_UART_Transmit(&huart2, (void *)str,sprintf(str, "\r\n%ld", ADC_value), 1000);
//			resend_flag = 1;
//			setTimerResend(RESENDING_TIME);
//		}
//		else if (strstr(command_data, led7seg) != NULL)
//		{
//			char str[10];
//			char strnum7[10];
//			int len7LED = strlen(led7seg);
//			int lenCommand = strlen(command_data);
//			int num7seg;
//			strncpy(strnum7, command_data + len7LED, lenCommand - len7LED);
//			strnum7[lenCommand - len7LED] = '\0';
//			num7seg = atoi(strnum7);
//			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n%ld\r\n", num7seg), 1000);
//			resend_flag = 1;
//			setTimerResend(RESENDING_TIME);
//		}
//		if (strcmp(command_data, ok) == 0)
//		{
//			resend_flag = 0;
//		}
//		if (resend_flag == 1)
//		{
//			communication_state = RESEND;
//		}
//		else
//		{
//			communication_state = WAITING;
//		}
//		command_data_size = 0;
//		command_flag = 0;
//		break;
//	case RESEND:
//
//		if (command_flag == 1)
//		{
//			communication_state = CHECKING_COMMAND;
//		}
//		if (timerResend_flag == 1 && strcmp(command_data, request) == 0)
//		{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
//			char str[10];
//			HAL_UART_Transmit(&huart2, (void *)str,
//							  sprintf(str, "\r\n%ld", ADC_value), 1000);
//			setTimerResend(RESENDING_TIME);
//		}
//		else if (timerResend_flag == 1 && strstr(command_data, led7seg) != NULL)
//		{
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
//			char str[10];
//			char strnum7[10];
//			int len7LED = strlen(led7seg);
//			int lenCommand = strlen(command_data);
//			int num7seg;
//			strncpy(strnum7, command_data + len7LED, lenCommand - len7LED);
//			strnum7[lenCommand - len7LED] = '\0';
//			num7seg = atoi(strnum7);
//			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "\r\n%ld\r\n", num7seg), 1000);
//			setTimerResend(RESENDING_TIME);
//		}
//		break;
//	}
//}
