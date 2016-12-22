//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// master node/data concentrator
// version 1.0 - coursework demonstration
//----------------------------------------------


#include <Ethernet.h>
#include <SPI.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 5, 4, 3, 2);

byte mac[] = { 0xAD, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 191, 168, 0, 66 };
byte server[] = {191, 168, 0, 1};; // Server IP
String location = "/out_3.php HTTP/1.0";

EthernetClient client;
char inString[32]; // string for incoming serial data
int stringPos = 0; // string index counter
boolean startRead = false;

void setup(){
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("node1 temp:"); //first line of the LCD to indicate what we are reading from the database
}

void loop(){
  String pageValue = connectAndRead(); //connect to the server and read the output

  Serial.println(pageValue); //print out the findings.
  int i = atoi(inString); //translate what we read from the php script to an integer value
  Serial.println(inString);
  
  

  lcd.setCursor(0, 1);

  lcd.print(i); //result from the php script gets displayed in the second line of the LCD

  delay(5000);
}

String connectAndRead(){
  //connect to the server

  Serial.println("connecting...");

  //port 80 is typical of a www page
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET ");
    client.println(location);
    client.println();

    //Connected - Read the page
    return readPage(); //go and read the output

  }else{
    return "connection failed";
  }

}

String readPage(){
  //read the page, and capture & return everything between '<' and '>'

  stringPos = 0;
  memset( &inString, 0, 32 ); //clear inString memory

  while(true){

    if (client.available()) {
      char c = client.read();

      if (c == '<' ) { //'<' is our begining character
        startRead = true; //Ready to start reading the part 
      }else if(startRead){

        if(c != '>'){ //'>' is our ending character
          inString[stringPos] = c;
          stringPos ++;
        }else{
          //got what we need, let's disconnect
          startRead = false;
          client.stop();
          client.flush();
          Serial.println("disconnecting.");
          return inString;

        }

      }
    }

  }

}
