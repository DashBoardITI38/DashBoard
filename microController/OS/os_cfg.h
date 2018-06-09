/*
 * os_cfg.h
 *
 *  Created on: Mar 8, 2018
 *      Author: Administrator
 */

#ifndef OS_CFG_H_
#define OS_CFG_H_
typedef struct {
	void (*pfTask)(void);
	u16 periodicity;
}os_cfg_t;
extern const os_cfg_t os_cfg[];


#endif /* OS_CFG_H_ */
