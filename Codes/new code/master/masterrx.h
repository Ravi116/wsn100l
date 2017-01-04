

#ifndef wsn100lrx_h
#define wsn100lrx_h


#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include<stdio.h>
#include<string.h>


class master {
    public:
    void wsnRxSetup(void);
    void init_lcd(void);
    int init_zigbee(void);
    void lcd_display(int start_point);
    void frame_parser(void);
    void serial_recieve(void);    
};

#endif

