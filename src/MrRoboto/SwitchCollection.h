/** Header file for SwitchCollection class
 *
 * @file SwitchCollection.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SWITCH_COLLECTION_H
#define MRROBOTO_SWITCH_COLLECTION_H

// always needed
#include <WProgram.h>

// for collection
#include "Switch.h"

/** Represents a collection of switches, simply for convenience
 */
class SwitchCollection
{
public:
    /// max supported number of switches
    static const uint8_t MAX_SWITCHES = 10;
    
private:
    /// collection of switches
    Switch* collection[MAX_SWITCHES];
    
    /// the number of current switches
    uint8_t switchNum;
    
public:
    /// standard constructor
    inline SwitchCollection(): switchNum(0) {}
    
    /// get the number of switches connected
    inline uint8_t getSwitchCount()
    {
        return this->switchNum;
    }
    
    /** Add a switch to the collection
     * @param switch the switch to add
     * @return true for added, false for max switches hit
     */
    inline bool addSwitch(Switch* sw)
    {
        if (switchNum == MAX_SWITCHES)
            return false;
        collection[switchNum] = sw;
        switchNum++;
        return true;
    }

    /** Get a switch by number
     * @param num the number of the switch to get
     * @return the switch or NULL if switch does not exist
     */
    inline Switch* getSwitch(uint8_t num)
    {
        if (num >= MAX_SWITCHES)
            return NULL;
        return collection[num];
    }

};





#endif















