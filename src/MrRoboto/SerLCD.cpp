/** Implementation file for SerLCD class
 *
 * @file SerLCD.h
 * @author Andrew Keating
 */

#include "SerLCD.h"

void SerLCD::setup()
{
	switch(type)
	{
		case LCD_16X4:
			stream->write(command2);
			stream->write(setup16Chars);
			stream->write(command2);
			stream->write(setup4Lines);
			break;
			
		case LCD_20X2:
			stream->write(command2);
			stream->write(setup20Chars);
			stream->write(command2);
			stream->write(setup2Lines);
			break;
			
		case LCD_20X4:
			stream->write(command2);
			stream->write(setup20Chars);
			stream->write(command2);
			stream->write(setup4Lines);
			break;
			
		case LCD_16X2:
		default:
			stream->write(command2);
			stream->write(setup16Chars);
			stream->write(command2);
			stream->write(setup2Lines);
	}
}


/** Set the cursor to the beginning of a certain line
 * @param line the line to set to
 */
void SerLCD::setLine(uint8_t line)
{
	switch(line)
	{
		case 1:
		default:
			switch(type)
			{
				case LCD_20X2:
				case LCD_20X4:
					this->setPosition(L20_1);
					break;
				case LCD_16X4:
				case LCD_16X2:
				default:
					this->setPosition(L16_1);
			}
		break;
		
		case 2:
			switch(type)
			{
				case LCD_20X2:
				case LCD_20X4:
					this->setPosition(L20_2);
					break;
				case LCD_16X4:
				case LCD_16X2:
				default:
					this->setPosition(L16_2);
			}
		break;
		
		case 3:
			switch(type)
			{
				case LCD_20X2:
				case LCD_20X4:
					this->setPosition(L20_3);
					break;
				case LCD_16X4:
				case LCD_16X2:
				default:
					this->setPosition(L16_3);
			}
		break;
		
		case 4:
			switch(type)
			{
				case LCD_20X2:
				case LCD_20X4:
					this->setPosition(L20_4);
					break;
				case LCD_16X4:
				case LCD_16X2:
				default:
					this->setPosition(L16_4);
			}
		break;
	}
}


uint8_t SerLCD::getMaxCharacters()
{
    switch (type)
    {
        case LCD_16X2:  return 16*2;
        case LCD_16X4:  return 16*4;
        case LCD_20X2:  return 20*2;
        case LCD_20X4:  return 20*4;
    }
}



















