/*Line following code
Written by: Michael Pyrch 
Get an average reading of two reflectivity
sensors, then determine to turn left or right.
If the two sensors dont detect a yellow line
then go into a search mode.*/

#include <WProgram.h>
#include "LineFollowingSystem.h"

#include "SerLCD.h"
extern SerLCD lcd;

//gather five readings then do an average
void LineFollowingSystem::getAvgSensor(int* leftOutAvg,
         int* leftInAvg, int* rightInAvg, int* rightOutAvg)
{ 
  //set values to zero
  leftInAvg = 0;
  rightInAvg = 0;
  leftOutAvg = 0;
  rightOutAvg = 0;
  
  // start sample average
  leftOut->startAvg(4);
  leftIn->startAvg(4);
  rightIn->startAvg(4);
  rightOut->startAvg(4);
  
  //Gather five readings from sensors
  for(int i = 0; i < 4; i++)
  {
    leftOut->addSample();
    leftIn->addSample();
    rightIn->addSample();
    rightOut->addSample();
    delay(50);   
  }
  
  //compute average of sensors
  (*leftInAvg) = leftIn->performAverage();
  (*rightInAvg) = rightIn->performAverage();
  (*leftOutAvg) = leftOut->performAverage();
  (*rightOutAvg) = rightOut->performAverage();
}


//adjust heading based on current heading and line
int LineFollowingSystem::followLine()
{  
  
  //call getAvgSensor to get left and right sensor values
  int leftInVal;
  int leftOutVal;
  int rightOutVal;
  int rightInVal;
  getAvgSensor(&leftOutVal, &leftInVal, &rightInVal, &rightOutVal);
  
  bool leftInOn = lightLike(leftInVal);
  bool leftOutOn = lightLike(leftOutVal);
  bool rightInOn = lightLike(rightInVal);
  bool rightOutOn = lightLike(rightOutVal);
               
  // if the left sensor is on and right is off, then veer left
  if(leftInOn && !rightInOn)
  {
    left->setForward(PSMCMotor::getMaxSpeed()/2);
    right->setForward(PSMCMotor::getMaxSpeed());
    lcd.clearDisplay();
    lcd.setLine(1);
    lcd.print("Veering Left");
    lcd.setLine(2);
    if (leftOutOn)   { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (leftInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightOutOn) { lcd.print("T "); }
    else            { lcd.print("F "); }
    return 0; // CONTINUE
  }
  
  // if right on and left not, then veer right
  else if(rightInOn && !leftInOn)
  {
    left->setForward(PSMCMotor::getMaxSpeed());
    right->setForward(PSMCMotor::getMaxSpeed()/2);
    lcd.clearDisplay();
    lcd.setLine(1);
    lcd.print("Veering Right");
    lcd.setLine(2);
    if (leftOutOn)   { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (leftInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightOutOn) { lcd.print("T "); }
    else            { lcd.print("F "); }
    return 0; // CONTINUE
  }
  
  //go to searh mode
  else if(!leftInOn && !rightInOn)
  {
    lcd.clearDisplay();
    lcd.setLine(1);
    lcd.print("ROOMBA!!");
    lcd.setLine(2);
    if (leftOutOn)   { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (leftInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightInOn)  { lcd.print("T "); }
    else            { lcd.print("F "); }
    if (rightOutOn) { lcd.print("T "); }
    else            { lcd.print("F "); }
    left->brake();
    right->brake();
    return 0;// ROOMBA
  }
  
  else
  {
      left->setForward(PSMCMotor::getMaxSpeed());
      right->setForward(PSMCMotor::getMaxSpeed());
      lcd.clearDisplay();
      lcd.setLine(1);
      lcd.print("Forward...");
      lcd.setLine(2);
      if (leftOutOn)   { lcd.print("T "); }
      else            { lcd.print("F "); }
      if (leftInOn)  { lcd.print("T "); }
      else            { lcd.print("F "); }
      if (rightInOn)  { lcd.print("T "); }
      else            { lcd.print("F "); }
      if (rightOutOn) { lcd.print("T "); }
      else            { lcd.print("F "); }
      return 0;
  }
  
  //Needs to only be performed in a room
  //might be a problem in the halway  
  //detect a left hand turn
  /*if(leftOutOn && !rightOutOn)
  {
    motor.turnLeft(leftTurn);
  }
  //detech a right hand turn
  if(rightOutOn && !leftOutOn)
  {
    motor.turnRight(rightTurn);
  }*/
  
}





