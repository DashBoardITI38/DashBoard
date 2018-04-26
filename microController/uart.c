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
#define NUMBER_OF_CHANNELS 4
volatile u8* const UCSRA[] ={&UCSR0A,&UCSR1A,&UCSR2A,&UCSR3A};
volatile	u8* const UCSRB[] ={&UCSR0B,&UCSR1B,&UCSR2B,&UCSR3B};
volatile u8* const UCSRC[] ={&UCSR0C,&UCSR1C,&UCSR2C,&UCSR3C};
volatile u8* const UDR[] ={&UDR0,&UDR1,&UDR2,&UDR3};
volatile	u8* const UBRRH[] ={&UBRR0H,&UBRR1H,&UBRR2H,&UBRR3H};
volatile u8* const UBRRL[] ={&UBRR0L,&UBRR1L,&UBRR2L,&UBRR3L};

static u8 Rx_arr[NUMBER_OF_CHANNELS][BUF_SIZE];
static u16 Rx_len[NUMBER_OF_CHANNELS]={0};


extern void UART_Init(u8 channelNumber)
{
	u8 u8parityBit0=0;
	u8 u8parityBit1=0;
	u8 u8CharacterBit0=0;
	u8 u8CharacterBit1=0;
	u8 u8StopBit=0;


	*UCSRA[channelNumber] = ((uart_cfg[channelNumber].doupleSpeed)<<U2X); //double transmission speed

	*UCSRB[channelNumber] = (1<<RXEN) | (1<<TXEN) ; //enable UART as transmitter and receiver.
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
	u8StopBit=uart_cfg[channelNumber].stopLen;

	*UCSRC[channelNumber] = (u8CharacterBit0<<UCSZ0) | (u8CharacterBit1<<UCSZ1)|(u8StopBit<<USBS)|(u8parityBit0<<UPM0)|(u8parityBit1<<UPM1); //8-bit data, NO parity, one stop bit and asynch


	/* baud rate=9600 & Fosc=16MHz -->  UBBR=( Fosc / (8 * baud rate) ) - 1 = 12 */
	////
	*UBRRH[channelNumber]=(((u32)FOSC/(u32)(uart_cfg[channelNumber].baud*(u32)8))-1)>>8;
	*UBRRL[channelNumber]=(((u32)FOSC/(u32)(uart_cfg[channelNumber].baud*(u32)8))-1);
}

extern void UART_Transmit(u8* ptrData , u16 length, u8 channelNumber)
{
	u16 i;
	for (i = 0 ; i < length ; i++)
	{
		while(GET_BIT((*UCSRA[channelNumber]),UDRE)==0);
		*UDR[channelNumber] = ptrData[i];
	}
}

extern void UART_Receive(u8* ptrData , u16* ptrLength,u8 channelNumber)
{
	u16 i;
	UART_DisableReceivingInterrupt(channelNumber);
	for (i = 0 ; i < Rx_len[channelNumber] ; i++)
	{
		ptrData[i]=Rx_arr[channelNumber][i];
	}
	*ptrLength = Rx_len[channelNumber];
	Rx_len[channelNumber] = 0;
	UART_EnableReceivingInterrupt(channelNumber);
}

/*Enable the receiving Interrupt for UART*/
extern void UART_EnableReceivingInterrupt(u8 channelNumber)
{
	SET_BIT((*UCSRB[channelNumber]),RXCIE);
}

/*Disable the receiving Interrupt for UART*/
extern void UART_DisableReceivingInterrupt(u8 channelNumber)
{
	CLR_BIT((*UCSRB[channelNumber]),RXCIE);
}

ISR(USART0_RX_vect)
{
	Rx_arr[0][Rx_len[0]++]=UDR0;
}
ISR(USART1_RX_vect)
{
	Rx_arr[1][Rx_len[1]++]=UDR1;
}
ISR(USART2_RX_vect)
{
	Rx_arr[2][Rx_len[2]++]=UDR2;
}
ISR(USART3_RX_vect)
{
	Rx_arr[3][Rx_len[3]++]=UDR3;
}
