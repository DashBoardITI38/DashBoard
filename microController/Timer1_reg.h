/*
 * Timer1_reg.h
 *
 *  Created on: Apr 11, 2018
 *      Author: Yasmin
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_


#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u8*)0x4e)
#define TCNT1H *((volatile u8*)0x4d)
#define TCNT1L *((volatile u8*)0x4c)
#define TCNT1 *((volatile u16*)0x4c)
#define OCR1AH *((volatile u8*)0x4b)
#define OCR1AL *((volatile u8*)0x4a)
#define OCR1A *((volatile u16*)0x4a)
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define OCR1B *((volatile u16*)0x48)
#define TIMSK    *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)
#define ICR1H    *((volatile u8*)0x47)
#define ICR1L    *((volatile u8*)0x46)
#define ICR1    *((volatile u16*)0x46)


#endif /* TIMER1_REG_H_ */
