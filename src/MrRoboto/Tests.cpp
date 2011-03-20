/** Implementation file for Tests class
 *
 * @file Tests.cpp
 * @author Andrew Keating
 */

#define TESTS_ENABLED
#include "Tests.h"


#ifdef TESTS_ENABLED

/// wait for the user to read the whole message and continue
void Tests::waitForUser()
{
    bool exit = false;
    lcd->refresh();
    while(lcd->getCurrentPage() < (lcd->getPageCount()-1))
    {
        sw->waitTillActive();
        lcd->nextPage();
        sw->waitTillInActive();
    }
    sw->waitTillActive();
    sw->waitTillInActive();
    lcd->clear();
}



#endif
