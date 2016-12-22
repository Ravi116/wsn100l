#include"wsn100ltx.h"
#include "Arduino.h"

////////////////////////////   init methods /////////////////////////////////////
int wsn100ltx::init_zigbee()
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
void wsn100ltx::init_sensor1_lm35()
{

}
void wsn100ltx::init_sensor2_gas()
{

}
void wsn100ltx::init_sensor2_cm()
{

}
void wsn100ltx::init_sensor3_dht11()
{

}
void wsn100ltx::init_sensor4_fs()
{

}
void wsn100ltx::init_sensor5_pir()
{
    pinMode(A4,INPUT);
}
void wsn100ltx::init_sensor7_bmp()
{

}

void wsn100ltx::init_sensor1_ldr()
{

}
void wsn100ltx::init_sensor3_ir()
{
    pinMode(A2,INPUT);
}

void wsn100ltx::init_sensor9_cap()
{
    pinMode(8,INPUT);
    pinMode(9,INPUT);
}
////////////////////////////////////////////////// read methods ///////////////////////////

int wsn100ltx::read_sensor1_lm35()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return analogRead(A0);

}

int wsn100ltx::read_sensor2_cm()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return analogRead(A1);

}

int wsn100ltx::read_sensor4_fs()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return analogRead(A3);

}

int wsn100ltx::read_sensor5_pir()
{
    int status = digitalRead(A4);
    return status;
}

int wsn100ltx::read_sensor1_ldr()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return analogRead(A0);
}

int wsn100ltx::read_sensor2_gas()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return analogRead(A1);
}

int wsn100ltx::read_sensor3_ir()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    return digitalRead(A2);
}

int wsn100ltx::read_sensor9_cap()
{
    digitalWrite(13,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    if(digitalRead(8)==LOW)
        return 1;
    else if(digitalRead(9)==LOW)
        return 2;
    else
        return 0;
}

