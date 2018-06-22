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
#include "BIT_MATH.h"


#define BYTE_NUMBER_GPS_LONGITUDE 		4	/* 0*/
#define BYTE_NUMBER_GPS_LONGITUDE_DIR 	1	/* 1*/
#define BYTE_NUMBER_GPS_LATITUDE		4	/* 2*/
#define BYTE_NUMBER_GPS_LATITUDE_DIR	1	/* 3*/
#define BYTE_NUMBER_GPS_TIME_SEC		1	/* 4*/
#define BYTE_NUMBER_GPS_TIME_MIN		1	/* 5*/
#define BYTE_NUMBER_GPS_TIME_HR			1	/* 6*/
#define BYTE_NUMBER_GPS_DATE_DAY 		1	/* 7*/
#define BYTE_NUMBER_GPS_DATE_MONTH		1	/* 8*/
#define BYTE_NUMBER_GPS_DATE_YEAR 		1	/* 9*/
#define BYTE_NUMBER_PA_DATA_RIGHT		1	/* 10*/
#define BYTE_NUMBER_PA_DATA_CENTER		1	/* 11*/
#define BYTE_NUMBER_PA_DATA_LEFT		1	/* 11*/
#define BYTE_NUMBER_OBD_SPEED 			1	/* 12*/
#define BYTE_NUMBER_OBD_RPM 			1	/* 13*/
#define BYTE_NUMBER_OBD_FUEL			1	/* 14*/
#define BYTE_NUMBER_OBD_TRANS_STATE		1	/* 15*/
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
	GPS_Longitude_Dir,	/* 1*/
	GPS_Latitude,		/* 2*/
	GPS_Latitude_Dir,	/* 3*/
	GPS_Time_Sec,		/* 4*/
	GPS_Time_Min,		/* 5*/
	GPS_Time_Hour,		/* 6*/
	GPS_Date_Day,		/* 7*/
	GPS_Date_Month,		/* 8*/
	GPS_Date_Year,		/* 9*/
	PA_Data_Right,		/* 10*/
	PA_Data_Center,		/* 11*/
	PA_Data_Left,		/* 12*/
	OBD_Speed,			/* 13*/
	OBD_RPM,			/* 14*/
	OBD_fuel,			/* 15*/
	OBD_transState		/* 16*/
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
	u8 delimeterStart='A',delimeterEnd=' ';
	u8 array[10]={0};
	u8 length =0;

	static gpsApp_tstrGpsData gpsData;
	static PA_tStrPaData PAdata;
	static EXCHANGER_Message_t messages[]=
	{
			{GPS_Longitude,(u8*)(&(gpsData.pos.longitude)),BYTE_NUMBER_GPS_LONGITUDE},
			{GPS_Longitude_Dir,(u8*)(&(gpsData.pos.longitudeDir)),BYTE_NUMBER_GPS_LONGITUDE_DIR},
			{GPS_Latitude,(u8*)(&(gpsData.pos.latitude)),BYTE_NUMBER_GPS_LATITUDE},
			{GPS_Latitude_Dir,(u8*)(&(gpsData.pos.latitudeDir)),BYTE_NUMBER_GPS_LATITUDE_DIR},
			{GPS_Time_Sec,(u8*)(&(gpsData.time.second)),BYTE_NUMBER_GPS_TIME_SEC},
			{GPS_Time_Min,(u8*)(&(gpsData.time.minute)),BYTE_NUMBER_GPS_TIME_MIN},
			{GPS_Time_Hour,(u8*)(&(gpsData.time.hour)),BYTE_NUMBER_GPS_TIME_HR},
			{GPS_Date_Day,(u8*)(&(gpsData.date.day)),BYTE_NUMBER_GPS_DATE_DAY},
			{GPS_Date_Month,(u8*)(&(gpsData.date.month)),BYTE_NUMBER_GPS_DATE_MONTH},
			{GPS_Date_Year,(u8*)(&(gpsData.date.year)),BYTE_NUMBER_GPS_DATE_YEAR},
			{PA_Data_Right,(u8*)(&(PAdata.sector_R)),BYTE_NUMBER_PA_DATA_RIGHT},
			{PA_Data_Center,(u8*)(&(PAdata.sector_C)),BYTE_NUMBER_PA_DATA_CENTER},
			{PA_Data_Center,(u8*)(&(PAdata.sector_C)),BYTE_NUMBER_PA_DATA_LEFT}
			/*TODO:Complete the rest of messages*/
	};
	GpsApp_getGpsData(&gpsData);
	PA_getPaData(&PAdata);

	for (i = 0; i < sizeof(messages)/sizeof(messages[0]); i++) {
		UART_Transmit(&delimeterStart,1,UART_EXCHANGER_CHANNEL);
		NumToAscii((messages[i].id),array,&length,1);
		UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);

		UART_Transmit(&delimeterEnd,1,UART_EXCHANGER_CHANNEL);
		//	UART_Transmit(&(messages[i].id),1,UART_EXCHANGER_CHANNEL);
		if(messages[i].noOfBytes==4)
		{
			NumToAscii(*((u32*)(messages[i].data)),array,&length,1);
			UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);
		}
		else
		{
			if(((messages[i].id)== GPS_Latitude_Dir)||((messages[i].id)==GPS_Longitude_Dir))
			{
				UART_Transmit(messages[i].data,1,UART_EXCHANGER_CHANNEL);
			}
			else
			{
				NumToAscii(*(messages[i].data),array,&length,1); /*TODO:change length to u16*/
				UART_Transmit(array,length,UART_EXCHANGER_CHANNEL);

			}
		}


		///////////////////////

		//	UART_Transmit(messages[i].data,messages[i].noOfBytes,UART_EXCHANGER_CHANNEL);

		UART_Transmit(&delimeterEnd,1,UART_EXCHANGER_CHANNEL);
	}


}
//264
//1*256		8
// 216 /100	= 2
// 216 %100 = 16
//	16 /10	= 1
//	16 %10	= 6


//65432*10

/*
u8* EXCHANGER_convertToAscii(u8* data,u16 size)
{
	u8 i;
	static u8* ret,temp
for(i=0; iM)
	while (data[0] != 0)
	{
		ret[i]=(data[0]%100;
	}
	for (i = 0; i < size; ++i)
	{
		ret[i]=data[i]+'0';
	}
	return ret;
}
 */
