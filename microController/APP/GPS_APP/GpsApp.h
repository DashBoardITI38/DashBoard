/*
 * GpsApp.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef GPSAPP_H_
#define GPSAPP_H_
typedef struct {
	u32 latitude;
	u8 latitudeDir;
	u32 longitude;
	u8 longitudeDir;
}gpsApp_tstrPosition;

typedef struct {
	u8 second;
	u8 minute;
	u8 hour;
}gpsApp_tstrTime;

typedef struct {
	u8 day;
	u8 month;
	u8 year;
}gpsApp_tstrDate;

typedef struct
{
	gpsApp_tstrPosition pos;
	gpsApp_tstrDate date;
	gpsApp_tstrTime time;
}gpsApp_tstrGpsData;

void GpsApp_init(void);
void GpsApp_task(void);
bool GpsApp_getGpsData(gpsApp_tstrGpsData *data);


#endif /* GPSAPP_H_ */
