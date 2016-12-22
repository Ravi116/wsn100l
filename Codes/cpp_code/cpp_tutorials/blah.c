/**
* Node1 Tx.code
*/

#include <LiquidCrystal.h>
#include <XBee.h>
#include <BMP085.h>
#include <Wire.h>

// Global Define
BMP085 bmp;
#define LM35_PIN A0
#define GAS_PIN A1
#define IR_PIN A2
#define FLEX_PIN A3
LiquidCrystal lcd(7,6,5,4,3,2);

// Function prototype
void init_lcd();
int init_zigbee();

class read_sensor
{
	public:
	int SERIAL_TIMEOUT = 2000;
    int serial_time;
	int lm35(void);
	int gas(void);
	int ir(void);
	int flex(void);
};
void display_and_send();

void setup
{
	Serial.begin(9600);
	XBee.begin(Serial);


    pinMode(IR_PIN,INPUT);		//IR sensor


	init_lcd();

	read_sensor Node2;

	if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }

}

void loop()
{
	display_and_send();
	delay(5000);
}

int init_zigbee(void)
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

//----- Read data from LM35 sensor -----

int read_sensor::lm35(void){
    int input = 0;
    input = analogRead(LM35_PIN);

    return(val / 9.31);
}

//----- Read data from MQ9 GAS sensor -----

int read_sensor::gas(void){
	int input = 0;
    float sensor_volt = (float)(analogRead(GAS_PIN)/1024 * 5.0);
    RS_gas = (5.0 - sensor_volt)/sensor_volt;
    ratio = 	RS_gas/1.66;
    return(RS_gas);
}

//----- Read data from IR sensor -----

int read_sensor::ir(void){
    int status = digitalRead(IR_PIN);
    return status; // if 0 not detected and if 1 detected
}

//----- Read data from Flex sensor -----

int read_sensor::flex(void){
int input = 0;
    input = analogRead(FLEX_PIN);
    int val = map(input,0,1023,0,90);
    return(val);
}

void display_and_send(void)
{

// -----LM35 sensor------
	 lcd.clear();
    Serial.print("SENSOR-1 : LM35*");

    lcd.setCursor(0,0);
    lcd.print("SENSOR-1 : LM35");

    Serial.print("Temperatue = ");
    Serial.print(Node2.lm35());
    Serial.print(" C*");

	lcd.print("Temperatue = ");
	lcd.print(Node2.lm35());
    lcd.print(" C*");


    delay(100);
// ------ MQ9 GAS  sensor -----
     lcd.setCursor(0,0);
    lcd.print("SENSOR-2 : MQ9 GAS");
   	serial.print("SENSOR-2 : MQ9 GAS");

    Serial.print(" RS_ratio = ");
    Serial.print(Node2.gas());
    Serial.print(" V*");

	lcd.print(" RS_ratio = ");
    lcd.print(Node2.gas());
    lcd.print(" V*");

    serial.print("RS/R0 = ");
    serial.print(RS_gas/1.66);

    lcd.setCursor(0,2);
    lcd.print("RS/R0 = ");
    lcd.print(RS_gas/1.66);

   delay(100);

// ------ Pressure sensor ------

    lcd.setCursor(0,0);
    lcd.print("SENSOR-3 : Pressure");
    Serial.print("Pressure =");
    lcd.print(bmp.readpressure();
    Serial.print(bmp.readpressure();
    lcd.print("pa");
    Serial.print("pa");

	delay(100);

// ----- IR sensor ------

 	lcd.setCursor(0,0);
    lcd.print("SENSOR-4 : IR");

    lcd.setCursor(0,1);
    Serial.print("Object =");
    lcd.print("Object =");
    if(Node2.ir() == 1){
      Serial.print("Detected*");
      lcd.print("Detected");
    }
    else{
      Serial.print("Not Det.*");
      lcd.print("Not Det.");
    }

	delay(100);
// ------- Flex sensor --------

	lcd.setCursor(0,0);
    lcd.print("SENSOR-5: FLEX");
    serial.print("SENSOR-5: FLEX");
    lcd.setCursor(0,1);
   	lcd.print("FLEX MOV. = ");
    serial.print("FLEX MOV. = ");
    lcd.print(val);
    serial.print(val);


}
