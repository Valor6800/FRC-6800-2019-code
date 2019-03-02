/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetElevatorSetpointRelative.h"

#include "Robot.h"

SetElevatorSetpointRelative::SetElevatorSetpointRelative(double setpoint) {
  m_setpoint = setpoint;
  Requires(&Robot::m_elevator);
}

// Called just before this Command runs the first time
void SetElevatorSetpointRelative::Initialize() {

  // If we are out of deadband
  // if(!std::abs(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kLeftHand)) > .05) {

      // Enable the PID thread and set the setpoint based on the button being pressed
      if(Robot::m_oi.g_shift) {
        Robot::m_elevator.SetSetpoint(Robot::m_elevator.GetPosition() + m_setpoint);
      } else {
        Robot::m_elevator.SetSetpoint(Robot::m_elevator.GetPosition() - m_setpoint);
      }
      Robot::m_elevator.Enable();
      Robot::m_elevator.EngageBrake(false);
  // }
  
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorSetpointRelative::IsFinished() { return Robot::m_elevator.OnTarget() || std::abs(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kLeftHand)) > .05  || Robot::m_elevator.encoderBroken;}

void SetElevatorSetpointRelative::End() { Robot::m_elevator.Disable(); Robot::m_elevator.EngageBrake(true);}

void SetElevatorSetpointRelative::Interrupted() { Robot::m_elevator.Disable();}


