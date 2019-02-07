/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <cmath>

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
//   AddChild("Front Left CIM", m_frontLeftCIM);
//   AddChild("Front Right CIM", m_frontRightCIM);
//   AddChild("Back Left CIM", m_backLeftCIM);
//   AddChild("Back Right CIM", m_backRightCIM);

  // Configure the DifferentialDrive to reflect the fact that all our
  // motors are wired backwards and our drivers sensitivity preferences.
  m_robotDrive.SetSafetyEnabled(false);
  m_robotDrive.SetExpiration(0.1);
  m_robotDrive.SetMaxOutput(1.0);
  m_robotDrive.SetDeadband(.05);
  m_driveMotorLeftA.SetParameter(rev::CANSparkMaxLowLevel::ConfigParameter::kSensorType, 1);
  m_driveMotorLeftB.SetParameter(rev::CANSparkMaxLowLevel::ConfigParameter::kSensorType, 1);
  m_driveMotorRightA.SetParameter(rev::CANSparkMaxLowLevel::ConfigParameter::kSensorType, 1);
  m_driveMotorRightB.SetParameter(rev::CANSparkMaxLowLevel::ConfigParameter::kSensorType, 1);



  // Configure encoders
  // m_rightEncoder.SetPIDSourceType(frc::PIDSourceType::kDisplacement);
  // m_leftEncoder.SetPIDSourceType(frc::PIDSourceType::kDisplacement);

//   AddChild("Right Encoder", m_rightEncoder);
//   AddChild("Left Encoder", m_leftEncoder);

//   AddChild("Gyro", m_gyro);

}

void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::TankDrive(double leftAxis, double rightAxis) {
  m_robotDrive.TankDrive(leftAxis, rightAxis);
}

void Drivetrain::Stop() { m_robotDrive.TankDrive(0.0, 0.0); }

void Drivetrain::SetShifter(bool pedal) {m_shifter.Set(pedal);}

double Drivetrain::GetMotorLeftA() {
  m_driveMotorLeftA.Get();
}

double Drivetrain::GetMotorLeftB() {
  m_driveMotorLeftB.Get();
}

double Drivetrain::GetMotorRightA() {
  m_driveMotorRightA.Get();
}

double Drivetrain::GetMotorRightB() {
  m_driveMotorRightB.Get();
}

bool Drivetrain::GetShifter() {
  m_shifter.Get();
}

// frc::Encoder& Drivetrain::GetLeftEncoder() { return m_leftEncoder; }

// frc::Encoder& Drivetrain::GetRightEncoder() { return m_rightEncoder; }
