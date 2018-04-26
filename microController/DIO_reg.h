/*
 * DIO_reg.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Administrator
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

#define PORTA (*((u8*)0X3B))
#define DDRA (*((u8*)0X3A))
#define PINA (*((volatile u8*)0X39))


#define PORTB (*((u8*)0X38))
#define DDRB (*((u8*)0X37))
#define PINB (*((volatile u8*)0X36))

#define PORTC (*((u8*)0X35))
#define DDRC (*((u8*)0X34))
#define PINC (*((volatile u8*)0X33))

#define PORTD (*((u8*)0X32))
#define DDRD (*((u8*)0X31))
#define PIND (*((volatile u8*)0X30))

#endif /* DIO_REG_H_ */
