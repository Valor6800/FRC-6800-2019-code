/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/ConditionalCommand.h>

/**
 * Moves the  Elevator to a given height. This command finishes when it is within
 * the tolerance, but leaves the PID loop running to maintain the position.
 * Other commands using the Elevator should make sure they disable PID!
 */
class SetElevatorSetpoint : public frc::ConditionalCommand {
 public:
  SetElevatorSetpoint(Command* hatchCommand, Command* cargoCommand);
  void Initialize() override;
  bool IsFinished() override;
  void Interrupted() override;
  bool Condition() override;

 private:
  double m_setpoint;
};
