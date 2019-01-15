/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetElevatorSetpointDefinite.h"

#include "Robot.h"

SetElevatorSetpointDefinite::SetElevatorSetpointDefinite(double setpoint) {
  m_setpoint = setpoint;
  Requires(&Robot::m_elevator);
  SetInterruptible(true);
}

// Called just before this Command runs the first time
void SetElevatorSetpointDefinite::Initialize() {
  Robot::m_elevator.Enable();
  Robot::m_elevator.SetSetpoint(m_setpoint);
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorSetpointDefinite::IsFinished() { return Robot::m_elevator.OnTarget(); }

void SetElevatorSetpointDefinite::Interrupted() { Robot::m_elevator.Disable(); }


