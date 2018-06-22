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

#define AUTOMATIC_LOCATION 0
#define INIT 1
#define CHECKING_GPS_STATUS 2
#define WAIT 3
#define EXIT 4

#define TIME			1
#define LAT				3
#define LAT_Dir 		4
#define LONG			5
#define LONG_Dir		6
#define DATE			10//9
#define OUT_OF_RANGE 	22
u8 state=6;
u8 arrData[204]={0};
u8 arr2[20]={0};
u8 array[10]={0};
u8 length=0;
#define LEN_INIT 17
#define LEN_AUTO 18

// AT-Command to Start Automatic mode in GPS
const u8 commandAuto[]={"AT+CGPSOUT=32;\r\n"};
const u8 ok[]={"OK"};
// AT-Command to power on GPS
const u8 commandInit[]="AT+CGPSPWR=1;\r\n";//Do not do that shelhm

static gps_tstrPosition position;
static gps_tstrDate date;
static gps_tstrTime time;





//void proccesCoord(void)
//{
//	u8 i=0,x,j=0;
//	u8 prevComma=0,comma=OUT_OF_RANGE;
//	u32 temp =0;
//
//	while(i<70)
//	{
//
//		//		if(arrData[i]=='$')
//		//		{
//		//			i=0;
//		//		}
//
//		if(arrData[i]==',')
//		{
//			//Counter
//			prevComma++;
//			comma=prevComma;
//		}
//		else
//		{
//			switch(comma)
//			{
//			case TIME:
//				time.hour=((arrData[i]-'0')*10)+(arrData[i+1]-'0');
//				time.minute=((arrData[i+2]-'0')*10)+(arrData[i+3]-'0');
//				time.second=((arrData[i+4]-'0')*10)+(arrData[i+5]-'0');
//				//i+=4;
//				break;
//
//			case LAT:
//				x=7;
//				for(j=0;j<9;j++)
//				{
//					if(arrData[j+i] == '.')
//					{
//						x=8;
//					}
//					else
//					{
//						temp+=((arrData[j+i]-'0')*po(10,x-j));//60  51  24  33  7-4=3  7-5=2  7-6=1  7-7=0
//					}
//				}
//				position.latitude=temp;
//				//i+=6;
//				break;
//			case LAT_Dir:
//				position.latitudeDir=arrData[i];
//				break;
//			case LONG:
//				temp=0;
//				x=8;
//				for(j=0;j<10;j++)
//				{
//					if(arrData[j+i] == '.')
//					{
//						x=9;
//					}
//					else
//					{
//						temp+=((arrData[j+i]-'0')*po(10,x-j));
//					}
//				}
//				position.longitude=temp;
//				//i+=7;
//				break;
//			case LONG_Dir:
//				position.longitudeDir=arrData[i];
//				break;
//			case DATE:
//				date.day=((arrData[i]-'0')*10)+(arrData[i+1]-'0');
//				date.month=((arrData[i+2]-'0')*10)+(arrData[i+3]-'0');
//				date.year=((arrData[i+4]-'0')*10)+(arrData[i+5]-'0');//
//				//i+=3;
//			//	UART_Transmit(arrData+i,2 ,UART_EXCHANGER_CHANNEL);
//				break;
//
//			}
//			//UART_Transmit(arrData+i,2 ,UART_EXCHANGER_CHANNEL);
//			comma=OUT_OF_RANGE;
//		}
//		i++;
//
//	}
//
////	NumToAscii(55,array,&length); /*TODO:change length to u16*/
//	//UART_Transmit(arrData,70 ,UART_EXCHANGER_CHANNEL);
//	//UART_Transmit(array,length ,UART_EXCHANGER_CHANNEL);
//}


void proccesCoord(void)
{
	u8 i,x=6;
	u32 temp =0;

	// Digits in lat
	for(i=0;i<9;i++)
	{
		if(arrData[20+i] == '.')
		{
			x=7;
		}
		else
		{
			temp+=((arrData[20+i]-'0')*po(10,x-i));
		}
	}


	position.longitude=temp;

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

	position.latitude=temp;
	position.longitudeDir=arrData[30];
	position.latitudeDir=arrData[43];
	time.hour=((arrData[7]-'0')*10)+(arrData[8]-'0');
	time.minute=((arrData[9]-'0')*10)+(arrData[10]-'0');
	time.second=((arrData[11]-'0')*10)+(arrData[12]-'0');
	date.day=((arrData[57]-'0')*10)+(arrData[58]-'0');
	date.month=((arrData[59]-'0')*10)+(arrData[60]-'0');
	date.year=((arrData[61]-'0')*10)+(arrData[62]-'0');//


}
void GPS_init(void)
{

	state = INIT;
}
void GPS_task(void)
{

	u8 i;
	static u16 len = 0;
	static u8 index = 0;
	u8 indexTemp = 0;


	switch (state) {
	case AUTOMATIC_LOCATION:
	{
		UART_Receive(&arrData[index],&len,UART_GPS_CHANNEL);
		for(i=index;	i<(index+len);	i++)
		{
			if(arrData[i]=='*')
			{
				if(arrData[i-1]=='A')
				{
					proccesCoord();
				}
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

		UART_Transmit(commandInit,(u16)LEN_INIT,(u8)UART_GPS_CHANNEL);
		UART_Receive(arr2,&len,UART_GPS_CHANNEL);

		if(len >= 2)
		{
			for(i = 0; i < len ; i++)
			{
				if(arr2[i]==ok[0] && arr2[i+1]==ok[1] )
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
