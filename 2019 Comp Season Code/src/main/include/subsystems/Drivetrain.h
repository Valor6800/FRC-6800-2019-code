/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/SparkMax.h>
#include <frc/Solenoid.h>

namespace frc
{
class Joystick;
} // namespace frc

/**
 * The DriveTrain subsystem controls the robot's chassis and reads in
 * information about it's speed and position.
 */
class DriveTrain : public frc::Subsystem
{
public:
  DriveTrain();

  void InitDefaultCommand();
  void TankDrive(double leftAxis, double rightAxis);
  void Stop();

  frc::Encoder& GetLeftEncoder();
  frc::Encoder& GetRightEncoder();    

private:
  rev::SparkMax m_driveMotorLeftA{0};
  rev::SparkMax m_driveMotorLeftB{1};
  rev::SparkMax m_driveMotorRightA{2};
  rev::SparkMax m_driveMotorRightB{3};

  frc::Solenoid m_shifter{0};

  frc::SpeedControllerGroup m_leftDrive{m_driveMotorLeftA, m_driveMotorLeftB};
  frc::SpeedControllerGroup m_rightDrive{m_driveMotorRightA, m_driveMotorRightB};

  frc::DifferentialDrive m_robotDrive{m_leftDrive, m_rightDrive};

  frc::Encoder m_leftEncoder{0, 1, false, frc::Encoder::k1X};
  frc::Encoder m_rightEncoder{2, 3, true, frc::Encoder::k1X};

};
