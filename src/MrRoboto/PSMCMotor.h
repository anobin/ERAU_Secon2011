/** Header file for PSMCMotor class
 *
 * @file PSMCMotor.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_PSMC_MOTOR_H
#define MRROBOTO_PSMC_MOTOR_H

// always needed
#include <WProgram.h>

// wiring stream interface
#include <Stream.h>

/** Interface to a motor connected using a 
 * Pololu Simple Motor Controller (PSMC) set to 
 * binary serial mode with no CRC.
 * <http://www.pololu.com/catalog/category/94>
 * As this class only uses the serial, not usb, interface
 * it does not allow parameters to be configured. This class
 * communicates with the controller using the Pololu protocol.
 */
class PSMCMotor
{
public:
    /// possible controller errors
    enum Errors
    {
        NONE,
        ERROR
    };
    
    /// Possible variables
    enum Variables
    {
        // status flag registers, all unsigned 16-bits
        ERROR_STATUS =          0,   // bitfield of possible errors
        ERRORS_OCCURED =        1,   // Read this variable to clear errors
        SERIAL_ERRORS_OCCURED=  2,   // bitfield of detailed serial errors, reading clears value
        LIMIT_STATUS =          3,   // bitfield of current motor limiters, not limits
        RESET_FLAGS =           127,   // indicates source of last board reset
        // RC channel inputs passthrough
        RC1_UNLIMITED_RAW =     4,   // unsigned
        RC1_LIMITED_RAW =       5,   // unsigned
        RC1_SCALED =            6,   // signed
        RC2_UNLIMITED_RAW =     8,   // unsigned
        RC2_LIMITED_RAW =       9,   // unsigned 
        RC2_SCALED =            10,   // signed
        // Analog channel inputs passthrough
        AN1_UNLIMITED_RAW =     12,  // unsigned
        AN1_LIMITED_RAW =       13,   // unsigned
        AN1_SCALED =            14,  // signed
        AN2_UNLIMITED_RAW =     16,  // unsigned
        AN2_LIMITED_RAW =       17,  // unsigned 
        AN2_SCALED =            18,  // signed
        // Diagnostic variables
        TARGET_SPEED =          20,  // signed (-3200 to 3200)
        SPEED =                 21,  // signed (-3200 to 3200)
        BRAKE_AMMOUNT =         22,  // unsigned (0 to 32, or 0xFF for no brake)
        INPUT_VOLTAGE =         23,  // unsigned (in mV)
        TEMPERATURE =           24,  // unsigned (in 0.1C increments above 0)
        RC_PERIOD =             26,  // unsigned (in 0.1ms increments)
        BAUD_RATE =             27,  // unsigned (divide into 7.2e7 to get real value, 0 for not detected yet)
        TIME_LOW_BYTES  =       28,  // unsigned (two lower bytes of time in ms)
        TIME_HIGH_BYTES =       29,  // unsigned (two upper bytes of time in ms)
        // Current motor limits, all unsigned 16 bits
        MAX_FORWARD_SPEED =     30,
        MAX_FORWARD_ACCEL =     31,
        MAX_FORWARD_DECEL =     32,
        FORWARD_BRAKE_DURATION= 33,
        MAX_REVERSE_SPEED =     36,
        MAX_REVERSE_ACCEL =     37,
        MAX_REVERSE_DECEL =     38,
        REVERSE_BRAKE_DURATION= 39
    };
    
    
    /// bitfield for ERROR_STATUS variable, all bit booleans
    struct ERROR_STATUS_fields
    {
        unsigned int safeStartViolation     : 1;
        unsigned int requiredChannelInvalid : 1;
        unsigned int serialError            : 1; // see SERIAL_ERRORS_OCCURED variable
        unsigned int commandTimeout         : 1;
        unsigned int limit_killSwitch       : 1;
        unsigned int lowVIN                 : 1;
        unsigned int highVIN                : 1;
        unsigned int overTemperature        : 1;
        unsigned int motorDriverError       : 1;
        unsigned int errorLineHigh          : 1;
        unsigned int reserved               : 6;
    };
    
    /// bitfield for SERIAL_ERRORS_OCCURED variable, all bit booleans
    struct SERIAL_ERRORS_OCCURED_fields
    {
        unsigned int reserved   : 1;
        unsigned int frame      : 1;
        unsigned int noise      : 1;
        unsigned int rxOverrun  : 1;
        unsigned int format     : 1;
        unsigned int crc        : 1;
        unsigned int reserved2  : 10;
    };
    
    /// bitfield for LIMIT_STATUS variable, all bit booleans
    struct LIMIT_STATUS_fields
    {
        unsigned int stoppedFromError                       : 1;
        unsigned int reducedSpeedFromTemp                   : 1;
        unsigned int reducedSpeedFromMaxLimit               : 1;
        unsigned int reducedSpeedFromStartingLimit          : 1;
        unsigned int inProgressDueToAccel_Decel_BrakeLimits : 1;
        unsigned int killedByRC1KillSwitch                  : 1;
        unsigned int killedByRC2KillSwitch                  : 1;
        unsigned int killedByAN1KillSwitch                  : 1;
        unsigned int killedByAN2KillSwitch                  : 1;
        unsigned int killedByUSBKillSwitch                  : 1;
        unsigned int reserved                               : 6;
    };
    
    /// possible values for RESET_FLAGS variable
    enum RESET_FLAGS_values
    {
        RST_PULLED_LOW =    0x04,
        POWER_RESET =       0x0C,
        SOFTWARE_RESET =    0x14,
        WATCHDOG_TIMER =    0x24    // should indicate a firmware bug
    };
    
    // few public constants
    static const uint8_t maxBrake = 32;
	
private:
	/// device id for the controller
	uint8_t id;
	
	/// pointer to print stream, representing serial line
	Stream* stream;
    
    /// error pin for controller
    uint8_t errorPin;
    
    /// optional reset pin
    uint8_t resetPin; // not present if 0
	
	/// standard constructor
	inline PSMCMotor(): id(0x00), stream(NULL), errorPin(0x00), resetPin(0x00) {}
	
	// static pololu protocol bytes
	static const uint8_t protocolByte =                 0xAA;
    static const uint8_t exitSafeStartCommand =         0x03;
    static const uint8_t motorForwardCommand =          0x05;
    static const uint8_t motorSimpleForwardCommand =    0x09;
    static const uint8_t motorReverseCommand =          0x06;
    static const uint8_t motorSimpleReverseCommand =    0x0A;
    static const uint8_t breakCommand =                 0x12;
    static const uint8_t getVariableCommand =           0x21;
    
    // internal set motor state, speed is 0-3200
	void set(uint8_t dirCommand, uint16_t speed);
    
    // internal simple set motor state, speed is 0-127
    void setSimple(uint8_t dirCommand, uint8_t speed);
    
    static uint16_t maxSpeed;
    static uint8_t maxSimpleSpeed;
	
public:
	/** standard constructor
     * @param id the set pololu id of the controller
     * @param stream the stream representing the serial line
     * @param errorPin the pin connected to the 'ERR' line
     * @param resetPin the pin connected to the 'RST' line, optional
     */
	inline PSMCMotor(uint8_t id, Stream* stream, uint8_t errorPin, uint8_t resetPin=0): 
        id(id), stream(stream), errorPin(errorPin), resetPin(resetPin) {}
        
    /** perform one-time setup for controller,
     * should be called after setup for serial line is done
     */
    inline void setup()
    {
        // set mode for error and reset line
        pinMode(errorPin, INPUT);
        if (resetPin) { pinMode(resetPin, OUTPUT); }
        
        // send protocol byte to let the controller auto-detect baud rate
        stream->write(PSMCMotor::protocolByte);
    }
    
    /** Reset the motor controller
     * @param wait if true, a 5 ms delay will be called in this method
     */
    inline void reset(bool wait = true)
    {
        if (resetPin)
        {
            digitalWrite(resetPin, LOW);
            if (wait) { delay(5); }
        }
    }
    
    /** Exit the safe start mode, thus allowing the motors to drive.
     * If safe start is enabled (default), this must be done after a reset or error
     */
    inline void start()
    {
        uint8_t b[] = { protocolByte, this->id, exitSafeStartCommand };
        stream->write(b, 3);
    }
    
    /** Cause the motor to brake
     * @param force how fast the motor breaks (0-32)
     */
    void brake(uint8_t force = maxBrake);
    
    /** Get the error if any, will perform serial communication if
     * the error if an error is present
     * @return the error code
     */
    PSMCMotor::Errors getError();
    
    /** Get the value of a variable
     * @param variable the variable to retrieve
     * @param unsignedType variable tp put unsigned value into, can be null
     * @param signedType variable to put signed value into, can be null
     * @param timeout timeout value to use (in ms), 0 means unlimited timeout
     * @return false for timeout or variable invalid, true for correct value recieved
     */
    bool getVariable(PSMCMotor::Variables variable, uint16_t* unsignedType, 
                     int16_t* signedType = NULL, unsigned long timeout = 0);
    
	/** set motor to move forward
     * @param speed speed to set (0-3200)
     */
	inline void setForward(uint16_t speed)
	{
        this->set(motorForwardCommand, speed);
    }
    
    /** set motor to move forward
     * @param speed speed to set (0-127)
     */
    inline void setSimpleForward(uint8_t speed)
    {
        this->setSimple(motorSimpleForwardCommand, speed);
    }
    
    /** set motor to move reverse
     * @param speed speed to set (0-3200)
     */
    inline void setReverse(uint16_t speed)
    {
        this->set(motorReverseCommand, speed);
    }
    
    /** set motor to move reverse
     * @param speed speed to set (0-127)
     */
    inline void setSimpleReverse(uint8_t speed)
    {
        this->setSimple(motorSimpleReverseCommand, speed);
    }
    
    /// set the max speed
    inline static void setMaxSpeed(uint16_t maxSpeed)
    {
        PSMCMotor::maxSpeed = maxSpeed;
    }
    inline static uint16_t getMaxSpeed()
    {
        return PSMCMotor::maxSpeed;
    }
    
    /// set the simple max speed
    inline static void setMaxSimpleSpeed(uint8_t maxSpeed)
    {
        PSMCMotor::maxSimpleSpeed = maxSpeed;
    }
    inline static uint8_t getMaxSimpleSpeed()
    {
        return PSMCMotor::maxSimpleSpeed;
    }
    
};















#endif













