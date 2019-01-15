/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/WPILib.h>
#include <frc/XboxController.h>
#include <frc/Joystick.h>
#include <frc/buttons/Button.h>

class OI {
 private:
  frc::Joystick m_leftJoyDrive{1};
  frc::Joystick m_rightJoyDrive{2};

  frc::XboxController m_gamepad{0};

  frc::Joystick m_button{3};
 public:
  frc::Joystick& GetLeftJoyDrive();
  frc::Joystick& GetRightJoyDrive();
  frc::XboxController& GetGamepad();
  frc::JoystickButton& GetShifter();

  frc::JoystickButton shifter{&button, 0};

  //Button *pedal;
  OI();
};

