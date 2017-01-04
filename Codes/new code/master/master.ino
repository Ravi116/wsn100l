


#include"masterrx.h"
#include <LiquidCrystal.h>

master rx;

void setup() {
  // put your setup code here, to run once:
    rx.init_lcd();
    rx.init_zigbee();
    rx.wsnRxSetup();
}

void loop() {
 rx.serial_recieve();
  
}
