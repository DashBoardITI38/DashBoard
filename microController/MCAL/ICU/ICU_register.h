/*
 * EXTI_register.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Yasmin
 */

#ifndef ICU_REGISTER_H_
#define ICU_REGISTER_H_


#define EICRA *((volatile u8*)0X69)
#define EICRB *((volatile u8*)0X6A)
#define EIMSK *((volatile u8*)0X3D)
#define EIFR *((volatile u8*)0X3C)


#endif /* ICU_REGISTER_H_ */
