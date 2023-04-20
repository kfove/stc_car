#include"mcontrol.h"

void moveForward()
{
	P1 &= 0xc3;
	P1 |= 0x14;
}
void moveBack()
{
	P1 &= 0xc3;
	P1 |= 0x28;
	
}
void moveLeft()
{
	P1 &= 0xc3;
	P1 |= 0x18;
}

void moveRight()
{
	P1 &= 0xc3;
	P1 |= 0x24;
}
void turnLeft()
{
	P1 &= 0xc3;
	P1 |= 0x10;
}
void turnRight()
{
	P1 &= 0xc3;
	P1 |= 0x04;
}
void stopMove()
{
	P1 &= 0xc3;
	P1 |= 0x00;
}
