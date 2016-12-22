/***********************************************************************************************
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
;||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	Important Note ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||;
;||~																						~||;
;||~		This part of the software coding is the sole property of the company!			
;||~		Any unauthorized re-usage or transformation of this code is prohibited.			
;||~																						~||;
;||~				  Sigma Trainers and Kits. | All rights Reserved				
;||~																						~||;
;||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||;
;||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
;||																							 ||;
;||	Title		: senosr3_dhtino 														
;||	Status		: Completed!															
;||	Features	: 							
;||	Description	: dht11/humidity-temperature senosr   												
;||				  Oscillator	 :	16MHz 							
;||	                    																								 ||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
/***********************************************************************************************/
#include"wsn100ltx.h"
#include<LiquidCrystal.h>
#include "dht.h"
#include<Wire.h>
/////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************** Object and Function init **********************************
wsn100ltx wsn;
dht DHT;
LiquidCrystal lcd(7,6,5,4,3,2);
const int BUZ = 11;
const int DS = 13;
#define DHT11_PIN A2
#define BUZZER
#define DATA_STATUS
////////////////////////////////////// LCD init /////////////////////////////////////////////////
void init_lcd()
{
    lcd.begin(20,4);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   SIGMA TRAINERS  ");
    lcd.setCursor(0,1);
    lcd.print("         &         ");
    lcd.setCursor(0,2);
    lcd.print("        KITS       ");
    lcd.setCursor(0,3);
    lcd.print("       WSN100L     ");
    delay(2000);
    lcd.clear();
}
////////////////////////////////////////////////////////// DHT sensor Status ///////////////////////////////////
void chk_dht()
{
int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK*"); 
                lcd.setCursor(0,1);
                lcd.print("Sensor Status= ");
                lcd.print("OK");
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("error*"); 
                lcd.setCursor(0,1);
                lcd.print("Sensor Status= ");
                lcd.print("error");
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("error*"); 
                lcd.setCursor(0,1);
                lcd.print("Sensor Status= ");
                lcd.print("error");
		break;
    default: 
		Serial.print("error*");
                lcd.setCursor(0,1);
                lcd.print("Sensor Status= ");
                lcd.print("error");
		break;
  }
}

//////////////////////////////////////////////read dht sensor /////////////////////////////////////////////
void read_dht()
{
  Serial.print(DHT.humidity, 1);
  lcd.setCursor(0,2);
  lcd.print("Humidity(RH%)=");
  lcd.print(DHT.humidity, 1);
}
  
////////////////////////////////////////// Sensor reading Display and Send ///////////////////////////
void displayAndSend(int input)
{
    lcd.clear();
    Serial.print("SENSOR-3 : Humidity*");
    
    lcd.setCursor(0,0);
    lcd.print("SENSOR-3 : Humidity");
    
    Serial.print("Sensor Status= ");
    delay(100);
    chk_dht();
   
    
    Serial.print("Humidity(RH%)=");
    read_dht();
    Serial.print("*");
    
    Serial.print("--*");
    
    lcd.setCursor(0,3);
    lcd.print("--");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************** setup *****************************************************
void setup()
{
  Serial.begin(9600);
  init_lcd();
  wsn.init_sensor2_cm();
  
  #ifdef BUZZER
    pinMode(BUZ,OUTPUT);
    digitalWrite(BUZ,LOW);
  #endif
  #ifdef DATA_STATUS
    pinMode(DS,OUTPUT);
    digitalWrite(DS,HIGH);
   #endif  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************** main loop **************************************************
void loop()
{
  displayAndSend(3);
  delay(2000);
}
//************************************************** end main loop **********************************************
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@