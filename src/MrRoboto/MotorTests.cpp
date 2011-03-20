/** Implementation file for MotorTests class
 *
 * @file MotorTests.cpp
 * @author Andrew Keating
 */

#define TESTS_ENABLED
#include "MotorTests.h"

#ifdef TESTS_ENABLED

/** Setup any resources used by the test
 */
void MotorTests::setup()
{  
    leftMotor->start();
    rightMotor->start();
}

/** Run the entire test suite. Individual tests should have the name
 * testXXXX, where XXXX is the functionality to test.
 */
void MotorTests::runSuite()
{
    lcd->print("[Motor Test Suite] Press switch to start");
    this->Tests::waitForUser();
    testStraight();
    testBack();
    testSpinning();
    lcd->print("[Motor Test Suite] Done!");
    this->Tests::waitForUser();
}

/// test going straight
void MotorTests::testStraight()
{
    lcd->print("[Test Straight] Drives both motors straight, press switch to stop motors");
    this->Tests::waitForUser();
    lcd->print("Driving Straight");
    leftMotor->setForward(PSMCMotor::getMaxSpeed());
    rightMotor->setForward(PSMCMotor::getMaxSpeed());
    this->Tests::waitForUser();
    leftMotor->brake();
    rightMotor->brake();
}

/// test going backward
void MotorTests::testBack()
{
    lcd->print("[Test Back] Drives both motors in reverse, press switch to stop motors");
    this->Tests::waitForUser();
    lcd->print("Driving Back");
    leftMotor->setReverse(PSMCMotor::getMaxSpeed());
    rightMotor->setReverse(PSMCMotor::getMaxSpeed());
    this->Tests::waitForUser();
    leftMotor->brake();
    rightMotor->brake();
}
    
/// test spinning
void MotorTests::testSpinning()
{
    lcd->print("[Test Spinning] Drives both motors in turn, press switch to stop motors");
    this->Tests::waitForUser();
    lcd->print("Motors Spinning");
    leftMotor->setForward(PSMCMotor::getMaxSpeed());
    rightMotor->setReverse(PSMCMotor::getMaxSpeed());
    this->Tests::waitForUser();
    leftMotor->brake();
    rightMotor->brake();
}

#endif






    
    
    
