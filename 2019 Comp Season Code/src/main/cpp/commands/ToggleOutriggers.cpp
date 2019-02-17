/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleOutriggers.h"

#include "Robot.h"

ToggleOutriggers::ToggleOutriggers() {

}

void ToggleOutriggers::Initialize() {

    // IF we are in gShift
    if(Robot::m_oi.g_shift) 
        // Set the Outriggers to the opposite of what they are at now
        Robot::m_forks.SetOutriggers(!Robot::m_forks.GetOutriggerState());
}

// Called repeatedly when this Command is scheduled to run
void ToggleOutriggers::Execute() {
    
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleOutriggers::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void ToggleOutriggers::End() {}
