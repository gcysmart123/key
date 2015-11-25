#ifndef __KEY_H__
#define __KEY_H__

#include "STC15.h"
extern void key(); 
extern void KeyRead(void);

//#define key_up		0x80
//#define key_down	0x40
//#define key_up_2	0x20
//#define key_down_2	0x04

extern unsigned char H, L;
extern unsigned char Trg;
extern unsigned char Cont;

#endif
