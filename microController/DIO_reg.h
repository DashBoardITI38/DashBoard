/*
 * DIO_reg.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Administrator
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

/*A*/
#define PORTA (*((u8*)0X22))
#define DDRA (*((u8*)0X21))
#define PINA (*((volatile u8*)0X20))
/*B*/
#define PORTB (*((u8*)0X25))
#define DDRB (*((u8*)0X24))
#define PINB (*((volatile u8*)0X23))
/*C*/
#define PORTC (*((u8*)0X28))
#define DDRC (*((u8*)0X27))
#define PINC (*((volatile u8*)0X26))
/*D*/
#define PORTD (*((u8*)0X2B))
#define DDRD (*((u8*)0X2A))
#define PIND (*((volatile u8*)0X29))
/*E*/
#define PORTE (*((u8*)0X2E))
#define DDRE (*((u8*)0X2D))
#define PINE (*((volatile u8*)0X2C))
/*F*/
#define PORTF (*((u8*)0X31))
#define DDRF (*((u8*)0X30))
#define PINF (*((volatile u8*)0X2F))
/*G*/
#define PORTG (*((u8*)0X34))
#define DDRG (*((u8*)0X33))
#define PING (*((volatile u8*)0X32))
/*H*/
#define PORTH (*((u8*)0X102))
#define DDRH (*((u8*)0X101))
#define PINH (*((volatile u8*)0X100))
/*J*/
#define PORTJ (*((u8*)0X105))
#define DDRJ (*((u8*)0X104))
#define PINJ (*((volatile u8*)0X103))
/*K*/
#define PORTK (*((u8*)0X108))
#define DDRK (*((u8*)0X107))
#define PINK (*((volatile u8*)0X106))
/*L*/
#define PORTL (*((u8*)0X10B))
#define DDRL (*((u8*)0X10A))
#define PINL (*((volatile u8*)0X109))

#endif /* DIO_REG_H_ */
