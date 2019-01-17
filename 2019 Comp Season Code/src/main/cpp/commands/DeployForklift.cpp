/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DeployForklift.h"

#include "Robot.h"

DeployForklift::DeployForklift(bool deployed) { Requires(&Robot::m_forks); }

void DeployForklift::Initialize() {
    Robot::m_forks.deployed = !Robot::m_forks.deployed;
}

// Called repeatedly when this Command is scheduled to run
void DeployForklift::Execute() {
    Robot::m_forks.deployed ? Robot::m_forks.Deploy() : Robot::m_forks.DisengageOutriggers();
}

// Make this return true when this Command no longer needs to run execute()
bool DeployForklift::IsFinished() { return (Robot::m_forks.GetForkState() && Robot::m_forks.GetOutriggerState()); }

// Called once after isFinished returns true
void DeployForklift::End() { Robot::m_drivetrain.Stop(); }
