/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithJoystick.h"

#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() { Requires(&Robot::m_drivetrain); }

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {

  double leftVal = Robot::m_oi.GetDriveGamepad().GetY(frc::GenericHID::JoystickHand::kLeftHand);
  double rightVal = Robot::m_oi.GetDriveGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand);
  auto& shifter = Robot::m_oi.GetShifter();

  // If joysticks out of deadband, DO set power to wheels, ELSE stop wheels from moving
  Robot::m_drivetrain.TankDrive(std::abs(leftVal) > 0.05 ? leftVal : 0, std::abs(rightVal) > 0.05 ? rightVal : 0);
  
  // Set low vs. high gear
  Robot::m_drivetrain.SetShifter(!shifter.Get());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithJoystick::End() { Robot::m_drivetrain.Stop(); }
