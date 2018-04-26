/*
 * GpsApp.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"

#include "GPS_Driver.h"
#include "GpsApp.h"
static gpsApp_tstrGpsData gpsData;
void GpsApp_init(void)
{
	GPS_init();
}
void GpsApp_task(void)
{
	gps_tstrPosition posCpy;
	gps_tstrDate dateCpy;
	gps_tstrTime timeCpy;
	GPS_getPosition(&posCpy);
	GPS_getDate(&dateCpy);
	GPS_getTime(&timeCpy);

	gpsData.pos.latitude=posCpy.latitude;
	gpsData.pos.latitudeDir=posCpy.latitudeDir;
	gpsData.pos.longitude=posCpy.longitude;
	gpsData.pos.longitudeDir=posCpy.longitudeDir;

	gpsData.date.day= dateCpy.day;
	gpsData.date.month= dateCpy.month;
	gpsData.date.year= dateCpy.year;

	gpsData.time.hour=timeCpy.hour;
	gpsData.time.minute=timeCpy.minute;
	gpsData.time.second=timeCpy.second;
}
bool GpsApp_getGpsData(gpsApp_tstrGpsData *data)
{

		data->pos.latitude=gpsData.pos.latitude;
		data->pos.latitudeDir=gpsData.pos.latitudeDir;
		data->pos.longitude=gpsData.pos.longitude;
		data->pos.longitudeDir=gpsData.pos.longitudeDir;

		data->date.day= gpsData.date.day;
		data->date.month= gpsData.date.month;
		data->date.year= gpsData.date.year;

		data->time.hour=gpsData.time.hour;
		data->time.minute=gpsData.time.minute;
		data->time.second=gpsData.time.second;

	return true;
}
