/** Header file for ReflectivityTests class
 *
 * @file ReflectivityTests.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_REFLECTIVITY_TESTS_H
#define MRROBOTO_REFLECTIVITY_TESTS_H

// always needed
#include <WProgram.h>

// include base class
#include "Tests.h"

// include needed
#include "BufferedLCD.h"
#include "Switch.h"
#include "ReflectivitySensor.h"


#ifdef TESTS_ENABLED

/** Holds all the reflectivity-related tests
 */
class ReflectivityTests : public Tests
{
private:
    /// reference to left outer sensor
    ReflectivitySensor* leftOut;
    /// reference to left inner sensor
    ReflectivitySensor* leftIn;
    /// reference to right inner sensor
    ReflectivitySensor* rightIn;
    /// reference to right outer sensor
    ReflectivitySensor* rightOut;
    
public:
    /// standard constructor
    inline ReflectivityTests(BufferedLCD* lcd, Switch* sw, ReflectivitySensor* leftOut,
           ReflectivitySensor* leftIn, ReflectivitySensor* rightIn, ReflectivitySensor* rightOut)
           : Tests(lcd, sw), leftOut(leftOut), leftIn(leftIn), rightIn(rightIn), rightOut(rightOut) {}

    /** Setup any resources used by the test
     */
    virtual void setup();

    /** Run the entire test suite. Individual tests should have the name
     * testXXXX, where XXXX is the functionality to test.
     */
    virtual void runSuite();

    /// test raw reading
    void testReading();
    
    /// test averaged readings
    void testAveragedReading();

};



#endif

#endif

































