/** Header file for Tests class
 *
 * @file Tests.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_TESTS_H
#define MRROBOTO_TESTS_H

// always needed
#include <WProgram.h>

// for output and switching pages
#include "BufferedLCD.h"
#include "Switch.h"


#ifdef TESTS_ENABLED

/** Base class for any test suite, helps to facilitate
 * testing based around messages with human interaction
 * in the form of a single switch.
 */
class Tests
{
private:
    /// default constructor
    inline Tests() {}
    
protected:
    /// lcd screen for output
    BufferedLCD* lcd;
    
    /// switch for interaction
    Switch* sw;
    
    /// wait for the user to read the whole message and continue
    void waitForUser();
    
    /// standard constructor
    inline Tests(BufferedLCD* lcd, Switch* sw): lcd(lcd), sw(sw) {}

public:
    
    /** Setup any resources used by the test
     */
    virtual void setup() = 0;

    /** Run the entire test suite. Individual tests should have the name
     * testXXXX, where XXXX is the functionality to test.
     */
    virtual void runSuite() = 0;


};



#endif
#endif




















