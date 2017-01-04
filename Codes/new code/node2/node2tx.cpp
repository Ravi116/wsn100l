#include <Wire.h>
#include"node2tx.h"
#include <LiquidCrystal.h>
#include "BMP085.h"




/*      -----Global Define-----      */
  LiquidCrystal lcd(7,6,5,4,3,2);
   BMP085 bmp;
    
   #define LM35_PIN A0
#define GAS_PIN A1
#define IR_PIN A2
#define FLEX_PIN A3
    
    
    const int SERIAL_TIMEOUT = 2000;
    static int serial_time;
    
     const char *sensor_name[] = {" Node Id ",
                " LM 35 ",
                " MQ-9 GAS ",
                " BMP085 ",
                " IR ",
                " Flex "};
    const char *data[] = {"Node ID = ",
                "Temperature(C) = ",
                "RS/R0 (ppm)= ",
                "Pressure (pa) = ",
                "Object = ",
                "Flex Mov. = "};
                
/*
*Function  :-init_lcd
*Class     :-noe
*Input     :-void
*Output    :-void
*Remarks   :-it will initiate the lcd display.
*/                
void node::init_lcd(void)
{
    lcd.begin(20,4);              //Begin lcd by mentioning lcd type i.e 16*2,16*4,20*4
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
    return;
}
/*
*Function  :-Init_zigbee 
*Class     :-node
*Input     :-void
*Output    :-Status of zigbee module init process
*Remarks   :-
*/                
int node::init_zigbee(void)
{
    Serial.write('+');
    Serial.write('+');
    Serial.write('+');
    serial_time = millis();

    while( ! (Serial.available()) ) {
      if( millis() - serial_time > SERIAL_TIMEOUT ) {
        return 0;
      }
    String str=Serial.readString();
    Serial.println(str);
    if(str=="OK")
        return 1;
    else
        return 0;
    }
}

/*
*Function  :-
*Class     :-
*Input     :-
*Output    :-
*Remarks   :-
*/                

                
void node::sensor_init(void)
{
        pinMode(IR_PIN,INPUT);		//pir sensor
       bmp.begin();
  return ;
}


//----- Read data from LM35 sensor -----

float node::lm35(void){
    float input = 0;
    input = analogRead(LM35_PIN);
    
    return(input / 9.31);
}

//----- Read data from MQ9 GAS sensor -----

float node::gas(void){
  int input = 0;
    float sensor_volt = (float)(analogRead(GAS_PIN)/1024 * 5.0);
   float RS_gas = (5.0 - sensor_volt)/sensor_volt;
    float ratio =   RS_gas/1.66;
    //return(RS_gas);
    return(ratio);
}


//----- Read data from IR sensor -----

int node::ir(void){
    int status = digitalRead(IR_PIN);
    return status; // if 0 not detected and if 1 detected
}

//----- Read data from Flex sensor -----

int node::flex(void){
int input = 0;
    input = analogRead(FLEX_PIN);         
    int val = map(input,0,1023,0,90);
    return(val);
}


/*
*Function  :-recieved_data
*Class     :-node
*Input     :-"Frame" Array  
*Output    :-Data of "Frame" array will be shown on LCD.
*Remarks   :-
*/                

void node::recieved_data(float arr0[])
{
    int i;
    for(i = 0;i<6;i++)
    {
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      if(i > 0){
       String list = "Sensor " + String(i) + ":- ";
        lcd.print(list);
        }
      lcd.setCursor(0,1);
      lcd.print(*(sensor_name+i));        // Print snesor name
      
      lcd.setCursor(0,2);
      lcd.print(*(data+i));            //print output name
      
      lcd.setCursor(0,3);
        if(i == 4){              //check if sensor is capacitive touch or PIR
            if(arr0[i])
                lcd.print("DETECTED");
            else
                lcd.print("NOT_DETECTED");
        }
        else
            lcd.print(arr0[i]);
    }
}

/*
*Function  :-Packet _generate()
*Class     :-node
*Input     :-frame buffer array
*Output    :-Node id,Reading of sensors will be saved in array passed to this function.
*Remarks   :-
*/                

float node::packet_generate(float frame[])
{
  frame[0] = 2;
  frame[1] = lm35();
  frame[2] = gas();
  frame[3] = bmp.readPressure();
  frame[4] = ir();
  frame[5] = flex();
}

void node::send_packet(float frame[])
{
 for(int i= 0 ; i < 6 ; i++)
 {
    Serial.print(frame[i]); 
    Serial.print(":");
 }
  Serial.print(";");
}
