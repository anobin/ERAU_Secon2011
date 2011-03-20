/** Header file for SoftSerial class
 * 
 * @file SoftSerial.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SOFT_SERIAL_H
#define MRROBOTO_SOFT_SERIAL_H

// always needed...
#include <WProgram.h>

// wiring stream interface
#include <Stream.h>

// normal software serial library
#ifdef FROM_CPP_FILE
#include <../../../../libraries/SoftwareSerial/SoftwareSerial.h>
#else
#include <SoftwareSerial.h>
#endif

// for new and delete
#include "Utils.h"

// for new and delete 
#include <stdlib.h>


/** Represents a software serial line, implementing
 * The Stream interface
 */
class SoftSerial : public Stream
{
private:
	/// pointer to software serial instance to use
	SoftwareSerial* serial;

	uint8_t rx;
	uint8_t tx;

	
	/// default constrcutor
	inline SoftSerial(): serial(NULL) {}
	
public:
	/** Standard constructor
	 * @param rx the pin to recieve on
	 * @param tx the pin to transmit on
	 */
	inline SoftSerial(uint8_t rx, uint8_t tx): serial(NULL), rx(rx), tx(tx)
	{
		serial = new SoftwareSerial(rx, tx);
	}
	
	/// destructor
	virtual ~SoftSerial();
	
	/// start the serial emulation at a given baud rate
	inline void begin(long baud_rate)
	{
                pinMode(rx, INPUT);
                pinMode(tx, OUTPUT);
		serial->begin(baud_rate);
	}
	
	/// end the serial emulation, does nothing
    inline void end() {}
	
	/** Check whether data is present, does nothing
	 * @return always 1
	 */
    virtual int available();
	
	/** Peek at data in read buffer, does nothing
	 * @return always 0
	 */
    virtual int peek();
	
	/** read a single byte
	 * @return single byte put into an int for no good reason
	 */
    virtual int read();
	
	/** flush all write data, does nothing
	 */
    virtual void flush();
	
	/** write a single byte
	 * @param byte the byte to write
	 */
    virtual void write(uint8_t);

};






#endif





