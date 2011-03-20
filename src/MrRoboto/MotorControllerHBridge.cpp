/** Implementation file for MotorController class
 *
 * @file MotorController.cpp
 * @author Andrew Keating
 */


#include "MotorControllerHBridge.h"
 
/// set motor direction and speed
void MotorHBridge::set(Directions dir, uint8_t speed)
{
	if (dir == MotorHBridge::REVERSE)
	{
		digitalWrite(pin1, LOW);
		analogWrite(pin2, speed);
	}
	else
	{
		analogWrite(pin1, speed);
		digitalWrite(pin2, LOW);
	}
}
