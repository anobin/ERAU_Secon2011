/** Implementation file for ReflectivityTests class
 *
 * @file ReflectivityTests.cpp
 * @author Andrew Keating
 */

#define TESTS_ENABLED
#include "ReflectivityTests.h"

#ifdef TESTS_ENABLED

/** Setup any resources used by the test
 */
void ReflectivityTests::setup()
{  
    
}

/** Run the entire test suite. Individual tests should have the name
 * testXXXX, where XXXX is the functionality to test.
 */
void ReflectivityTests::runSuite()
{
    lcd->print("[Reflectivity Tests] PSC");
    this->Tests::waitForUser();
    testReading();
    testAveragedReading();
    lcd->print("[Reflecivity Tests] Done!");
    this->Tests::waitForUser();
}

/// test reading raw values
void ReflectivityTests::testReading()
{
    lcd->print("[Test Reading] Tests reading raw values, PSC");
    this->Tests::waitForUser();
    while(!this->Tests::sw->active())
    {
        lcd->clear();
        lcd->print("LO ");
        lcd->print(leftOut->read());
        lcd->print(" ");
        lcd->print("LI ");
        lcd->print(leftIn->read());
        lcd->print(" ");
        lcd->print("RI ");
        lcd->print(rightIn->read());
        lcd->print(" ");
        lcd->print("RO ");
        lcd->print(rightOut->read());
        lcd->print(" ");
        lcd->refresh();
        delay(500);
    }
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}

/// test going backward
void ReflectivityTests::testAveragedReading()
{
    lcd->print("[Test Averaged Reading] Tests reading averaged values, PSC");
    this->Tests::waitForUser();
    while(!this->Tests::sw->active())
    {
        int leftInAvg = 0;
        int rightInAvg = 0;
        int leftOutAvg = 0;
        int rightOutAvg = 0;
  
        // start sample average
        leftOut->startAvg(4);
        leftIn->startAvg(4);
        rightIn->startAvg(4);
        rightOut->startAvg(4);
  
        //Gather five readings from sensors
        for(int i = 0; i < 4; i++)
        {
            leftOut->addSample();
            leftIn->addSample();
            rightIn->addSample();
            rightOut->addSample();
            delay(50);   
        }
  
        //compute average of sensors
        leftInAvg = leftIn->performAverage();
        rightInAvg = rightIn->performAverage();
        leftOutAvg = leftOut->performAverage();
        rightOutAvg = rightOut->performAverage();
        
        // ouput averaged values
        lcd->clear();
        lcd->print("LO ");
        lcd->print(leftOutAvg);
        lcd->print(" ");
        lcd->print("LI ");
        lcd->print(leftInAvg);
        lcd->print(" ");
        lcd->print("RI ");
        lcd->print(rightInAvg);
        lcd->print(" ");
        lcd->print("RO ");
        lcd->print(rightOutAvg);
        lcd->print(" ");
        lcd->refresh();
        delay(300);
    }
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}
    



#endif








    
    
    
