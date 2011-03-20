/** Header file for BufferedLCD class
 * 
 * @file BufferedLCD.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_BUFFERED_LCD_H
#define MRROBOTO_BUFFERED_LCD_H

// always needed
#include <WProgram.h>

// wiring print interface
#include <Print.h>

// needed to interface with LCD
#include "SerLCD.h"


/** Provides buffering services onto of the normal
 * serial backpack LCD screen
 */
class BufferedLCD: public Print
{
public:
    /// character displayed to show that there is another page
    static const char NEXT_PAGE_CHAR = '>';
    
    /// character displayed to show that the input was bounded by max page limit
    static const char BOUNDED_MAX_CHAR = '#';
    
    /// max number of pages supported
    static const uint8_t MAX_PAGES = 15;
    
private:
    /// lcd to control
    SerLCD* lcd;
    
    /// max number of characters per page, depends on LCD
    uint8_t pageCharCount;
    
    /// storage for page data
    char pages[MAX_PAGES][SerLCD::MAX_POSSIBLE_CHARS];
    
    /// the number of current pages
    uint8_t pageCount;
    
    /// the current displayed page
    uint8_t curPage;
    
    /// the current position cursor in the last page
    uint8_t curPos;
    
public:
    /** Standard constructor
     * @param lcd the lcd to control
     */
    inline BufferedLCD(SerLCD* lcd): lcd(lcd), pageCharCount(lcd->getMaxCharacters()-1), // -1 for next page char to fit in
        pageCount(0), curPage(0), curPos(0) {}
        
    /// append a byte onto the buffer
    virtual void write(uint8_t b);
    
    /** refreshes current page, needs to be done if content that should
     * be viewable was just added
     */
    void refresh();
        
    /// clear the display and all pages
    void clear();
    
    /** display the next page
     * @return true for success, false for next page is non-existant
     */
    bool nextPage();
    
    /** display the previous page
     * @return true for success, false for previous page is non-existant
     */
    bool previousPage();
    
    /// get the number of current pages
    inline uint8_t getPageCount()
    {
        return pageCount;
    }
    
    /// get the current page, -1 for none
    inline uint8_t getCurrentPage()
    {
        return curPage;
    }
    

};





#endif






























