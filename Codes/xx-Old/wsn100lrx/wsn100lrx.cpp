#include"wsn100lrx.h"
#include "Arduino.h"
//#include <WString.h>

void wsn100lrx::wsnRxSetup()
{
     //////////////////// Serial port config/////////////////
   Serial.begin(9600);
   ////////////////////MASTER/SLAVE///////////////////////
   pinMode(A5,INPUT_PULLUP); // MASTER JUMPER
   //////////////////// Analog I/O///////////////////////
   int analog_value=analogRead(A4);

   ///////////////////Interrupts ////////////////////////
   //attachInterrupt(0,ISR_0,CHANGE);
   //attachInterrupt(1,ISR_1,CHANGE);
   ///////////////////// BUZZER///////////////////////
   pinMode(BUZZER,OUTPUT);
   ////////////////////LEDS//////////////////////////////
   pinMode(GREEN_LED,OUTPUT);
   pinMode(RED_LED,OUTPUT);
   pinMode(YELLOW_LED,OUTPUT);
   ///////////////////// Relays ////////////////////////
   pinMode(RELAY1,OUTPUT);
   pinMode(RELAY2,OUTPUT);
}

int wsn100lrx::cmdMode()
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
    //Serial.println(str);
    if(str=="OK")
        return 1;
    else
        return 0;
    }
}

int wsn100lrx::exitCmdMode()
{
    Serial.print("ATCN");
    Serial.write(0x0d);
    serial_time = millis();

    while( ! (Serial.available()) ) {
      if( millis() - serial_time > SERIAL_TIMEOUT ) {
        return 0;
      }
    String str=Serial.readString();
    //Serial.println(str);
    if(str=="OK")
        return 1;
    else
        return 0;
    }
}

int wsn100lrx::setAddress(String dl, String dh)
{
    Serial.print("ATDL" + dl);
    Serial.write(0x0d);

    serial_time = millis();
    while( ! (Serial.available()) ) {
      if( millis() - serial_time > SERIAL_TIMEOUT ) {
        return 0;
      }
        String str=Serial.readString();
        if(str=="OK")
        {
            Serial.print("ATDH" + dh);
            Serial.write(0x0d);

            serial_time = millis();
            while( ! (Serial.available()) ) {
                if( millis() - serial_time > SERIAL_TIMEOUT ) {
                    return 0;
                }
            String str=Serial.readString();
            if(str=="OK")
                return 1;
            else
                return 0;
            }
        }
    }
}

int wsn100lrx::requestData()
{
    Serial.write("ACK");
    serial_time = millis();

    while( ! (Serial.available()) ) {
      if( millis() - serial_time > SERIAL_TIMEOUT ) {
        return 0;
      }
    String str=Serial.readString();
    //Serial.println(str);
    if(str=="OK")
        return 1;
    else
        return 0;
    }
}
