/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Elevator.h"

Elevator::Elevator() : frc::PIDSubsystem("Elevator", .004, 0.0, 0) {
  SetAbsoluteTolerance(0.01);
  GetPIDController()->SetContinuous(false);
  SetOutputRange(-.4, .8); // -.4 to .8 
  // Put everything to the LiveWindow for testing.
  // AddChild("Upper Limit Switch", m_upperLimitSwitch);
  // AddChild("Lower Limit Switch", m_lowerLimitSwitch);
  // AddChild("Pot", m_pot);
  // AddChild("Motor", m_motor);
  m_liftEncoder.SetDistancePerPulse(1);
  m_liftEncoder.SetMinRate(10);

  encoderBroken = false;

}

void Elevator::InitDefaultCommand() {SetDefaultCommand(new ElevatorManual());}
double Elevator::ReturnPIDInput() { return m_liftEncoder.Get(); }

void Elevator::UsePIDOutput(double output) { 

  if(GetPosition() < GetSetpoint()) {
    m_liftMotors.PIDWrite(-output); 
  } else {
    m_liftMotors.PIDWrite(output);
  }

  // double power = output;

  // // This is for going up
  // if(power < .15 && power > 0) {
  //   power = .15;
  // } 
  // // This is for going down
  // else if(power > -.15 && power < 0) {
  //   power = -.15;
  // }

  // m_liftMotors.PIDWrite(-power);
}

bool Elevator::IsAtLowerLimit() {
  // return false;
  return (!m_limitSwitch1.Get() && !m_limitSwitch2.Get());  // TODO: inverted from real robot
                                                            // (prefix with !)
}

double Elevator::GetSpeed() {
  return m_liftMotors.Get();
}

double Elevator::GetHeight() { return m_liftEncoder.Get(); }

bool Elevator::GetBrake() { return m_brake.Get(); }

void Elevator::SetLiftSpeed(double power) {
    m_liftMotors.Set(power);
}

bool Elevator::EncoderBroken() {
  return false;
  // return m_liftEncoder.GetStopped() && std::abs(m_liftMotors.Get()) > .05;
}

void Elevator::EngageBrake(bool engage) {
    m_brake.Set(!engage);
}
