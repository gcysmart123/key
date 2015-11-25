#ifndef __TIMER_0_H__
#define __TIMER_0_H__

#include "stc15.h"

typedef unsigned char BYTE;
typedef unsigned int WORD;

#define FOSC 12000000L

//#define T1MS (65536-FOSC/1000)      //1Tģʽ
#define T1MS (65536-10000) //12Tģʽ


//sfr AUXR = 0x8e;                    //Auxiliary register
//sbit P10 = P1 ^ 0;
extern void timer_0_init();
#endif
