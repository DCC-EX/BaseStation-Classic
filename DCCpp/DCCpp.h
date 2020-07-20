/**********************************************************************

DCCpp.h
COPYRIGHT (c) 2013-2016 Gregg E. Berman

Part of DCC++ BASE STATION for the Arduino

**********************************************************************/

#include "Config.h"

#ifndef DCCpp_h
#define DCCpp_h

/////////////////////////////////////////////////////////////////////////////////////
// RELEASE VERSION
/////////////////////////////////////////////////////////////////////////////////////

#define VERSION "1.2.1+"

/////////////////////////////////////////////////////////////////////////////////////
// AUTO-SELECT ARDUINO BOARD
/////////////////////////////////////////////////////////////////////////////////////

#ifdef ARDUINO_AVR_MEGA                   // is using Mega 1280, define as Mega 2560 (pinouts and functionality are identical)
  #define ARDUINO_AVR_MEGA2560
#endif

#if defined  ARDUINO_AVR_UNO

  #define ARDUINO_TYPE    "UNO"

  #define DCC_SIGNAL_PIN_MAIN 10          // Ardunio Uno  - uses OC1B
  #define DCC_SIGNAL_PIN_PROG 5           // Arduino Uno  - uses OC0B

  #if COMM_INTERFACE != 0                 // Serial was not selected

    #error CANNOT COMPILE - DCC++ FOR THE UNO CAN ONLY USE SERIAL COMMUNICATION - PLEASE SELECT THIS IN THE CONFIG FILE

  #endif

#elif defined  ARDUINO_AVR_MEGA2560

  #define ARDUINO_TYPE    "MEGA"

  #define DCC_SIGNAL_PIN_MAIN 12          // Arduino Mega - uses OC1B
  #define DCC_SIGNAL_PIN_PROG 2           // Arduino Mega - uses OC3B

#else

  #error CANNOT COMPILE - DCC++ ONLY WORKS WITH AN ARDUINO UNO OR AN ARDUINO MEGA 1280/2560

#endif

/////////////////////////////////////////////////////////////////////////////////////
// SELECT MOTOR SHIELD
/////////////////////////////////////////////////////////////////////////////////////

#if MOTOR_SHIELD_TYPE == 0

  #define MOTOR_SHIELD_NAME "ARDUINO MOTOR SHIELD"

  #define SIGNAL_ENABLE_PIN_MAIN 3
  #define SIGNAL_ENABLE_PIN_PROG 11

  #define CURRENT_MONITOR_PIN_MAIN A0
  #define CURRENT_MONITOR_PIN_PROG A1

  #define DIRECTION_MOTOR_CHANNEL_PIN_A 12
  #define DIRECTION_MOTOR_CHANNEL_PIN_B 13

#elif MOTOR_SHIELD_TYPE == 1

  #define MOTOR_SHIELD_NAME "POLOLU MC33926 MOTOR SHIELD"

  #define SIGNAL_ENABLE_PIN_MAIN 9
  #define SIGNAL_ENABLE_PIN_PROG 11

  #define CURRENT_MONITOR_PIN_MAIN A0
  #define CURRENT_MONITOR_PIN_PROG A1

  #define DIRECTION_MOTOR_CHANNEL_PIN_A 7
  #define DIRECTION_MOTOR_CHANNEL_PIN_B 8

#else

  #error CANNOT COMPILE - PLEASE SELECT A PROPER MOTOR SHIELD TYPE

#endif

/////////////////////////////////////////////////////////////////////////////////////
// SELECT COMMUNICATION INTERACE
/////////////////////////////////////////////////////////////////////////////////////

#if COMM_INTERFACE == 0

  #if (SERIAL_PORT == 0)
    #define COMM_TYPE 0
    #define INTERFACE Serial
  #endif

  #if (SERIAL_PORT == 1)
    #define COMM_TYPE 0
    #define INTERFACE Serial1
  #endif  

  #if (SERIAL_PORT == 2)
    #define COMM_TYPE 0
    #define INTERFACE Serial2
  #endif

  #if (SERIAL_PORT == 3)
    #define COMM_TYPE 0
    #define INTERFACE Serial3
  #endif

#elif (COMM_INTERFACE==1) || (COMM_INTERFACE==2) || (COMM_INTERFACE==3)

  #define COMM_TYPE 1
  #define INTERFACE eServer
  #define SDCARD_CS 4
  
#else

  #error CANNOT COMPILE - Please select a proper value for COMM_INTERFACE in CONFIG.H file

#endif

#endif
