/*
 * Delay.h
 *
 *  Created on: Apr 26, 2018
 *      Author: Yasmin
 */

#ifndef DELAY_H_
#define DELAY_H_


#define DELAY_0_5US asm("NOP");\
					asm("NOP");\
					asm("NOP");\
					asm("NOP");\
					asm("NOP");\
					asm("NOP");\
					asm("NOP");\
					asm("NOP");

#define DELAY_1US DELAY_0_5US\
				  DELAY_0_5US

#define DELAY_5US DELAY_1US\
				  DELAY_1US\
				  DELAY_1US\
				  DELAY_1US\
				  DELAY_1US

#endif /* DELAY_H_ */
