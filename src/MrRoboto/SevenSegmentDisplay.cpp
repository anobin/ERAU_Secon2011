/** Implementation file for SevenSegmentDisplay class
 *
 * @file SevenSegementDisplay.cpp
 * @author Andrew Keating
 */

#include "SevenSegmentDisplay.h"


const uint8_t SevenSegmentDisplay::char2PanelsTable[127] =
{
    0x00,           // 0 - NUL
    0x00,           // 1 - SOH
    0x00,           // 2 - STX
    0x00,           // 3 - ETX
    0x00,           // 4 - EOT
    0x00,           // 5 - ENQ
    0x00,           // 6 - ACK
    0x00,           // 7 - BEL
    0x00,           // 8 - BS (backspace)
    0x00,           // 9 - TAB
    0x00,           // 10 - LF (new line) 
    0x00,           // 11
    0x00,           // 12
    0x00,           // 13
    0x00,           // 14
    0x00,           // 15
    0x00,           // 16
    0x00,           // 17
    0x00,           // 18
    0x00,           // 19
    0x00,           // 20
    0x00,           // 21
    0x00,           // 22
    0x00,           // 23
    0x00,           // 24
    0x00,           // 25
    0x00,           // 26
    0x00,           // 27
    0x00,           // 28
    0x00,           // 29
    0x00,           // 30
    0x00,           // 31
    0x00,           // 32 - Space
    0x00,           // 33 - !
    0x00,           // 34 - "
    0x00,           // 35 - #
    0x00,           // 36 - $
    0x00,           // 37 - %
    0x00,           // 38 - &
    0x00,           // 39 - '
    0x00,           // 40 - (
    0x00,           // 41 - )
    0x00,           // 42 - *
    0x00,           // 43 - +
    0x00,           // 44 - ,
    0x00,           // 45 - -
    0x00,           // 46 - .
    0x00,           // 47 - /
    P1|P2|P3|P5|P6|P7,            // 48 - 0
    P3|P7,           // 49 - 1
    P2|P3|P4|P5|P6,           // 50 - 2
    P2|P3|P4|P7|P6,           // 51 - 3
    P1|P4|P3|P7,           // 52 - 4
    P2|P1|P4|P7|P6,           // 53 - 5
    P1|P4|P5|P7|P6|P2,           // 54 - 6
    P2|P3|P7,           // 55 - 7
    P1|P2|P3|P4|P5|P6|P7,           // 56 - 8
    P1|P2|P3|P4|P7|P6,           // 57 - 9
    0x00,           // 58 - :
    0x00,           // 59 - ;
    0x00,           // 60 - <
    0x00,           // 61 - =
    0x00,           // 62 - >
    0x00,           // 63 - ?
    0x00,           // 64 - @
    P5|P1|P2|P4|P3|P7,           // 65 - A
    P1|P2|P3|P4|P5|P6|P7,           // 66 - B
    P1|P2|P5|P6,           // 67 - C
    P1|P2|P3|P5|P6|P7,           // 68 - D
    P1|P2|P4|P5|P6,           // 69 - E
    0x00,           // 70 - F
    0x00,           // 71 - G
    P1|P3|P4|P5|P7,           // 72 - H
    0x00,           // 73 - I
    0x00,           // 74 - J
    0x00,           // 75 - K
    0x00,           // 76 - L
    0x00,           // 77 - M
    P4|P5|P7,           // 78 - N
    P1|P2|P3|P5|P6|P7,           // 79 - O
    0x00,           // 80 - P
    0x00,           // 81 - Q
    0x00,           // 82 - R
    0x00,           // 83 - S
    P1|P2|P5,           // 84 - T
    0x00,           // 85 - U
    0x00,           // 86 - V
    0x00,           // 87 - W
    0x00,           // 88 - X
    0x00,           // 89 - Y
    0x00,           // 90 - Z
    0x00,           // 91 - [
    0x00,           // 92 - \
    0x00,           // 93 - ]
    0x00,           // 94 - ^
    0x00,           // 95 - _
    0x00,           // 96 - `
    0x00,           // 97 - a
    0x00,           // 98 - b
    0x00,           // 99 - c
    0x00,           // 100 - d
    0x00,           // 101 - e
    0x00,           // 102 - f
    0x00,           // 103 - g
    0x00,           // 104 - h
    0x00,           // 105 - i
    0x00,           // 106 - j
    0x00,           // 107 - k
    0x00,           // 108 - l
    0x00,           // 109 - m
    P4|P5|P7,           // 110 - n
    P4|P5|P6|P7,           // 111 - o
    0x00,           // 112 - p
    0x00,           // 113 - q
    P4|P5,           // 114 - r
    0x00,           // 115 - s 
    0x00,           // 116 - t
    0x00,           // 117 - u
    0x00,           // 118 - v
    0x00,           // 119 - w
    0x00,           // 120 - x
    0x00,           // 121 - y
    0x00,           // 122 - z
    0x00,           // 123 - {
    0x00,           // 124 - }
    0x00,           // 125 - ~
    0x00,           // 126 - DEL (**-end of original ascii table-**)
};













   