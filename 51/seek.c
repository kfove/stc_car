#include "seek.h"
#include "display.h"
#include "mcontrol.h"
void seekInit(){
	TMOD &= 0xf0;
	TMOD |= 0x01;
	TF0 = 0;
	// TR0 = 1;
	TH0 = 0xb8;
	TL0 = 0x00;
	ET0 = 1;
	EA=  1;
	PT0 = 0;
}
void seekRun() interrupt 1
{
	TH0 = 0xdb;
	TL0 = 0xe2; // reset
	
	if(P3_6 ==  1 && P3_7 == 1) moveForward();
	if(P3_6 == 0 && P3_7 == 1) moveLeft();
	if(P3_6 == 1 && P3_7 == 0) moveRight();
	if(P3_6 == 0 && P3_7 == 0) stopMove();
	
	
}