/*
 * exchanger.h*
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef EXCHANGER_H_
#define EXCHANGER_H_

void EXCHANGER_init(void);

void EXCHANGER_task(void);



////////ID/////Name///////BYTES
/*		0		Longiude	4+(1 Direction)
 * 		1		Latiude 	4+(1 Direction)
 * 		2		Time		3
 * 		3		Date		3
 * 		4		PaData		3
 * 		5		OBDSpeed	1
 * 		6		RPM			1
 * 		7		FUel		1
 * 		8		TransState	1
 *
 */
#endif /* EXCHANGER_H_ */
