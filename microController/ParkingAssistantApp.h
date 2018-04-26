/*
 * ParkingAssistantApp.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef PARKINGASSISTANTAPP_H_
#define PARKINGASSISTANTAPP_H_
typedef enum
{
SECTOR_RED=0,
SECTOR_YELLOW,
SECTOR_GREEN,
SECTOR_NONE
}PA_tenumSectorIndicator;
typedef struct
{
	PA_tenumSectorIndicator sector_R;
	PA_tenumSectorIndicator sector_C;
	PA_tenumSectorIndicator sector_L;
}PA_tStrPaData;
void PA_init(void);
void PA_task(void);
bool PA_getPaData(PA_tStrPaData * data);


#endif /* PARKINGASSISTANTAPP_H_ */
