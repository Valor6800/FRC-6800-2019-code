/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

class SetIntake : public frc::Command {
 public:
  explicit SetElevatorSetpoint(double setpoint);
  void Initialize() override;
  bool IsFinished() override;
  void Interrupted() override;

 private:
  double m_setpoint;
};
