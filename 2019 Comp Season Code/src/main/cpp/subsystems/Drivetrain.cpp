/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <cmath>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include "Robot.h"

Drivetrain::Drivetrain() : frc::PIDSubsystem("Drivetrain", 0.005, 0, 0) {
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

  GetPIDController()->SetOutputRange(-180, 180);
  GetPIDController()->SetAbsoluteTolerance(0.5);
  GetPIDController()->SetContinuous(true);
  GetPIDController()->SetOutputRange(-1, 1);



  // Configure encoders
  // m_rightEncoder.SetPIDSourceType(frc::PIDSourceType::kDisplacement);
  // m_leftEncoder.SetPIDSourceType(frc::PIDSourceType::kDisplacement);

//   AddChild("Right Encoder", m_rightEncoder);
//   AddChild("Left Encoder", m_leftEncoder);

//   AddChild("Gyro", m_gyro);

}

double clamp(double in,double minval,double maxval)
{
  if (in > maxval) return maxval;
  if (in < minval) return minval;
  return in;
}

double Drivetrain::ReturnPIDInput() { 
  return GetHeading();
}

void Drivetrain::UsePIDOutput(double output) { 

  // if(GetPosition() < GetSetpoint()) {
  //   m_liftMotors.PIDWrite(-output); 
  // } else {
  //   m_liftMotors.PIDWrite(output);
  // }

  TankDrive(-output, output); //TODO: If this goes the wrong way, swap the negative
}

void Drivetrain::AddOffset(double toAdd) {
  visionOffset += toAdd;
}

void Drivetrain::InitDefaultCommand() {
  SetDefaultCommand(new DriveWithJoystick());
}

void Drivetrain::TankDrive(double leftAxis, double rightAxis) {
  m_robotDrive.TankDrive(leftAxis, rightAxis, true);
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

double Drivetrain::GetLeftEncoder() {
  return -m_driveMotorLeftA.GetEncoder().GetPosition();
}

double Drivetrain::GetRightEncoder() {
  return m_driveMotorRightA.GetEncoder().GetPosition();
}

double Drivetrain::GetEncoderAverage() {
  return (GetLeftEncoder() + GetRightEncoder()) / 2.0;
}

double Drivetrain::GetHeading() {
  return 1;
  // m_gyro.GetYaw();
}

void Drivetrain::UpdateLimelightTracking() {
  // Proportional Steering Constant:
  // If your robot doesn't turn fast enough toward the target, make this number bigger
  // If your robot oscillates (swings back and forth past the target) make this smaller
  const double STEER_K = 0.05;
  // comp bot = .05
  // practice bot = .06

  // Proportional Drive constant: bigger = faster drive
  const double DRIVE_K = 2.5;

  // Area of the target when your robot has reached the goal
  DESIRED_TARGET_AREA = 1.7;
  const double MAX_DRIVE = 0.55;

  const double MAX_STEER = 0.6f;
  // comp bot = .6
  // practice bot = .7

  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  // NOTE: THIS NUMBER IS OUR OFFSET. Subtracting is left, adding is right
  double tx = table->GetNumber("tx",0.0) + visionOffset;
  double ty = table->GetNumber("ty",0.0);
  double ta = table->GetNumber("ta",0.0);
  double tv = table->GetNumber("tv",0.0);

  double y_val;

  if (tv < 1.0) {
    m_LimelightHasTarget = false;
    m_LimelightTurnCmd = 0.0;
  } else {
    m_LimelightHasTarget = true;

    // Proportional steering
    m_LimelightTurnCmd = tx*STEER_K;
    m_LimelightTurnCmd = clamp(m_LimelightTurnCmd,-MAX_STEER,MAX_STEER);

    // drive forward until the target area reaches our desired area
    // m_LimelightDriveCmd = (DESIRED_TARGET_AREA - ta) * DRIVE_K;
    // m_LimelightDriveCmd = clamp(m_LimelightDriveCmd,-MAX_DRIVE,MAX_DRIVE);
    
  }

  m_LimelightDriveCmd = Robot::m_oi.GetDriveGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) * std::abs(Robot::m_oi.GetDriveGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand));
  
}

// frc::Encoder& Drivetrain::GetLeftEncoder() { return m_leftEncoder; }

// frc::Encoder& Drivetrain::GetRightEncoder() { return m_rightEncoder; }
