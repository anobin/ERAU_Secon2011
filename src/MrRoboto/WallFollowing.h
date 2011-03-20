/** Header file for WallFollowing class
 *
 * @file WallFollowing.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_WALL_FOLLOWING_H
#define MRROBOTO_WALL_FOLLOWING_H

// always needed
#include <WProgram.h>

// needed
//#define IR_RATE
#include "PSMCMotor.h"
#include "IR.h"
#include "ReflectivitySensor.h"

/** High-level logic for performing wall following
 * using IR's
 */
class WallFollowing
{
public:
    /// walls that we can follow
    enum Walls
    {
        LEFT_WALL,
        RIGHT_WALL
    };
    
    /// distance that we try to be from the wall (cm)
    static const uint8_t FOLLOW_DISTANCE = 20;
    
    /// distance threshold (cm)
    static const uint8_t THRESHOLD = 5;
    
private:
    /// reference to left motor
    PSMCMotor* leftMotor;
    /// reference to right motor
    PSMCMotor* rightMotor;
    
    /// forward IR
    IR* forward;
    /// left IR
    IR* left;
    /// right IR
    IR* right;
    
    /// the current wall we want to follow
    Walls wall;
    
    /// test if a distance is within our distance
    inline bool within(uint8_t value)
    {
        uint8_t t = ABS(value-FOLLOW_DISTANCE);
        if (t <= THRESHOLD)
            return true;
        return false;
    }
    inline bool close(uint8_t value)
    {
        if (value < (FOLLOW_DISTANCE-THRESHOLD))
            return true;
        return false;
    }
    
public:
    /// standard constructor
    inline WallFollowing(PSMCMotor* leftMotor, PSMCMotor* rightMotor, IR* forward,
                  IR* left, IR* right): leftMotor(leftMotor), rightMotor(rightMotor),
                  forward(forward), left(left), right(right), wall(RIGHT_WALL) {}
                  
    /// perform an iteration of wall following
    void followWallIteration();
};









#endif

 
