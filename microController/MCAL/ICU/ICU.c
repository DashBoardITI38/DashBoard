/*
 * EXTI_prog.c
 *
 *  Created on: Feb 7, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ICU.h"
#include "ICU_register.h"
/*
 * 	ISCn1	ISCn0
 * 	  0		  0			LOW LEVEL
 * 	  0		  1			ANY EDGE
 * 	  1		  0			Falling EDGE
 * 	  1	  	  1			Raising EDGE
 * */

void ICU_init(u8 ICU_Channel)
{
	/*ICU_Channel Should be in range 0 -> 5 D0,D1,D2,D3,E4,E5*/
	/*set EXTI to be IOC*/
	if(ICU_Channel < 4)
	{
		SET_BIT(EICRA,(2*ICU_Channel));
		CLR_BIT(EICRA,((2*ICU_Channel)+1));
	}
	else
	{
		SET_BIT(EICRB,(2*(4-ICU_Channel)));
		CLR_BIT(EICRB,((2*(4-ICU_Channel))+1));
	}
	CLR_BIT(EIMSK,ICU_Channel);
	SET_BIT(EIFR,ICU_Channel);
}
void ICU_Enable(u8 ICU_Channel){
	SET_BIT(EIMSK, ICU_Channel);
}
void ICU_Disable(u8 ICU_Channel){
	CLR_BIT(EIMSK,ICU_Channel);
}
void ICU_RaisingEdge(u8 ICU_Channel){

	if(ICU_Channel < 4)
	{
		SET_BIT(EICRA,(2*ICU_Channel));
		SET_BIT(EICRA,((2*ICU_Channel)+1));
	}
	else
	{
		SET_BIT(EICRB,(2*(4-ICU_Channel)));
		SET_BIT(EICRB,((2*(4-ICU_Channel))+1));
	}

}
void ICU_FallingEdge(u8 ICU_Channel)
{
	if(ICU_Channel < 4)
	{
		CLR_BIT(EICRA,(2*ICU_Channel));
		SET_BIT(EICRA,((2*ICU_Channel)+1));
	}
	else
	{
		CLR_BIT(EICRB,(2*(4-ICU_Channel)));
		SET_BIT(EICRB,((2*(4-ICU_Channel))+1));
	}
}
