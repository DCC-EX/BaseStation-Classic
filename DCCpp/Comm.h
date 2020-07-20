

/**********************************************************************

Comm.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

Due to PIN 12 conflict the ETHERNET shield cannot be used with the Arduino UNO

//////////////////////////////////////////////////////////////////////
PINS used for ARDUINO-CC ETHERNET SHIELD (WIZNET 5100) on MEGA
COMM_INTERFACE == 1

D4:  SD card chip Selection - must be set HIGH
D10: W5200 Chip Selection
D50: SPI MOSI
D51: SPI MISO
D52: SPI SCK
D53. Not used for shield comms but must be set as output for SPI port to operated

//////////////////////////////////////////////////////////////////////
PINS used for ARDUINO-ORG ETHERNET-2 SHIELD (WIZNET 5500) on MEGA
COMM_INTERFACE == 2

D4:  SD card chip Selection - must be set HIGH
D10: W5200 Chip Selection
D50: SPI MOSI
D51: SPI MISO
D52: SPI SCK
D53. Not used for shield comms but must be set as output for SPI port to operated

//////////////////////////////////////////////////////////////////////
PINS used for SEEED STUDIO ETHERNET SHIELD (WIZNET 5200) on MEGA
COMM_INTERFACE == 3

D4:  SD card chip Selection - must be set HIGH
D10: W5200 Chip Selection
D50: SPI MOSI
D51: SPI MISO
D52: SPI SCK
D53. Not used for shield comms but must be set as output for SPI port to operate

**********************************************************************/

#include "Config.h"

#if COMM_TYPE == 1                 // Ethernet Shield Card Selected

  #if COMM_INTERFACE == 1
    #define COMM_SHIELD_NAME      "ARDUINO-CC ETHERNET SHIELD (WIZNET 5100)"
    #include <Ethernet.h>         // built-in Arduino.cc library

  #elif COMM_INTERFACE == 2
    #define COMM_SHIELD_NAME      "ARDUINO-ORG ETHERNET-2 SHIELD (WIZNET 5500)"
    #include <Ethernet2.h>        // https://github.com/arduino-org/Arduino

  #elif COMM_INTERFACE == 3
    #define COMM_SHIELD_NAME      "SEEED STUDIO ETHERNET SHIELD (WIZNET 5200)"
    #include <EthernetV2_0.h>     // https://github.com/Seeed-Studio/Ethernet_Shield_W5200

  #endif

  extern EthernetServer INTERFACE;
#endif
