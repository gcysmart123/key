#include "display.h"
#include "key.h"
#include "debug.h"
#include "delay.h"

#if DISPLAY 

unsigned char num = 1;
unsigned char code duanma[9] = { 0X00, 0X01, 0X03, 0X07, 0X0F, 0X01F, 0X03F, 0X07F, 0X0FF };// œ‘ æ∂Œ¬Î÷µ0~9

void display(unsigned char LED_H, unsigned char LED_L)
{
	P2 = 0X00;
	P1 = 0x7F;
	P2 = duanma[LED_H];

	DelayMs(10);

	P2 = 0X00;
	P1 = 0XBF;
	P2 = duanma[LED_L];

	DelayMs(10);
}
#endif