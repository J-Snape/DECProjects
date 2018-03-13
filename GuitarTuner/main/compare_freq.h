#SEPARATE
void compare_dD (void);
#SEPARATE
void compare_E (void);
#SEPARATE
void compare_A (void);
#SEPARATE
void compare_D (void);
#SEPARATE
void compare_G (void);
#SEPARATE
void compare_B (void);
#SEPARATE
void compare_hE (void);

void compare_freq(int, int*);


compare_freq(int stabilityTime, int* freq)
{
	do
	{
		clear();
		do
		{
			if(T1L >= 0x3E/*0A*/)
			{
				delay_ms(3000);
				detect();
				finish_f(T1H_val, T1L_val);
			}
			if(D7 == 1)
			{
				main_menu = 1;
				done = 1;
				break;
			}
		}while(finish_flag == 0);

		finish_flag = 0;

		if(main_menu == 1) //if main menu button is pressed
		{
			goto end; //goes to the end label
		}
		
		if(freq <= (50))
		{
			C7 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 61) & (freq > 50))
		{
			C6 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq < 71) & (freq > 61))
		{
			C5 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 75) & (freq >= 71))
		{
			C4 = 1;
			done = 1;
			display(0x00);
			printf(string("Perfect!"));
			delay_ms(4000);
		}
		if((freq <= 85) & (freq > 75))
		{
			C3 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if((freq <= 95) & (freq > 85))
		{
			C2 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if(freq > 95)
		{
			C1 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		
		PORTC = 0;
		end: //end label
		;
	}while(done == 0);
}


#SEPARATE
void compare_dD (void) //compares frequency calculated to drop D
{
	do
	{
		clear();
		do
		{
			if(T1L >= 0x3E/*0A*/)
			{
				delay_ms(3000);
				detect();
				finish_f(T1H_val, T1L_val);
			}
			if(D7 == 1)
			{
				main_menu = 1;
				done = 1;
				break;
			}
		}while(finish_flag == 0);

		finish_flag = 0;

		if(main_menu == 1) //if main menu button is pressed
		{
			goto end; //goes to the end label
		}
		
		if(freq <= (50))
		{
			C7 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 61) & (freq > 50))
		{
			C6 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq < 71) & (freq > 61))
		{
			C5 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 75) & (freq >= 71))
		{
			C4 = 1;
			done = 1;
			display(0x00);
			printf(string("Perfect!"));
			delay_ms(4000);
		}
		if((freq <= 85) & (freq > 75))
		{
			C3 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if((freq <= 95) & (freq > 85))
		{
			C2 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if(freq > 95)
		{
			C1 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		
		PORTC = 0;
		end: //end label
		;
	}while(done == 0);
}

#SEPARATE
void compare_E (void)
{
	do
	{
		clear();
		do
		{
			if(T1L >= 0x3E/*0A*/)
			{
			delay_ms(4000);
			detect();
			finish_f(T1H_val, T1L_val);
		}
			if(D7 == 1)
			{
				main_menu = 1;
				done = 1;
				break;
			}
		}while(finish_flag == 0);
		
		finish_flag = 0;
		
		if(main_menu == 1)
		{
			goto end;
		}
		
		if(freq <= 60)
		{
			C7 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 70)& (freq > 60))
		{
			C6 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq < 80)& (freq > 70))
		{
			C5 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		if((freq <= 84)& (freq >= 80))
		{
			C4 = 1;
			done = 1;
			display(0x00);
			printf(string("Perfect!"));
			delay_ms(4000);
		}
		if((freq <= 94)& (freq > 84))
		{
			C3 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if((freq <= 104)& (freq > 94))
		{
			C2 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		if(freq > 104)
		{
			C1 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		
		PORTC = 0;
		end:
		;
	}while(done == 0);
}

#SEPARATE
void compare_A (void)
{
do
{
clear();
do
{
if(T1L >= 0x3E/*0A*/)
{
delay_ms(2000);
detect();
finish_f(T1H_val, T1L_val);
}
}while(finish_flag == 0);
if(D7 == 1)
{
main_menu = 1;
done = 1;
break;
}
finish_flag = 0;
if(main_menu == 1)
{
goto end;
}
if(freq <= 88)
{
C7 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 98)& (freq > 88))
{
C6 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq < 108)& (freq > 98))
{
C5 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 112)& (freq >= 108))
{
C4 = 1;
done = 1;
//clear();
display(0x00);
printf(string("Perfect!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 122)& (freq > 112))
{
C3 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 132)& (freq > 122))
{
C2 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if(freq > 132)
{
C1 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
PORTC = 0;
end:
;
}while(done == 0);
}

#SEPARATE
void compare_D (void)
{
do
{
clear();
do
{
if(T1L >= 0x3E/*0A*/)
{
delay_ms(1750);
detect();
finish_f(T1H_val, T1L_val);
}
if(D7 == 1)
{
main_menu = 1;
done = 1;
break;
}
}while(finish_flag == 0);
finish_flag = 0;
if(main_menu == 1)
{
goto end;
}
if(freq <= 125)
{
C7 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 135)& (freq > 125))
{
C6 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq < 145)& (freq > 135))
{
C5 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 149)& (freq >= 145))
{
C4 = 1;
done = 1;
//clear();
display(0x00);
printf(string("Perfect!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 159)& (freq > 149))
{
C3 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 169)& (freq > 159))
{
C2 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if(freq > 169)
{
C1 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
PORTC = 0;
end:
;
}while(done == 0);
}

#SEPARATE
void compare_G (void)
{
do
{
clear();
do
{
if(T1L >= 0x96/*3E/*0A*/)
{
delay_ms(2313);
detect();
finish_f(T1H_val, T1L_val);
}
if(D7 == 1)
{
main_menu = 1;
done = 1;
break;
}
}while(finish_flag == 0);
finish_flag = 0;
if(main_menu == 1)
{
goto end;
}
if(freq <= 174)
{
C7 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 184)& (freq > 174))
{
C6 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq < 194)& (freq > 184))
{
C5 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 198)& (freq >= 194))
{
C4 = 1;
done = 1;
//clear();
display(0x00);
printf(string("Perfect!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 208)& (freq > 198))
{
C3 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 218)& (freq > 208))
{
C2 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if(freq > 218)
{
C1 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
PORTC = 0;
end:
;
}while(done == 0);
}

#SEPARATE
void compare_B (void)
{
do
{
clear();
do
{
if(T1L >= 0x3E)
{
delay_ms(300);
detect();
finish_f(T1H_val, T1L_val);
}
if(D7 == 1)
{
main_menu = 1;
done = 1;
break;
}
}while(finish_flag == 0);
finish_flag = 0;
if(main_menu == 1)
{
goto end;
}
if(freq <= 225)
{
C7 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 235)& (freq > 225))
{
C6 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq < 245)& (freq > 235))
{
C5 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 249)& (freq >= 245))
{
C4 = 1;
done = 1;
//clear();
display(0x00);
printf(string("Perfect!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 259)& (freq > 249))
{
C3 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 269)& (freq > 259))
{
C2 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if(freq > 269)
{
C1 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
PORTC = 0;
end:
;
}while(done == 0);
}

#SEPARATE
void compare_hE (void)
{
do
{
clear();
do
{
if(T1L >= 0x3E/*0A*/)
{
delay_ms(5);
detect();
finish_f(T1H_val, T1L_val);
}
if(D7 == 1)
{
main_menu = 1;
done = 1;
break;
}
}while(finish_flag == 0);
finish_flag = 0;
if(main_menu == 1)
{
goto end;
}
if(freq <= 308)
{
C7 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 318)& (freq > 308))
{
C6 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq < 328)& (freq > 318))
{
C5 = 1;
//clear();
display(0x00);
printf(string("Tighter!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 332)& (freq >= 328))
{
C4 = 1;
done = 1;
//clear();
display(0x00);
printf(string("Perfect!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 342)& (freq > 332))
{
C3 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if((freq <= 352)& (freq > 342))
{
C2 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
if(freq > 352)
{
C1 = 1;
//clear();
display(0x00);
printf(string("Looser!"));
//display(0x40);
//printnumber(freq);
//printf(string(" Hz"));
delay_ms(4000);
}
PORTC = 0;
end:
;
}while(done == 0);
}
