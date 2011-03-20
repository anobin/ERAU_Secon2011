/** Header file for LED class 
 * 
 * @file LED.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_LED_H
#define MRROBOTO_LED_H

// always needed
#include <WProgram.h>


/** Interface to single LED
 */
class LED
{
private:
	/// pin to use
	uint8_t pin;
	
	/// default constructor
	inline LED(): pin(0) {}
	
public:
	/// standard constructor
	inline LED(uint8_t pin): pin(pin) {}
	
	/// setup the led
	inline void setup()
	{
		pinMode(pin, OUTPUT);
	}
	
	/// set the LED to on
	inline void on()
	{
		digitalWrite(pin, HIGH);
	}
	
	/// set the LED to off
	inline void off()
	{
		digitalWrite(pin, LOW);
	}
	
	
};






#endif

