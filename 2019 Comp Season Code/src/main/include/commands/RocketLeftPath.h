/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include <pathfinder.h>
#include <pathfinder/trajectory.h>
#include <pathfinder-frc.h>
#include <pathfinder/followers/encoder.h>
#include <pathfinder/modifiers/tank.h>
#include <AHRS.h>
#include "../subsystems/Drivetrain.h"

/**
 * This command allows PS3 joystick to drive the robot. It is always running
 * except when interrupted by another command.
 */
class RocketLeftPath : public frc::Command {
 public:
  RocketLeftPath();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  double l;
  double r;

 private:
  // const int k_ticks_per_rev = 1024;
  // const int k_wheel_diameter = .1524; // 6 in wheels in meters
  // const int k_max_velocity = 10;

  // EncoderFollower leftFollower;
  // EncoderFollower rightFollower;

  TrajectoryCandidate candidate;

  EncoderConfig leftConfig;
  EncoderConfig rightConfig;

  EncoderFollower* leftFollower;
  EncoderFollower* rightFollower;

  Segment *leftTrajectory;
  Segment *rightTrajectory;
};
