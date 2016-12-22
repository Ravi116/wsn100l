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
;||	Title		: sensor1_lm35.ino 														
;||	Status		: Completed!															
;||	Features	: 							
;||	Description	: LM35 temperature sensor 												
;||				  Oscillator	 :	16MHz 							
;||	                    																								 ||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
/***********************************************************************************************/
#include"wsn100ltx.h"
#include<LiquidCrystal.h>
#include <Wire.h>
#include <BMP085.h>
/////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************** Object and Function init **********************************
wsn100ltx wsn;
BMP085 bmp;
LiquidCrystal lcd(7,6,5,4,3,2);
const int BUZ = 11;
 const int DS = 13;
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
////////////////////////////////////////// Sensor reading Display and Send ///////////////////////////
void displayAndSend(int input)
{
    lcd.clear();
    Serial.print("SENSOR-7 : BMP085*");
    
    lcd.setCursor(0,0);
    lcd.print("SENSOR-7 : BMP085");
    
    Serial.print("Pressure =");
    int temp=bmp.readPressure();
    Serial.print(temp);
    Serial.print(" Pa*");
    
    lcd.setCursor(0,1);
    lcd.print("Pressure =");
    lcd.print(temp);
    lcd.print(" Pa");
    
    Serial.print("Alt.=");
    int temp1=bmp.readAltitude();
    Serial.print(temp1);
    Serial.print(" mtr*");
    
    lcd.setCursor(0,2);
    lcd.print("Alt.=");
    lcd.print(temp1);
    lcd.print(" mtr");
    
    Serial.print("R alt.=");
    int temp3 = bmp.readAltitude(101500);
    Serial.print(temp3);
    Serial.print( " mtr*");
    
    lcd.setCursor(0,3);
    lcd.print("R alt.=");
    lcd.print(temp3);
    lcd.print( " mtr");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************** setup *****************************************************
void setup()
{
  Serial.begin(9600);
  init_lcd();
  wsn.init_sensor7_bmp();
  
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
  displayAndSend(1);
  delay(2000);
}
//************************************************** end main loop **********************************************
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@