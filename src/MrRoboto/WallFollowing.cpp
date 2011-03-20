/** Implementation file for WallFollowing class
 *
 * @file WallFollowing.cpp
 * @author Andrew Keating
 */

#include "WallFollowing.h"

void WallFollowing::followWallIteration()
{
    // rates
    /*float frontRate;
    float leftRate;
    float rightRate;*/
    
    // get readings
    uint8_t frontValue = forward->read(/*&frontRate*/);
    uint8_t leftValue = left->read(/*&leftRate*/);
    uint8_t rightValue = right->read(/*&rightRate*/);
    
    // turn detection
    /*static uint8_t rightTurns = 0;
    static uint8_t leftTurns = 0;
    if (rightRate > 40)
        rightTurns++;
    if (leftRate > 40)
        leftTurns++;*/
        
    
    // if we have come to a wall in front
    if (close(frontValue))
    {
        // and a wall to the right, then heavy turn left
        if (close(rightValue))
        {
            leftMotor->setReverse(PSMCMotor::getMaxSpeed());
            rightMotor->setForward(PSMCMotor::getMaxSpeed());
            wall = WallFollowing::RIGHT_WALL; // start following right wall
        }
        // otherwise heavy turn right
        else
        {
            leftMotor->setForward(PSMCMotor::getMaxSpeed());
            rightMotor->setReverse(PSMCMotor::getMaxSpeed());
            wall = WallFollowing::LEFT_WALL; // start following left wall
        }
    }
    
    // if we want to follow the right wall
    else if (wall == RIGHT_WALL)
    {
        // and we are not within trail, veer
        if (!within(rightValue))
        {
            // veer away, left
            if (rightValue < WallFollowing::FOLLOW_DISTANCE)
            {
                leftMotor->setForward(PSMCMotor::getMaxSpeed()/2);
                rightMotor->setForward(PSMCMotor::getMaxSpeed());
            }
            // veer in, right
            else
            {
                leftMotor->setForward(PSMCMotor::getMaxSpeed());
                rightMotor->setForward(PSMCMotor::getMaxSpeed()/2);
            }
        }
    }
    
    // if we want to follow left wall
    else
    {
        // and we are not within trail, veer
        if (!within(leftValue))
        {
            // veer away, right
            if (leftValue < WallFollowing::FOLLOW_DISTANCE)
            {
                leftMotor->setForward(PSMCMotor::getMaxSpeed());
                rightMotor->setForward(PSMCMotor::getMaxSpeed()/2);
            }
            // veer in, left
            else
            {
                leftMotor->setForward(PSMCMotor::getMaxSpeed()/2);
                rightMotor->setForward(PSMCMotor::getMaxSpeed());
            }
        }
    }
    
    
}





















