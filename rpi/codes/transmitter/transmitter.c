#include <wiringPi.h>  
#include <wiringSerial.h>
#include <lcd.h>                //LCD headers from WiringPi 

#include <stdio.h>  
#include <stdlib.h> 
#include <stdint.h>  
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <unistd.h>
#include <arpa/inet.h>

//Pin numbers below are the WiringPi pin numbers
 
#define LCD_RS 29              //Register select pin
#define LCD_E  28               //Enable Pin
#define LCD_D4 21               //Data pin 4
#define LCD_D5 22               //Data pin 5
#define LCD_D6 23               //Data pin 6
#define LCD_D7 24               //Data pin 7
 
int lcd;                //Handle for LCD
int fd ;		//fd for serial

#define MAX_TIME 85  
#define DHT11PIN 25
#define LM35PIN 24
int dht11_val[5]={0,0,0,0,0};  
  
void serial_send(void)
{
    	if ((fd = serialOpen ("/dev/ttyAMA0", 9600)) < 0)
  	{
    		//fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
		lcdClear(lcd);
		lcdPosition(lcd,0,1);
    		lcdPuts(lcd,"Ser.open Fail");
	}
	
       	serialPrintf(fd,"H %d.%d T %d.%d\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3]);  
	
}

void dht11_read_val()  
{  
  uint8_t lststate=HIGH;  
  uint8_t counter=0;  
 uint8_t j=0,i;   
  //float farenheit;  
  for(i=0;i<5;i++)  
     dht11_val[i]=0;  
  pinMode(DHT11PIN,OUTPUT);  
  digitalWrite(DHT11PIN,LOW);  
  delay(18);  
  digitalWrite(DHT11PIN,HIGH);  
  delayMicroseconds(40);  
  pinMode(DHT11PIN,INPUT);  
  for(i=0;i<MAX_TIME;i++)  
  {  
    counter=0;  
    while(digitalRead(DHT11PIN)==lststate){  
      counter++;  
      delayMicroseconds(1);  
      if(counter==255)  
        break;  
    }  
    lststate=digitalRead(DHT11PIN);  
    if(counter==255)  
       break;  
    // top 3 transistions are ignored  
    if((i>=4)&&(i%2==0)){  
      dht11_val[j/8]<<=1;  
      if(counter>16)  
        dht11_val[j/8]|=1;  
      j++;  
    }  
  }  
  // verify cheksum and print the verified data  
  if((j>=40)&&(dht11_val[4]==((dht11_val[0]+dht11_val[1]+dht11_val[2]+dht11_val[3])& 0xFF)))  
  {  
    //farenheit=dht11_val[2]*9./5.+32;  
    
    //printf("Humidity = %d.%d %% Temperature = %d.%d *C (%.1f *F)\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3],farenheit);  
 	 
	lcdClear(lcd);
	lcdPosition(lcd,0,1);
    	lcdPrintf(lcd,"Humidity = %d.%d",dht11_val[0],dht11_val[1]); 
	lcdPosition(lcd,1,0);
   	lcdPrintf(lcd,"Temp. = %d.%d",dht11_val[2],dht11_val[3]); 
	serial_send(); 
     	delay(3000);  
  
 } 
/*	else  {
    	printf("Invalid Data!!\n");  
	lcdPosition(lcd,0,1);
    	lcdPrintf(lcd,"Invalid Data!!");} */
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

int main(void)  
{  
  

  if (wiringPiSetup () == -1)
  {
    //fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
    lcdClear(lcd);
	lcdPosition(lcd,0,1);
	lcdPuts(lcd,"Error:start wiringPi");
	return 1 ;
  }

  //printf("Interfacing Temperature and Humidity Sensor (DHT11) With Raspberry Pi\n");  
	
 //Initialise LCD(int rows, int cols, int bits, int rs, int enable, int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7)
    if (lcd = lcdInit (2, 16,4, LCD_RS, LCD_E ,LCD_D4 , LCD_D5, LCD_D6,LCD_D7,0,0,0,0)){
	
            printf ("lcdInit failed! \n");
            return -1 ;
    } 
	
     show_ip();
  while(1)  
  { 
	lcdClear(lcd);
    	lcdPosition(lcd,0,0);           //Position cursor on the first line in the first column
    	lcdPuts(lcd, "DHT11 SENSOR");  //Print the text on the LCD at the current cursor postion
    	delay(3000); 
     	dht11_read_val(); 
	delay(3000);
	}  
  return 0;  
}  
