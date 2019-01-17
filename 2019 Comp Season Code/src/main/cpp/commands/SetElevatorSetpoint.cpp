/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetElevatorSetpoint.h"

#include "Robot.h"

SetElevatorSetpoint::SetElevatorSetpoint(Command* hatchCommand, Command* cargoCommand) : frc::ConditionalCommand(hatchCommand, cargoCommand) {
  Requires(&Robot::m_elevator);
  SetInterruptible(true);
}

// Called just before this Command runs the first time
void SetElevatorSetpoint::Initialize() {}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorSetpoint::IsFinished() { return Robot::m_elevator.OnTarget(); }

void SetElevatorSetpoint::Interrupted() { Robot::m_elevator.Disable(); }

bool SetElevatorSetpoint::Condition() {
  return Robot::m_oi.GetGamepad().GetStartButton();
}