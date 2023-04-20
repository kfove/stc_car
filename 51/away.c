#include "away.h"
void awayInit(){
	TMOD &= 0xf0;
	TMOD |= 0x01;
	TF0 = 0;
	TR0 = 1;
	TH0 = 0xb8;
	TL0 = 0x00;
	ET0 = 1;
	EA=  1;
	PT0 = 0;
}
void away()  interrupt 1 {
	if(P3_4 ==  1 && P3_5 == 1) moveForward();
	else {
		Delay50ms();
		if(P3_4 == 0 && P3_5 == 1) {
			moveLeft();
		}
		if(P3_4 == 1 && P3_5 == 0) {
			moveRight();
		}
		if(P3_4 == 0 && P3_5 == 0) {
			moveRight();
		}
	}
}
