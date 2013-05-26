/* Wii Remote IR Sensor Test Sketch
   2011 Andrew Beckett - drasnor@tamu.edu
   
   Tests PixArt IR sensor and writes tracked blobs to serial port 0.
   
   Any tracked blob will generate a serial message of "BLOB# Detected: X:xxxx Y:yyyy" at roughly 10Hz.
   With the plastic filter off, the detector can track a lit candle or match at arm's length.
*/ 

#include <AP_PixArt.h>
#include <I2C.h>

#define baud_rate 57600 // serial port baud rate
/* Sensitivity settings guide:
p0: MAXSIZE: Maximum blob size. Wii uses values from 0x62 to 0xc8
p1: GAIN: Sensor Gain. Smaller values = higher gain
p2: GAINLIMIT: Sensor Gain Limit. Must be less than GAIN for camera to function. No other effect?
p3: MINSIZE: Minimum blob size. Wii uses values from 3 to 5
*/

// Default settings:
int p0=0x72; int p1=0x20; int p2=0x1F; int p3=0x03; // Kako 1
//int p0=0xC8; int p1=0x36; int p2=0x35; int p3=0x03; // Kako 2
//int p0=0xAA; int p1=0x64; int p2=0x63; int p3=0x03; // Kako 3
//int p0=0x96; int p1=0xB4; int p2=0xB3; int p3=0x04; // Kako 4
//int p0=0x96; int p1=0xFE; int p2=0xFD; int p3=0x05; // Kako 5

const int ledPin = 13; // standard pin for Arduino built-in LED
//const int ledPin = 37; // pc0 APM1 Oilpan green LED 'A'
boolean ledState = false;
uint8_t mask; // active blobs bitmask. See AP_PixArt driver library for details.

AP_PixArt IRcam; // IR sensor object.

void setup() {
  I2c.begin();
  IRcam.init();
  Serial.begin(baud_rate); // open serial port
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
  IRcam.setSensitivity(p0,p1,p2,p3);
  Serial.println("Initialized!");
}

  void loop() {
  // Toggle LED
  ledState = !ledState;
  if (ledState) { digitalWrite(ledPin,HIGH); } else { digitalWrite(ledPin,LOW); }
  
  mask = IRcam.read(); // update sensor state and get active blobs list

  if (mask & 0x01) {
    Serial.print("BLOB0 detected. X:");
    Serial.print(IRcam.getBlobX(0));
    Serial.print(" Y:");
    Serial.println(IRcam.getBlobY(0));
  }
  if (mask & 0x02) {
    Serial.print("BLOB1 detected. X:");
    Serial.print(IRcam.getBlobX(1));
    Serial.print(" Y:");
    Serial.println(IRcam.getBlobY(1));
  }
  if (mask & 0x04) {
    Serial.print("BLOB2 detected. X:");
    Serial.print(IRcam.getBlobX(2));
    Serial.print(" Y:");
    Serial.println(IRcam.getBlobY(2));
  }
  if (mask & 0x08) {
    Serial.print("BLOB3 detected. X:");
    Serial.print(IRcam.getBlobX(3));
    Serial.print(" Y:");
    Serial.println(IRcam.getBlobY(3));
  }

  // Short delay...
  delay(100);
}