/*
 * os.c
 *
 *  Created on: Feb 26, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"
#include "TIM0.h"
#include "os.h"
#include "avr/interrupt.h"

#define NUM_OF_TASKS 1


/* Tick Timer*/

u32 u32osTick = 0;
u8 u8Flag = 0;
void OS_Init(void)
{

	/*SET callback of the timer to scheduler function*/
}
void OS_Start(void)
{
	static u8 i;
	while(1)
	{
		if (1==u8Flag){
			u8Flag=0;
			for(i=0;i<NUM_OF_TASKS;i++)
			{
				if( u32osTick%os_cfg[i].periodicity == 0){
					os_cfg[i].pfTask();
				}
			}
		}

	}
}

/* Tick Timer*/

ISR(TIMER0_COMP_vect)
{
	u8Flag=1;
	u32osTick++;
}
