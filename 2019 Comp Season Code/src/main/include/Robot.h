/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <thread>

#include <frc/WPILib.h>
#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/shuffleboard/BuiltInWidgets.h>
#include <frc/shuffleboard/WidgetType.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTableEntry.h>

#include "OI.h"
#include "subsystems/Carriage.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Elevator.h"
#include "subsystems/Intake.h"
#include "subsystems/Pneumatics.h"
#include "subsystems/Forks.h"
// #include "commands/RocketLeftPath.h"

class Robot : public frc::TimedRobot {
 public:

  static Drivetrain m_drivetrain;
  static Carriage m_carriage;
  static Elevator m_elevator;
  static Intake m_intake;
  static OI m_oi;
  static Pneumatics m_pneumatics;
  static Forks m_forks;

 private:
  frc::Command* m_autonomousCommand = nullptr;
  //DriveAndShootAutonomous m_driveAndShootAuto;
  //DriveForward m_driveForwardAuto;
  // RocketLeftPath m_pathfinder;
  frc::SendableChooser<frc::Command*> m_autoChooser;

  void RobotInit() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;

  void Log();
};
