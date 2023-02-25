/*
[Part of ADVANCED COOLING CONTROL ALGORITHM]

PCF8574 I/O expander, arduino compatible library
-------------------------------------------------

Setup library for PCF8574 I/O Expansion modules.
Each module controls two different 'Device Relay Control Blocks',
~(controls two PCF8574 modues, total (8*2) 16 I/O pins).

(I2C Protocol based) For scanning address of the available 
connected PCF8574 I2C modules and to initiate its pins in
arduino environment.

[vishnus_technologies (C) 2022]
-----------------------------------------------------------------
*/

#include <PCF8574.h>
//#include <Buzzer.h>

// device ID's [PCF8574 1: I2C_RELAY #1]
#define PELTIER1 101
#define PELTIER2 102
#define PELTIER3 103
#define PELTIER4 104
#define AC_BLOWERFAN 105
#define RADIATOR_FAN 106
#define HS_WATERPUMP 107
#define CS_WATERPUMP 108

// device ID's [PCF8574 2: I2C_RELAY #2]
#define CABINEXHAUST1_IN 201
#define CABINEXHAUST1_OUT 202
#define CABINEXHAUST2_IN 203
#define CABINEXHAUST2_OUT 204
#define CABIN2_LIGHT 205
#define NOCP0 206
#define NOCP1 207
#define NOCP2 208

/* ------------------------------------
change your PCF8574's address accordingly:
[PCF8574 8-BIT ADDRESS TABLE]
1. 000 = 0x20 (by default)
2. 001 = 0x21
3. 010 = 0x22
4. 011 = 0x23
5. 100 = 0x24
6. 101 = 0x25
7. 110 = 0x26
8. 111 = 0x27
--------------------------------------- */

// define PCF8574 addresses:
#define I2C_RELAY1_ADDR 0x25  // I2C RELAY #1
#define I2C_RELAY2_ADDR 0x38  // I2C RELAY #2

// Initiates PCF8574 class constructors
PCF8574 pcf8574(0x20);
PCF8574 I2C_RELAY1(I2C_RELAY1_ADDR);
PCF8574 I2C_RELAY2(I2C_RELAY2_ADDR);

void INIT();

// pin initiator/beginner for PCF8574 [I2C_RELAY #1, #2]:
void init_I2C_RELAY() {
  INIT();
  // I2C_RELAY #1
  if(I2C_RELAY1.begin()) {
    Serial.println(F("P202"));   // P202: "Successfully initialised I2C_RELAY #1"
  }
  else if(!I2C_RELAY1.begin()) {
    Serial.println(F("P204"));  // P204: "I2C_RELAY #1 device error!"
  }

  if(I2C_RELAY1.isConnected()) {
    Serial.println(F("P208")); // P208: "I2C RELAY #1 is connected"
  }
  else if(!I2C_RELAY1.isConnected()) {
    Serial.println(F("P209")); // P209: "I2C RELAY #1 is disconnected"
  }
  I2C_RELAY1.selectAll();   // initially release all relays [I2C_RELAY #1]

  // I2C_RELAY #2 
  if(I2C_RELAY2.begin()) {
    Serial.println(F("P205"));  // P205: "Successfully initialised I2C_RELAY #2"
  }
  else if(!I2C_RELAY2.begin()) {
    Serial.println(F("P207"));  // P204: "I2C_RELAY #2 device error!"
  }

  if(I2C_RELAY2.isConnected()) {
    Serial.println(F("P210")); // P208: "I2C RELAY #2 is connected"
  }
  else if(!I2C_RELAY2.isConnected()) {
    Serial.println(F("P211")); // P209: "I2C RELAY #2 is disconnected"
  }
  I2C_RELAY2.selectAll();   //initially release all relays [I2C_RELAY #2]
}

void INIT() {
  pcf8574.begin();
}