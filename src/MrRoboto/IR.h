/** Header file for IR class
 *
 * @file IR.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_IR_H
#define MRROBOTO_IR_H

// always needed...
#include <WProgram.h>

// for round
#include <math.h>

// needed for I2C comms
#include <../../../../libraries/Wire/Wire.h>


/** Interface to single IR sensor
 */
class IR
{
public:
	/// the types of return data
	enum ReturnTypes
	{
		INCHES = 1,
		CENTIMETERS = 2,
		RAW = 3
	};
	
private:
	/// address of the sensor
	int address;

        /// type of data to return
	ReturnTypes type;
    
#ifdef IR_RATE
    /// the last reading
    uint8_t last;
    
    /// milisecond timestamp of last reading
    unsigned long lastTime;    
#endif
	
	/// whether or not we have performed setup
	static bool setupPerformed;
    
        /// get a reading from the sensor
        uint8_t _read();

public:
	/// standard constructor
	inline IR(int address, ReturnTypes type=CENTIMETERS): address(address), type(type)
#ifdef IR_RATE
        , last(-1), lastTime(0) 
#endif
       {}
	
	/// perform setup for sensor
	inline void setup()
	{
		if (!IR::setupPerformed)
		{
			Wire.begin();
			IR::setupPerformed = true;
		}
	}

    /** perform a reading
     * @param rate out parameter to give rate, can be NULL
     * @return the reading
     * @note rate is in Hz (units per second)
     */
#ifdef IR_RATE
    inline uint8_t read(float* rate = NULL)
    {
        // perform reading
        uint8_t r = this->_read();
        unsigned long newTime = millis();
        
        // calculate rate
        if (rate != NULL)
        {
            float diff = (float(newTime-lastTime))/1000;
            if (last < 0)
                (*rate) = 0.0f;
            else
                (*rate) = round((float(r - last)) / diff); // integer mathz
        }
            
        // set temps for next time and return
        last = r;
        lastTime = newTime;
        return r;
    }
#else
    inline uint8_t read()
    {
        return _read();
    }
#endif


};
















#endif




















