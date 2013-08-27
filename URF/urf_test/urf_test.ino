#include <FastSerial.h>
#include <AP_Common.h>
#include <urf.h>

URF urf;
FastSerialPort0(Serial);
int16_t timeLast;
int16_t alt;

void setup()
{
	Serial.begin(115200, 128, 128);
	Serial.print("Time (ms)\tRange (cm)\n");
}

void loop()
{
  //maximum read rate appears to be 10 readings/0.9 sec ~= 11.1 Hz
  timeLast = millis();
  urf.read_alt();//it takes 100 ms to read via PWM dear god
  //analog reading takes like 1 ms tops
	Serial.print(millis()-timeLast);  
    alt = urf.get_alt_cm();
	Serial.print("\t");
	Serial.print(alt);
	Serial.print("\n");
}