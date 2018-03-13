#bit B7 = 0x06.7
#bit B6 = 0x06.6
#bit B5 = 0x06.5
#byte TRISB = 0x86
#byte PORTB = 0x06
#bit B4 = 0x06.4
#bit RS = 0x06.3
#bit EN = 0x06.2
#byte TRISD = 0x88
#bit D0 = 0x08.0
#bit D1 = 0x08.1
#bit D2 = 0x08.2
#bit D3 = 0x08.3
#bit D4 = 0x08.4
#bit D5 = 0x08.5
#bit D6 = 0x08.6
#bit D7 = 0x08.7
#byte TRISC = 0x87
#bit C0 = 0x07.0
#bit C1 = 0x07.1
#bit C2 = 0x07.2
#bit C3 = 0x07.3
#bit C4 = 0x07.4
#bit C5 = 0x07.5
#bit C6 = 0x07.6
#bit C7 = 0x07.7
#byte PORTC = 0x07
int x, val, place, portb_val, value_to_send, bits_to_keep, toggle, hunds, tens, ones, ascii_hunds, ascii_tens, ascii_ones, adc_val;
int thous, tenthous, hundthous, mill, ascii_thous, ascii_tenthous, ascii_hundthous, ascii_mill;
void init_4 (void);
void set (int x);
void pulse (void);
void LCD_ON_4(void);
void split (int val);
void clear(void);
void string (char first);
void display (int place);
void RS (int toggle);
void bcd_conv (int32 bleh);
void printnumber (int32 bleh);
void printbignumber (int32 bleh);
void printdecnumber(int16 decimal_val);
void printadc(void);
int16 adc_val16, decimal_val;
int32 bleh;

void LCD_ON_4(void)
{
   RS(0);
   split(0x0C);
   RS(1);
}

void init_4(void)
{
   RS(0);
   set(0x30);
   set(0x30);
   set(0x30);
   set(0x20);
   split(0x28);
   RS(1);
}

void set(int x)
{
   TRISB = 0x00;
   portb_val = PORTB;
   bits_to_keep = portb_val & 0x0F;
   value_to_send = (x | bits_to_keep);
   PORTB = value_to_send;
   //delay_ms(50);
   delay_ms(5);
   pulse();
}

void pulse(void)
{
   portb_val = PORTB;
   bits_to_keep = portb_val & 0xFB;
   value_to_send = 0x04 | bits_to_keep;
   PORTB = value_to_send;
   delay_us(10);
   portb_val = PORTB;
   bits_to_keep = portb_val & 0xFB;
   value_to_send = 0x00 | bits_to_keep;
   PORTB = value_to_send;
   delay_us(10);
}


void split(int val)
{
   set(val & 0xF0);
   //delay_ms(1);
   set((val & 0x0F)<<4);
   //delay_ms(1);
}

void clear(void)
{
   RS(0);
   split(0x01);
   RS(1);
}

void string(char first)
{
   split(first);
}

void display(int place)
{
   RS(0);
   split(place | 0x80);
   RS(1);
}

void RS(int toggle)
{
   portb_val = PORTB;
   bits_to_keep = portb_val & 0xF7;
   value_to_send = (toggle<<3) | bits_to_keep;
   PORTB = value_to_send;
   delay_ms(50);
}

void bcd_conv(int32 bleh)
{
mill = 0;
hundthous = 0;
tenthous = 0;
thous = 0;
hunds = 0;
tens = 0;
ones = 0;
   while(bleh >= 1000000)
   {
   bleh = bleh - 1000000;
   mill++;
   }
      while(bleh >= 100000)
      {
      bleh = bleh - 100000;
      hundthous++;
      }
         while(bleh >= 10000)
         {
         bleh = bleh - 10000;
         tenthous++;
         }
            while(bleh >= 1000)
            {
            bleh = bleh - 1000;
            thous++;
            }
               while(bleh >= 100)
               {
               bleh = bleh - 100;
               hunds = hunds + 1;
               }
                  while(bleh >= 10)
                  {
                  bleh = bleh - 10;
                  tens = tens + 1;
                  }
                     while(bleh >= 1)
                     {
                     bleh = bleh - 1;
                     ones = ones + 1;
                     }
ascii_mill = mill | 0x30;
ascii_hundthous = hundthous | 0x30;
ascii_tenthous = tenthous | 0x30;
ascii_thous = thous | 0x30;
ascii_hunds = hunds | 0x30;
ascii_tens = tens | 0x30;
ascii_ones = ones | 0x30;
}

void printnumber(int32 bleh)
{
   bcd_conv(bleh);
   split(ascii_hunds);
   split(ascii_tens);
   split(ascii_ones);
}

void printbignumber(int32 bleh)
{
   bcd_conv(bleh);
   split(ascii_mill);
   split(ascii_hundthous);
   split(ascii_tenthous);
   split(ascii_thous);
   split(ascii_hunds);
   split(ascii_tens);
   split(ascii_ones);
}

void printadc(void)
{
   delay_ms(50);
   adc_val = read_adc();
   display(0x00);
   printnumber(adc_val);
   adc_val16 = adc_val;
   decimal_val = (adc_val16*100)/51;
   display(0x40);
   printdecnumber(decimal_val);
}

void printdecnumber(int16 decimal_val)
{
   bcd_conv(decimal_val);
   split(ascii_hunds);
   split(0x2E);
   split(ascii_tens);
   split(ascii_ones);
}

