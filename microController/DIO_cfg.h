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
	inputWithoutPUR,
	reserved,
	notUsed
}DIO_mode_t;
typedef enum{
	/*Port A*/
/*PA0*/	PA0 = 0,
/*PA1*/	PA1,
/*PA2*/	PA2,
/*PA3*/	PA3,
/*PA4*/	PA4,
/*PA5*/	PA5,
/*PA6*/	PA6,
/*PA7*/	PA7,
	/*Port B*/
/*PB0*/	PB0,
/*PB1*/	PB1,
/*PB2*/	PB2,
/*PB3*/	PB3,
/*PB4*/	PB4,
/*PB5*/	PB5,
/*PB6*/	PB6,
/*PB7*/	PB7,
	/*Port C*/
/*PC0*/	PC0,
/*PC1*/	PC1,
/*PC2*/	PC2,
/*PC3*/	PC3,
/*PC4*/	PC4,
/*PC5*/	PC5,
/*PC6*/	PC6,
/*PC7*/	PC7,
	/*Port D*/
/*PD0*/	PD0,
/*PD1*/	PD1,
/*PD2*/	PD2,
/*PD3*/	PD3,
/*PD4*/	PD4,
/*PD5*/	PD5,
/*PD6*/	PD6,
/*PD7*/	PD7,
	/*Port E*/
/*PE0*/	PE0,
/*PE1*/	PE1,
/*PE2*/	PE2,
/*PE3*/	PE3,
/*PE4*/	PE4,
/*PE5*/	PE5,
/*PE6*/	PE6,
/*PE7*/	PE7,
	/*Port F*/
/*PF0*/	PF0,
/*PF1*/	PF1,
/*PF2*/	PF2,
/*PF3*/	PF3,
/*PF4*/	PF4,
/*PF5*/	PF5,
/*PF6*/	PF6,
/*PF7*/	PF7,
	/*Port G*/ /*JUST 6 PINS*/
/*PG0*/	PG0,
/*PG1*/	PG1,
/*PG2*/	PG2,
/*PG3*/	PG3,
/*PG4*/	PG4,
/*PG5*/	PG5,
/*PG6*/	PG6,
/*PG7*/	PG7,
	/*Port H*/
/*PH0*/	PH0,
/*PH1*/	PH1,
/*PH2*/	PH2,
/*PH3*/	PH3,
/*PH4*/	PH4,
/*PH5*/	PH5,
/*PH6*/	PH6,
/*PH7*/	PH7,
	/*Port J*/
/*PJ0*/	PJ0,
/*PJ1*/	PJ1,
/*PJ2*/	PJ2,
/*PJ3*/	PJ3,
/*PJ4*/	PJ4,
/*PJ5*/	PJ5,
/*PJ6*/	PJ6,
/*PJ7*/	PJ7,
	/*Port K*/
/*PK0*/	PK0,
/*PK1*/	PK1,
/*PK2*/	PK2,
/*PK3*/	PK3,
/*PK4*/	PK4,
/*PK5*/	PK5,
/*PK6*/	PK6,
/*PK7*/	PK7,
	/*Port L*/
/*PL0*/	PL0,
/*PL1*/	PL1,
/*PL2*/	PL2,
/*PL3*/	PL3,
/*PL4*/	PL4,
/*PL5*/	PL5,
/*PL6*/	PL6,
/*PL7*/	PL7,

	pinsCount

}DIO_pinName_t;


typedef struct {
	//DIO_pinName_t pinName;
	DIO_mode_t mode;
}DIO_cfg_t;


extern const DIO_cfg_t DIO_cfg[];

#endif /* DIO_CFG_H_ */
