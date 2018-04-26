/*
 * ULS_Driver.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef ULS_DRIVER_H_
#define ULS_DRIVER_H_
typedef enum{
	SENSOR_R=0,
	SENSOR_C,
	SENSOR_L
}UlsDriver_tenumSensorId;
typedef struct{
	u16 obstacle_R;
	u16 obstacle_C;
	u16 obstacle_L;
}UlsDriver_tStrObstacleDist;

void UlsDriver_Trigger(UlsDriver_tenumSensorId id);
bool UlsDriver_getDistance(UlsDriver_tStrObstacleDist * obstacle_dist);
void UlsDriver_init(void);
#endif /* ULS_DRIVER_H_ */
