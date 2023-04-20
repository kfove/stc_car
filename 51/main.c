#include <REGX52.H>
#include "mcontrol.h"
#include "delay.h"
#include "display.h"
#include "seek.h"
#include "uart.h"
#include "ultrasound.h"
void main()
{	
	//seekInit();
	uart_init();
	soundinit();
	while(1)
	{
		//follow();
	}		
}

