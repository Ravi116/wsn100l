// include the library code:
#include <LiquidCrystal.h>
#include"dht.h"

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6,7,8,9,10,11);
#define LM35_PIN A0
#define DHT11_PIN A2

dht DHT;

void chk_dht()
{
int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
    lcd.print("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    lcd.print("error"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
    lcd.print("error"); 
                  break;
    default: 
    lcd.print("error");
                 break;
  }
}

void read_dht()
{
float test = DHT.humidity;
  lcd.print(test);  
  Serial.print(DHT.humidity, 1);
  Serial.print("*");
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Sigma Hightech.");
//pinMode(A0,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
float vout = analogRead(LM35_PIN);
float tempc = (vout * 500)/1023;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SENSOR-1:LM35");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("TEMP = ");
    lcd.print(tempc);
    Serial.print(tempc);
    Serial.print("*");
    lcd.print("C");  
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("SENSOR-2:DHT11");  
     delay(1000);
     lcd.setCursor(0,1);
    lcd.print("Sensor Stat= "); 
    chk_dht();
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Humid(RH%)=");
    read_dht();
delay(10000);
}
