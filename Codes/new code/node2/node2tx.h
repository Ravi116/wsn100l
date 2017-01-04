

#ifndef node2tx_h
#define node2tx_h


#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


class node {
    public:
    void sensor_init(void);
    void recieved_data(float arr0[]);
    void packet_generate(float frame[]);
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
