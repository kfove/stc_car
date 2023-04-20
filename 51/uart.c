#include "uart.h"
#include "display.h"
#include "delay.h"
#include "mcontrol.h"
#include "ultrasound.h"
unsigned char rec;
unsigned char control;
void uart_init()
{
    SCON = 0x50;
    PCON |= 0x00;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xFd;
    TH1 = 0xFd;
    ET1 = 0;
    TR1 = 1;
    EA = 1;
    ES = 1;
	PS = 1;
}
void uart() interrupt 4 
{
	rec =  SBUF;
	SBUF = rec;
	while(!TI);
	TI  = 0;
	RI =  0;
	if (rec == '0' || rec == '1' || rec == '9' || rec == '3' || rec == '7')
    {
        control = rec;
    }
    if (control == '0')
    {
		display(0);
		TR0 = 0;
        switch (rec)
        {
        case '5':
        {
            stopMove();
            break;
        }
        case '2':
        {
            moveForward();
            break;
        }
        case '8':
        {
            moveBack();
            break;
        }
        case '4':
        {
            moveLeft();
            break;
        }
        case '6':
        {
            moveRight();
            break;
        }
        default:
        {
            break;
        }
        }
    } else if(control == '1') {follow();} else if(control == '9')  {stopMove();display(9);TR0 = 0;} else if(control == '3') {TR0 = 0;stopMove();seek();} else if(control == '7') {display(7);away();}
}
void away()
{
	while(control == '7')
	{
		if(P3_4 ==  1 && P3_5 == 1) moveForward();
		else {
			Delay50ms();
			if(P3_4 == 0 && P3_5 == 1) {
				moveRight();
			}
			if(P3_4 == 1 && P3_5 == 0) {
				moveLeft();
			}
			if(P3_4 == 0 && P3_5 == 0) {
				moveRight();
			}
		}
}
	}
void seek()
{
	display(3);
	while(control == '3')
	{
		if(P3_6 ==  1 && P3_7 == 1) moveForward();
		if(P3_6 == 0 && P3_7 == 1) moveLeft();
		if(P3_6 == 1 && P3_7 == 0) moveRight();
		if(P3_6 == 0 && P3_7 == 0) stopMove();
		delay_ms(20);
	}
}
void follow()
{
	float len;
	while(control == '1')
	{
		len = soundlen();
		display((unsigned int)len % 10);
		if(len >=  12.0 && len <= 14) stopMove();
		else if(len > 25.0) stopMove();
		else if(len > 14.0 &&  len < 25.0) moveForward();
		else if(len < 12.0) moveBack();
		delay_ms(100);
	}
	display(1);
}