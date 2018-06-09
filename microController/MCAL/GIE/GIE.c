/*
 * GIE.c
 *
 *  Created on: Feb 7, 2018
 *      Author: Yasmin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE.h"

#include "GIE_register.h"


void GIE_voidEnable(void){
SET_BIT(SREG,7);
}
void GIE_voidDisable(void){
CLR_BIT(SREG,7);
}

