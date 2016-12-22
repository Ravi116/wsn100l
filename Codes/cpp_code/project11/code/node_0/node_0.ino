//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// node 0
// version 1.0 - coursework demonstration
//----------------------------------------------

#include <Wire.h>
#include <SPI.h>
#include <XBee.h>

// xbee
uint8_t text[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // this array will be used to transport data inbetween the XBees, id = 0
XBee xbee = XBee();
XBeeAddress64 remoteAddress = XBeeAddress64(0x0013a200, 0x403c884f); // this is the network address of the XBee cordinator which is where we want this node to send it's data sets
ZBTxRequest zbTx = ZBTxRequest(remoteAddress, text, sizeof(text));

// analog sensors
int tmp102Address = 0x48; // hardware address for the I2C tmp102 sensor
int s_tempPin = 3; //analog pin for soil temperature reading
int s_tempReading;
int temt6000Pin = 2; // analog pin for light level reading
int photocellReading;

// soil humidity
#define voltageFlipPin1 2 //first digital pin we are going to use for the flip-flop soil humidity sensor 
#define voltageFlipPin2 4 //second digital pin we are going to use for the flip-flop soil humidity sensor 
#define sensorPin 0 // analog pin for soild humidity reading
int flipTimer = 1000;
int avg = 0;

// humidity
float val = 0;
float RH = 0;
int RH2 = 0;
float my_room_temperature = 20; //in degrees C, fall back to ensure loop won't get stuck in case we don't get a reading from the tmp102
float max_voltage = 3.27;
float Zerov = 0.8;

int flag;
 
void setup(void) {
  Serial.begin(9600);
  Wire.begin(); 
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(sensorPin, INPUT);
}
 
void loop(void) {
  s_tempReading = analogRead(s_tempPin); //read the soild temperature reading into s_tempReading
  photocellReading = analogRead(temt6000Pin); //read the light level reading into photocellReading
 
  Serial.print("soil temperature = "); //debugging info, sent to the serial monitor
  Serial.println(s_tempReading); //debugging info, sent to the serial monitor
  Serial.print("photocell = "); //debugging info, sent to the serial monitor
  Serial.println(photocellReading); //debugging info, sent to the serial monitor
 
  int celsius = getTemperature(); // reads the temperature from the tmp102 into celsius
  Serial.print("temperature in celsius: "); //debugging info, sent to the serial monitor
  Serial.println(celsius); //debugging info, sent to the serial monitor
 
  val = analogRead(1);  // reads the humidity reading into val
  my_room_temperature = getTemperature(); // reads the temperature from the tmp104 into my_room_temperature 
  max_voltage = (3.27-(0.006706*my_room_temperature)) ; // The max voltage value drops down 0.006705882 for each degree C over 0C. The voltage at 0C is 3.27 (corrected for zero precent voltage)
  RH = ((((val/1023)*5)-Zerov)/max_voltage)*100;
  Serial.print("humidity in %: "); //debugging info, sent to the serial monitor
  Serial.println(RH); //debugging info, sent to the serial monitor
  RH2 = RH; //humidity float -> int
  
  
  setSensorPolarity(true);
  delay(flipTimer);
  int val1 = analogRead(sensorPin);
  delay(flipTimer);  
  setSensorPolarity(false);
  delay(flipTimer);
  // invert the reading
  int val2 = 1023 - analogRead(sensorPin);
  avg = (val1 + val2) / 2;
  Serial.print("Arduino_nr1 soil humidity = "); //debugging info, sent to the serial monitor
  Serial.println(avg); //debugging info, sent to the serial monitor
  
  delay(100);              // wait 100ms for next reading  
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(1000);
  

 //val2 INTO PAYLOAD
 //break down 10-bit reading into two bytes and place in payload
 text[0] = s_tempReading >> 8 & 0xff;
 text[1] = s_tempReading & 0xff;
  
 //distance2 INTO PAYLOAD
 //break down 10-bit reading into two bytes and place in payload
 text[2] = photocellReading >> 8 & 0xff;
 text[3] = photocellReading & 0xff;
 
 //avg INTO PAYLOAD
 //break down 10-bit reading into two bytes and place in payload
 text[7] = avg >> 8 & 0xff;
 text[8] = avg & 0xff;
 
 if (celsius < 0) //we are sending this flag as part of the XBee payload to indicate if the temperature value is above or beyond 0
 {flag = 0;}
 
 else
 {flag = 1;}
 
 // this simply fills the readings we acquired above into our XBee payload array
 text[4] = flag;
 text[5] = celsius;
 text[6] = RH2;
  
 

  
  xbee.send(zbTx); //this sends our XBee payload array to the coordinator
  delay(180000); //wait 3min before we acquire and send another set of sensor readings

  
}

// this reads the temperature from the tmp102's registers via I2C
float getTemperature(){
  Wire.requestFrom(tmp102Address,2); 

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it's a 12bit int, using two's compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4; 

  float celsius = TemperatureSum*0.0625;
  return celsius;
}

// we are using this to flip the voltage between reading from the soild humidity sensor to avoid corrosion of our probes
void setSensorPolarity(boolean flip){
  if(flip){
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  }else{
    digitalWrite(voltageFlipPin1, LOW);
    digitalWrite(voltageFlipPin2, HIGH);
  }
}


