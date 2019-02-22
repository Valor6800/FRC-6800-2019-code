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
#include "commands/ElevatorManual.h"
#include <frc/Solenoid.h>

/**
 * The Pivot subsystem contains the Van-door motor and the pot for PID control
 * of angle of the pivot and claw.
 */
class Elevator : public frc::PIDSubsystem {
 public:
  // Constants for some useful angles
  static constexpr double kBottom =             550;
  static constexpr double kLevelOneHatch =      90;
  static constexpr double kLevelOneCargo =      90;
  static constexpr double kLevelTwoHatch =      350;
  static constexpr double kLevelTwoCargo =      350;
  static constexpr double kLevelThreeHatch =    650;
  static constexpr double kLevelThreeCargo =    650;
  static constexpr double kTop =                750;

  Elevator();
  void InitDefaultCommand() override;

  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;

  bool IsAtLowerLimit();
  double GetHeight();
  double GetSpeed();
  bool GetBrake();

  void SetLiftSpeed(double power);
  void EngageBrake(bool engage);

  frc::Encoder m_liftEncoder{3, 4, frc::Encoder::k1X};

 private:

  // Sensors for measuring the position of the pivot
  frc::DigitalInput m_limitSwitch1{0};
  frc::DigitalInput m_limitSwitch2{1};

  // Piston for brake caliper
  frc::Solenoid m_brake{4};

  // Motor to move the pivot
  frc::VictorSP m_liftMotorA{4};
  frc::VictorSP m_liftMotorB{5};
  frc::VictorSP m_liftMotorC{6};
  frc::VictorSP m_liftMotorD{7};

  frc::SpeedControllerGroup m_liftMotors{m_liftMotorA, m_liftMotorB, m_liftMotorC, m_liftMotorD};
  
};
