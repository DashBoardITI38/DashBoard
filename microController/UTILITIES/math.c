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
void NumToAscii (u32 num1,u8 * array , u8 length)
{
	u8 ASCII[16]= {'0','1','2','3','4','5','6','7','8','9','=','C','+','-','*','/'};

	u32 num;
	u32 index=1,max=0;
	num=num1;
	while(index ==1)
	{
		num =num/10;
		max++;
		if(num ==0)
		{
			index=0;
		}
		else
		{

		}
	}
	num = 0;
	for(index=0; index<max; index++)
	{
		num = num1-num;

		num=((num)/(po(10,(max-index-1))));
		array[index]=ASCII[num];
		num=((num1)/(po(10,(max-index-1))))*((po(10,(max-index-1))));
	}
	array[index]='/0';
	length=max;
}
