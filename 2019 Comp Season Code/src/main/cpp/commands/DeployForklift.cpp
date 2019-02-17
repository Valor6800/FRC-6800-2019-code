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

    // If gShift
    if (Robot::m_oi.g_shift)
    {
        // If the forks are deployed
        if (Robot::m_forks.GetForkState())
            // If positive and out of deadband, DO set positive power to forks through right stick, OTHERWISE set fork power to 0
            Robot::m_forks.SetForks((Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) > .05) ? Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) : 0.0);
        // Otherwise, 
        else
            // If out of deadband, DO set power to forks through right stick, OTHERWISE set fork power to 0
            Robot::m_forks.SetForks((std::abs(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand)) > 0.05) ? Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) : 0.0);
    }
    // Otherwise
    else
        // Stop the forks from moving
        Robot::m_forks.SetForks(0.0);

    // Robot::m_oi.g_shift 
    //     ? Robot::m_forks.GetForkState()
    //         ? Robot::m_forks.SetForks((Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) > .05) ? Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand) : 0.0)
    //         : Robot::m_forks.SetForks(Robot::m_oi.GetGamepad().GetY(frc::GenericHID::JoystickHand::kRightHand))
    //     : Robot::m_forks.SetForks(0.0);
    // Robot::m_forks ? Robot::m_forks.Deploy(true) : Robot::m_forks.Deploy(false);
}

// Make this return true when this Command no longer needs to run execute()
bool DeployForklift::IsFinished() { return false; }

// Called once after isFinished returns true
void DeployForklift::End() {}
