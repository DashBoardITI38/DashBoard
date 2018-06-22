/*
 * ULS_Driver.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO.h"
#include "uart.h"
#include "ULS_Driver.h"
#include "ICU.h"
#include "Delay.h"
#include "avr/interrupt.h"
#include "os.h"
static u16 t11=400,t12=400,t13=400;
static u16 t21, t22, t23;
static u16 temp;
void UlsDriver_Trigger(UlsDriver_tenumSensorId id)
{
	u8 echoPins[]={trig1,trig2,trig3};
	DIO_setPinValue(echoPins[id],DIO_High);
	DELAY_5US;
	DELAY_5US;

	DIO_setPinValue(echoPins[id],DIO_low);
	ICU_RaisingEdge(ICU_CHANNEL0);
		ICU_RaisingEdge(ICU_CHANNEL1);
		ICU_RaisingEdge(ICU_CHANNEL4);
	OS_START_MEASUREMENT;

}
bool UlsDriver_getDistance(UlsDriver_tStrObstacleDist * obstacle_dist)
{
	//x=v*t;
	u8 array[10]={0};
	u8 length =0;
	obstacle_dist->obstacle_R=(u16)((u32)((u32)340*((u32)(((u32)t21-(u32)t11)*(u32)64)))/((u32)2000)); //in mm
	obstacle_dist->obstacle_C=(u16)((u32)((u32)340*((u32)(((u32)t22-(u32)t12)*(u32)64)))/((u32)2000)); //in mm
	obstacle_dist->obstacle_L=(u16)((u32)((u32)340*((u32)(((u32)t23-(u32)t13)*(u32)64)))/((u32)2000)); //in mm
//	UART_Transmit("R",1,UART_EXCHANGER_CHANNEL);
//	NumToAscii(obstacle_dist->obstacle_R,array,&length,1); /*TODO:change length to u16*/
//	UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);
//
//	UART_Transmit("C",1,UART_EXCHANGER_CHANNEL);
//	NumToAscii(obstacle_dist->obstacle_C,array,&length,1); /*TODO:change length to u16*/
//	UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);
//
//	UART_Transmit("L",1,UART_EXCHANGER_CHANNEL);
//	NumToAscii(obstacle_dist->obstacle_L,array,&length,1); /*TODO:change length to u16*/
//	UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);
//to do
//	t21=400;
//	t22=400;
//	t23=400;
	return true;
}
void UlsDriver_init(void)
{

}
ISR(INT0_vect)
{
	OS_STOP_MEASUREMENT(temp);

if(DIO_getPinValue(ICU_Channel0)==DIO_High)
{
ICU_FallingEdge(ICU_CHANNEL0);
t11=temp;
DIO_setPinValue(PA0,DIO_High);

}
else
{
	t21=temp;
	DIO_setPinValue(PA0,DIO_low);

}
}
ISR(INT1_vect)
{
	OS_STOP_MEASUREMENT(temp);

	if(DIO_getPinValue(ICU_Channel1)==DIO_High)
	{
		ICU_FallingEdge(ICU_CHANNEL1);
		t12=temp;
		DIO_setPinValue(PA1,DIO_High);

	}
	else
	{
		t22=temp;

		DIO_setPinValue(PA1,DIO_low);
	}
}
ISR(INT4_vect)
{
	OS_STOP_MEASUREMENT(temp);

	if(DIO_getPinValue(ICU_Channel4)==DIO_High)
	{
		ICU_FallingEdge(ICU_CHANNEL4);
		t13=temp;
		DIO_setPinValue(PA2,DIO_High);
	}
	else
	{
		t23=temp;
		DIO_setPinValue(PA2,DIO_low);
	}
}
