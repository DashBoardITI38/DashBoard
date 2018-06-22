/*
 * os_cfg.c
 *
 *  Created on: Mar 8, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"

#include "os_cfg.h"
#include "ParkingAssistantApp.h"
#include "GPS_Driver.h"
#include "GpsApp.h"
#include "obdApp.h"
#include "OBD_ChipDriver.h"
#include "exchanger.h"
#include "ULS_Scanner.h"
const os_cfg_t os_cfg []={
		{GpsApp_task,100},
		{GPS_task,10},
		{UlsScanner_task,50},
		{PA_task,50},
		//{OBD_task,50},
		//{obdApp_task,50},
		{EXCHANGER_task,100}
};
















