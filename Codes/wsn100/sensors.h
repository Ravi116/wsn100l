#ifndef SENSORS_H
#define SENSORS_H
#endif
//Divide sensors as interfaced in node (node no can b/w 1 to 5 at current scenario)
#define NODE2
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

void init_sensor_ldr(void);
void init_sensor_cm(void);
void init_sensor_dht11(void);
void init_sensor_bmp(void);
void init_sensor_light(void);

void init_sensor_ir(void);
void init_sensor_ct(void);
void init_sensor_flex(void);
void init_sensor_pir(void);
void init_sensor_solar(void);   //DATA NOT AVAILABLE YET

int read_sensor_ldr(void);
int read_sensor_cm(void);
int read_sensor_dht11(void);
int read_sensor_bmp(void);
int read_sensor_light(void);

int read_sensor_ir(void);
int read_sensor_ct(void);
int read_sensor_flex(void);
int read_sensor_pir(void);
int read_sensor_solar(void);  //DATA NOT AVAILABLE YET




