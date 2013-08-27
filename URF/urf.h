/*
urf.h

header file for ultrasonic rangefinder object
*/

#ifndef __URF_H_DEFINED__
#define __URF_H_DEFINED__

#include <AP_Common.h>

class URF{
public:
	//constructor
	URF();
	URF(uint8_t pin);
	//update current altitude
	void read_alt();
	uint16_t get_alt_cm();//returns altitude in centimeters
	float get_alt();//returns altitude in meters
private:
	uint16_t alt;
//pin for the URF input - default is 62, may be specified in constructor
	uint8_t urf_pin;
	int16_t _bias_offset;
};

#endif