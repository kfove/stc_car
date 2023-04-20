#include "buzzer.h"
#include "delay.h"
sbit buzzer  = P2^3;
void playOn()
{
	unsigned int t = 50000;
	while(t--)
	{
		delay_us(1000);
		buzzer = !buzzer;
	}
}
#include <REGX52.H>