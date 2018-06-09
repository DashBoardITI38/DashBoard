/*
 * ParkingAssistantApp.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "uart.h"
#include "ULS_Scanner.h"
#include "ParkingAssistantApp.h"

static UlsScanner_tStrMap map;

void PA_init(void)
{

}

void PA_task(void)
{
	UlsScanner_getMap(&map);


}
bool PA_getPaData(PA_tStrPaData * data)
{
data->sector_C =map.sector_C;
data->sector_R =map.sector_R;
data->sector_L =map.sector_L;

	return true;
}
