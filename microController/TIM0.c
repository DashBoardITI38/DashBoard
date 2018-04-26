/*
 * TIM0.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

/*
 * *
 *
Bit	 7		6	5	 4  3  2	1 0
 COM0A1 COM0A0 COM0B1 COM0B0 – – WGM01 WGM00 TCCR0A
/////////////
0  0 0 0 Normal 0xFF Immediate MAX
1  0 0 1 PWM, Phase Correct 0xFF TOP BOTTOM
2  0 1 0 CTC OCRA Immediate MAX
3  0 1 1 Fast PWM 0xFF TOP MAX
4  1 0 0 Reserved – – –
5  1 0 1 PWM, Phase Correct OCRA TOP BOTTOM
6  1 1 0 Reserved – – –
7  1 1 1 Fast PWM OCRA BOTTOM TOP
 ////////////
 Bit 		7 		6 	5 4 3 		2	 1	 0
0x25 (0x45) FOC0A FOC0B – – WGM02 CS02 CS01 CS00 TCCR0B
///////////
CS02CS01 CS00 Description
 0 0 0 No clock source (Timer/Counter stopped)
 0 0 1 clkI/O/(No prescaling)
 0 1 0 clkI/O/8 (From prescaler)
 0 1 1 clkI/O/64 (From prescaler)
 1 0 0 clkI/O/256 (From prescaler)
 1 0 1 clkI/O/1024 (From prescaler)
 1 1 0 External clock source on T0 pin. Clock on falling edge
 1 1 1 External clock source on T0 pin. Clock on rising edge
//////////
 	   7 6 5 4 3 	2 	   1 	0
(0x6E) – – – – – OCIE0B OCIE0A TOIE0 	TIMSK0
 */
#include  "STD_TYPES.h"
#include "TIM0_register.h"
void Timer0_Init(void)
{
TCCR0A=0x02 ;
TCCR0B=0x05 ;// prescaller 1024
TIFR0=0x02;
TIMSK0=0x02;
TCNT0=0;
OCR0A=78;//5ms
}
