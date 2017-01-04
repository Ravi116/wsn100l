// include the lcd library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Sigma Hightech.");

}
void print_temp(String str){
        lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("SENSOR-1:LM35");
       lcd.setCursor(0, 1);
       lcd.print("TEMP = ");
       lcd.print(str); 
      
  }
  
void print_hum(String str){
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print("SENSOR-2:DHT11");
       lcd.setCursor(0, 1);
       lcd.print("Humid(RH%)=");
       lcd.print(str); 
  }

void loop() {
    if(Serial.available()>0)
    {
      String str=Serial.readStringUntil('*');
    
   if(str == "T")
      {
         String str1=Serial.readStringUntil('*');
       print_temp(str1);
       
      }
      if(str == "H")
      {
         String str1=Serial.readStringUntil('*');
       print_hum(str1);
      } 
    }
     
}
