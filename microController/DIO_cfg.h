/*
 * DIO_cfg.h
 *
 *  Created on: Mar 28, 2018
 *      Author: Administrator
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

typedef enum{
	output = 0,
	inputWithPUR,
	inputWithoutPUR
}DIO_mode_t;
typedef enum{
	/*Port A*/
/*PA0*/	seg1A = 0,
/*PA1*/	seg1B,
/*PA2*/	seg1C,
/*PA3*/	seg1D,
/*PA4*/	seg1E,
/*PA5*/	seg1F,
/*PA6*/	seg1G,
/*PA7*/	seg1Dot,

	/*Port B*/
/*PB0*/	redLed,
/*PB1*/	greenLed,
/*PB2*/	yellowLed,
/*PB3*/	PB3,
/*PB4*/	PB4,
/*PB5*/	PB5,
/*PB6*/	PB6,
/*PB7*/	PB7,

	/*Port C*/
/*PC0*/	seg2A,
/*PC1*/	seg2B,
/*PC2*/	seg2C,
/*PC3*/	seg2D,
/*PC4*/	seg2E,
/*PC5*/	seg2F,
/*PC6*/	seg2G,
/*PC7*/	seg2Dot,

	/*Port D*/
/*PD0*/	RxD,
/*PD1*/	TxD,
/*PD2*/	PD2,
/*PD3*/	PD3,
/*PD4*/	PD4,
/*PD5*/	PD5,
/*PD6*/	PD6,
/*PD7*/	LED2,

	pinsCount

}DIO_pinName_t;


typedef struct {
	//DIO_pinName_t pinName;
	DIO_mode_t mode;
}DIO_cfg_t;


extern const DIO_cfg_t DIO_cfg[];

#endif /* DIO_CFG_H_ */
