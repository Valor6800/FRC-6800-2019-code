/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"

Elevator::Elevator() : frc::PIDSubsystem("Elevator", 7.0, 0.0, 8.0) {
  SetAbsoluteTolerance(0.01);
  GetPIDController()->SetContinuous(false);

  // Put everything to the LiveWindow for testing.
  // AddChild("Upper Limit Switch", m_upperLimitSwitch);
  // AddChild("Lower Limit Switch", m_lowerLimitSwitch);
  // AddChild("Pot", m_pot);
  // AddChild("Motor", m_motor);
}

void InitDefaultCommand() {}
double Elevator::ReturnPIDInput() { return m_liftEncoder.Get(); }

void Elevator::UsePIDOutput(double output) { m_liftMotors.PIDWrite(output); }

bool Elevator::IsAtUpperLimit() {
  return m_upperLimitSwitch.Get();  // TODO: inverted from real robot
                                    // (prefix with !)
}

bool Elevator::IsAtLowerLimit() {
  return m_lowerLimitSwitch.Get();  // TODO: inverted from real robot
                                    // (prefix with !)
}

double Elevator::GetHeight() { return m_liftEncoder.Get(); }


void Elevator::SetLiftSpeed(double power) {
    m_liftMotors.Set(power);
}
