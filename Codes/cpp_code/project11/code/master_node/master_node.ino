//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// master node/data concentrator
// version 1.0 - coursework demonstration
//----------------------------------------------

#include <XBee.h>
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 191, 168, 0, 65 };
byte server[] = {191, 168, 0, 1};

XBee xbee = XBee();
ZBRxResponse zbRx = ZBRxResponse();
uint8_t text[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //initialises the data array with 0s

//local variables to submit the readings from the payload to the php form
int A = 0;
int B = 0;
int C = 0;
int D = 0;
int E = 0;
int F = 0;
int flag;

void setup () {
  delay(1000);
  xbee.begin(9600);
}

void loop () {

  // read any data that is available:
  xbee.readPacket();

  // check if a packet was received: 
  if (xbee.getResponse().isAvailable()) {
    if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
      xbee.getResponse().getZBRxResponse(zbRx);
    // read available message into text
     for (int i = 0; i < zbRx.getDataLength(); i++) {
         
          text [i] = zbRx.getData(i);
     }
 //this rebuilds our 10-bit readings which we had stored in two bytes     
 uint8_t analogHigh = text[0];
 uint8_t analogLow = text[1];
 int value1 = analogLow + (analogHigh * 256);
  //Serial.println(value1);   
 
  //this rebuilds our 10-bit readings which we had stored in two bytes
 uint8_t analogHigh2 = text[2];
 uint8_t analogLow2 = text[3];
 int value2 = analogLow2 + (analogHigh2 * 256);
  //Serial.println(value2);
  
   //this rebuilds our 10-bit readings which we had stored in two bytes
 uint8_t analogHigh3 = text[7];
 uint8_t analogLow3 = text[8];
 int value3 = analogLow3 + (analogHigh3 * 256);
  //Serial.println(value3);
     
     
A = value1; //assigns the sensor readings to variables A-F which we can then send to the terminal and submit to the php form
B = value2;
C = text[5];
D = text[6];
E = text[9];
F = value3;
int flag = text[4];
//Serial.println(flag);


//if loops on E resolve which board the data is comming from so we can select the correct senddata function
//if loops on flag resolve if we need to print a "-" in front of the temperature reading
if (E == 0)
{  
Serial.println("s_temp =");
Serial.println(A);
Serial.println("Light =");
Serial.println(B);
Serial.println("Temperature =");

if (flag == 0)
{
Serial.println("-");  
Serial.println(C);
Serial.println("Humidity =");
Serial.println(D);
Serial.println("s_hum =");
Serial.println(F);
Serial.println("Board Identifier =");
Serial.println(E);
senddata0();}

else {
Serial.println(C);
Serial.println("Humidity =");
Serial.println(D);
Serial.println("s_hum =");
Serial.println(F);
Serial.println("Board Identifier =");
Serial.println(E);
senddata0();}
}

else if (E == 1)
{  
Serial.println("Light =");
Serial.println(A);
Serial.println("Tank =");
Serial.println(B);
Serial.println("Temperature =");

if (flag == 0)
{
Serial.println("-");  
Serial.println(C);
Serial.println("Board Identifier =");
Serial.println(E);
senddata1();}

else {
Serial.println(C);
Serial.println("Board Identifier =");
Serial.println(E);
senddata1();}
}

else if (E == 2)
{  
Serial.println("Light =");
Serial.println(A);
Serial.println("Temperature =");

if (flag == 0)
{
Serial.println("-");  
Serial.println(C);
Serial.println("Board Identifier =");
Serial.println(E);
senddata2();}

else {
Serial.println(C);
Serial.println("Board Identifier =");
Serial.println(E);
senddata2();}
}

else
{
Serial.println("error");}

delay(1000);
          
    }
  }
}

// each send data works slightly differently as each node submitts different readings but all data gets stored in the same table.
// all unused fields are simply filled with 0s
void senddata0()
{


Ethernet.begin(mac, ip);
EthernetClient client;
Serial.println();
Serial.println("Connecting");
delay(1000);						//Keeps the connection from freezing

if(client.connect(server, 80)>0) {
Serial.println("Connected");
client.print("GET http://191.168.0.1/p00602.php?temp=");
client.print(C);
client.print("&");
client.print("humid=");
client.print(D);
client.print("&");
client.print("light=");
client.print(B);
client.print("&");
client.print("s_temp=");
client.print(A);
client.print("&");
client.print("s_humid=");
client.print(F);
client.print("&");
client.print("tank=0&");
client.print("id=");
client.print(E);
client.println(" HTTP/1.1");
client.println("Host: www.server.com");
client.println();
Serial.println();
				   }

else
{
Serial.println("Connection unsuccesfull");
}
 client.stop();
 while(client.status() != 0)
{
  delay(5);
}
}

void senddata1()
{


Ethernet.begin(mac, ip);
EthernetClient client;
Serial.println();
Serial.println("Connecting");
delay(1000);						//Keeps the connection from freezing

if(client.connect(server, 80)>0) {
Serial.println("Connected");
client.print("GET http://191.168.0.1/p00602.php?temp=");
client.print(C);
client.print("&");
client.print("humid=0&");
client.print("light=");
client.print(A);
client.print("&");
client.print("s_temp=0&");
client.print("s_humid=0&");
client.print("tank=");
client.print(B);
client.print("&");
client.print("id=");
client.print(E);
client.println(" HTTP/1.1");
client.println("Host: www.server.com");
client.println();
Serial.println();
				   }

else
{
Serial.println("Connection unsuccesfull");
}
 client.stop();
 while(client.status() != 0)
{
  delay(5);
}
}

void senddata2()
{


Ethernet.begin(mac, ip);
EthernetClient client;
Serial.println();
Serial.println("Connecting");
delay(1000);						//Keeps the connection from freezing

if(client.connect(server, 80)>0) {
Serial.println("Connected");
client.print("GET http://191.168.0.1/p00602.php?temp=");
client.print(C);
client.print("&");
client.print("humid=0&");
client.print("light=");
client.print(A);
client.print("&");
client.print("s_temp=0&");
client.print("s_humid=0&");
client.print("tank=0&");
client.print("id=");
client.print(E);
client.println(" HTTP/1.1");
client.println("Host: www.server.com");
client.println();
Serial.println();
				   }

else
{
Serial.println("Connection unsuccesfull");
}
 client.stop();
 while(client.status() != 0)
{
  delay(5);
}
}
