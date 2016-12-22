#ifndef wsn100lrx_h
#define wsn100lrx_h
#include <inttypes.h>
#include <WString.h>

class wsn100lrx{
private:
    int SERIAL_TIMEOUT = 2000;
    int serial_time;
public:
    const int BUZZER = 4;
    const int GREEN_LED = 5;
    const int RED_LED = 10;
    const int YELLOW_LED = 12;
    const int RELAY1 = 11;
    const int RELAY2 = 13;
    void wsnRxSetup();
    int cmdMode();
    int exitCmdMode();
    int setAddress(String dl, String dh);
    int requestData();
};

#endif // wsn100lrx_h

















































/*
 LCD configuration
 * LCD RS pin to digital pin 9
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin A0
 * LCD D5 pin to digital pin A1
 * LCD D6 pin to digital pin A2
 * LCD D7 pin to digital pin A3
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 */
