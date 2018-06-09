/*
 * ULS_Scanner.c
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "ULS_Driver.h"
#include "ULS_Scanner.h"
UlsDriver_tStrObstacleDist dist;
void UlsScanner_init(void)
{

}
void UlsScanner_task(void)
{
	static u32 osTick=0;
	UlsDriver_Trigger(osTick%3);
	osTick++;
	UlsDriver_getDistance(&dist);
}
bool UlsScanner_getMap(UlsScanner_tStrMap * map)
{
	if((dist.obstacle_R )< RED_MAX_DIST)
	{
		map->sector_R =SECTOR_R;
	}
	else if(dist.obstacle_R < YELLOW_MAX_DIST)
	{
		map->sector_R =SECTOR_Y;
	}
	else if(dist.obstacle_R < GREEN_MAX_DIST)
	{
		map->sector_R =SECTOR_G;
	}
	else
	{
		map->sector_R =SECTOR_NON;
	}
	//////////////////////
	if(dist.obstacle_L < RED_MAX_DIST)
	{
		map->sector_L =SECTOR_R;
	}
	else if(dist.obstacle_L < YELLOW_MAX_DIST)
	{
		map->sector_L =SECTOR_Y;
	}
	else if(dist.obstacle_L < GREEN_MAX_DIST)
	{
		map->sector_L =SECTOR_G;
	}
	else
	{
		map->sector_L =SECTOR_NON;
	}
	//////////////////////////////////
	if(dist.obstacle_C < RED_MAX_DIST)
	{
		map->sector_C =SECTOR_R;
	}
	else if(dist.obstacle_C < YELLOW_MAX_DIST)
	{
		map->sector_C =SECTOR_Y;
	}
	else if(dist.obstacle_C < GREEN_MAX_DIST)
	{
		map->sector_C =SECTOR_G;
	}
	else
	{
		map->sector_C =SECTOR_NON;
	}
/////////////////////////////
	return true;
}
