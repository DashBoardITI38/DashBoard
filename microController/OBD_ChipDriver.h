/*
 * OBD_ChipDriver.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef OBD_CHIPDRIVER_H_
#define OBD_CHIPDRIVER_H_

void OBD_init(void);
void OBD_task(void);
bool OBD_getSpeed(u16* speed);
bool OBD_getRPM(u16* rpm);
bool OBD_getFuel(u8* fuel);
bool OBD_getTransState(u8* transState);
#endif /* OBD_CHIPDRIVER_H_ */
