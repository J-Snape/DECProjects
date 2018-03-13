#include <16F887.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz)
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOMCLR                   //Master Clear pin used for I/O
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOCPD                    //No EE protection
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOWRT                    //Program memory not write protected
#FUSES BORV40                   //Brownout reset at 4.0V

#use delay(clock=20000000,RESTART_WDT)
#use rs232(baud=9600,parity=N,xmit=PIN_E3,rcv=PIN_E2,bits=8)//#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

void show(int which);
void reset(void);

void reset(void) //resets count variables
{
	T0 = 0;
	T0COUNT = 0;
	//set_timer1(0);
	T1H = 0;
	T1L = 0;
}

void show (int which) //determines the necessary frequency comparison function for the button pressed
{ 
	switch(which)
	{
		case 6: reset(); compare_dD();
		break;
		case 5: reset(); compare_E();
		break;
		case 4: reset(); compare_A();
		break;
		case 3: reset(); compare_D();
		break;
		case 2: reset(); compare_G();
		break;
		case 1: reset(); compare_B();
		break;
		case 0: reset(); compare_hE();
		break;
	}
}
