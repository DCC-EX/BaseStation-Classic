/**********************************************************************

Config.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

*******************************************************************************************************
Modified to enable selection of different COMM ports for the Arduino MEGA (will not work on Uno as only one serial poet)
This modification allows the use of Serial1, Serial2 or Serial3 for the DCC Command/Response packets.

Suggested use, 

a) to allow for ESP8266 unit to provide WIFI network connectivity
b) can use Serial0 for Arduino IDE and Serial1, 2, or 3 for DCC communications, can look at Arduino msgs at same time as DCC comms

**********************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE MOTOR_SHIELD_TYPE ACCORDING TO THE FOLLOWING TABLE:
//
//  0 = ARDUINO MOTOR SHIELD          (MAX 18V/2A PER CHANNEL)
//  1 = POLOLU MC33926 MOTOR SHIELD   (MAX 28V/3A PER CHANNEL)

#define MOTOR_SHIELD_TYPE   0

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE NUMBER OF MAIN TRACK REGISTER

#define MAX_MAIN_REGISTERS 12

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE COMMUNICATIONS INTERFACE
//
//  0 = Serial Port on Arduino - Port Number is selected in the next Variable "SERIAL_PORT
//  1 = Arduino.cc Ethernet/SD-Card Shield
//  2 = Arduino.org Ethernet/SD-Card Shield
//  3 = Seeed Studio Ethernet/SD-Card Shield W5200

#define COMM_INTERFACE 0

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE SERIAL PORT for DCC Communications
// This allows the use of Wifi Modules (eg ESP8266 for DCC Communications) or USB to RS232 converters
//
//  0 = Serial Port - Serial (this is the USB Port - named Serial or Serial0)  - This is the only Port available to DCC++ on the Arduino UNO 
//  1 = Serial Port - Serial1
//  2 = Serial Port - Serial2
//  3 = Serial Port - Serial3 (Note - Wemos Mega Board uses Serial3 for comms between Mega and onboard ESP8266)
//
//  SERIAL_PORT added by DTucker

#define SERIAL_PORT 3

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE STATIC IP ADDRESS *OR* COMMENT OUT TO USE DHCP
//

//#define IP_ADDRESS { 192, 168, 1, 200 }

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE PORT TO USE FOR ETHERNET COMMUNICATIONS INTERFACE
//

#define ETHERNET_PORT 2560

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE MAC ADDRESS ARRAY FOR ETHERNET COMMUNICATIONS INTERFACE
//

#define MAC_ADDRESS {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF }

/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
// SET WHETHER TO SHOW PACKETS - DIAGNOSTIC MODE ONLY
/////////////////////////////////////////////////////////////////////////////////////
//
// If SHOW_PACKETS is set to 1, then for select main operations track commands that modify an internal DCC packet register,
// if printFlag for that command is also set to 1, DCC++ BASE STATION will additionally return the 
// DCC packet contents of the modified register in the following format:

//    <* REG: B1 B2 ... Bn CSUM / REPEAT>
//
//    REG: the number of the main operations track packet register that was modified
//    B1: the first hexidecimal byte of the DCC packet
//    B2: the second hexidecimal byte of the DCC packet
//    Bn: the nth hexidecimal byte of the DCC packet
//    CSUM: a checksum byte that is required to be the final byte in any DCC packet
//    REPEAT: the number of times the DCC packet was re-transmitted to the tracks after its iniital transmission
 
#define SHOW_PACKETS  0       // set to zero to disable printing of every packet for select main operations track commands

/////////////////////////////////////////////////////////////////////////////////////