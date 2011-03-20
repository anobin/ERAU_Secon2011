/** Implementation file for IR class
 *
 * @file IR.cpp
 * @author Andrew Keating
 */
 
#include "IR.h"

bool IR::setupPerformed = false;

uint8_t IR::_read()
{
	uint8_t rdata = 0;
	Wire.beginTransmission(address);
	Wire.send(type); 
	Wire.endTransmission();
	Wire.requestFrom(address,1);
	if (Wire.available()) rdata = Wire.receive();
	Wire.endTransmission();
	return rdata;
}
