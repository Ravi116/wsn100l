#ifndef wsn100ltx_h
#define wsn100ltx_h
#include <inttypes.h>


class wsn100ltx{

private:


public:
    int SERIAL_TIMEOUT = 2000;
    int serial_time;

    int init_zigbee();
    void init_sensor1_lm35();
    void init_sensor2_cm();
    void init_sensor3_dht11();
    void init_sensor4_fs();
    void init_sensor5_pir();
    void init_sensor7_bmp();
    void init_sensor1_ldr();
    void init_sensor2_gas();
    void init_sensor3_ir();
    void init_sensor9_cap();

//////////////////////  sensor read methods /////////////////////////////
    int read_sensor1_lm35();
    int read_sensor2_cm();
    int read_sensor3_dht11();
    int read_sensor4_fs();
    int read_sensor5_pir();
    int read_sensor1_ldr();
    int read_sensor2_gas();
    int read_sensor3_ir();
    int read_sensor9_cap();

////////////////////////  send data over zigbee //////////////////////////


};

#endif
