#include "debug.h"
#include "key.h"

#if  KEY
unsigned char H, L;
unsigned char Trg = 0;
unsigned char Cont = 0;
unsigned int  cnt_plus;
unsigned char key_up;
unsigned char key_down;
unsigned char key_up_2;
unsigned char key_down_2;
bit key_up_cnt = 0;
bit key_down_cnt = 0;
bit key_up_2_cnt = 0;
bit key_down_2_cnt = 0;

void Key(void)
{
	

	if (key_up == 3)  // 如果按下的是key_up
	{
		L++;
		key_up = 0;
		if (L>8)
		{
			if (H == 8)
			{
				H = 0;
				L = 0;
			}
			else
			{
				H++;
				L = 0;
			}

		}			
	}
	if (key_down==3)  // 如果按下的是key_down
	{
		key_down = 0;
			if (L == 0)
			{
				if (H == 0)
				{
					H = 8;
					L = 8;
				}
				else
				{
					L = 8;
					H--;
				}
			}
			else
			{
				L--;
			}
	}
	if (key_up_2==3)  // 如果按下的是key_up_2
	{
		key_up_2 = 0;
			if (H == 8)
			{
				H = 0;
			}
			else
			{
				H++;
			}
	}
	if (key_down_2==3)  // 如果按下的是key_down_2
	{
		key_down_2 = 0;
			if (H == 0)
			{
				H = 8;
				//L = 8;
			}
			else
			{
				H--;
			}			
	}
	if (key_up_cnt)  // 如果按下的是key_up
	{
		key_up_cnt = 0;
		L++;
		key_up = 0;
		if (L>8)
		{
			if (H == 8)
			{
				H = 0;
				L = 0;
			}
			else
			{
				H++;
				L = 0;
			}

		}
	}
	if (key_up_2_cnt)  // 如果按下的是key_up
	{
		key_up_2_cnt = 0;
		key_up_2 = 0;
		if (H == 8)
		{
			H = 0;
		}
		else
		{
			H++;
		}
	}
	if (key_down_cnt)  // 如果按下的是key_up
	{
		key_down_cnt = 0;
		key_down = 0;
		if (L == 0)
		{
			if (H == 0)
			{
				H = 8;
				L = 8;
			}
			else
			{
				L = 8;
				H--;
			}
		}
		else
		{
			L--;
		}
	}
	if (key_down_2_cnt)  // 如果按下的是key_up
	{
		key_down_2_cnt = 0;
		key_down_2 = 0;
		if (H == 0)
		{
			H = 8;
		//	L = 8;
		}
		else
		{
			H--;
		}
	}
}

void KeyRead(void)

{

	unsigned char ReadData = P3^ 0xff;     // 1 

	Trg = ReadData & (ReadData ^ Cont);    // 2 

	Cont = ReadData;                        // 3

		switch (Trg)
		{
		case 0X80:
			key_up++;
			if (key_up < 3)
			{
				Cont = 0x00;
			}
			break;
		case 0X40:
			key_down++;
			if (key_down < 3)
			{
				Cont = 0x00;
			}
			break;
		case 0X20:
			key_up_2++;
			if (key_up_2 < 3)
			{
				Cont = 0x00;
			}
			break;
		case 0X08:
			key_down_2++;
			if (key_down_2 < 3)
			{
				Cont = 0x00;
			}
			break;
		default:
			break;
		}
		switch (Cont)
		{
		case 0x80:
			cnt_plus++;
			if (cnt_plus>300)
			{
				if (cnt_plus % 20 == 0)
				{
					key_up_cnt = 1;
				}
			}
			break;
		case 0x40:
			cnt_plus++;
			if (cnt_plus>300)
			{
				if (cnt_plus % 20 == 0)
				{
					key_down_cnt = 1;
				}
			}
			break;
		case 0x20:
			cnt_plus++;
			if (cnt_plus>300)
			{
				if (cnt_plus % 20 == 0)
				{
					key_up_2_cnt = 1;
				}
			}
			break;
		case 0x08:
			cnt_plus++;
			if (cnt_plus>300)
			{
				if (cnt_plus % 20 == 0)
				{
					key_down_2_cnt = 1;
				}
			}
			break;
		default:
			cnt_plus = 0;
			break;
		}
	//	return key_up;
}

#endif