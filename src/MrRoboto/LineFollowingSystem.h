/** Header file for LineFollowingSystem class
 *
 * @file LineFollowingSystem.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_LINE_FOLLOWING_H
#define MRROBOTO_LINE_FOLLOWING_H


// always needed
#include <WProgram.h>

// for used
#include "ReflectivitySensor.h"
#include "PSMCMotor.h"



/** Represents the line following system, which is assumed to
 * use two parallel reflectivity sensors position slightly smaller than
 * a line position 7-10mm from the floor
 */
class LineFollowingSystem
{   
private:
    /// reference to left motor to control
    PSMCMotor* left;
    /// reference to right motor to control
    PSMCMotor* right;
    
    /// reference to left outside reflectivity sensor to use
    ReflectivitySensor* leftOut;
    /// reference to left inside reflectivity sensor to use
    ReflectivitySensor* leftIn;
    /// reference to right inside reflectivity sensor to use
    ReflectivitySensor* rightIn;
    /// reference to right outside reflectivity sensor to use
    ReflectivitySensor* rightOut;
    
    /// threshold for detecting light color
    int threshold;
    /// the perfect value for the light color
    int lightColorReading;
    
    /// gather five readings then
    void getAvgSensor(int* leftOutAvg,
         int* leftInAvg, int* rightInAvg, int* rightOutAvg);
    
    /*inline int ABS(int value)
    {
        return value < 0 ? value*-1 : value;
    }*/
         
    /// check whether a value is within the threshold to light colot
    inline bool lightLike(int value)
    {
        int t = value-lightColorReading;
        t = ABS(t);
        if (t <= threshold)
            return true;
        return false;
    }
    
public:
    inline LineFollowingSystem(PSMCMotor* left, PSMCMotor* right, 
             ReflectivitySensor* leftOut, ReflectivitySensor* leftIn,
             ReflectivitySensor* rightIn, ReflectivitySensor* rightOut):
             left(left), right(right), leftOut(leftOut), leftIn(leftIn),
             rightIn(rightIn), rightOut(rightOut), threshold(100),
             lightColorReading(500) {}
  
    int followLine();

    /// set the light color threshold
    inline void setThreshold(int threshold)
    {
        this->threshold = threshold;
    }
    
    /// set the perfect value for the light color reading
    inline void setPerfectLightColor(int reading)
    {
        this->lightColorReading = reading;
    }
    
};

















#endif
