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
void decToAscii(u32 num,u8 *str,u8* len)
{
	u8 i=0,j,tmp;
	while(num!=0)
	{
		str[i]=(num%10)+'0';
		num/=10;
		i++;
	}
	for(j=0;	j<i/2;	j++)
	{
		tmp=str[j];
		str[j]=str[(i-1)-j];
		str[(i-1)-j]=tmp;
	}
	str[i]='\0';
	*len = i-1;
}
void NumToAscii (u32 num1,u8 * array , u8* length, u8 op)
{
	//0 y3ni char
	//1 y3ni num
	u8 ASCII[16]= {'0','1','2','3','4','5','6','7','8','9','=','C','+','-','*','/'};

	u32 num;
	u32 index=1,max=0;
	if(op==0)
	{
		array[0]=num1;
		*length =1;
	}
	else
	{
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
		*length=max;
	}
}
