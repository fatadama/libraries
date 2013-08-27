/*
urf.cpp

function definitions for ultrasonic rangefinder class object
*/

#include "urf.h"

//scale factor for reading PWM inputs - constant for MB12## series rangefinders in PWM output mode
//static const float scaling = 0.017241;//scale factor in cm/microsecond
static const float scaling = 1.0;//scale factor for analog reading

URF::URF()
{
	urf_pin = 62;
	//declare pin as an input
	//pinMode(urf_pin,INPUT);
	//set bias value
	_bias_offset = 0;//centimeters
}

URF::URF(uint8_t pin)
{
	urf_pin = pin;
	//declare pin as input
	//pinMode(urf_pin,INPUT);
	//set bias value
	_bias_offset = 0;//centimeters
}

void URF::read_alt()
{
	//read pwn input from urf
	//alt = pulseIn(urf_pin,HIGH);
	alt = analogRead(urf_pin);
	//scale to output in centimeters
	alt*=scaling;
	//subtract bias value:
	alt-=_bias_offset;
}

uint16_t URF::get_alt_cm()
{
	return alt;
}

float URF::get_alt()
{
	return(0.01*alt);
}
