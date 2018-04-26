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



#define BYTE_NUMBER_GPS_LONGITUDE 		5	/* 0*/
#define BYTE_NUMBER_GPS_LATITUDE		5	/* 1*/
#define BYTE_NUMBER_GPS_TIME			3	/* 2*/
#define BYTE_NUMBER_GPS_DATE 			3	/* 3*/
#define BYTE_NUMBER_PA_DATA				3	/* 4*/
#define BYTE_NUMBER_OBD_SPEED 			1	/* 5*/
#define BYTE_NUMBER_OBD_RPM 			1	/* 6*/
#define BYTE_NUMBER_OBD_FUEL			1	/* 7*/
#define BYTE_NUMBER_OBD_TRANS_STATE		1	/* 8*/
////////ID/////Name///////BYTES
/*		0		Longitude	4+(1 Direction)
 * 		1		Latitude 	4+(1 Direction)
 * 		2		Time		3
 * 		3		Date		3
 * 		4		PaData		3
 * 		5		OBDSpeed	1
 * 		6		RPM			1
 * 		7		FUel		1
 * 		8		TransState	1
 *
 */
typedef enum
{						/*ID*/
	GPS_Longitude=0,	/* 0*/
	GPS_Latitude,		/* 1*/
	GPS_Time,			/* 2*/
	GPS_Date,			/* 3*/
	PA_Data,			/* 4*/
	OBD_Speed,			/* 5*/
	OBD_RPM,			/* 6*/
	OBD_fuel,			/* 7*/
	OBD_transState		/* 8*/
}EXCHANGER_ID_t;

typedef struct
{
	EXCHANGER_ID_t id;
	u8* data;
	u8  noOfBytes;
}EXCHANGER_Message_t;

void EXCHANGER_init(void)
{
	GpsApp_init();
}


void EXCHANGER_task(void)
{
	u8 i;
	u8 delimeterStart='\r',delimeterEnd='\n';
	static gpsApp_tstrGpsData gpsData;
	static EXCHANGER_Message_t messages[]={
			{GPS_Longitude,(u8*)(&(gpsData.pos.longitude)),BYTE_NUMBER_GPS_LONGITUDE},
			{GPS_Latitude,(u8*)(&(gpsData.pos.latitude)),BYTE_NUMBER_GPS_LATITUDE},
			{GPS_Time,(u8*)(&(gpsData.time.second)),BYTE_NUMBER_GPS_TIME},
			{GPS_Date,(u8*)(&(gpsData.date.day)),BYTE_NUMBER_GPS_DATE},

			/*TODO:Complete the rest of messages*/
	};
	GpsApp_getGpsData(&gpsData);

	for (i = 0; i < sizeof(messages)/sizeof(messages[0]); ++i) {
		UART_Transmit(&delimeterStart,1,UART_EXCHANGER_CHANNEL);
		UART_Transmit(&(messages[i].id),1,UART_EXCHANGER_CHANNEL);
		UART_Transmit(messages[i].data,messages[i].noOfBytes,UART_EXCHANGER_CHANNEL);
		UART_Transmit(&delimeterEnd,1,UART_EXCHANGER_CHANNEL);
	}


}

u8* EXCHANGER_convertToAscii(u8* data,u16 size)
{
	u8 i;
	static u8* ret;

	for (i = 0; i < size; ++i)
	{
			ret[i]=data[i]+'0';
	}
	return ret;
}
