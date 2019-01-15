/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetElevatorSetpoint.h"

#include "Robot.h"

SetElevatorSetpoint::SetElevatorSetpoint(double setpoint) {
  m_setpoint = setpoint;
  Requires(&Robot::m_elevator);
}

// Called just before this Command runs the first time
void SetElevatorSetpoint::Initialize() {
  Robot::m_elevator.Enable();
  Robot::m_elevator.SetSetpoint(m_setpoint);
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorSetpoint::IsFinished() { return Robot::m_elevator.OnTarget(); }
