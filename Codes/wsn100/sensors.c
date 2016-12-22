 /*this file contains initialization and data reading process of sensors.
*Analog sensors do not require initialization as they are power by external source.
*/
#include"Arduino.h"
#include"sensors.h"
#include"dht.h"
//#include"Adafruit_BMP085.h" not necessory will be added later (remove if not needed)

// check analog pin connections of sensors before running code change  pin number if required
#define LDR_PIN A0
#define CM_PIN A1
#define DHT11_PIN A2
#define BMP_PIN A3  //MAY BE CHANGED
#define LIGHT_PIN A4 //MAY BE CHANGED
#define IR_PIN A2   //MAY BE CHANGED
#define CT_PIN0 8
#define CT_PIN1 9
#define FLEX_PIN A1
#define PIR_PIN A4
#define SOLAR_PIN //DATA NOT AVAILABLE YET


/*         ____LIST OF SENSORS____
*   Sensor 1 :- LDR sensor
*   Sensor 2 :- Audio sensor
*   Sensor 3 :- Humidity sensor
*   Sensor 4 :- pressure sensor
*   Sensor 5 :- Light-IL luminance sensor
*   Sensor 6 :- Infrared sensor
*   Sensor 7 :- Capacitive Touch sensor
*   Sensor 8 :- Flex sensor
*   Sensor 9 :- PIR-Passive infrared sensor
*   Sensor 10:- Solar sensor
*/

/*-------------All sensor initialization functions-----------------*/
void init_sensor_ldr(void);

void init_sensor_cm(void);

void init_sensor_dht11(void);

/*if its BMP sensor have to add BMP085.H from adafruit to calculate pressure so wait till hardware arrives.*/

void init_sensor_bmp(void);

void init_sensor_light(void);//no detail yet

void init_sensor_ir(void){
    pinMode(IR_PIN,INPUT);      // check analog pin to sensor before running code change number if required
};

void init_sensor_ct(void){
    pinMode(CT_PIN0,INPUT);
    pinMode(CT_PIN1,INPUT);
};
void init_sensor_flex(void);

void init_sensor_pir(void){
    pinMode(PIR_PIN,INPUT);      // check analog pin to sensor before running code change number if required
};


/*--------------------Read values from sensor--------------------------*/
int read_sensor_ldr(void){
    int input = 0;
    input = analogRead(LDR_PIN);
    int val = map(input,0,1023,0,100);
    return(val);
};

//addition on display.c ::::- audio should return in % so add '%' when displaying result on screen.
int read_sensor_cm(void){
int input = 0;
    input = analogRead(CM_PIN);
    int val = map(input,0,1023,0,100);
    return(val);
};



int read_sensor_dht11(void){               //check for sensor response/timeout
    int chk = DHT.read11(DHT11_PIN);
    if(chk == DHTLIB_OK){
        val = DHT.humidity;
        return val;     // sensor value
    }
    else
        return 0;   //error
};



int read_sensor_ir(void){
    return(analogRead(IR_PIN)); // if 0 not detected and if 1 detected
};


int read_sensor_ct(void){
    if(digitalRead(CT_PIN0)==LOW)
        return 1;               // touch detected
    else if(digitalRead(CT_PIN1)==LOW)
        return 2;               // touch not detected
    else
        return 0;               // touch not detected

};

int read_sensor_flex(void){
int input = 0;
    input = analogRead(FLEX_PIN);         // check analog pin to sensor before running code change number if required
    int val = map(input,0,1023,0,90);
    return(val);
};

int read_sensor_pir(void){
    int status = digitalRead(PIR_PIN);
    return status; // if 0 not detected and if 1 detected
};

