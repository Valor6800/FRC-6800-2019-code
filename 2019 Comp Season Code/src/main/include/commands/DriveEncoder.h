/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include <cmath>

/**
 * This command allows PS3 joystick to drive the robot. It is always running
 * except when interrupted by another command.
 */
class DriveEncoder : public frc::Command {
 public:
  DriveEncoder(double distance, double speed);
  DriveEncoder(double distance, double angle, double speed);
  void Execute() override;
  bool IsFinished() override;
  void End() override;

  double turn, angError, currDist, targetHeading, currHeading, power, targetDist;
  int direction;
};
