/** Implementation file for IRTests class
 *
 * @file IRTests.cpp
 * @author Andrew Keating
 */

#define TESTS_ENABLED
#define IR_RATE
#include "IRTests.h"

#ifdef TESTS_ENABLED

/** Setup any resources used by the test
 */
void IRTests::setup()
{  
    
}

/** Run the entire test suite. Individual tests should have the name
 * testXXXX, where XXXX is the functionality to test.
 */
void IRTests::runSuite()
{
    lcd->print("[IR Tests] PSC");
    this->Tests::waitForUser();
    testIndividual();
    testReading();
    //testRate();
    lcd->print("[IR Tests] Done!");
    this->Tests::waitForUser();
}

/// test individual sensors
void IRTests::testIndividual()
{
    lcd->print("[Test Individual] Tests sensors individually, PSC");
    this->Tests::waitForUser();

    lcd->clear();
    lcd->print("FL ");
    lcd->print(frontLeft->read(), DEC);
    lcd->refresh();
    this->Tests::waitForUser();
    lcd->clear();
    lcd->print("R ");
    lcd->print(right->read(), DEC);
    lcd->refresh();
    this->Tests::waitForUser();
    lcd->clear();
    lcd->print("L ");
    lcd->print(left->read(), DEC);
    lcd->refresh();
    this->Tests::waitForUser();
    lcd->clear();
    lcd->print("FR ");
    lcd->print(frontRight->read(), DEC);
    lcd->refresh();
    this->Tests::waitForUser();
        
  
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}

/// test reading raw values
void IRTests::testReading()
{
    lcd->print("[Test Reading] Tests reading raw values, PSC");
    this->Tests::waitForUser();
    while(!this->Tests::sw->active())
    {
        lcd->clear();
        lcd->print("L ");
        lcd->print(left->read(), DEC);
        lcd->print(" ");
        lcd->print("FL ");
        lcd->print(frontLeft->read(), DEC);
        lcd->print(" ");
        lcd->print("FR ");
        lcd->print(frontRight->read(), DEC);
        lcd->print(" ");
        lcd->print("R ");
        lcd->print(right->read(), DEC);
        lcd->print(" ");
        lcd->refresh();
        delay(500);
    }
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}

/// test the rate calcs
/*void IRTests::testRate()
{
    lcd->print("[Test Rate] Tests reading rate values, PSC");
    this->Tests::waitForUser();
    while(!this->Tests::sw->active())
    {
        lcd->clear();
        lcd->print("L ");
        float t;
        left->read(&t);
        lcd->print(t);
        lcd->print(" ");
        lcd->print("FL ");
        frontLeft->read(&t);
        lcd->print(t);
        lcd->print(" ");
        lcd->print("FR ");
        frontRight->read(&t);
        lcd->print(t);
        lcd->print(" ");
        lcd->print("R ");
        right->read(&t);
        lcd->print(t);
        lcd->print(" ");
        lcd->refresh();
        delay(500);
    }
    this->Tests::sw->waitTillInActive();
    lcd->clear();
}*/
    



#endif








    
    
    
