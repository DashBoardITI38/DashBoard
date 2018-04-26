/*
 * Timer1_reg.h
 *
 *  Created on: Apr 11, 2018
 *      Author: Yasmin
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

/*
 * (0x8D) OCR1CH Timer/Counter1 - Output Compare Register C High Byte page 159
(0x8C) OCR1CL Timer/Counter1 - Output Compare Register C Low Byte page 159
(0x8B) OCR1BH Timer/Counter1 - Output Compare Register B High Byte page 159
(0x8A) OCR1BL Timer/Counter1 - Output Compare Register B Low Byte page 159
(0x89) OCR1AH Timer/Counter1 - Output Compare Register A High Byte page 159
(0x88) OCR1AL Timer/Counter1 - Output Compare Register A Low Byte page 159
(0x87) ICR1H Timer/Counter1 - Input Capture Register High Byte page 160
(0x86) ICR1L Timer/Counter1 - Input Capture Register Low Byte page 160
(0x85) TCNT1H Timer/Counter1 - Counter Register High Byte page 158
(0x84) TCNT1L Timer/Counter1 - Counter Register Low Byte page 158
(0x83) Reserved - - - - - - - -
(0x82) TCCR1C FOC1A FOC1B FOC1C - - - - - page 157
(0x81) TCCR1B ICNC1 ICES1 - WGM13 WGM12 CS12 CS11 CS10 page 156
(0x80) TCCR1A COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
(0x6F) TIMSK1 - - ICIE1 - OCIE1C OCIE1B OCIE1A TOIE1 page 161
(0x36) TIFR1 - - ICF1 - OCF1C OCF1B OCF1A TOV1 page 162
 *
 *
 * */
#define TCCR1A *((volatile u8*)0x80)
#define TCCR1B *((volatile u8*)0x81)
#define TCCR1C *((volatile u8*)0x82)
#define TCNT1H *((volatile u8*)0x85)
#define TCNT1L *((volatile u8*)0x84)
#define TCNT1 *((volatile u16*)0x84)
#define OCR1AH *((volatile u8*)0x89)
#define OCR1AL *((volatile u8*)0x88)
#define OCR1A *((volatile u16*)0x88)

#define OCR1BH *((volatile u8*)0x8B)
#define OCR1BL *((volatile u8*)0x8A)
#define OCR1B *((volatile u16*)0x8A)

#define TIMSK1    *((volatile u8*)0x6F)
#define TIFR1    *((volatile u8*)0x36)
#define ICR1H    *((volatile u8*)0x87)
#define ICR1L    *((volatile u8*)0x86)
#define ICR1    *((volatile u16*)0x86)


#endif /* TIMER1_REG_H_ */
