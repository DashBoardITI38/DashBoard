/*
 * uart_cfg.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"
#include "uart_cfg.h"
const uart_cfg_t uart_cfg[]=
						  {		/*Baud	 Parity	  DataBits	StopBit/s */
								  {9600,	PARITY_NO ,		8,		STOP_BIT_1 , DOUPLE_SPEED_ON},
								  {9600,	PARITY_NO ,		8,		STOP_BIT_1 , DOUPLE_SPEED_ON},
								  {9600,	PARITY_NO ,		8,		STOP_BIT_1 , DOUPLE_SPEED_ON},

						  };
