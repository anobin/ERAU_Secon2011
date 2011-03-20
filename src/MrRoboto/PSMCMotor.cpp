/** Implementation file for PSMCMotor class
 *
 * @file PSMCMotor.cpp
 * @author Andrew Keating
 */


#include "PSMCMotor.h"

// default max speeds
uint16_t PSMCMotor::maxSpeed = (3200/2) + (3200/4);
uint8_t PSMCMotor::maxSimpleSpeed = (127/2) + (127/4);
 
/** Get the error if any, will perform serial communication if
  * the error if an error is present
  * @return the error code
  */
PSMCMotor::Errors PSMCMotor::getError()
{
    int e =  digitalRead(this->errorPin);
    if (e == LOW)
        return PSMCMotor::NONE;
    
    return PSMCMotor::ERROR;
}
 
// internal set motor state
void PSMCMotor::set(uint8_t dirCommand, uint16_t speed)
{
    static const uint16_t speedDivider = 32;
    uint8_t b[] = { PSMCMotor::protocolByte, this->id, dirCommand, 
        speed % speedDivider, speed / speedDivider };
    stream->write(b, 5);
}
    
// internal simple set motor state
void PSMCMotor::setSimple(uint8_t dirCommand, uint8_t speed)
{
    uint8_t b[] = { PSMCMotor::protocolByte, this->id, dirCommand, speed };
    stream->write(b, 4);
}

/** Cause the motor to brake
 * @param force how fast the motor breaks (0-32)
 */
void PSMCMotor::brake(uint8_t force)
{
    uint8_t b[] = { PSMCMotor::protocolByte, this->id, PSMCMotor::breakCommand,
        force};
    stream->write(b, 4);
}


/** Get the value of a variable
 * @param variable the variable to retrieve
 * @param unsignedType variable tp put unsigned value into, can be null
 * @param signedType variable to put signed value into, can be null
 * @param timeout timeout value to use (in ms), 0 means unlimited timeout
 * @return false for timeout or variable invalid, true for correct value recieved
 */
bool PSMCMotor::getVariable(PSMCMotor::Variables variable, uint16_t* unsignedType, 
                     int16_t* signedType, unsigned long timeout)
{
    uint8_t var = (uint8_t) variable;
    // check for invalid value
    if (var > 41 && var < 127)
        return false;
    
    // send request
    uint8_t b[] = { PSMCMotor::protocolByte, this->id, 
        PSMCMotor::getVariableCommand, var };
    stream->write(b, 4);
    
    
    // continuly check for response till timeout.
    // note that we don't rely on available or peek to make it compatable with
    // the software serial. Also note that if we are using software serial and
    // no data ever returns, we will freeze here.
    unsigned long start = millis();
    uint8_t bytes[] = { 0x00, 0x00 };
    bool firstRead = false;
    int temp;
    while(true)
    {
        temp = stream->read();
        if (temp > 0)
        {
            if (!firstRead)
            {
                bytes[0] = temp;
                firstRead = true;
            }
            else
            {
                bytes[1] = temp;
                break;
            }
                
        }
        if ( timeout != 0 && (millis()-start) > timeout)
            return false; // hit timeout
    }
    
    // set outputs
    if (unsignedType)
        (*unsignedType) = (uint16_t(bytes[0])) + (256 * (uint16_t(bytes[1])));
    if (signedType)
        (*signedType)   = ((int32_t(bytes[0])) + (256 * (int32_t(bytes[1])))) - 65536;
    
    return true;
}





































