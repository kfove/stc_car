#include"mcontrol.h"

void moveForward()
{
	P1 &= 0xc3;
	P1 |= 0x14;
}
void move_Back()
{
	P1 &= 0xc3;
	P1 |= 0x28;
	
}
void move_Left()
{
	P1 &= 0xc3;
	P1 |= 0x18;
}

void move_Right()
{
	P1 &= 0xc3;
	P1 |= 0x24;
}
void turn_Left()
{
	P1 &= 0xc3;
	P1 |= 0x10;
}
void turn_Right()
{
	P1 &= 0xc3;
	P1 |= 0x04;
}