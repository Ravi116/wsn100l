
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>

#include<wiringPi.h>
#include<lcd.h>
#include <wiringSerial.h>

#define LCD_RS 28
#define LCD_E 29
#define LCD_D4 25
#define LCD_D5 24
#define LCD_D6 23
#define LCD_D7 22

void display(void);
void show_ip(void);
char data[20];
int lcd;
int main ()
{
  int fd ;
  int i = 0 ;
  wiringPiSetup();
  if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
    return 1 ;
  }
 if(lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0))
{
 fprintf(stderr,"LCD INIT FAIL\n");
}
// Loop, getting and printing characters
 show_ip();

  while(1)
  {
	int prev = i;
        data[i++] = serialGetchar (fd) ;
	if(data[prev] == '\n'){
			display();
			fflush(stdout);
			i = 0;
			}
  }
}

void show_ip(void)
{
	delay(10000);
   struct ifreq ifr;
    char array[] = "eth0";
    int n = socket(AF_INET, SOCK_DGRAM, 0);
    //Type of address to retrieve - IPv4 IP address
    ifr.ifr_addr.sa_family = AF_INET;
    //Copy the interface name in the ifreq structure
    strncpy(ifr.ifr_name , array , IFNAMSIZ - 1);
    ioctl(n, SIOCGIFADDR, &ifr);
    close(n);
    //display result
	lcdClear(lcd);
	lcdPosition(lcd,0,0);
	lcdPuts(lcd,"Ip Address:");
	lcdPosition(lcd,0,1);
        lcdPrintf(lcd," %s", inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr) );
	delay(10000);
	lcdClear(lcd);
}

void display(void)
{
int i = 0;
char lcd_buffer[20]={0};
char temp[10] = {0};
char hum[10] = {0};

strcpy(lcd_buffer,data);
for(i=0;i<15;i++)
	{
	if(lcd_buffer[i] == 'T')
		{
			//printf("i is %d",i);
			strncpy(hum,lcd_buffer,i-1);
			//printf("h is %d",strlen(hum));
			strncpy(temp,lcd_buffer+i,6);
		}
	}
//puts(data);

lcdClear(lcd);
lcdPuts(lcd," DHT SENSOR ");
delay(300);
lcdPosition(lcd,0,1);
lcdPrintf(lcd,"Humidity: %s%%",hum+2);
lcdPosition(lcd,1,0);
lcdPrintf(lcd,"Temp.: %s C",temp+2);
if(lcd> 0)
	lcd--;
//puts("out of display");
}
