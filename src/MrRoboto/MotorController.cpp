/** Implementation file for MotorController class
 *
 * @file MotorController.cpp
 * @author Andrew Keating
 */


#include "MotorController.h"
 
/// set motor direction and speed
void Motor::set(Directions dir, uint8_t speed)
{
	uint8_t data[4];
	data[0] = startByte;
	data[1] = deviceId;
	data[2] = id;
	data[2] += (uint8_t)dir;
	data[3] = speed;
	stream->write(data, 4);
}
