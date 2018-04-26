/*
 * uart.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "uart.h"
#include "avr/interrupt.h"
#define BUF_SIZE 204


static u8 Rx_arr[BUF_SIZE];
static u16 Rx_len=0;


extern void UART_Init(u8 channelNumber)
{
	u8 u8parityBit0=0;
	u8 u8parityBit1=0;
	u8 u8CharacterBit0=0;
	u8 u8CharacterBit1=0;
	u8 u8StopBit=0;
	UCSRA = (1<<U2X); //double transmission speed

	UCSRB = (1<<RXEN) | (1<<TXEN) ; //enable UART as transmitter and receiver.
	switch(uart_cfg[channelNumber].parity )
	{
	case PARITY_NO:
		u8parityBit0= 0;
		u8parityBit1=0;
		break;
	case PARITY_EVEN:
		u8parityBit0= 0;
		u8parityBit1= 1;
		break;
	case PARITY_ODD:
		u8parityBit0= 1;
		u8parityBit1= 1;

		break;
	}
	switch(uart_cfg[channelNumber].dataLen )
	{
	case 8:
		u8CharacterBit0=1;
		u8CharacterBit1=1;
		break;
	case 7:
		u8CharacterBit0=0;
		u8CharacterBit1=1;
		break;
	case 6:

		u8CharacterBit0=1;
		u8CharacterBit1=0;
		break;
	case 5:

		u8CharacterBit0=0;
		u8CharacterBit1=0;
		break;
	}
u8parityBit0=uart_cfg[channelNumber].stopLen;

	UCSRC = (1<<URSEL) | (u8CharacterBit0<<UCSZ0) | (u8CharacterBit1<<UCSZ1)|(u8StopBit<<USBS)|(u8parityBit0<<UPM0)|(u8parityBit1<<UPM1); //8-bit data, NO parity, one stop bit and asynch


	/* baud rate=9600 & Fosc=16MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */

	UBRRH = ((u16)(FOSC / (8 * uart_cfg[channelNumber].baud)) - 1)>>8;
	UBRRL = ((u16)(FOSC / (8 * uart_cfg[channelNumber].baud)) - 1);
}

extern void UART_Transmit(u8* ptrData , u16 length)
{
	u16 i;
	for (i = 0 ; i < length ; i++)
	{
		while(GET_BIT(UCSRA,UDRE)==0);
		UDR = ptrData[i];
	}
}

extern void UART_Receive(u8* ptrData , u16* ptrLength)
{
	u16 i;
	UART_DisableReceivingInterrupt();
	for (i = 0 ; i < Rx_len ; i++)
	{
		ptrData[i]=Rx_arr[i];
	}
	*ptrLength = Rx_len;
	Rx_len = 0;
	UART_EnableReceivingInterrupt();
}

/*Enable the receiving Interrupt for UART*/
extern void UART_EnableReceivingInterrupt(void)
{
	SET_BIT(UCSRB,RXCIE);
}

/*Disable the receiving Interrupt for UART*/
extern void UART_DisableReceivingInterrupt(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

ISR(USART_RXC_vect)
{
	Rx_arr[Rx_len++]=UDR;
}
