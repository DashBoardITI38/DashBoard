/*
 * main.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "os.h"
#include "GIE.h"
#include "TIM0.h"
#include "TIM1.h"
#include "ICU.h"
#include "uart.h"
#include "exchanger.h"
#include "ULS_Scanner.h"
#include "ULS_Driver.h"
#include "GpsApp.h"
#include "GPS_Driver.h"
#include "ParkingAssistantApp.h"

void main (void)
{
	const u8 start[2]={"st"};
	DIO_Init();
	UART_Init(UART_EXCHANGER_CHANNEL);
	UART_Init(UART_GPS_CHANNEL);
	ICU_init(ICU_CHANNEL0);
	ICU_init (ICU_CHANNEL1);
	ICU_init (ICU_CHANNEL4);
	ICU_RaisingEdge(ICU_CHANNEL0);
	ICU_RaisingEdge(ICU_CHANNEL1);
	ICU_RaisingEdge(ICU_CHANNEL4);
	ICU_Enable(ICU_CHANNEL0);
	ICU_Enable(ICU_CHANNEL1);
	ICU_Enable(ICU_CHANNEL4);


	Timer0_Init();
	Timer1_Init();
	UlsDriver_init();

	UlsScanner_init();
	PA_init();
	GPS_init();
	GpsApp_init();
	EXCHANGER_init();
	GIE_voidEnable();


	OS_Start();

}
