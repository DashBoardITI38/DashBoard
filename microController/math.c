/*
 * math.c
 *
 *  Created on: Apr 3, 2018
 *      Author: Administrator
 */
#include "STD_TYPES.h"

u32 po(u8 base,u8 power)
{
	u32 i;
	u32 res=1;
	for(i=0;i<power;i++)
	{
		res*=base;
	}
	return res;
}
