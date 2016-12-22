//----------------------------------------------
// coursework p00602 2012
// Peter Haban
// actuator node
// version 1.0 - coursework demonstration
//----------------------------------------------

#include <Ethernet.h>
#include <SPI.h>

byte ip[] = { 191, 168, 0, 65 };
byte server[] = { 191,168,0,1 };
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
String location = "/out_3.php HTTP/1.0";
EthernetClient client;

char inString[32]; // string for incoming serial data
int stringPos = 0; // string index counter
boolean startRead = false;

void setup(){
  Ethernet.begin(mac);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop(){
  String pageValue = connectAndRead(); //connect to the server and read the output

  Serial.println(pageValue); //print out the findings.
  int i = atoi(inString); //translate what we read from the php script to an integer value
  Serial.println(inString);
  
  
  if (i > 16) //if temperature above below 16C
  {digitalWrite(7, HIGH); // green LED -> ON
   digitalWrite(8, LOW); // red LED -> OFF
   digitalWrite(2, HIGH); // fan -> ON
  }
  
  else //if temperature below below 16C
  {digitalWrite(7, LOW); // green LED -> OFF
   digitalWrite(8, HIGH); // red LED -> ON
   digitalWrite(2, LOW); // fan -> OFF
  }

  delay(5000); //wait 5 seconds before connecting again
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
