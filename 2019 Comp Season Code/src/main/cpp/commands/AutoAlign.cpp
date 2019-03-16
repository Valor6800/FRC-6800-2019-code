/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoAlign.h"

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

AutoAlign::AutoAlign() {Requires(&Robot::m_drivetrain);}

void AutoAlign::Initialize() {
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
  table->PutNumber("ledMode",3);
}

void AutoAlign::Execute() {

        Robot::m_drivetrain.UpdateLimelightTracking();

        if (Robot::m_drivetrain.m_LimelightHasTarget)
        {
          // Robot::m_drivetrain.m_LimelightDriveCmd
          Robot::m_drivetrain.m_robotDrive.ArcadeDrive(-Robot::m_drivetrain.m_LimelightDriveCmd, -Robot::m_drivetrain.m_LimelightTurnCmd);
        }
        else
        {
          Robot::m_drivetrain.m_robotDrive.ArcadeDrive(0.0,0.0);
        }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAlign::IsFinished() { return Robot::m_drivetrain.m_LimelightDriveCmd < 0; }

void AutoAlign::End() {
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    table->PutNumber("ledMode",1);
}


