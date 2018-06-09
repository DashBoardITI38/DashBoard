/*
 * ULS_Scanner.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Yasmin
 */

#ifndef ULS_SCANNER_H_
#define ULS_SCANNER_H_

#define RED_MAX_DIST 	1000
#define YELLOW_MAX_DIST 2000
#define GREEN_MAX_DIST 	3000
typedef enum
{
SECTOR_R=0,
SECTOR_Y,
SECTOR_G,
SECTOR_NON
}UlsScanner_tenumSectorInd;
typedef struct
{
UlsScanner_tenumSectorInd sector_R;
UlsScanner_tenumSectorInd sector_C;
UlsScanner_tenumSectorInd sector_L;
}UlsScanner_tStrMap;
void UlsScanner_init(void);
void UlsScanner_task(void);
bool UlsScanner_getMap(UlsScanner_tStrMap * map);

#endif /* ULS_SCANNER_H_ */
