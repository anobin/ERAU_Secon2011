/** Header file for AnalogIR class
 *
 * @file AnalogIR.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_ANALOG_IR_H
#define MRROBOTO_ANALOG_IR_H


// always needed
#include <WProgram.h>


/** Represents interface to analog IR range finder
 */
class AnalogIR
{
private:
    /// pin to read from
    uint8_t pin;
    
public:
    /// standard constructor
    inline AnalogIR(uint8_t pin): pin(pin) {}
    
    /// get a raw analog reading (0-1024)
    inline int getRawReading()
    {
        return analogRead(pin);
    }
    
    /// get a distance reading (cm)
    inline int getReading()
    {
        return this->getRawReading();
    }


};


#endif




