/** Header file for SIPOShiftRegisterIC class
 *
 * @file SIPOShiftRegisterIC.cpp
 * @author Andrew Keating
 */

#include "SIPOShiftRegisterIC.h"

/** shift a bit into the register
 * @param b either HIGH or LOW
 */
void SIPOShiftRegisterIC::shiftBit(uint8_t b)
{
    
}

/** Shift a whole byte (8 bits) into the register
 * @param b the byte to shift in
 */
void SIPOShiftRegisterIC::shift(uint8_t b)
{
    // shift all eight bits, IC samples on clock's rising edge
    for(int i=0; i < 8; i++)
    {
        // set serial line
        if ((b >> i) & 0x01)
            digitalWrite(this->serialPin, HIGH);
        else
            digitalWrite(this->serialPin, LOW);
        
        // trigger rising edge to cuase sample and shift
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->clockPin, HIGH);
    }
}
