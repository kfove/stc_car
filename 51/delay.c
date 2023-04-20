#include "delay.h"

void delay_us(unsigned int t)
{
	for(;t > 0;t--);
}
void delay_ms(unsigned int t)
{
	unsigned int  j;
	for(;t>0;t--)
		for(j = 110;j>0;j--);
}
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}
void Delay50ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 90;
	j = 163;
	do
	{
		while (--j);
	} while (--i);
}
void Delay10us()		//@11.0592MHz
{
	unsigned char i;

	i = 2;
	while (--i);
}