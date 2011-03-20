/** Header file for DIPTests class
 *
 * @file DIPTests.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_DIP_TESTS_H
#define MRROBOTO_DIP_TESTS_H

// always needed
#include <WProgram.h>

// include base class
#include "Tests.h"

// include needed
#include "SwitchCollection.h"
#include "Switch.h"


#ifdef TESTS_ENABLED

/** Holds all the DIP switch related tests
 */
class DIPTests : public Tests
{
private:
    /// The switch collection to test
    SwitchCollection* switches;
    
public:
    /// standard constructor
    inline DIPTests(BufferedLCD* lcd, Switch* sw, SwitchCollection* switches): 
        Tests(lcd, sw), switches(switches) {}

    /** Setup any resources used by the test
     */
    virtual void setup();

    /** Run the entire test suite. Individual tests should have the name
     * testXXXX, where XXXX is the functionality to test.
     */
    virtual void runSuite();

    /// test going straight
    void testSwitches();


};



#endif
#endif

































