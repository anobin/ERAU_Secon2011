/** Header file for SIPOShiftGroup class
 * 
 * @file SIPOShiftGroup.h
 * @author Andrew Keating
 */
#ifndef SIPO_SHIFT_GROUP_H
#define SIPO_SHIFT_GROUP_H

// always needed
#include <WProgram.h>


/** Represents the interface to a group of 8-bit Serial in,
 * Parallel out (SIPO) shift registers (74164) with a shared clock line. It 
 * is assumed that the CLEAR and one of the serial lines are shorted HIGH always
 */
class SIPOShiftGroup
{
public:
    /// maximum number of shift registers supported
    static const uint8_t MAX_REGISTERS = 8;
    
private:
    /// the shared clock pin to use
    uint8_t clockPin;
    
    /// the single serial lines for each register, max number of registers is bounded
    uint8_t serialPins[MAX_REGISTERS];
    /// the values that should be put in each register on update
    uint8_t serialValues[MAX_REGISTERS];
    /// the current number of registers connected
    uint8_t numRegisters;

public:
    /// standard constructor
    inline SIPOShiftGroup(uint8_t clockPin): clockPin(clockPin), numRegisters(0) {}
    
    /// one-time setup
    inline void setup()
    {
        pinMode(clockPin, OUTPUT);
    }
    
    /** get the current number of registers in this group
     * @return the current number of registers in this group
     */
    inline uint8_t getRegisterCount()
    {
        return this->numRegisters;
    }
    
    /** add a new register to the group
     * @param serialPin the single serial pin of the register
     * @return true for register added, false for already at max registers
     */
    bool addRegister(uint8_t serialPin);
    
    /** Set a certain register to a specific value
     * @param registerNum the number of the register, stating at 0
     * @param value the value to set the register to on the next update
     * @return true for value set, false for registerNum does not exist
     */
    inline bool setRegister(uint8_t registerNum, uint8_t value)
    {
        if (registerNum >= this->numRegisters)
            return false;
        serialValues[registerNum] = value;
        return true;
    }
    
    /** Set the values of all the registers in the group
     * @param values array of values to set, array must be at least register
     *               count length
     */
    inline void setRegisters(const uint8_t* values)
    {
        for (int i=0; i < this->numRegisters; i++)
            serialValues[i] = values[i];
    }
    
    /// shift all set values into the registers
    void shiftAll();


};





#endif








































