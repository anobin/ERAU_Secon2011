/** Simple code to test motor controller
 * @author Andrew J. Keating
 */

// make sure build script includes following libraries 
#include <SoftwareSerial.h>
#include <Wire.h>

// enable rate 
//#define IR_RATE

#include "Utils.h"
#include "SoftSerial.h"
#include "SerLCD.h"
#include "BufferedLCD.h"
#include "LED.h"
#include "Switch.h"
#include "SwitchCollection.h"
#include "PSMCMotor.h"
#include "DigitDisplay.h"
#include "ReflectivitySensor.h"
#include "SIPOShiftRegisterIC.h"
#include "SIPOShiftGroup.h"
#include "SevenSegmentDisplay.h"
#include "IR.h"
#include "OperationMode.h"
#include "LineFollowingSystem.h"
#include "WallFollowing.h"

// test classes
#define TESTS_ENABLED
#include "Tests.h"
#include "MotorTests.h"
#include "DIPTests.h"
#include "ReflectivityTests.h"
#include "IRTests.h"

//SoftSerial msoft(11, 12);
PSMCMotor leftMotor(15, &Serial3, 34);
PSMCMotor rightMotor(13, &Serial3, 34);
//SoftSerial soft(9, 10);
SerLCD lcd(&Serial2, SerLCD::LCD_16X2);
BufferedLCD blcd(&lcd);
LED led(13);
Switch sw(31);
SIPOShiftGroup shift(33);
DigitDisplay digits(&shift);

// dip switches
Switch dip1(2);
Switch dip2(3);
Switch dip3(4);
Switch dip4(5);
Switch dip5(6);
Switch dip6(7);
Switch dip7(8);
Switch dip8(9);
Switch dip9(10);
Switch dip10(11);
SwitchCollection dips;

// reflectivity sensor
ReflectivitySensor leftOutRF(0);
ReflectivitySensor leftInRF(1);
ReflectivitySensor rightInRF(2);
ReflectivitySensor rightOutRF(3);

// IR rangefinders
//IR leftIR(0x26);
IR frontLeftIR(0x28, IR::INCHES);
IR frontRightIR(0x20, IR::INCHES);
IR rightIR(0x22, IR::INCHES);

// tests
DIPTests dipTests(&blcd, &sw, &dips);
ReflectivityTests rfTests(&blcd, &sw, &leftOutRF, &leftInRF, &rightInRF, &rightOutRF);
IRTests irTests(&blcd, &sw, &rightIR, &frontLeftIR, &frontRightIR, &rightIR);
MotorTests mtests(&blcd, &sw, &leftMotor, &rightMotor);

// mode determinier
OperationMode modeDeterminier(&dips);

// high level logic states
LineFollowingSystem lineFollowing(&leftMotor, &rightMotor, &leftOutRF, &leftInRF,
                                  &rightInRF, &rightOutRF);
WallFollowing wallFollowing(&leftMotor, &rightMotor, &frontRightIR, &rightIR, &rightIR);
                                  


/// setup DIP switches
void setupDIPS()
{
  dip1.setup(); dips.addSwitch(&dip1);
  dip2.setup(); dips.addSwitch(&dip2);
  dip3.setup(); dips.addSwitch(&dip3);
  dip4.setup(); dips.addSwitch(&dip4);
  dip5.setup(); dips.addSwitch(&dip5);
  dip6.setup(); dips.addSwitch(&dip6);
  dip7.setup(); dips.addSwitch(&dip7);
  dip8.setup(); dips.addSwitch(&dip8);
  dip9.setup(); dips.addSwitch(&dip9);
  dip10.setup(); dips.addSwitch(&dip10);
  dipTests.setup();
}

/// init function
void setup() 
{  
  Serial.begin(9600);
  
  led.setup();
  led.on();
  sw.setup();
  
  setupDIPS();
  
  Wire.begin();
  
  shift.setup();
  shift.addRegister(37);
  shift.addRegister(39);
  shift.addRegister(41);
  shift.addRegister(43);
  shift.addRegister(45);
  shift.addRegister(47);
  
  // set adjustment for left outer
  leftOutRF.setAdjustment(-100);
  
  // set buad rates for serial lines 
  //soft.begin(9600);
  //msoft.begin(9600);
  Serial.begin(::BAUD_RATE);
  Serial1.begin(::BAUD_RATE);
  Serial2.begin(::BAUD_RATE);
  Serial3.begin(::BAUD_RATE);
  leftMotor.setup();
  rightMotor.setup();
  lcd.setup();
  randomSeed(analogRead(10));
  
  // tests setup
  irTests.setup();
  rfTests.setup();
  mtests.setup();
  
  delay(2000);
  //lcd.setBrightness(SerLCD::MAX_BRIGHTNESS/2);
  led.off();
  return;
  
INIT_FAILED:
    lcd.clearDisplay();
    lcd.setLine(1);
    lcd.print("INIT FAILED");
    while (true)
    {
      led.on();
      delay(5);
      led.off();
      delay(5);
    }
      
  //leftMotor.start();
  //rightMotor.start();
}

void todo(const char* mode)
{
  lcd.clearDisplay();
  lcd.setLine(1);
  lcd.print(mode);
  lcd.print(" TODO");
  delay(2000);
}

/// main exection loop
void loop() 
{
    /*lcd.clearDisplay();
    lcd.setLine(1);
    lcd.print("Mr. Roboto");
    lcd.setLine(2);
    uint16_t temp;
    bool b = leftMotor.getVariable(PSMCMotor::INPUT_VOLTAGE, &temp);
    if (b)
        lcd.print((float(temp))/1000, DEC);
    else
        lcd.print("error reading input voltage");
        
    leftMotor.setForward(PSMCMotor::maxSpeed/2 + PSMCMotor::maxSpeed/4);
    rightMotor.setForward(PSMCMotor::maxSpeed/2 + PSMCMotor::maxSpeed/4);*/
    
    /*lcd.clearDisplay();
    lcd.setLine(1);*/
    /*led.on();
    sw.waitTillActive();
    //blcd.nextPage();
    led.off();
    sw.waitTillInActive();*/
    //mtests.runSuite();
    //dipTests.runSuite();
    
    /*digits.setDigit(0, '7');
    digits.update();
    delay(500);*/
    /*static char c = '0';
    shift.setRegister(0, SevenSegmentDisplay::char2PanelsTable[c]);
    shift.shiftAll();
    if (c == '9')
      c = '0';
    else
      c++;*/
    /*for (char i='0'; i <= '9'; i++)
    {
      for(int j=0; j < digits.getDigitCount(); j++)
      {
         digits.setDigit(j, i);
      }
      digits.update();
      delay(500);
    }*/
    
    /*for (int i=0; i < 8; i++)
    {
      uint8_t panel;
      switch(i+1)
      {
        case 1: panel = SevenSegmentDisplay::P1; break;
        case 2: panel = SevenSegmentDisplay::P2; break;
        case 3: panel = SevenSegmentDisplay::P3; break;
        case 4: panel = SevenSegmentDisplay::P4; break;
        case 5: panel = SevenSegmentDisplay::P5; break;
        case 6: panel = SevenSegmentDisplay::P6; break;
        case 7: panel = SevenSegmentDisplay::P7; break;
        case 8: panel = SevenSegmentDisplay::P8; break;
      }
      
      for(int j=0; j < shift.getRegisterCount(); j++)
      {
         shift.setRegister(j, panel);
      }
      shift.shiftAll();
      delay(50);
    }*/
    
    /*digits.setDigits("TECHNO");
    digits.update();
    
    delay(2000);
    
    for (int k=0; k < 100; k++)
    {
    for(int j=0; j < shift.getRegisterCount(); j++)
    {
      long rand = random(1, 9);
      uint8_t panel = 0x00;
      for (int i=0; i < rand; i++)
      {
        switch(random(1, 9))
        {
          case 1: panel |= SevenSegmentDisplay::P1; break;
          case 2: panel |= SevenSegmentDisplay::P2; break;
          case 3: panel |= SevenSegmentDisplay::P3; break;
          case 4: panel |= SevenSegmentDisplay::P4; break;
          case 5: panel |= SevenSegmentDisplay::P5; break;
          case 6: panel |= SevenSegmentDisplay::P6; break;
          case 7: panel |= SevenSegmentDisplay::P7; break;
          case 8: panel |= SevenSegmentDisplay::P8; break;
        }
      }
      shift.setRegister(j, panel);
    }
    shift.shiftAll();
    delay(50);
    }*/

    
    /*lcd.clearDisplay();
    lcd.setLine(1);
    for (int i=0; i < dips.getSwitchCount(); i++)
    {
      lcd.print(i, DEC);
      lcd.print(dips.getSwitch(i)->active());
      lcd.print(",");
    }
    delay(500);*/
    
    // determine and print mode
    static bool once = false;
    static OperationMode::Modes mode = OperationMode::DO_NOTHING_MODE;
    if (!once)
    {
      digits.setDigits("       ");
      digits.update();
      mode = modeDeterminier.determineMode();
      lcd.clearDisplay();
      lcd.setLine(1);
      lcd.print(OperationMode::ModeStrings[(int)mode]);
      lcd.print(", PSC");
      if (mode != OperationMode::AUTO_MODE)
        sw.waitTillCycle();
      
      //PSMCMotor::setMaxSpeed(PSMCMotor::getMaxSpeed()/4);
      once = true;
    }
    
    // evaluate mode
    switch(mode)
    {
      // tests
      case OperationMode::MOTOR_TESTS:
        mtests.runSuite();
        break;
      case OperationMode::SEVEN_SEGMENT_TESTS:
        digits.setDigits("TECHNO");
        digits.update();
        delay(2000);
        break;
      case OperationMode::IR_TESTS:
        irTests.runSuite();
        break;
      case OperationMode::REFLECTIVITY_TESTS:
        rfTests.runSuite();
        break;
      case OperationMode::CAMERA_TESTS:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::GYRO_TESTS:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::EM_DETECTOR_TESTS:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
        
      // special modes
      case OperationMode::ROOMBA_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::LINE_FOLLOWING_STRAIGHT_SPECIAL:
        /*lcd.clearDisplay();
        lcd.setLine(1);
        lcd.print("Following Line, Straight");*/
        while (true)
        {
          wallFollowing.followWallIteration();
          delay(50);
        }
        break;
      case OperationMode::LINE_FOLLOWING_LEFT_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::LINE_FOLLOWING_RIGHT_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::ROOM_SEARCH_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::HAZARD_DETECTION_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
      case OperationMode::VICTIM_STATUS_SPECIAL:
        todo(OperationMode::ModeStrings[(int)mode]);
        break;
        
      // auto mode
      case OperationMode::AUTO_MODE:
        while(true)
        {
          leftMotor.setForward(PSMCMotor::getMaxSpeed());
          rightMotor.setForward(PSMCMotor::getMaxSpeed());
          for (int k=0; k < 100; k++)
          {
            for(int j=0; j < shift.getRegisterCount(); j++)
            {
              long rand = random(1, 9);
              uint8_t panel = 0x00;
              for (int i=0; i < rand; i++)
              {
              switch(random(1, 9))
             {
          case 1: panel |= SevenSegmentDisplay::P1; break;
          case 2: panel |= SevenSegmentDisplay::P2; break;
          case 3: panel |= SevenSegmentDisplay::P3; break;
          case 4: panel |= SevenSegmentDisplay::P4; break;
          case 5: panel |= SevenSegmentDisplay::P5; break;
          case 6: panel |= SevenSegmentDisplay::P6; break;
          case 7: panel |= SevenSegmentDisplay::P7; break;
          case 8: panel |= SevenSegmentDisplay::P8; break;
        }
      }
      shift.setRegister(j, panel);
    }
    shift.shiftAll();
    delay(10);
    }
       int f = 0;
      Wire.beginTransmission(0x28);
      Wire.send(1); 
      Wire.endTransmission();
      Wire.requestFrom(0x28,1);
      if (Wire.available())
      {
        f = Wire.receive();
        Wire.endTransmission();
        if (f != 0 && f < 20)
        {
          leftMotor.brake();
          rightMotor.brake();
          while (true) {delay(100); }
        }
      }
    
        }
        break;
      
      // do nothing mode
      case OperationMode::DO_NOTHING_MODE:
        // well...
        lcd.clearDisplay();
        lcd.setLine(1);
        lcd.print("Doing Nothing...");
        delay(2000);
      break;
      
      // switch error
      case OperationMode::SWITCH_ERROR:
        lcd.clearDisplay();
        lcd.setLine(1);
        digits.setDigits("ERROR ");
        digits.update();
        lcd.print("Error in DIP switches");
        delay(2000);
        break;
      
      // error mode undefined
      default:
        lcd.clearDisplay();
        lcd.setLine(1);
        digits.setDigits("ERROR ");
        digits.update();
        lcd.print("Error: Mode Undefined");
        delay(2000);
        break;
    }
    
    /*byte rdata = 0;
    for (int i=0x20; i <= 0x2E; i++)
    {
      Wire.beginTransmission(i);
      Wire.send(1); 
      Wire.endTransmission();
      Wire.requestFrom(i,1);
      if (Wire.available())
      {
        rdata = Wire.receive();
        Wire.endTransmission();
        Serial.print(i, HEX);
        Serial.print(" ");
        Serial.println(rdata, DEC);
      }
      delay(100);
    }*/
    
    
} // end of loop()













































