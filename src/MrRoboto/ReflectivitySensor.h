/** Header file for ReflectiveSensor class
 *
 * @file ReflectiveSensor.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_REFLECTIVE_SENSOR_H
#define MRROBOTO_REFLECTIVE_SENSOR_H

// always needed
#include <WProgram.h>

// for ABS
#include "Utils.h"

/** Interface to ReflectivitySensor
 */
class ReflectivitySensor
{
public:
	/// generic average color values from a distance of 8 mm
	enum Colors
	{
		RED   = 0,
		GREEN = 1,
		BLUE  = 2,
		BLACK = 3,
		WHITE = 4
	};
    
    /// the max number of samples
    static const uint8_t MAX_AVG_SAMPLES = 10;
	
private:
	/// analog pin sensor is connected to
	uint8_t pin;
	
	/// max number of average color values
	static const int maxColors = 5;
	
	/// array of average color values from a distance of 8 mm
	static const int colorValues[maxColors];
    
    /// adjustment value for every reading
    int adjustment;
    
    /// array of averages
    int samples[MAX_AVG_SAMPLES];
    /// number of samples to average currently
    uint8_t sampleCount;
    /// number of the current sample
    uint8_t curSample;
	
public:
	/// standard contructor
	inline ReflectivitySensor(uint8_t pin): pin(pin), adjustment(0), 
        sampleCount(0), curSample(0) {}

	/// get reading value, from 0 to 1024
	inline int read() const
	{
		return analogRead(pin) + adjustment;
	}
	
	/// start delay algorithmn with a number of samples
    inline void startAvg(uint8_t samples)
    {
        sampleCount = samples;
        curSample = 0;
    }
    
    /// record a sample for averaging
    inline bool addSample()
    {
        if (curSample >= sampleCount)
            return false;
        samples[curSample] = this->read();
        curSample++;
        return true;
    }
    
    /// perform average of current samples
    int performAverage();

	/// get closest average color value
	inline Colors getColor() const
	{
		int v = this->read();
                int closet = 0;
                int dis = 2000;
		for (int i=0; i < ReflectivitySensor::maxColors; i++)
                {
                    int loc = ABS(ReflectivitySensor::colorValues[i]-v);
                    if (loc < dis)
                    {
                      closet = i;
                      dis = loc;
                    }
                }
                return (ReflectivitySensor::Colors)closet;
	}
	
	/// set adjustment
    inline void setAdjustment(int a)
    {
        this->adjustment = a;
    }
    
};








#endif









