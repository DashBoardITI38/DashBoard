/*
 * main.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "os.h"
#include "GIE.h"
#include "TIM0.h"


void main (void)
{
	DIO_Init();
	GIE_voidEnable();
	Timer0_Init();
	OS_Start();

}
