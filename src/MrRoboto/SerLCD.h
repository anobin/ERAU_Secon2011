/** Header file for SerLCD class
 *
 * @file SerLCD.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_SER_LCD_H
#define MRROBOTO_SER_LCD_H


// always needed...
#include <inttypes.h>

// wiring stream interface
#include <Print.h>


/** Interface to LCD with serial backpack
 */
class SerLCD
{
public:
	/// the types of LCD displays
	enum Types
	{
		LCD_16X2,
		LCD_16X4,
		LCD_20X2,
		LCD_20X4
	};
	
	/// possible commands
	enum Commands
	{
		CLEAR_DISPLAY = 0x01,
		MOVE_CURSOR_RIGHT = 0x14,
		MOVE_CURSOR_LEFT = 0x10,
		SCROLL_RIGHT = 0x1C,
		SCROLL_LEFT = 0x18,
		DISPLAY_ON_NO_FEATURES = 0x0C,
		DISPLAY_OFF = 0x08,
		UNDERLINE_CURSOR_ON = 0x0E,
		BLICKING_BOX_CURSOR_ON = 0x0D
	};

	static const uint8_t MAX_BRIGHTNESS = 29;
    
    /// the max possible number of characters, regardless of LCD type
    static const uint8_t MAX_POSSIBLE_CHARS = 20*4;
	
private:
	/// stream to write to
	Print* stream;
	
	/// the type of LCD this interfaces to
	Types type;
	
	/// default constructor
	inline SerLCD(): stream(NULL), type(LCD_16X2) {}
	
	static const uint8_t command1 = 0xFE;
	static const uint8_t command2 = 0x7C;
	
	static const uint8_t brightnessLevels = 30;
	static const uint8_t brightnessOffset = 128;
	
	static const uint8_t setup20Chars = 3;
	static const uint8_t setup16Chars = 4;
	static const uint8_t setup4Lines = 5;
	static const uint8_t setup2Lines = 6;
	
	static const uint8_t cursorPositionOffset = 0x80;
	static const uint8_t cursorPossiblePositions = 0x7F;
	
	enum LineStarts
	{
		L16_1 = 0,
		L16_2 = 64,
		L16_3 = 16,
		L16_4 = 80,
		L20_1 = 0,
		L20_2 = 64,
		L20_3 = 20,
		L20_4 = 84
	};
	
public:
	/** Standard constructor
	 * @param stream serial line the LCD is on
	 */
	inline SerLCD(Print* stream, Types type): stream(stream), type(type) {}
	
	/** Set the backlight brightness
	 * @param value to set backlight to, 0 - 29
	 */
	inline void setBrightness(uint8_t v)
	{
		stream->write(command2);
		stream->write((uint8_t)(brightnessOffset + (v%brightnessLevels)));
	}
	
	/** Set the type of LCD screen, only needed if backpack has not been setup
	 */
	void setup();
	
	/** Send a special command
	 * @param command the command to send
	 */
	inline void sendCommand(Commands command)
	{
		stream->write(command1);
		stream->write((uint8_t)command);
	}
	
	/** Set the cursor position
	 * @param position the position to set to
	 */
	inline void setPosition(uint8_t position)
	{
		stream->write(command1);
		stream->write((position%cursorPossiblePositions) + cursorPositionOffset);
	}
	
	/** Set the cursor to the beginning of a certain line
	 * @param line the line to set to
	 */
	void setLine(uint8_t line);
	
	/// convenience method for clearing the display
	inline void clearDisplay()
	{
		this->sendCommand(CLEAR_DISPLAY);
	}
	
	/// max number of characters can be displayed on the screen
    uint8_t getMaxCharacters();

	// print methods, all with the line to write to
	inline void print(const String & s) { stream->print(s); }
    inline void print(const char* s) { stream->print(s); }
    inline void print(char s, int t= BYTE) { stream->print(s, t); }
    inline void print(unsigned char s, int t= BYTE) { stream->print(s, t); }
    inline void print(int s, int t= DEC) { stream->print(s, t); }
    inline void print(unsigned int s, int t= DEC) { stream->print(s, t); }
    inline void print(long s, int t= DEC) { stream->print(s, t); }
    inline void print(unsigned long s, int t= DEC) { stream->print(s, t); }
    inline void print(double s, int t= 2) { stream->print(s, t); }

};





#endif














