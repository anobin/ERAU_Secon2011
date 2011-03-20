/** Header file for IRTests class
 *
 * @file IRTests.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_IR_TESTS_H
#define MRROBOTO_IR_TESTS_H

// always needed
#include <WProgram.h>

// include base class
#include "Tests.h"

// include needed
#include "BufferedLCD.h"
#include "Switch.h"
#include "IR.h"


#ifdef TESTS_ENABLED

/** Holds all the IR-related tests
 */
class IRTests : public Tests
{
private:
    /// reference to left IR
    IR* left;
    /// reference to right IR
    IR* right;
    /// reference to front left
    IR* frontLeft;
    /// reference to front right
    IR* frontRight;
    
public:
    /// standard constructor
    inline IRTests(BufferedLCD* lcd, Switch* sw, IR* leftOut,
           IR* leftIn, IR* rightIn, IR* rightOut)
           : Tests(lcd, sw), left(left), frontLeft(frontLeft), frontRight(frontRight) {}

    /** Setup any resources used by the test
     */
    virtual void setup();

    /** Run the entire test suite. Individual tests should have the name
     * testXXXX, where XXXX is the functionality to test.
     */
    virtual void runSuite();

    /// test raw reading
    void testReading();
    
    /// test rate values
   // void testRate();
    
    // test individual sensors
    void testIndividual();

};



#endif

#endif

































