/**
* Node1 Tx.code 
*/

#include <LiquidCrystal.h>
//#include <XBee.h>
#include"node1tx.h"

//Define class node1 
node node1;

void setup()
{
	Serial.begin(9600);
 //Initialization of lcd
   node1.init_lcd();
  //Initialization of zigbee module
   node1.init_zigbee();
  
  //Initialization of sensors
	node1.sensor_init();
}

void loop()
{
  //Defining Array of size 6 which will save node_id as well as sensor data,also it will be sent to reciever as Data packet/frame.
	float frame[6] = {0};
  //function for reading data from sensors and saving them into "frame" array.
        node1.packet_generate(frame);
   //function for sending data.
        node1.send_packet(frame);
   //function for displaying data on lcd.
        node1.recieved_data(frame);
 
	delay(5000);
}


