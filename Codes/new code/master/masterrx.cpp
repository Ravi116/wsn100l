 
 #include"masterrx.h"
#include <LiquidCrystal.h>
#define SIZE 35
 LiquidCrystal lcd(9, 8, A0, A1, A2, A3);

    int SERIAL_TIMEOUT = 2000;
    int serial_time;
    
    String str;
    char rx_buffer[SIZE] = {0};
    char data[6][5] = {0};
    
    const int BUZZER = 4;
    const int GREEN_LED = 5;
    const int RED_LED = 10;
    const int YELLOW_LED = 12;
    const int RELAY1 = 11;
    const int RELAY2 = 13;

 const char *sensor_name[] = {" Node Id ",
                " LM 35 ",      //node 2
                " MQ-9 GAS ",
                " BMP085 ",
                " IR ",
                " Flex ",
                " LDR ",        //node 1
                " Con. MIC ",
                " Humidity ",
                " PIR ",
                " Capacitive touch"};

const char * sensor_data[] = {"Node ID = ",
                "Temperature(C) = ",        //node 2
                "RS/R0 (ppm)= ",
                "Pressure (pa) = ",
                "Object = ",
                "Flex Mov. = ",
                "Light Level(%) = ",        //node 1
                "Sound Level (%)= ",
                "Humidity(RH%) = ",
                "Live(@_@) = ",
                "Touch = "};


void master::wsnRxSetup()
{
     //////////////////// Serial port config/////////////////
   Serial.begin(9600);
  
   ////////////////////MASTER/SLAVE///////////////////////
  // pinMode(A5,INPUT_PULLUP); // MASTER JUMPER
   //////////////////// Analog I/O///////////////////////
  // int analog_value=analogRead(A4);

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

void master::init_lcd()
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
    return ;
}

int master::init_zigbee(void)
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

void master::serial_recieve(void)
{ 
   
      while(Serial.available()>0)
      {
      str=Serial.readStringUntil('\0');
  // lcd.print(String(str.length()));
      str.toCharArray(rx_buffer,str.length());
      if(rx_buffer[0] == '1'){
              frame_parser();
              lcd_display(5);
              }
      else if(rx_buffer[0] == '2'){
            frame_parser();
            lcd_display(0);
      }
      else
        lcd.print("INVALID NODE ID");
      
     /* lcd.setCursor(0,0);
      lcd.print("recieved data");
      str.toCharArray(rx_buffer,str.length());
      lcd.print(rx_buffer);
      */
      }
      
}

void master::lcd_display(int start_point)
 {
   int temp = 0;
   int num = temp + start_point;
  for(temp = 0;temp < 6;temp++,num++) 
  {
    if(temp > 0)
    {
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
        String list = "Sensor " + String(temp) + ":- ";
        lcd.print(list);
             //printf(" Sensor " "%d" " :- ",i);
        lcd.setCursor(0,1);
        lcd.print(*(sensor_name + num ));        // Print snesor name
        // puts(*(sensor_name + i+ start_point));
        lcd.setCursor(0,2);
        lcd.print(*(sensor_data + num));            //print output name
        //puts(*(sensor_data + i + start_point));
        lcd.setCursor(0,3);
        lcd.print(data[temp]);            //print output name
        // puts(data[i]);
       //puts(data[i]);
     }
     else
     {
       delay(2000);
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print(*(sensor_name + temp));        // Print snesor name
      lcd.setCursor(0,2);
      lcd.print(*(sensor_data + temp));            //print output name
      lcd.setCursor(0,3);
      lcd.print(data[temp]);            //print output name
       }
   }
  
  
 }

void master::frame_parser(void)
{
  int x,y,prev;
  x = y = prev = 0;
  
  char found = ':';
  
  for( x = 0,y = 0;(rx_buffer[x] != '\0')&&(y <=6);x++)
    {
      if((rx_buffer[x] == found)||(rx_buffer[x] == ';')){
        strncpy(data[y],rx_buffer + prev,x-(prev + 1));
        y ++; 
        if(prev < 35)
          prev = x+1;
       }
     } 
 }
