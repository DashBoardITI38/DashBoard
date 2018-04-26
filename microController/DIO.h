/*
 * DIO.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Administrator
 */

#ifndef DIO_H_
#define DIO_H_

#include "DIO_cfg.h"


typedef enum{
	portA = 0,
	portB,
	portC,
	portD,
	portE,
	portF,
	portG,/*JUST 6 PINS*/
	portH,
	portJ,
	portK,
	portL,
}DIO_portName_t;

typedef enum{
	DIO_low =0,
	DIO_High
}DIO_level_t;
extern void DIO_Init(void);
extern void DIO_setPinValue(DIO_pinName_t,DIO_level_t);
extern DIO_level_t DIO_getPinValue(DIO_pinName_t);



#endif /* DIO_H_ */
