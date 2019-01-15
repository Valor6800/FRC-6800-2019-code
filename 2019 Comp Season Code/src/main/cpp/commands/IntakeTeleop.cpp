/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeTeleop.h"

#include "Robot.h"

IntakeTeleop::IntakeTeleop() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_intake);
}

// Called just before this Command runs the first time
void IntakeTeleop::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeTeleop::Execute() {
    if (Robot::m_oi.GetGamepad()->GetBButton()) {
        Robot::m_intake.SetWheelMotor(0.5);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeTeleop::IsFinished() { return false; }

// Called once after isFinished returns true
void IntakeTeleop::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeTeleop::Interrupted() {}
