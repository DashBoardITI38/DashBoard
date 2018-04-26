/*
 * obdApp.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef OBDAPP_H_
#define OBDAPP_H_
typedef struct
{
	u16* speed;
	u16* rpm;
	u8* fuel;
	u8* transState;
}obdApp_tstrObdData;
void obdApp_init(void);
void obdApp_task(void);
bool obdApp_getObdData(obdApp_tstrObdData *data);

#endif /* OBDAPP_H_ */
