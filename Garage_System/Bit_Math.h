#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(n,Reg) (Reg|=(1<<n))
#define GET_BIT(n,Reg) ((Reg>>n)&1)
#define CLR_BIT(n,Reg) (Reg&=~(1<<n))
#define TOGG_BIT(n,Reg) (Reg^=(1<<n))


#define OK  1
#define NOK  0

#define IDLE   1
#define BUSY   2

#define BUSY_FUNC   3

#define NULL    0

#endif
