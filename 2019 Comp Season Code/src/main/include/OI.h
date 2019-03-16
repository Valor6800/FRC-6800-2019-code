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
#include "commands/HoldHatch.h"
#include "commands/AutoAlign.h"

#include "commands/ElevatorMacros/Region1/ElevatorOneLowMacro.h"
#include "commands/ElevatorMacros/Region1/ElevatorOneMedMacro.h"
#include "commands/ElevatorMacros/Region1/ElevatorOneHighMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoLowMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoMedMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoHighMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeLowMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeMedMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeHighMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourLowMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourMedMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourHighMacro.h"

#include "commands/ElevatorMacros/Region1/ElevatorOneCargoMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoCargoMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeCargoMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourCargoMacro.h"

#include "commands/ElevatorMacros/Region1/ElevatorOneRocketCargo.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargo.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeRocketCargo.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourRocketCargo.h"

#include "commands/ElevatorMacros/Region4/ElevatorFourCargoInMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourLowInMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourMedInMacro.h"
#include "commands/ElevatorMacros/Region4/ElevatorFourRocketCargoIn.h"
#include "commands/ElevatorMacros/Region1/ElevatorOneMedInMacro.h"
#include "commands/ElevatorMacros/Region1/ElevatorOneRocketCargoIn.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeCargoInMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeLowInMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeRocketCargoIn.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoCargoInMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoMedInMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargoIn.h"
#include "commands/ElevatorMacros/Region1/ElevatorOneHighInMacro.h"
#include "commands/ElevatorMacros/Region2/ElevatorTwoHighInMacro.h"
#include "commands/ElevatorMacros/Region3/ElevatorThreeMedInMacro.h"


#include "commands/ElevatorHighSetpoint.h"
#include "commands/ElevatorMedSetpoint.h"
#include "commands/ElevatorLowSetpoint.h"
#include "commands/ElevatorCargoSetpoint.h"

#include "subsystems/Elevator.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Forks.h"
#include "subsystems/Carriage.h"

#include "CustomTrigger.h"

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

  frc::CustomTrigger One_Low {'X', -100, 220};
  frc::CustomTrigger One_Med {'B', -100, 220};
  frc::CustomTrigger One_High {'Y', -100, 220};

  frc::CustomTrigger Two_Low {'X', 220, 330};
  frc::CustomTrigger Two_Med {'B', 220, 330};
  frc::CustomTrigger Two_High {'Y', 220, 330};

  frc::CustomTrigger Three_Low {'X', 330, 550};
  frc::CustomTrigger Three_Med {'B', 330, 550};
  frc::CustomTrigger Three_High {'Y', 330, 550};

  frc::CustomTrigger Four_Low {'X', 550, 1000};
  frc::CustomTrigger Four_Med {'B', 550, 1000};
  frc::CustomTrigger Four_High {'Y', 550, 1000};

  // frc::Trigger High_Low {}

 public:
  frc::Joystick& GetLeftJoyDrive();
  frc::Joystick& GetRightJoyDrive();
  frc::XboxController& GetGamepad();
  frc::JoystickButton& GetShifter();

  frc::JoystickButton shifter{&m_footPedal, 1};
  frc::JoystickButton aligner{&m_rightJoyDrive, 1};

  bool g_shift = false;

  OI();
};

