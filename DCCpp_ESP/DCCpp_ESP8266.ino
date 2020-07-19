///////////////////////////////////////////////////////////////////////////////
// This sketch is for loading onto an ESP8266 Wifi Module to enable WiFi communication 
// between JMRI and Arduino MEGA running DCC++
//
// It has been tested on:
//    (a) WEMOS Pro Mini D1 R1 Board communicating with an Arduino Mega 2560 on the Mega Serial 1, 2 or 3
//    (b) WEMOS Arduino Mega 2560 with the on board ESP8266 
//
///////////////////////////////////////////////////////////////////////////////
//
// Rev 1.04 - DTucker - 28/04/2019
//
///////////////////////////////////////////////////////////////////////////////

#include <ESP8266WiFi.h>              //Need the ESP8266WiFi Library for this sketch to function

#define INTERFACE eServer             // Name for Server
#define ETHERNET_PORT 2560            // Ethernet port for connectrion to JMRI
#define MAX_COMMAND_LENGTH 30         // Maximum number of characters for DCC++ command

WiFiServer INTERFACE(ETHERNET_PORT);  // Set Port number for Server to listen for connecting clients

///////////////////////////////////////////////////////////////////////////////
// Change the following variables to your Wifi IP Network Details 
// 
// IPAddress staticIP(xxx,xxx,xxx,xxx);     Set IP Address to match JMRI IP Address for Ethernet Connection
// IPAddress gateway(xxx,xxx,xxx,xxx);      Set IP Address of the Wifi Router
// IPAddress subnet(xxx,xxx,xxx,xcxx);      Set Subnet for for the Wifi network
//
///////////////////////////////////////////////////////////////////////////////

IPAddress staticIP(192,168,1,126);    // Set IP Address to match JMRI IP Address for Ethernet Connection 
IPAddress gateway(192,168,1,1);       // Set IP Address of the Wifi Router
IPAddress subnet(255,255,255,0);      // Set Subnet for for the Wifi network

///////////////////////////////////////////////////////////////////////////////
// Variable Settings for Wifi Network
//
// String nwID = "SSID";                 Set SSID to the name of the Wifi Network
// String pwd = "WiFiPassword";          Set WiFiPassword to the password for the Wifi Network
//
///////////////////////////////////////////////////////////////////////////////

String nwID = "SSID";                 // Variable for SSID of Wifi Network
String pwd = "WiFiPassword";          // Variable for Password of Wifi Network
//String c_str = "";                    // Incoming string from the Wifi client
//String s_str = "";                    // Incoming string from the Serial Port
int incomingByte = 0;                 // Incoming data from Serial Port

////////////////////////////////////////////////////////////////////////////
//  Sketch Setup - Setup Wifi Connection and start Server
//
//  For WiFi connection checking remove // from the Serial.Print code so the ESP8266  
//  will output connection details on its Serial port.
//

void setup()
{
  Serial.begin(115200);                                 // Sets ESP8266 serial link to 115200 baud rate

  WiFi.config(staticIP, gateway, subnet);               // Sets the IP address of the ESP8266
  WiFi.mode(WIFI_STA);                                  // Ensure ESP8266 connects in STATION Mode
  WiFi.begin(nwID,pwd );                                // connect to Wifi network with SSID and Password

//  Serial.println();
//  Serial.println("ESP Connecting to Wifi Network");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
//    Serial.print(".");
  }
//  Serial.println();

//  Serial.print("ESP Connected, IP address: ");
//  Serial.println(WiFi.localIP());

  INTERFACE.begin();                  // Start Server as INTERFACE to listen for incoming client connections 
  INTERFACE.setNoDelay(true);         // Turn NoDelay ON so maximise responses and minimise the response time
  
//  WiFi.printDiag(Serial);             // Prints diagnostic info to serial port  // Prints the ESP8266 diagnostics
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The void loop
// 
//         a) listens for incoming messages from the JMRI on the Wifi Port and sends them to the Arduino on the ESP8266 Serial Port 
//         b) listens for incoming messages from the Arduino on the ESP826 Serial Port and sends them to the JMRI on the Wifi Port
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
 
  WiFiClient client = INTERFACE.available();
 
  if (client) {

    while (client.connected()) {       //while a client is connected

//////////////////////////////////////////////////////////////////
      while (client.available()) {     // start of while loop for incoming data from clinet, process the data

              char c = client.read();                           // read byte from client data
              Serial.print(c);                                  // Print the byte to the Serial Port
               
            }                                                   // End of While for Client Data from Wifi

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of Data processing while Serial data available from Arduino on ESP8266 Serial Port
//

             while (Serial.available()) {                       // While data available of the Esp8266 Serial Port

                  char incomingByte = (char)Serial.read();      // get the new data byte:
                  client.print(incomingByte);                   // Send serial byte to connected client via the Wifi
                  
                }                                               // End of While for Data received on the ESP8266 Serial Port from the Arduino
//////////////////////////////////////////////////////////////////
           }
  }
}
