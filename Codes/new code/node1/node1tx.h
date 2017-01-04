#ifndef node1tx_h
#define node1tx_h

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

class node
{
    public:
    void sensor_init(void);
    void recieved_data(float arr0[]);
    float packet_generate(float arr[]);
    void init_lcd(void);
    int init_zigbee(void);
    void send_packet(float frame[]);
    
    private:
    int ldr(void);
    int cm(void);
    float dht11(void);
    int pir(void);
    int ct(void);

};

#endif
