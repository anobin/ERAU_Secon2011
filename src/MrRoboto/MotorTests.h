/** Header file for MotorTests class
 *
 * @file MotorTests.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_MOTOR_TESTS_H
#define MRROBOTO_MOTOR_TESTS_H

// always needed
#include <WProgram.h>

// include base class
#include "Tests.h"

// include needed
#include "BufferedLCD.h"
#include "Switch.h"
#include "PSMCMotor.h"


#ifdef TESTS_ENABLED

/** Holds all the motor-related tests
 */
class MotorTests : public Tests
{
private:
    /// the left motor to use
    PSMCMotor* leftMotor;
    
    /// the right motor to use
    PSMCMotor* rightMotor;
    
public:
    /// standard constructor
    inline MotorTests(BufferedLCD* lcd, Switch* sw, PSMCMotor* leftMotor,
           PSMCMotor* rightMotor): Tests(lcd, sw), leftMotor(leftMotor),
           rightMotor(rightMotor) {}

    /** Setup any resources used by the test
     */
    virtual void setup();

    /** Run the entire test suite. Individual tests should have the name
     * testXXXX, where XXXX is the functionality to test.
     */
    virtual void runSuite();

    /// test going straight
    void testStraight();

    /// test going backward
    void testBack();
    
    /// test spinning
    void testSpinning();


};



#endif

#endif

































