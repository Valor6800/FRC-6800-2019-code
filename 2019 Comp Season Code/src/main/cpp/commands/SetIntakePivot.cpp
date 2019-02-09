/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetIntakePivot.h"

#include "Robot.h"
#include "OI.h"

SetIntakePivot::SetIntakePivot() {
  SetInterruptible(true);
}

// Called just before this Command runs the first time
void SetIntakePivot::Initialize() {

  Robot::m_oi.g_shift ? toGo = !Robot::m_intake.GetPivot() : toGo = Robot::m_intake.GetPivot();
  Robot::m_intake.SetPivot(toGo);
}

void SetIntakePivot::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakePivot::IsFinished() {return Robot::m_intake.GetPivot() == toGo;}

void SetIntakePivot::Interrupted() {}
