/******************************************/
/* Author: Ahmed Ramadan                  */
/* Date:   28 feb                         */
/* Release: v01                           */
/******************************************/




#ifndef _TIM_REGISTER_H
#define _TIM_REGISTER_H


#define TCCR0A   *((u8*)0x44)
#define TCCR0B   *((u8*)0x45)
#define OCR0A    *((u8*)0x47)
#define OCR0B    *((u8*)0x48)
#define TCNT0   *((u8*)0x46)
#define TIMSK0    *((u8*)0x6E)
#define TIFR0    *((u8*)0x35)


	
#endif
