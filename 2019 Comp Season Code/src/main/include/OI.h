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

#include "commands/DeployForklift.h"
#include "commands/ElevatorHatchMacro.h"
#include "commands/SetElevatorSetpoint.h"
#include "commands/SetIntakePivot.h"
#include "commands/SetElevatorSetpointDefinite.h"
#include "commands/SetElevatorSetpointRelative.h"
#include "commands/SpinIntakeMotors.h"
#include "commands/EnableGShift.h"
#include "commands/ToggleOutriggers.h"
#include "commands/ScoreHatch.h"
#include "commands/PrepareHatch.h"

#include "subsystems/Elevator.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Forks.h"

class OI {
 private:

  frc::Joystick m_leftJoyDrive{1};
  frc::Joystick m_rightJoyDrive{2};

  frc::XboxController m_gamepad{0};

  frc::Joystick m_footPedal{3};

  frc::JoystickButton m_a {&m_gamepad, 1};
  frc::JoystickButton m_b {&m_gamepad, 2};
  frc::JoystickButton m_x {&m_gamepad, 3};
  frc::JoystickButton m_y {&m_gamepad, 4};
  frc::JoystickButton m_bumperL {&m_gamepad, 5};
  frc::JoystickButton m_bumperR {&m_gamepad, 6};
  frc::JoystickButton m_back {&m_gamepad, 7};

 public:
  frc::Joystick& GetLeftJoyDrive();
  frc::Joystick& GetRightJoyDrive();
  frc::XboxController& GetGamepad();
  frc::JoystickButton& GetShifter();

  frc::JoystickButton shifter{&m_footPedal, 1};
  
  bool g_shift = false;

  OI();
};

