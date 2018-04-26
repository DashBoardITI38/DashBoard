/*
 * TIM1.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */
/*
 * 		7		 6		 5	 4	 	3 		2 		1 	0
(0x80) COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10 TCCR1A
 *
 *
0 		0 0 0 0 Normal 0xFFFF Immediate MAX
1 		0 0 0 1 PWM, Phase Correct, 8-bit 0x00FF TOP BOTTOM
2 		0 0 1 0 PWM, Phase Correct, 9-bit 0x01FF TOP BOTTOM
3 		0 0 1 1 PWM, Phase Correct, 10-bit 0x03FF TOP BOTTOM
4 		0 1 0 0 CTC OCRnA Immediate MAX
5 		0 1 0 1 Fast PWM, 8-bit 0x00FF BOTTOM TOP
6 		0 1 1 0 Fast PWM, 9-bit 0x01FF BOTTOM TOP
7 		0 1 1 1 Fast PWM, 10-bit 0x03FF BOTTOM TOP
8 		1 0 0 0 PWM, Phase and Frequency Correct ICRn BOTTOM BOTTOM
9 		1 0 0 1 PWM,Phase and FrequencyCorrect OCRnA BOTTOM BOTTOM
10		1 0 1 0 PWM, Phase Correct ICRn TOP BOTTOM
11 		1 0 1 1 PWM, Phase Correct OCRnA TOP BOTTOM
12 		1 1 0 0 CTC ICRn Immediate MAX
13 		1 1 0 1 (Reserved) – – –
14 		1 1 1 0 Fast PWM ICRn BOTTOM TOP
15 		1 1 1 1 Fast PWM OCRnA BOTTOM TOP
 Bit 	7 		6  5 4 		3 	  2 	1 	0
(0x81) ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10 TCCR1B
 *
 *
 *
 *
 * */
#include  "STD_TYPES.h"
#include "Timer1_reg.h"
void Timer1_Init(void)
{
TCCR1A=0 ;
TCCR1B=0x05 ;//1024
TCCR1C=0x0;//
TCNT1=0;
}
