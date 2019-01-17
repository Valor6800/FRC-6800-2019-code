/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SpinIntakeMotors.h"

#include "Robot.h"

SpinIntakeMotors::SpinIntakeMotors() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_intake);
}

// Called just before this Command runs the first time
void SpinIntakeMotors::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SpinIntakeMotors::Execute() { // possible edit trigger axis value
    if (Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > 0.05) {        
        Robot::m_intake.SetWheelMotor(Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand));
    }
    else if (Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > 0.05) {        
        Robot::m_intake.SetWheelMotor(-(Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand)));
    }
}

// Make this return true when this Command no longer needs to run execute()
bool SpinIntakeMotors::IsFinished() { return false; } 

// Called once after isFinished returns true
void SpinIntakeMotors::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinIntakeMotors::Interrupted() {}