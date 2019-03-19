/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/commands/PIDSubsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>
#include <frc/Solenoid.h>
#include "commands/DriveWithJoystick.h"
#include <rev/CANSparkMaxLowLevel.h>
#include <AHRS.h>

namespace frc
{
class Joystick;
} // namespace frc

/**
 * The DriveTrain subsystem controls the robot's chassis and reads in
 * information about it's speed and position.
 */
class Drivetrain : public frc::PIDSubsystem
{
public:
  Drivetrain();

  void InitDefaultCommand();
  void TankDrive(double leftAxis, double rightAxis);
  void Stop();
  void SetShifter(bool pedal);

  double GetMotorLeftA();
  double GetMotorLeftB();
  double GetMotorRightA();
  double GetMotorRightB();
  bool GetShifter();

  double GetLeftEncoder();
  double GetRightEncoder();
  double GetEncoderAverage();

  double GetHeading();

  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;

  void UpdateLimelightTracking();

  bool m_LimelightHasTarget;
  double m_LimelightTurnCmd;
  double m_LimelightDriveCmd;

  double l;
  double r;

  double DESIRED_TARGET_AREA;

  // frc::Encoder& GetLeftEncoder();
  // frc::Encoder& GetRightEncoder();
  frc::Solenoid m_shifter{3};

  rev::CANSparkMax m_driveMotorLeftA{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_driveMotorLeftB{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_driveMotorRightA{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_driveMotorRightB{2, rev::CANSparkMax::MotorType::kBrushless};  

  frc::SpeedControllerGroup m_leftDrive{m_driveMotorLeftA, m_driveMotorLeftB};
  frc::SpeedControllerGroup m_rightDrive{m_driveMotorRightA, m_driveMotorRightB};

  frc::DifferentialDrive m_robotDrive{m_leftDrive, m_rightDrive}; 

  AHRS m_gyro{SerialPort::Port::kMXP};

private:
  




  // frc::Encoder m_leftEncoder{0, 1, false, frc::Encoder::k1X};
  // frc::Encoder m_rightEncoder{2, 3, true, frc::Encoder::k1X};

};
