#include"node1tx.h"
#include <LiquidCrystal.h>


#include "dht.h"


/*      -----Global Define-----      */
  LiquidCrystal lcd(7,6,5,4,3,2);
    dht DHT;
    
    #define LDR_PIN A0
    #define CM_PIN A1
    #define DHT11_PIN A2
    #define CT_PIN0 8
    #define CT_PIN1 9
    #define PIR_PIN A4
    
    
    const int SERIAL_TIMEOUT = 2000;
    static int serial_time;
    
    const char *sensor_name[] = {"Node Id",
                " LDR ",
                " Con. MIC ",
                " Humidity ",
                " PIR ",
                " Capacitive touch"};
    const char *data[] = {"Node ID = ",
                "Light Level(%) = ",
                "Sound Level (%)= ",
                "Humidity(RH%) = ",
                "Live(@_@) = ",
                "Touch = "};
                
/*
*Function  :-init_lcd
*Class     :-noe
*Input     :-void
*Output    :-void
*Remarks   :-it will initiate the lcd display.
*/                
void node::init_lcd(void)
{
    lcd.begin(20,4);              //Begin lcd by mentioning lcd type i.e 16*2,16*4,20*4
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
    return;
}
/*
*Function  :-Init_zigbee 
*Class     :-node
*Input     :-void
*Output    :-Status of zigbee module init process
*Remarks   :-
*/                
int node::init_zigbee(void)
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

/*
*Function  :-
*Class     :-
*Input     :-
*Output    :-
*Remarks   :-
*/                

                
void node::sensor_init(void)
{
       pinMode(PIR_PIN,INPUT);		//pir sensor
        pinMode(CT_PIN0,INPUT);	// for capacitive touch sensor
        pinMode(CT_PIN1,INPUT);
  return ;
}

/*
*Function  :-
*Class     :-
*Input     :-
*Output    :-
*Remarks   :-
*/                

int node::ldr(void){
    int input = 0;
    input = analogRead(LDR_PIN);
    int val = map(input,0,1023,0,100);
    return(val);
}

/*
*Function  :-
*Class     :-
*Input     :-
*Output    :-
*Remarks   :-
*/                
int node::cm(void){
int input = 0;
    input = analogRead(CM_PIN);
    int val = map(input,0,1023,0,100);
    return(val);
}

/*
*Function  :-
*Class     :-
*Input     :-
*Output    :-
*Remarks   :-
*/                


float node::dht11(void){               //check for sensor response/timeout
    int chk = DHT.read11(DHT11_PIN);
    if(chk == DHTLIB_OK){
       int val = DHT.humidity;
        return val;     // sensor value
    }
    else
        return 0;   //error
}

/*
*Function  :-pir
*Class     :-node
*Input     :-void
*Output    :-sensor status 
*Remarks   :-
*/                

int node::pir(void){
    int status = digitalRead(PIR_PIN);
    return status; // if 0 not detected and if 1 detected
}
/*
*Function  :-ct
*Class     :-node
*Input     :-void
*Output    :-stauts of sensor wether touch detected ot not
*Remarks   :-
*/                

int node::ct(void){
    if(digitalRead(CT_PIN0)==LOW)
        return 1;               // touch detected
    else if(digitalRead(CT_PIN1)==LOW)
        return 2;               // touch not detected
    else
        return 0;               // touch not detected

}


/*
*Function  :-recieved_data
*Class     :-node
*Input     :-"Frame" Array  
*Output    :-Data of "Frame" array will be shown on LCD.
*Remarks   :-
*/                

void node::recieved_data(float arr0[])
{
    int i;
    for(i = 0;i<6;i++)
    {
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0);
      if(i > 0){
       String list = "Sensor " + String(i) + ":- ";
        lcd.print(list);
        }
      lcd.setCursor(0,1);
      lcd.print(*(sensor_name+i));        // Print snesor name
      
      lcd.setCursor(0,2);
      lcd.print(*(data+i));            //print output name
      
      lcd.setCursor(0,3);
        if(i == 5 || i == 4){              //check if sensor is capacitive touch or PIR
            if(arr0[i])
                lcd.print("DETECTED");
            else
                lcd.print("NOT_DETECTED");
        }
        else
            lcd.print(arr0[i]);
    }
}

/*
*Function  :-Packet _generate()
*Class     :-node
*Input     :-frame buffer array
*Output    :-Node id,Reading of sensors will be saved in array passed to this function.
*Remarks   :-
*/                

float node::packet_generate(float frame[])
{
  frame[0] = 1;
  frame[1] = ldr();
  frame[2] = cm();
  frame[3] = dht11();
  frame[4] = pir();
  frame[5] = ct();
}

void node::send_packet(float frame[])
{
 for(int i= 0 ; i <= 6 ; i++)
 {
    Serial.print(frame[i]); 
    if(i == 6)
    Serial.print(";");
    else
    Serial.print(":");
 }
}

