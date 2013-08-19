//VSCL - class for computing airspeed from five-hole probe readings
//	modelled after the existing AP_Airspeed class for syntactical consistency

#ifndef __FHP_AIRSPEED_INCLUDED__
#define __FHP_AIRSPEED_INCLUDED__

#include <AP_Common.h>
#include <AP_Param.h>

class FHP_Airspeed {
public:
	//constructor
	void FHP_Airspeed(FHP* source);
	void read();//read the source and update airspeed
	void calibrate(void (*callback)(unsigned long t));//calibrate zero airspeed on startup
	float get_airspeed();//return the current airspeed
	float get_airspeed_cm();//return airspeed in cm/s
	bool use();//return 1 if airspeed is enabled and use is set to "on"
	bool enabled();//return 1 if airspeed is enabled
	void set_HIL(float airspeed);//set the airspeed from to a given value in HIL mode
	static const struct AP_Param::GroupInfo         var_info[];
private:
	FHP* _source;
	AP_Int8         _use;
    AP_Int8         _enable;
    float           _airspeed;
	//coefficient vectors for polynomial fits to compute airspeed, angle-of-attack, and sideslip
	const double[] Cq_a = {0.9534521504842,-0.00430393572210401,-0.00277037855396079,0.00103120935887708,-0.0468367633310386};
	const double[] Cq_b = {0.952092573306363,-0.00394141318945571,-0.0130476614630522,-0.0111801307500386,-0.0462961679965432};
	const double[] C_a = {0.174765241265372,17.3280853933476,-0.427732349516511,0.8064240343191,0.383140187656122};
	const double[] C_b = {1.88295731457312,17.588305755074,-0.062377037608365,0.570757479525977,-0.321504793057219};
	//factor: used to compute airspeed. factor = 133.3226/1.13471 = [conversion factor from Torr to SI]/[assumed air density at 318 ft ASL on a 70 degC day]
	const double factor = 117.494866;
};

#endif