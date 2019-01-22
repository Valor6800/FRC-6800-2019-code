/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetIntakePivot.h"

#include "Robot.h"

SetIntakePivot::SetIntakePivot(bool up) {
  Requires(&Robot::m_intake);
  SetInterruptible(true);
  Robot::m_intake.m_pivotDown = up;
}

// Called just before this Command runs the first time
void SetIntakePivot::Initialize() {
  Robot::m_intake.SetPivot(Robot::m_intake.m_pivotDown); // change values
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakePivot::IsFinished() { return Robot::m_intake.m_pivotSolenoid.Get() == Robot::m_intake.m_pivotDown;}

void SetIntakePivot::Interrupted() {}
