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
void EXTI_voidInitialization(void)
{
SET_BIT(MCUCR,0);/*set EXTI to be IOC*/

CLR_BIT(MCUCR,1);
CLR_BIT(GICR,6);/*set EXTI to be IOC*/

SET_BIT(GIFR,6);
}

void EXTI_voidEnable(void){
SET_BIT(GICR,6);
}
void EXTI_voidDisable(void){
CLR_BIT(GICR,6);
}
void EXTI_voidSetFallingEdge(void)
{
CLR_BIT(MCUCR,0);
SET_BIT(MCUCR,1);
}
void EXTI_voidSetRisingEdge(void)
{
SET_BIT(MCUCR,0);
SET_BIT(MCUCR,1);
}