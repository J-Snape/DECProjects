void detect(void);
void calc(int16 T1H_val, T1L_val);
void finish_f (int16 T1H_val, T1L_val);

void compare_freq(int16, int*);

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


compare_freq(int16 stabilityTime, int16 frequencyTable[6])
{
	do
	{
		clear();
		do
		{
			if(T1L >= 0x3E)
			{
				delay_ms(stabilityTime);
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
		
		if(freq <= frequencyTable[0])
		{
			C7 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		else if(freq <= frequencyTable[1])
		{
			C6 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		else if(freq < frequencyTable[2])
		{
			C5 = 1;
			display(0x00);
			printf(string("Tighter!"));
			delay_ms(4000);
		}
		else if(freq <= frequencyTable[3])
		{
			C4 = 1;
			done = 1;
			display(0x00);
			printf(string("Perfect!"));
			delay_ms(4000);
		}
		else if(freq <= frequencyTable[4])
		{
			C3 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		else if(freq <= frequencyTable[5])
		{
			C2 = 1;
			display(0x00);
			printf(string("Looser!"));
			delay_ms(4000);
		}
		else
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
	int16 table[6] = {50, 61, 71, 75, 85, 95};
	compare_freq(3000, table);
}

#SEPARATE
void compare_E (void)
{
	int16 table[6] = {60, 70, 80, 84, 94, 104};
	compare_freq(4000, table);
}

#SEPARATE
void compare_A (void)
{
	int16 table[6] = {88, 98, 108, 112, 122, 132};
	compare_freq(2000, table);
}

#SEPARATE
void compare_D (void)
{
	int16 table[6] = {125, 135, 145, 149, 159, 169};
	compare_freq(1750, table);
}

#SEPARATE
void compare_G (void)
{
	int16 table[6] = {174, 184, 194, 198, 208, 218};
	compare_freq(2313, table);
}

#SEPARATE
void compare_B (void)
{
	int16 table[6] = {225, 235, 245, 249, 259, 269};
	compare_freq(300, table);
}

#SEPARATE
void compare_hE (void)
{
	int16 table[6] = {308, 318, 328, 332, 342, 352};
	compare_freq(5, table);
}

void finish_f(int16 T1H_val, int16 T1L_val) //finishing function to calculate frequencies
{
	calc(T1H_val, T1L_val); //calculates frequencies
	delay_ms(100);
	finish_flag = 1;
	display(0x40);
	printnumber(freq);
	printf(string(" Hz"));
	delay_ms(4000);
	reset();
}

void calc (int16 T1H_val, T1L_val) //calculates frequencies
{
	freq = (((T1H_val<<8) | T1L_val));
}

void detect (void) //function to detect input frequency
{
	do //endless T1L loop only exits when string is plucked
	{
		OPTION = 0xA0; //resets count variables
		T0 = 0;
		T0COUNT = 0;
		T1H = 0;
		T1L = 0;
		T1CON = 0x03;
		OPTION = 0x80;

		do
		{
			if(D7 == 1) //if main menu button is pressed
			{
				main_menu = 1; //sets main_menu variable for future use
				done = 1; //sets done variable for future use
				break; //ejects from endless while loop
			}
		}while(T0COUNT < 0x264E);

		//T1CON = 0x02;
		OPTION = 0xA0;

		if(main_menu == 1) //if main_menu button was pressed
		{
			break; //ejects from endless T1L loop
		}

	}while(T1L < 0x3F);

	if(main_menu == 1) //if main_menu button was pressed
	{
		break; //ejects from detect function
	}

	if(T0COUNT == 0x264E)
	{
		T1H_val = T1H;
		T1L_val = T1L;
	}
}