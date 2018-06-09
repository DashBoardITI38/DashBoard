/*
 * uart_cfg.h
 *
 *  Created on: Mar 11, 2018
 *      Author: Administrator
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_

#define UART_GPS_CHANNEL 		0
#define UART_EXCHANGER_CHANNEL  1

#define FOSC 16000000ul
#define PARITY_NO  		 0
#define PARITY_ODD 		 1
#define PARITY_EVEN 	 2
#define STOP_BIT_1 		 0
#define STOP_BIT_2 		 1
#define DOUPLE_SPEED_ON  1
#define DOUPLE_SPEED_OFF 0

typedef struct
{
	u32 baud;
	u8 parity;
	u8 dataLen;
	u8 stopLen;
	u8 doupleSpeed;
	/*u8 channel;*/
}uart_cfg_t;
extern const uart_cfg_t uart_cfg[];

#endif /* UART_CFG_H_ */
