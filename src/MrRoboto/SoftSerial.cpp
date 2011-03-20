/** Implementation file for SoftSerial class
 *
 * @file SoftSerial.cpp
 * @author Andrew Keating
 */

#define FROM_CPP_FILE
#include "SoftSerial.h"


/// destructor
SoftSerial::~SoftSerial()
{
	delete this->serial;
}
	
/** Check whether data is present, does nothing
 * @return always 1
 */
int SoftSerial::available()
{
	return 1;
}
	
/** Peek at data in read buffer, does nothing
 * @return always 0
 */
int SoftSerial::peek()
{
	return 0;
}
	
/** read a single byte
 * @return single byte put into an int for no good reason
 */
int SoftSerial::read()
{
	return serial->read();
}
	
/** flush all write data, does nothing
 */
void SoftSerial::flush()
{
	/* intentionally left blank */
}
	
/** write a single byte
 * @param byte the byte to write
 */
void SoftSerial::write(uint8_t byte)
{
	serial->print(byte);
}
	
	
	
	
	
	
	
	
	
	
