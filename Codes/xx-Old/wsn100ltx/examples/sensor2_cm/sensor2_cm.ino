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
;||	Title		: sensor2_cm.ino 														
;||	Status		: Completed!															
;||	Features	: 							
;||	Description	: condenser microphone  												
;||				  Oscillator	 :	16MHz 							
;||	                    																								 ||;
;||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||;
/***********************************************************************************************/
#include"wsn100ltx.h"
#include<LiquidCrystal.h>
#include<Wire.h>
/////////////////////////////////////////////////////////////////////////////////////////////////
//*********************************** Object and Function init **********************************
wsn100ltx wsn;
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
    Serial.print("SENSOR-2 : CON. MIC*");
    
    lcd.setCursor(0,0);
    lcd.print("SENSOR-2 : CON. MIC");
    
    Serial.print("Sound Level= ");
    int val = map(input, 0, 1023, 0, 100);
    Serial.print(val);
    Serial.print(" %*");
    
    lcd.setCursor(0,1);
    lcd.print("Sound Level= ");
    lcd.print(val);
    lcd.print(" %");
    
    Serial.print("Sound RAW VAL =");
    Serial.print(input);
    Serial.print("*");
    
    lcd.setCursor(0,2);
    lcd.print("Sound RAW VAL =");
    lcd.print(input);
    
    Serial.print("SL--> 1023 =100%*");
    
    lcd.setCursor(0,3);
    lcd.print("SL--> 1023 =100%");
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
  displayAndSend(wsn.read_sensor2_cm());
  delay(2000);
}
//************************************************** end main loop **********************************************
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@