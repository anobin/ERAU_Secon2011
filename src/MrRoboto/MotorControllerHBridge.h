/** Header file for MotorController
 *
 * @file MotorController.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_MOTOR_CONTROLLER_H
#define MRROBOTO_MOTOR_CONTROLLER_H

// always needed
#include <WProgram.h>

// wiring print interface
#include <Print.h>

/** Interface to a single Motor
 */
class MotorHBridge
{
public:
	enum Directions
	{
		REVERSE = 0x00,
		FORWARD = 0x01
	};
	
private:
	/// enable pin
	uint8_t enablePin;

	/// first control pin 
	uint8_t pin1;
	
	/// second control pin
	uint8_t pin2;
	
	/// standard constructor
	inline MotorHBridge(): enablePin(0x00), pin1(0x00), pin2(0x00) {}
	
public:
	/// standard constructor
	inline MotorHBridge(uint8_t enablePin, uint8_t pin1, uint8_t pin2): 
		enablePin(enablePin), pin1(pin1), pin2(pin2)
	{
		pinMode(enablePin, OUTPUT);
		pinMode(pin1, OUTPUT);
		pinMode(pin2, OUTPUT);
		this->enable();
	}
	
	/// set motor direction and speed
	void set(Directions dir, uint8_t speed);
	
	inline void enable()
	{
		digitalWrite(enablePin, HIGH);
	}
	
	inline void disable()
	{
		digitalWrite(enablePin, LOW);
	}
};









#endif





