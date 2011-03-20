/** Implementation file for OperationMode class
 *
 * @file OperationMode.cpp
 * @author Andrew Keating
 */

#include "OperationMode.h"

/** Determine the operation mode and settings from the 
 * current values of the dip switches
 * @return the current operation mode
 */
OperationMode::Modes OperationMode::determineMode()
{
   // check to make sure we have enough switches for mode determinination
   if (switches->getSwitchCount() < 10)
       return OperationMode::SWITCH_ERROR;
   
   // rearrange switches to start from 1 (since they are physically labelled as so)
   bool sw[11];
   sw[0] = NULL;
   for (int i=1; i < 11; i++)
       sw[i] = switches->getSwitch(i-1)->active();
   
   // check for top-level mode group
   
   // tests
   if (sw[1])
   {
       if (sw[2])
           return OperationMode::MOTOR_TESTS;
       else if (sw[3])
           return OperationMode::SEVEN_SEGMENT_TESTS;
       else if (sw[4])
           return OperationMode::IR_TESTS;
       else if (sw[5])
           return OperationMode::REFLECTIVITY_TESTS;
       else if (sw[6])
           return OperationMode::CAMERA_TESTS;
       else if (sw[7])
           return OperationMode::GYRO_TESTS;
       else if (sw[8])
           return OperationMode::EM_DETECTOR_TESTS;
       else
           return OperationMode::DO_NOTHING_MODE;
   }
   
   // special modes
   else if (sw[2])
   {
       if (sw[3])
           return OperationMode::ROOMBA_SPECIAL;
       else if (sw[4])
           return OperationMode::LINE_FOLLOWING_STRAIGHT_SPECIAL;
       else if (sw[5])
           return OperationMode::LINE_FOLLOWING_LEFT_SPECIAL;
       else if (sw[6])
           return OperationMode::LINE_FOLLOWING_RIGHT_SPECIAL;
       else if (sw[7])
           return OperationMode::ROOM_SEARCH_SPECIAL;
       else if (sw[8])
           return OperationMode::HAZARD_DETECTION_SPECIAL;
       else if (sw[9])
           return OperationMode::VICTIM_STATUS_SPECIAL;
       else
           return OperationMode::DO_NOTHING_MODE;
   }
   
   // auto mode
   else if (sw[3])
       return OperationMode::AUTO_MODE;
   
   // do nothing, i guess
   else
       return OperationMode::DO_NOTHING_MODE;
}

/** Determine the current settings when in auto mode
 * @param settings the current settings
 */
uint8_t OperationMode::getAutoModeSettings()
{
    // check to make sure we have enough switches for mode determinination
   if (switches->getSwitchCount() < 10)
       return 0x00;
   
   // rearrange switches to start from 1 (since they are physically labelled as so)
   bool sw[11];
   sw[0] = NULL;
   for (int i=1; i < 11; i++)
       sw[i] = switches->getSwitch(i-1)->active();
   
   // check for not auto mode
   uint8_t settings = 0x00;
   if (!sw[3])
       return settings; // not auto mode
   
   // check settings
   if (sw[4])
       settings |= OperationMode::CUT_MAX_SPEED;
   if (sw[5])
       settings |= OperationMode::USE_AAOE_LINE_FOLLOWING;
   if (sw[6])
       settings |= OperationMode::USE_EM_FIELD_SENSOR;
   if (sw[7])
       settings |= OperationMode::USE_LCD_DISPLAY;
   
   return settings;
}
    
const char* OperationMode::ModeStrings[OperationMode::LAST_MODE] =
{
    "Do Nothing",
    // tests
    "Motor Tests",
    "Seven Segment Tests",
    "IR Tests",
    "Reflectivity Tests",
    "Camera Tests",
    "Gyroscope Tests",
    "EM Detector Tests",
    // special modes
    "Roomba Mode",
    "Line Follow-straight",
    "Line Follow-left",
    "Line Follow-right",
    "Room Search Mode",
    "Hazard Detection Mode",
    "Victim Status Id. Mode",
    // auto mode
    "Autonomous Mode",
    "Error with DIP switches"
};



















