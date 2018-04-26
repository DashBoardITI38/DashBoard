/*
 * os.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Administrator
 */

#ifndef OS_H_
#define OS_H_
#include "os_cfg.h"
#define RTO_u16_TICK_TIME_MS 100
#define RTO_u16_MS_TO_US    1000



#define OS_START_MEASUREMENT TCNT1=0
#define OS_STOP_MEASUREMENT_X1 x1=TCNT1
#define OS_STOP_MEASUREMENT_X2 x2=TCNT1
#define OS_STOP_MEASUREMENT_X3 x3=TCNT1

extern void OS_Init(void);
extern void OS_Start(void);
#endif /* OS_H_ */
