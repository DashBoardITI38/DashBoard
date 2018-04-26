/*
 * GPS_Driver.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef GPS_DRIVER_H_
#define GPS_DRIVER_H_


typedef struct {
	u32 latitude;
	u8 latitudeDir;
	u32 longitude;
	u8 longitudeDir;
}gps_tstrPosition;

typedef struct {
	u8 second;
	u8 minute;
	u8 hour;
}gps_tstrTime;

typedef struct {
	u8 day;
	u8 month;
	u8 year;
}gps_tstrDate;


void GPS_init(void);
void GPS_task(void);
bool GPS_getPosition(gps_tstrPosition *pos);
bool GPS_getTime(gps_tstrTime *time);
bool GPS_getDate(gps_tstrDate *date);

#endif /* GPS_DRIVER_H_ */
