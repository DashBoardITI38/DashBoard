/*
 * EXTI_int.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Yasmin
 */

#ifndef ICU_H_
#define ICU_H_

/*
 * 	ISCn1	ISCn0
 * 	  0		  0			LOW LEVEL
 * 	  0		  1			ANY EDGE
 * 	  1		  0			Falling EDGE
 * 	  1	  	  1			Raising EDGE
 * */
#define ICU_CHANNEL0 0
#define ICU_CHANNEL1 1
#define ICU_CHANNEL2 2

void ICU_init(u8 ICU_Channel);
void ICU_Enable(u8 ICU_Channel);
void ICU_Disable(u8 ICU_Channel);
void ICU_RaisingEdge(u8 ICU_Channel);
void ICU_FallingEdge(u8 ICU_Channel);
#endif /* ICU_H_ */
