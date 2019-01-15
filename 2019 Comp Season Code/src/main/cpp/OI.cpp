/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() {
  // Process operator interface input here.



  //pedal = new Button(3);
}

frc::Joystick& OI::GetLeftJoyDrive() {
  return leftJoyDrive;
}

frc::Joystick& OI::GetRightJoyDrive() {
  return rightJoyDrive;
}

frc::XboxController& OI::GetGamepad() {
  return gamepad;
}

frc::JoystickButton& OI::GetShifter() {
  return shifter;
}