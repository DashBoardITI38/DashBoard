/*
 * exchanger.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */


#include "STD_TYPES.h"
#include "uart.h"
#include "GpsApp.h"
#include "ParkingAssistantApp.h"
#include "obdApp.h"
#include "exchanger.h"
typedef enum
{						/*ID*/
	GPS_Longitude=0,	/* 0*/
	GPS_Latitude,		/* 1*/
	GPS_Time,			/* 2*/
	GPS_Speed,			/* 3*/
	GPS_Date,			/* 4*/
	PA_Data,			/* 5*/
	OBD_Speed,			/* 6*/
	OBD_RPM,			/* 7*/
	OBD_fuel,			/* 8*/
	OBD_transState		/* 9*/
}EXCHANGER_ID_t;

typedef struct
{
	EXCHANGER_ID_t id;
	u8* data;
	u8  noOfBytes;
}EXCHANGER_Message_t;

void EXCHANGER_init(void)
{


}


void EXCHANGER_task(void)
{

}
