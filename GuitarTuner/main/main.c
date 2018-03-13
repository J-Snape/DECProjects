#include "./main.h"
#include "../MCU_Header.c"
#include "./freq.h"
#byte T1CON = 0x10
#byte OPTION = 0x81
#byte T1H = 0x0F
#byte T1L = 0x0E
#byte T0 = 0x01

int finish_flag;
int16 T1H_val, T1L_val, freq;
int32 T0COUNT;
int which, main_menu, done;
#int_TIMER0
void TIMER0_isr(void) 
{
	T0COUNT++;
}

void main()
{

	setup_adc_ports(NO_ANALOGS|VSS_VDD);
	setup_adc(ADC_OFF);
	setup_spi(FALSE);
	setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
	setup_timer_1(T1_DISABLED);
	setup_timer_2(T2_DISABLED,0,1);
	setup_comparator(NC_NC_NC_NC);
	setup_oscillator(False);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);

	OPTION = 0xA0;
	TRISD = 0xFF;
	TRISC = 0x01;
	T1CON = 0x03;//0x20;

	init_4(); //initializing LCD screen
	LCD_ON_4(); //Turns LCD on
	RS(0);
	split(0x0C);
	RS(1);
	printf(string("Hello!"));
	delay_ms(3000);
	display(0x00);
	printf(string("Please choose a"));
	display(0x40);
	printf(string("setting."));

	while(true)
	{
		top: //top label for goto at end of function
		done = 0; //resets done variable
		main_menu = 0; //resets main_menu variable
		which = 7; //sets which variable to value that will not trigger case
		PORTC = 0x00; 

		if(D6 == 1) //Drop D
		{
			clear();
			printf(string("Drop D"));
			delay_ms(3000);
			which = 6;
		}
		if(D5 == 1) //E
		{
			clear();
			printf(string("E"));
			delay_ms(3000);
			which = 5;
		}
		if(D4 == 1) //A
		{
			clear();
			printf(string("A"));
			delay_ms(3000);
			which = 4;
		}
		if(D3 == 1) //D
		{
			clear();
			printf(string("D"));
			delay_ms(3000);
			which = 3;
		}
		if(D2 == 1) //G
		{
			clear();
			printf(string("G"));
			delay_ms(3000);
			which = 2;
		}
		if(D1 == 1) //B
		{
			clear();
			printf(string("B"));
			delay_ms(3000);
			which = 1;
		}
		if(D0 == 1) //High E
		{
			clear();
			printf(string("High E"));
			delay_ms(3000);
			which = 0;
		}
		if(main_menu == 1) //if main menu button is pressed, goto top label
		{
			goto top;
		}

		show(which);

		if(done == 1) //if function has resolved and note has been tuned
		{
			clear();
			printf(string("Please choose a"));
			display(0x40);
			printf(string("setting."));
			delay_ms(100);
		}
	} //while true loop end
} //main function end