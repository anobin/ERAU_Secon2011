/** Header file for Switch class
 *
 * @file Switch.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SWITCH_H
#define MRROBOTO_SWITCH_H

// always needed
#include <WProgram.h>


/** Represents the interface to a single switch,
 * normally opened or closed
 */
class Switch
{
public:
    /// types of switches
    enum Types
    {
        NORMALLY_CLOSED = HIGH, // value is used for value when switch is active
        NORMALLY_OPENED = LOW
    };
    
private:
    /// pin the switch is on
    uint8_t pin;
    
    /// the type of switch this is
    Types type;
    
public:
    /** Standard constructor
     * @param pin the pin number to use
     * @param type the type of this switch
     */
    inline Switch(uint8_t pin, Types type = NORMALLY_CLOSED): pin(pin), type(type) {}
    
    /// one-time setup
    inline void setup()
    {
        pinMode(pin, INPUT);
    }
    
    /** returns true when switch is active, perferred way to check 
     * if a switch is switched/pushed.
     */
    inline bool active()
    {
        return (digitalRead(pin) == type);
    }
    
    /// returns true when switch is open
    inline bool open()
    {
        return (digitalRead(pin) == LOW);
    }
    
    /// returns true when switch is closed
    inline bool closed()
    {
        return (digitalRead(pin) == HIGH);
    }
    
    /** waits until switch is active/switched/pushed
     * @param delayChecks the delay between checks (ms)
     * @warning this method can wait forever if condition is never meet
     */
    inline void waitTillActive(uint8_t delayChecks = 0)
    {
        while (!this->active()) { ::delay(delayChecks); }
    }
    
    inline void waitTillInActive(uint8_t delayChecks = 0)
    {
        while (this->active()) { ::delay(delayChecks); }
    }
    
    inline void waitTillCycle()
    {
        this->waitTillActive();
        this->waitTillInActive();
    }
    
};


#endif







































