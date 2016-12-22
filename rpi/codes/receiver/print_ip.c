#include<wiringPi.h>
#include<lcd.h>

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>

// pin numbers below are the wiringPi pinnumbers

#define LCD_RS 28
#define LCD_E 29
#define LCD_D4 25
#define LCD_D5 24
#define LCD_D6 23
#define LCD_D7 22

int main()
{
    int n;
    wiringPiSetup();
   int lcd;
   if(lcd = lcdInit(2,16,4,LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7,0,0,0,0))
	{
	 fprintf(stderr,"LCD INIT FAIL\n");
	}
    struct ifreq ifr;
    char array[] = "eth0";
    n = socket(AF_INET, SOCK_DGRAM, 0);
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
    return 0;
}
