/** Header file for SevenSegmentDisplay class
 *
 * @file SevenSegmentDisplay.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SEVEN_SEGMENT_DISPLAY
#define MRROBOTO_SEVEN_SEGMENT_DISPLAY

// always needed
#include <WProgram.h>

// needed for shift register group interface
#include "SIPOShiftGroup.h"

/** Represents the interface to a single 7-segment display controlled
 * using a 8-bit Serial-in, Paralell out (SIPO) shift register (74164).
 * The assumed pinout for the seven-segment display is as follows:
 *  1 2 G 4 5
 *  | | | | |
 *  
 *  |--[4]--|
 *  [2]     [5]
 *  |--[1]--|
 *  [6]     [9]
 *  |--[7]--|() <- 10
 *  
 *  | | | | |
 *  6 7 G 9 10
 *  
 * The mapping between the outputs on the IC and the pins on the display are
 * as follows:
 *  A -> 1
 *  B -> 2
 *  C -> 4
 *  D -> 5
 *  E -> 6
 *  F -> 7
 *  G -> 9
 *  H -> 10
 *
 * It is assumed that one of ther serial lines and the clear line are always
 * pulled HIGH.
 *
 * The following panel numbers are used:
 *  |--[2]--|
 * [1]     [3]
 *  |--[4]--|
 * [5]     [7]
 *  |--[6]--|() <- 8
 */
class SevenSegmentDisplay
{
public:
    /// the bytes to send to set each panel of the display
    static const uint8_t P1 = B01000000;
    static const uint8_t P2 = B00100000;
    static const uint8_t P3 = B00010000;
    static const uint8_t P4 = B10000000;
    static const uint8_t P5 = B00001000;
    static const uint8_t P6 = B00000100;
    static const uint8_t P7 = B00000010;
    static const uint8_t P8 = B00000001;
    
    /// table of bytes that are set for all 8-bit characters (ASCII)
    static const uint8_t char2PanelsTable[127];

};








#endif


