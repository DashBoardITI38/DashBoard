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
/*		0		Longiude	4
 * 		1		Latiude 	4
 * 		2		Time		3
 * 		3		Speed		2
 * 		4		Date		4
 * 		5		PaData		3
 * 		6		OBDSpeed	1
 * 		7		RPM			1
 * 		8		FUel		1
 * 		9		TransState	1
 *
 */
#endif /* EXCHANGER_H_ */
