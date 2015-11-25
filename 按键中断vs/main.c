#include "stc15.h"
#include "debug.h"
#include "timer_0.h"
#include "key.h"
#include "display.h"

void main()
{
#if TIMER_0
	timer_0_init();
#endif

		P1M1 = 0X00;
		P1M0 = 0XFF;

		P2M1 = 0X00;
		P2M0 = 0XFF;

		P1 = 0X00;
		P2 = 0X00;

		H = 1;
		L = 2;

		while (1)
		{
			key();
			display(H,L);
		}
}