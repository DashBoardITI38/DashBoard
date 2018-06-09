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
		{GPS_task,200},
		{GpsApp_task,200},
		//{UlsScanner_task,10},
		//{PA_task,50},
		//{OBD_task,50},
		//{obdApp_task,50},
		//{EXCHANGER_task,50}
};
