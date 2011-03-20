/** Header file for DigitDisplay class
 *
 * @file DigitDisplay.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_DIGIT_DISPLAY_H
#define MRROBOTO_DIGIT_DISPLAY_H

// always needed
#include <WProgram.h>

// includes for digits
#include "SevenSegmentDisplay.h"

// include for interfaces
#include "SIPOShiftGroup.h"


/** Represents the interface to a collection of
 * 7-segment displays that are connected as documented
 * in the SevenSegmentDisplay class. This class serves to
 * represent a collection of digits with a shared clock, using
 * a synchronous shiftAll for efficieny (versus a shiftAll for
 * every digit update)
 */
class DigitDisplay
{
private:
    /// the SIPO shift group to use
    SIPOShiftGroup* shift;
    
    
public:
    /** Standard constructor
     * @param group the shift group to use, one register per digit
     */
    inline DigitDisplay(SIPOShiftGroup* group): shift(group) {}
    
    /** Get the number of digits in this display
     * @return number of digits in this display
     */
    inline uint8_t getDigitCount()
    {
        return shift->getRegisterCount();
    }
    
    /** Set a the value of one of the digits to display
     * @param digitNum the number of the digit
     * @param value the value of the digit
     * @return true for set, false for digit does not exist
     */
    inline bool setDigit(uint8_t digitNum, char value)
    {
        return shift->setRegister(digitNum, 
                     SevenSegmentDisplay::char2PanelsTable[value]);
    }
    
    /** Set the values of every digit
     * @param values array of values, must be at least digit count long
     */
    inline void setDigits(const char* values)
    {
        for (int i=0; i < this->getDigitCount(); i++)
        {
            shift->setRegister(i, 
                     SevenSegmentDisplay::char2PanelsTable[values[i]]);
        }
    }
    
    /// update the actual display with the values of the digits
    inline void update()
    {
        shift->shiftAll();
    }
    
    
    
};




#endif

































