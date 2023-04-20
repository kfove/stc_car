#include "ultrasound.h"
void soundinit(){
	TMOD  |= 0x01;
	TR0 = 0;
	TH0 = 0x00;
	TL0 = 0x00;
}
float soundlen(){
	float len;
	P2_0 = 0;
	P2_0 = 1;
	Delay10us();Delay10us();
	P2_0 = 0;
	while(!P2_1);
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;
	while(P2_1);
	TR0 = 0;
	len = (float)TH0  * 256  + TL0;
	return (len*0.00034/2) * 100;
}