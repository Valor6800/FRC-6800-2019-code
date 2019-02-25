/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PIDTurn.h"

#include "Robot.h"

PIDTurn::PIDTurn(double setpoint) {
  m_setpoint = setpoint;
  Requires(&Robot::m_drivetrain);

}

// Called just before this Command runs the first time
void PIDTurn::Initialize() {

  // If we are out of deadband
  // if(!std::abs(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kLeftHand)) > .05) {
  // Enable the PID thread and set the setpoint based on the button being pressed
  Robot::m_drivetrain.SetSetpoint(m_setpoint);
  Robot::m_drivetrain.Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool PIDTurn::IsFinished() { return Robot::m_drivetrain.OnTarget() || std::abs(Robot::m_oi.GetLeftJoyDrive().GetY()) > .05 || std::abs(Robot::m_oi.GetRightJoyDrive().GetY()) > .05;}

void PIDTurn::End() { Robot::m_drivetrain.Disable();}

void PIDTurn::Interrupted() { Robot::m_drivetrain.Disable();}


