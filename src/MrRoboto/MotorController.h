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
class Motor
{
public:
	enum Directions
	{
		REVERSE = 0x00,
		FORWARD = 0x01
	};
	
private:
	/// motor id for this motor
	uint8_t id;
	
	/// pointer to print stream
	Print* stream;
	
	/// standard constructor
	inline Motor(): id(0x00), stream(NULL) {}
	
	static const uint8_t startByte = 0x80;
	static const uint8_t deviceId = 0x00;
	
public:
	/// standard constructor
	inline Motor(uint8_t id, Print* stream): id(id), stream(stream) {}
	
	/// set motor direction and speed
	void set(Directions dir, uint8_t speed);
};



/** Interface to Motor Controller
 */
class MotorController
{
private:
	/// motor 1
	Motor motor1;
	/// motor 2
	Motor motor2;
	
	/// resetPin
	uint8_t resetPin;

        static const uint8_t motor1Id = 0x00;
        static const uint8_t motor2Id = 0x02;
	
public:
	/// standard constructor
	inline MotorController(Print* stream, uint8_t resetPin): 
		motor1(motor1Id, stream), motor2(motor2Id, stream), resetPin(resetPin) {}
		
	/// setup the motor controller
	inline void setup()
	{
                pinMode(resetPin, OUTPUT);
		digitalWrite(resetPin, HIGH);
	}
	
	/// get the first motor
	inline Motor* getMotor1()
	{
		return &motor1;
	}
	
	/// get the second motor
	inline Motor* getMotor2()
	{
		return &motor2;
	}

};





#endif





