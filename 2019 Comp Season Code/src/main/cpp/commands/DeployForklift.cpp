/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DeployForklift.h"

#include "Robot.h"

DeployForklift::DeployForklift() { Requires(&Robot::m_forks); }

void DeployForklift::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DeployForklift::Execute() {

    Robot::m_oi.g_shift 
        ? Robot::m_forks.GetForkState()
            ? Robot::m_forks.SetForks((Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) > .05) ? Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) : 0.0)
            : Robot::m_forks.SetForks(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand))
        : Robot::m_forks.SetForks(0.0);
    // Robot::m_forks ? Robot::m_forks.Deploy(true) : Robot::m_forks.Deploy(false);
}

// Make this return true when this Command no longer needs to run execute()
bool DeployForklift::IsFinished() { return (Robot::m_forks.GetForkState() && Robot::m_forks.GetOutriggerState()); }

// Called once after isFinished returns true
void DeployForklift::End() {}
