/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DigitalInput.h>
#include <frc/VictorSP.h>
#include <frc/commands/PIDSubsystem.h>
#include <frc/Encoder.h>
#include <frc/SpeedControllerGroup.h>

/**
 * The Pivot subsystem contains the Van-door motor and the pot for PID control
 * of angle of the pivot and claw.
 */
class Elevator : public frc::PIDSubsystem {
 public:
  // Constants for some useful angles
  static constexpr double kBottom =             0.00;
  static constexpr double kLevelOneHatch =      0.25;
  static constexpr double kLevelOneCargo =      0.35;
  static constexpr double kLevelTwoHatch =      0.55;
  static constexpr double kLevelTwoCargo =      0.65;
  static constexpr double kLevelThreeHatch =    0.85;
  static constexpr double kLevelThreeCargo =    0.95;
  static constexpr double kTop =                1.00;

  Elevator();
  void InitDefaultCommand() override {}

  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;

  bool IsAtUpperLimit();
  bool IsAtLowerLimit();
  double GetHeight();
  double GetSpeed();

  void SetLiftSpeed(double power);

  frc::Encoder m_liftEncoder{4, 5, frc::Encoder::k1X};

 private:

  // Sensors for measuring the position of the pivot
  frc::DigitalInput m_upperLimitSwitch{1};
  frc::DigitalInput m_lowerLimitSwitch{2};

  // Motor to move the pivot
  frc::VictorSP m_liftMotorA{2};
  frc::VictorSP m_liftMotorB{3};
  frc::VictorSP m_liftMotorC{4};
  frc::VictorSP m_liftMotorD{5};

  frc::SpeedControllerGroup m_liftMotors{m_liftMotorA, m_liftMotorB, m_liftMotorC, m_liftMotorD};
  
};
