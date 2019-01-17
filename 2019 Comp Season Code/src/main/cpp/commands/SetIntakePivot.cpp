/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetIntakePivot.h"

#include "Robot.h"

SetIntakePivot::SetIntakePivot() {
  Requires(&Robot::m_intake);
  SetInterruptible(true);
}

// Called just before this Command runs the first time
void SetIntakePivot::Initialize() {
  Robot::m_intake.Enable();
  Robot::m_intake.SetPivot(Robot::m_intake.TogglePivot() ? 1.0 : 0.0); // change values
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakePivot::IsFinished() { return Robot::m_intake.OnTarget(); }

void SetIntakePivot::Interrupted() { Robot::m_intake.Disable(); }
