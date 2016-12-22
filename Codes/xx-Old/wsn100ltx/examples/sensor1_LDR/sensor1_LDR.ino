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
;||	Title		: sensor1_ldr.ino 														
;||	Status		: Completed!															
;||	Features	: 							
;||	Description	: Light sensor  												
;||				  Oscillator	 :	16MHz 							
;||	                    																								 ||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
/***********************************************************************************************/
#include"wsn100ltx.h"
#include<Wire.h>
#include<LiquidCrystal.h>
/////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************** Object and Function init **********************************
wsn100ltx wsn;
LiquidCrystal lcd(6,7,8,9,10,11);
const int BUZ = 11;
 const int DS = 13;
#define BUZZER
#define DATA_STATUS
////////////////////////////////////// LCD init /////////////////////////////////////////////////
void init_lcd()
{
    lcd.begin(16,2);
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
    Serial.print("SENSOR-1 : LDR*");
    
    lcd.setCursor(0,0);
    lcd.print("SENSOR-1 : LDR");
    
    int val =map(input,0,1023,0,100);
    Serial.print("Light Level= ");
    Serial.print(val);
    Serial.print(" %*");
    
    lcd.setCursor(0,1);
    lcd.print("Light Level= ");
    lcd.print(val);
    lcd.print(" %");
    
    Serial.print("LDR RAW VAL =");
    Serial.print(input);
    Serial.print("*");
    
    lcd.setCursor(0,2);
    lcd.print("LDR RAW VAL =");
    lcd.print(input);
    
    Serial.print("-*");
    
    lcd.setCursor(0,3);
    lcd.print("-");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************** setup *****************************************************
void setup()
{
  Serial.begin(9600);
  init_lcd();
  wsn.init_sensor1_ldr();
  
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
  displayAndSend(wsn.read_sensor1_ldr());
  delay(1000);
}
//************************************************** end main loop **********************************************
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
