/*
 * GPS_Driver.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "uart.h"
#include "GPS_Driver.h"
#include "DIO_reg.h"
#define UART_GPS_CHANNEL 0
#define AUTOMATIC_LOCATION 0
#define  INIT 1
#define CHECKING_GPS_STATUS 2
#define WAIT 3
#define EXIT 4
u8 state=6;
u8 arrData[204]={0};

#define LEN_INIT 17
#define LEN_AUTO 18
const u8 commandInit[]="AT+CGPSPWR=1;\r\n";//Do not do thatshelhm
const u8 commandAuto[]="AT+CGPSOUT=32;\r\n";

static gps_tstrPosition position;
static gps_tstrDate date;
static gps_tstrTime time;

void proccesCoord(void)
{
	u8 i,x=6;
	u32 temp =0;

	for(i=0;i<9;i++)
	{
		if(arrData[20+i] == '.')
		{
			x=7;
		}
		else
		{
			//temp+=((arrData[20+i]-'0')*po(10,x-i));
		}
	}

	//	position.latitude=temp;
	temp=0;
	for(i=0;i<10;i++)
	{
		if(arrData[32+i] == '.')
		{
			x=8;
		}
		else
		{
			temp+=((arrData[32+i]-'0')*po(10,x-i));
		}
	}

	position.longitude=temp;
	position.latitudeDir=arrData[30];
	position.longitudeDir=arrData[43];

	time.hour=((arrData[7]-'0')*10)+(arrData[8]-'0');
	time.minute=((arrData[9]-'0')*10)+(arrData[10]-'0');
	time.second=((arrData[11]-'0')*10)+(arrData[12]-'0');

	date.day=((arrData[60]-'0')*10)+(arrData[61]-'0');
	date.month=((arrData[62]-'0')*10)+(arrData[63]-'0');
	date.year=((arrData[64]-'0')*10)+(arrData[65]-'0');



}
void GPS_init(void)
{
	UART_Transmit(commandInit,(u16)LEN_INIT,(u8)UART_GPS_CHANNEL);
	state = INIT;
}
void GPS_task(void)
{

	u8 i;
	static u16 len = 0;
	static u8 index = 0;
	u8 indexTemp = 0;

	u8 ok[]="OK";

	switch (state) {
	case AUTOMATIC_LOCATION:
	{
		UART_Receive(&arrData[index],&len,UART_GPS_CHANNEL);
		for(i=index;	i<(index+len);	i++)
		{
			if(arrData[i]=='*')
			{
				proccesCoord();
				TOGGLE_BIT(PORTA,0);
			}
			if(arrData[i]=='$'  )
			{

				indexTemp = i;
			}
		}
		for(i=0;i<len+index-indexTemp;	i++)
		{
			arrData[i]=arrData[indexTemp+i];
		}
		index = len+index-indexTemp;

	}
	break;
	case WAIT :
		/*TODO: */
		UART_Transmit(commandAuto,LEN_AUTO,UART_GPS_CHANNEL);
		state = AUTOMATIC_LOCATION;
		break;
	case INIT:
		UART_Receive(arrData,&len,UART_GPS_CHANNEL);
		if(len >= 2)
		{
			for(i = 0; i < len ; i++)
			{
				if(arrData[i]==ok[0] && arrData[i+1]==ok[1] )
				{
					state=WAIT;
				}
			}
		}
		break;
		/*	case EXIT:
		UART_Receive(arrData,&len);
		if(len >= 2)
		{
			for(i = 0; i < len ; i++)
			{
				if(arrData[i]==ok[0] && arrData[i+1]==ok[1] )
				{
					state=INIT;
				}
			}
		}
		break;*/

	default:
		break;
	}

}
bool GPS_getPosition(gps_tstrPosition *posCpy)
{
	posCpy->latitude=position.latitude;
	posCpy->latitudeDir=position.latitudeDir;
	posCpy->longitude=position.longitude;
	posCpy->longitudeDir=position.longitudeDir;
	return true;
}
bool GPS_getTime(gps_tstrTime *timeCpy)
{
	timeCpy->hour=time.hour;
	timeCpy->minute=time.minute;
	timeCpy->second=time.second;
	return true;
}
bool GPS_getDate(gps_tstrDate *dateCpy)
{

	dateCpy->day=date.day;
	dateCpy->month=date.month;
	dateCpy->year=date.year;
	return true;
}
