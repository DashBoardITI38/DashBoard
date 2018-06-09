/*
 * uart.h
 *
 *  Created on: Mar 11, 2018
 *      Author: Administrator
 */

#ifndef UART_H_
#define UART_H_

#include "uart_cfg.h"

///USART3

#define UDR3  	 *((volatile u8*)0x136)
#define UBRR3L   *((volatile u8*)0x134)
#define UBRR3H   *((volatile u8*)0x135)
#define UCSR3A   *((volatile u8*)0x130)
#define UCSR3B   *((volatile u8*)0x131)
#define UCSR3C   *((volatile u8*)0x132)
///USART2

#define UDR2     *((volatile u8*)0xD6)
#define UBRR2L   *((volatile u8*)0xD4)
#define UBRR2H   *((volatile u8*)0xD5)
#define UCSR2A   *((volatile u8*)0xD0)
#define UCSR2B   *((volatile u8*)0xD1)
#define UCSR2C   *((volatile u8*)0xD2)
///USART1

#define UDR1  	 *((volatile u8*)0xCE)
#define UBRR1L   *((volatile u8*)0xCC)
#define UBRR1H   *((volatile u8*)0xCD)
#define UCSR1A   *((volatile u8*)0xC8)
#define UCSR1B   *((volatile u8*)0xC9)
#define UCSR1C   *((volatile u8*)0xCA)
///USART0

#define UDR0  	 *((volatile u8*)0xC6)
#define UBRR0L   *((volatile u8*)0xC4)
#define UBRR0H   *((volatile u8*)0xC5)
#define UCSR0A   *((volatile u8*)0xC0)
#define UCSR0B   *((volatile u8*)0xC1)
#define UCSR0C   *((volatile u8*)0xC2)


/////UCSRA register bits
#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0
//////UCSRB register bits
#define  RXCIE 7
#define  TXCIE 6
#define  UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define  TXB8 0
/////ucrsc register bits
#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0


extern void UART_Init(u8);
extern void UART_Transmit(u8* ptrData , u16 length, u8 channelNumber);
extern void UART_Receive(u8* ptrData , u16* ptrLength,u8 channelNumber);
extern void UART_EnableReceivingInterrupt(u8 channelNumber);
extern void UART_DisableReceivingInterrupt(u8 channelNumber);

#endif /* UART_H_ */

