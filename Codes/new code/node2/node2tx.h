#ifndef node2tx_h
#define node2tx_h

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
   float lm35(void);
   float gas(void);
   
   int ir(void);
   int flex(void);

};

#endif
