#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(reg,bitnum) reg |=(1<<bitnum)
#define CLR_BIT(reg,bitnum) reg &=~(1<<bitnum)
#define TOGGLE_BIT(reg,bitnum) reg^=(1<<bitnum)
#define GET_BIT(reg,bitnum)  (((reg)>>(bitnum))&(0x01))

#define CIRSHLEFT(reg,numberOfShifts)  (reg)=(((reg)<<(numberOfShifts))|(((reg)>>((sizeof((reg))*8)-(numberOfShifts)))))
#define CIRSHRIGHT(reg,numberOfShifts)  (reg)=(((reg)>>(numberOfShifts))|(((reg)<<((sizeof(reg)*8)-(numberOfShifts)))))


#define BIT_CONC(B7,B6,B5,B4,B3,B2,B1,B0)  CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0
u32 po(u8 base,u8 power);
void decToAscii(u32 num,u8 *str,u8* len);
void NumToAscii (u32 num1,u8 * array , u8* length,u8 op);

#endif
