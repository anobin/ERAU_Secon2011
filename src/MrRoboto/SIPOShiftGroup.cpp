/** Implementation file for SIPOShiftGroup class
 * 
 * @file SIPOShiftGroup.cpp
 * @author Andrew Keating
 */

#include "SIPOShiftGroup.h"

/** add a new register to the group
 * @param serialPin the single serial pin of the register
 * @return true for register added, false for already at max registers
 */
bool SIPOShiftGroup::addRegister(uint8_t serialPin)
{
    if (this->numRegisters >= SIPOShiftGroup::MAX_REGISTERS)
        return false;
    this->numRegisters++;
    this->serialPins[this->numRegisters-1] = serialPin;
    this->serialValues[this->numRegisters-1] = 0x00; // default to 0x00
    pinMode(serialPin, OUTPUT);
    return true;
}
    
/// shift all set values into the registers
void SIPOShiftGroup::shiftAll()
{    
    // shift all eight bits, IC samples on clock's rising edge
    for(int i=0; i < 8; i++)
    {
        // set serial line for each register
        for (int j=0; j < this->numRegisters; j++)
        {
            if ((serialValues[j] >> i) & 0x01)
                digitalWrite(serialPins[j], HIGH);
            else
                digitalWrite(serialPins[j], LOW);
        }
        
        // trigger rising edge to cuase every register to sample and shift
        digitalWrite(this->clockPin, LOW);
        digitalWrite(this->clockPin, HIGH);
    }
}














