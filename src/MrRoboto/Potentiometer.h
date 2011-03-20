/** Header file for Potentiometer class
 *
 * @file Potentiometer.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_POTENTIOMETER
#define MRROBOTO_POTENTIOMETER

// always needed
#include <WProgram.h>


/** Represents the interface to a potentiometer
 */
class Potentiometer
{
private:
    /// pin to use for the pot
    uint8_t pin;
    
public:
    /// standard constructor
    inline Potentiometer(uint8_t pin): pin(pin) {}
    
    /// get reading (0-1024)
    inline int getReading()
    {
        return analogRead(pin);
    }
};




#endif




