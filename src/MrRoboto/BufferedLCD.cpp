/** Implementation file for BufferedLCD class
 *
 * @file BufferedLCD.cpp
 * @author Andrew Keating
 */

#include "BufferedLCD.h"

/// append a byte onto the buffer
void BufferedLCD::write(uint8_t b)
{
    // check for new page
    if (pageCount == 0 || (curPos+1) > pageCharCount)
    {
        // check for end of buffer
        if (pageCount == BufferedLCD::MAX_PAGES)
        {
            pages[pageCount-1][curPos] = BufferedLCD::BOUNDED_MAX_CHAR;
            return;
        }
        
        // increase page count and clear new page
        pageCount++;
        pages[pageCount-1][0] = 0;
        curPos = 0;
    }
    
    // write content
    pages[pageCount-1][curPos] = b;
    curPos++;
    pages[pageCount-1][curPos] = 0;
}
    
/** refreshes current page, needs to be done if content that should
 * be viewable was just added
 */
void BufferedLCD::refresh()
{
    lcd->clearDisplay();
    lcd->print(pages[curPage]);
    if ((curPage + 1) < pageCount)
        lcd->print(BufferedLCD::NEXT_PAGE_CHAR);
}
    
        
/// clear the display and all pages
void BufferedLCD::clear()
{
    lcd->clearDisplay();
    curPage = 0;
    pageCount = 0;
    curPos = 0;
}
    
/** display the next page
 * @return true for success, false for next page is non-existant
 */
bool BufferedLCD::nextPage()
{
    if (curPage < 0 || curPage >= (pageCount-1))
        return false;
    lcd->clearDisplay();
    curPage++;
    lcd->print(pages[curPage]);
    if ((curPage+1) < pageCount)
        lcd->print(BufferedLCD::NEXT_PAGE_CHAR);
}
    
/** display the previous page
 * @return true for success, false for previous page is non-existant
 */
bool BufferedLCD::previousPage()
{
    if ( curPage <= 0)
        return false;
    lcd->clearDisplay();
    --curPage;
    lcd->print(pages[curPage]);
    lcd->print(BufferedLCD::NEXT_PAGE_CHAR);
}






















