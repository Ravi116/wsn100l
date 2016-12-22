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
;||	Title		: sensor2_gas.ino 														
;||	Status		: Completed!															
;||	Features	: 							
;||	Description	: MQ-9 carbon gas sensor 												
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
float sensor_volt;
float RS_gas; // Get value of RS in a GAS
float ratio; // Get ratio RS_GAS/RS_air

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
    Serial.print("SENSOR-2 : MQ9 GAS*");
    
    lcd.setCursor(0,0);
    lcd.print("SENSOR-2 : MQ9 GAS");
    
    Serial.print("Sensor volt= ");
    sensor_volt=(float)input/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
    ratio = RS_gas/1.66;//R0;  // ratio = RS/R0 
    Serial.print(sensor_volt);
    Serial.print(" V*");
    
    lcd.setCursor(0,1);
    lcd.print("Sensor volt= ");
    lcd.print(sensor_volt);
    lcd.print(" V");
    
    Serial.print("RS_ratio = ");
    Serial.print(RS_gas);
    Serial.print("*");
    
    lcd.setCursor(0,2);
    lcd.print("RS_ratio = ");
    lcd.print(RS_gas);
    
    Serial.print("Rs/R0 =");
    Serial.print(ratio);
    Serial.print("*");
    
    lcd.setCursor(0,3);
    lcd.print("Rs/R0 =");
    lcd.print(ratio);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************** setup *****************************************************
void setup()
{
  Serial.begin(9600);
  init_lcd();
  wsn.init_sensor2_gas();
  
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
  displayAndSend(wsn.read_sensor2_gas());
  delay(1000);
}
//************************************************** end main loop **********************************************
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@