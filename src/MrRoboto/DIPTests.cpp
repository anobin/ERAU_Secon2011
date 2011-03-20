/** Implementation file for DIPTests class
 *
 * @file DIPTests.h
 * @author Andrew Keating
 */

#define TESTS_ENABLED
#include "DIPTests.h"


#ifdef TESTS_ENABLED

/** Setup any resources used by the test
 */
void DIPTests::setup()
{
    
}

/** Run the entire test suite. Individual tests should have the name
 * testXXXX, where XXXX is the functionality to test.
 */
void DIPTests::runSuite()
{
    lcd->print("[DIP Switches Test Suite] Press switch to start");
    this->Tests::waitForUser();
    
    this->testSwitches();
    
    lcd->print("[DIP Switches Test Suite] Done!");
    this->Tests::waitForUser();
}

/// test going straight
void DIPTests::testSwitches()
{
    lcd->print("[Test Switches] Shows the values of each DIP switch");
    this->Tests::waitForUser();
    
    while(!this->Tests::sw->active())
    {
        lcd->clear();
        for (int i=0; i < switches->getSwitchCount(); i++)
        {
            lcd->print(i, DEC);
            lcd->print(switches->getSwitch(i)->active());
            lcd->print(",");
        }
        lcd->refresh();
        delay(200);
    }
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}



#endif






















