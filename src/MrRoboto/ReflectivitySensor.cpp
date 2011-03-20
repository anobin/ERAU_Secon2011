/** Implementation file for ReflectivitySensor clas
 *
 * @file ReflectivitySensor.cpp
 * @author Andrew Keating
 */


#include "ReflectivitySensor.h"

const int ReflectivitySensor::colorValues[ReflectivitySensor::maxColors] =
{
	470,	// Red
	435,	// Green
	469,	// Blue
	900,	// Black
	100	// White
};

/// perform average of current samples
int ReflectivitySensor::performAverage()
{
    int avg = 0;
  
    // sum
    for(int i = 0; i < sampleCount; i++)
        avg += samples[i];
  
    // average
    return (avg / sampleCount);
}



