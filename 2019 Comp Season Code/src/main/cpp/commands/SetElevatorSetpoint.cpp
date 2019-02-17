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
}

// Called just before this Command runs the first time
void SetElevatorSetpoint::Initialize() {}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorSetpoint::IsFinished() { 

  // Return true if the elevator has gotten to the specified PID setpoint
  return Robot::m_elevator.OnTarget(); 
}

void SetElevatorSetpoint::End() { 
  // On end, disable the PID thread and return the elevator to manual control
  Robot::m_elevator.Disable(); 
}

void SetElevatorSetpoint::Interrupted() { 
  // If interrupted by manual control, disable the PID thread and return the elevator to manual control
  Robot::m_elevator.Disable(); 
}

bool SetElevatorSetpoint::Condition() {
  // Decide which command to call based on if we are in "hatch" mode or "cargo" mode
  return Robot::m_oi.GetGamepad().GetStartButton();
}