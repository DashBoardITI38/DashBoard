/*
 * EXTI_register.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Yasmin
 */

#ifndef ICU_REGISTER_H_
#define ICU_REGISTER_H_

#define MCUCR *((volatile u8*)0X55)
#define GICR *((volatile u8*)0X5B)
#define GIFR *((volatile u8*)0X5A)

#endif /* ICU_REGISTER_H_ */
