/*
 * DIO.c
 *
 *  Created on: Mar 28, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO.h"

 u8* const DDR[] ={&DDRA,&DDRB,&DDRC,&DDRD,&DDRE,&DDRF,&DDRG,&DDRH,&DDRJ,&DDRK,&DDRL};
 u8* const PORT[]={&PORTA,&PORTB,&PORTC,&PORTD,&PORTE,&PORTF,&PORTG,&PORTH,&PORTJ,&PORTK,&PORTL};
 volatile u8* const PIN[] ={&PINA,&PINB,&PINC,&PIND,&PINE,&PINF,&PING,&PINH,&PINJ,&PINK,&PINL};
void DIO_Init(void)
{
	u8 Counter =0;
	for (Counter = 0; Counter < pinsCount; ++Counter)
	{
		switch(DIO_cfg[Counter].mode)
		{
		case output:
			SET_BIT(*DDR[(Counter/8)],(Counter%8));
			break;

		case inputWithPUR:
			CLR_BIT(*DDR[(Counter/8)],(Counter%8));
			SET_BIT(*PORT[(Counter/8)],(Counter%8));
			break;

		case inputWithoutPUR:
			CLR_BIT(*DDR[(Counter/8)],(Counter%8));
			break;
		case reserved:
		case notUsed:
			break;
		}
	}
}
void DIO_setPinValue(DIO_pinName_t name,DIO_level_t level)
{
	switch(level)
	{
		case DIO_low:
			CLR_BIT(*PORT[(name/8)],(name%8));
			break;

		case DIO_High:
			SET_BIT(*PORT[(name/8)],(name%8));
			break;
	}
}
DIO_level_t DIO_getPinValue(DIO_pinName_t name)
{
	return GET_BIT(*PIN[(name/8)],(name%8));
}
/*void DIO_setPortValue(u8 port,u8 value)
{
	(*PORT[port]) = value;
}
u8 DIO_getPortValue(u8 port)
{
	return (*PIN[port]);
}*/
