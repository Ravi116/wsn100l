//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// node 2
// version 1.0 - coursework demonstration
//----------------------------------------------

#include <XBee.h>
#include <Wire.h>

//xbee
uint8_t text[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 2};
XBee xbee = XBee();
XBeeAddress64 remoteAddress = XBeeAddress64(0x0013a200, 0x403c884f);
ZBTxRequest zbTx = ZBTxRequest(remoteAddress, text, sizeof(text));

// just some local variables to mangle data...
byte res;
byte msb;
byte lsb;
int val;
int val2;
int val3;
int val4;

void setup(void) {
  Serial.begin(9600); 
  xbee.begin(9600); 
  Wire.begin();
  pinMode(13, OUTPUT);

}
 
void loop(void) {
 
 // read temperature from tmp102 via I2C
 res = Wire.requestFrom(72,2); 
  if (res == 2) {
    msb = Wire.read(); /* Whole degrees */ 
    lsb = Wire.read(); /* Fractional degrees */ 
    val = ((msb) << 4);   /* MSB */
    val |= (lsb >> 4);    /* LSB */
    val3 = val*0.0625;
    Serial.println(val3); //debugging info, sent to the serial monitor
    delay(1000);
    
//we are sending this flag as part of the XBee payload to indicate if the temperature value is above or beyond 0       
 if (val3 > 0)
{val4 = 1;}
else
{val4 = 0;}
Serial.println(val4); //debugging info, sent to the serial monitor

  
  val2 = analogRead(0);     // read analog input pin 0 (light level) into val2
  Serial.print(val2, DEC);  // debugging info, sent to the serial monitor
  Serial.print(" ");	    // prints a space between the numbers
  
                                   
  
  delay(100);              // wait 100ms for next reading  
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);              // wait for a second
  
 //val2 INTO PAYLOAD
 //break down 10-bit reading into two bytes and place in payload
 text[0] = val2 >> 8 & 0xff;
 text[1] = val2 & 0xff;
 
//remaining readings INTO PAYLOAD 
 text[4] = val4;
 text[5] = val3;

  }
 

  
  xbee.send(zbTx); //this sends our XBee payload array to the coordinator
 
  delay(180000); //wait 3min before we acquire and send another set of sensor readings
}



