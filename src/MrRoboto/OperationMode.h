/** Header for OperationMode class
 *
 * @file OperationMode.h
 * @author Andrew Keating
 */
#ifndef MRROBOTO_OPERATION_MODE_H
#define MRROBOTO_OPERATION_MODE_H

// always needed
#include <WProgram.h>

// for dip switches
#include "SwitchCollection.h"

/** Handles determining the operational mode and settings
 */
class OperationMode
{
public:
    /// available modes
    enum Modes
    {
        DO_NOTHING_MODE =                       0,
        // tests
        MOTOR_TESTS =                           1,
        SEVEN_SEGMENT_TESTS =                   2,
        IR_TESTS =                              3,
        REFLECTIVITY_TESTS =                    4,
        CAMERA_TESTS =                          5,
        GYRO_TESTS =                            6,
        EM_DETECTOR_TESTS =                     7,
        // special modes
        ROOMBA_SPECIAL =                        8,
        LINE_FOLLOWING_STRAIGHT_SPECIAL =       9,
        LINE_FOLLOWING_LEFT_SPECIAL =           10,
        LINE_FOLLOWING_RIGHT_SPECIAL =          11,
        ROOM_SEARCH_SPECIAL =                   12,
        HAZARD_DETECTION_SPECIAL =              13,
        VICTIM_STATUS_SPECIAL =                 14,
        // auto mode
        AUTO_MODE =                             15,
        SWITCH_ERROR =                          16,
        LAST_MODE =                             17
    };
    
    /// available settings for auto mode
    static const uint8_t CUT_MAX_SPEED =                     B01000000;
    static const uint8_t USE_AAOE_LINE_FOLLOWING =            B00100000;
    static const uint8_t USE_EM_FIELD_SENSOR =               B00010000;
    static const uint8_t USE_LCD_DISPLAY =                   B00001000;
    
    /// string versions of modes
    static const char* ModeStrings[OperationMode::LAST_MODE];
    
private:
    /// dip switch collection to use for determining mode
    SwitchCollection* switches;
    
public:
    /** Standard constructor
     * @param switches the switches to use to determine the mode
     */
    inline OperationMode(SwitchCollection* switches): switches(switches) {}
        
    /** Determine the operation mode and settings from the 
     * current values of the dip switches
     * @return the current operation mode
     */
    OperationMode::Modes determineMode();

    /** Determine the current settings when in auto mode
     * @param settings the current settings
     */
    uint8_t getAutoModeSettings();
    
};








#endif











