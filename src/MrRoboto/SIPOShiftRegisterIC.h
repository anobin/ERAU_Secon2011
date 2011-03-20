/** Header file for SIPOShiftRegisterIC class
 *
 * @file SIPOShiftRegisterIC.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SIPO_SHIFT_REGISTER_IC_H
#define MRROBOTO_SIPO_SHIFT_REGISTER_IC_H

// always needed
#include <WProgram.h>


/** Represents the interface to a single 8-bit Serial-in, 
 * Paralell out (SIPO) shift register (74164). It is assumed that one 
 * of the serial lines and the clear line are always pulled HIGH.
 */
class SIPOShiftRegisterIC
{
private:
    /// the clock pin
    uint8_t clockPin;
    
    /// one of the serial pins (the other should be shorted HIGH always)
    uint8_t serialPin;

public:
    /** standard constructor
     * @param clockPin the pin to use for the rising-edge clock
     * @param serialPin one of the serial pins
     */
    inline SIPOShiftRegisterIC(uint8_t clockPin, uint8_t serialPin):
        clockPin(clockPin), serialPin(serialPin) {}
        
    /// perform one-time setup
    inline void setup()
    {
        // just set pin modes
        pinMode(clockPin, OUTPUT);
        pinMode(serialPin, OUTPUT);
    }

    /** shift a bit into the register
     * @param b either HIGH or LOW
     */
    void shiftBit(uint8_t b);

    /** Shift a whole byte (8 bits) into the register
     * @param b the byte to shift in
     */
    void shift(uint8_t b);


};






#endif













