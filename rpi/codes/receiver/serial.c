#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <lcd.h>                //LCD headers from WiringPi
#include <wiringPi.h>           //WiringPi headers

#include <wiringSerial.h>
#define MAXSIZE 15 
int lcd;                //Handle for LCD
char data[MAXSIZE] = {'0'};

//Pin numbers below are the WiringPi pin numbers
 
#define LCD_RS 28              //Register select pin
#define LCD_E  29               //Enable Pin
#define LCD_D4 25               //Data pin 4
#define LCD_D5 24               //Data pin 5
#define LCD_D6 23               //Data pin 6
#define LCD_D7 22               //Data pin 7

void display(void)
{
	lcdPosition(lcd,0,0);           //Position cursor on the first line in the first column
    	lcdPuts(lcd,"DHT Sensor");  //Print the text on the LCD at the current cursor postion
	delay(1000);
	lcdClear(lcd);
	lcdPosition(lcd,0,1);
	lcdPrintf(lcd,"%.*s",5,data);
	delay(100);
	lcdPosition(lcd,1,0);
	lcdPrintf(lcd,"%.*s",13,data+8);
	delay(100);
	}

int main ()
{
    wiringPiSetup();        //Initialise WiringPi
 
    //Initialise LCD(int rows, int cols, int bits, int rs, int enable, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
    if (lcd = lcdInit (2, 16,4, LCD_RS, LCD_E ,LCD_D4 , LCD_D5, LCD_D6,LCD_D7,0,0,0,0)){
            printf ("lcdInit failed! \n");
            return -1 ;
    }

  int fd ;
	int i = 0;

  if ((fd = serialOpen ("/dev/ttyS0",9600) ) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }

// Loop, getting and printing characters

   for(;;)
  {
  data[i++] = serialGetchar(fd) ;
	
	if(i == 17){
		display();
		i = 0;
		puts(data);
		fflush (stdout);
		
		}
  
  }

	
}
