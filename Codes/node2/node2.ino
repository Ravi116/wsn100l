/**
* Node1 Tx.code 
*/


//#include <XBee.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include"node2tx.h"

node node2;
void setup()
{
	Serial.begin(9600);
	//XBee.begin(Serial);
	node2.init_zigbee();
	node2.init_lcd();
        node2.sensor_init();

}


void loop()
{
	float frame[6] = {0};
        node2.packet_generate(frame);
        node2.recieved_data(frame);
	delay(5000);
}


