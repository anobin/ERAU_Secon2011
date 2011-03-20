/** Header file for EMFieldDetector class
 * 
 * @file EMFieldDetector.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_EM_FIELD_DETECTOR_H
#define MRROBOTO_EM_FIELD_DETECTOR_H

// always needed
#include <WProgram.h>


/** Represents the interface to the EM field detector, detecting 
 * 33 and 44kHz frequencies
 */
class EMFieldDetector
{
public:
    /// the types
    enum Types
    {
        MODE_33,
        MODE_44
    };
    
private:
    /// the pin for the 33kHz detection
    uint8_t pin33;
    
    /// the pin for the 44kHz detection
    uint8_t pin44;
    
public:
    /// standard constructor
    inline EMFieldDetector(uint8_t pin33, uint8_t pin44): pin33(pin33), pin44(pin44) {}

    /// get the reading off the 33kHz line (0-1024)
    inline int get33Reading()
    {
        return analogRead(pin33);
    }
    
    /// get the reading off the 44kHz line (0-1024)
    inline int get44Reading()
    {
        return analogRead(pin44);
    }
    
    inline 


};


#endif




