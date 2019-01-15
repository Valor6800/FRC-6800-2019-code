/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorManual.h"

#include "Robot.h"

ElevatorManual::ElevatorManual() { Requires(&Robot::m_elevator); }

// Called repeatedly when this Command is scheduled to run
void ElevatorManual::Execute() {
  auto& gamepad = Robot::m_oi.GetGamepad();
  Robot::m_elevator.SetLiftSpeed(gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand) > .05 ? gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand) : 0);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorManual::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorManual::End() { Robot::m_elevator.Stop();