/*
 * ULS_Driver.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO.h"
#include "ULS_Driver.h"
#include "ICU.h"
#include "Delay.h"
#include "avr/interrupt.h"
#include "os.h"
static u16 t1=0,t2=0,t3=0;

void UlsDriver_Trigger(UlsDriver_tenumSensorId id)
{
	u8 echoPins[]={echo1,echo2,echo3};
	DIO_setPinValue(echoPins[id],DIO_High);
	DELAY_5US;
	OS_START_MEASUREMENT;

}
bool UlsDriver_getDistance(UlsDriver_tStrObstacleDist * obstacle_dist)
{
	//x=v*t;
	obstacle_dist->obstacle_R=(u16)(340*((u16)(t1*64))/1000)/2; //in mm
	obstacle_dist->obstacle_C=(u16)(340*((u16)(t2*64))/1000)/2; //in mm
	obstacle_dist->obstacle_L=(u16)(340*((u16)(t3*64))/1000)/2; //in mm
	t1=400;
	t2=400;
	t3=400;
	return true;
}
void UlsDriver_init(void)
{

}
ISR(INT0_vect)
{
	OS_STOP_MEASUREMENT(t1);
}
ISR(INT1_vect)
{
	OS_STOP_MEASUREMENT(t2);
}
ISR(INT2_vect)
{
	OS_STOP_MEASUREMENT(t3);
}
