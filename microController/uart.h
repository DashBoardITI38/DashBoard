/*
 * uart.h
 *
 *  Created on: Mar 11, 2018
 *      Author: Administrator
 */

#ifndef UART_H_
#define UART_H_

#include "uart_cfg.h"



#define UDR  	*((volatile u8*)0x2C)
#define UBRRL   *((volatile u8*)0x29)
#define UBRRH   *((volatile u8*)0x40)
#define UCSRA   *((volatile u8*)0x2B)
#define UCSRB   *((volatile u8*)0x2A)
#define UCSRC   *((volatile u8*)0x40)


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
extern void UART_Transmit(u8* ptrData , u16 length);
extern void UART_Receive(u8* ptrData , u16* ptrLength);
extern void UART_EnableReceivingInterrupt(void);
extern void UART_DisableReceivingInterrupt(void);

#endif /* UART_H_ */

