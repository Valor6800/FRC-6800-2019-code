/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ToggleOutriggers.h"

#include "Robot.h"

ToggleOutriggers::ToggleOutriggers() { Requires(&Robot::m_forks); }

void ToggleOutriggers::Initialize() {
    Robot::m_forks.outriggersOut = !Robot::m_forks.outriggersOut;
    
}

// Called repeatedly when this Command is scheduled to run
void ToggleOutriggers::Execute() {

    Robot::m_forks.outriggersOut ? Robot::m_forks.SetOutriggers(true) : Robot::m_forks.SetOutriggers(false);
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleOutriggers::IsFinished() { return (Robot::m_forks.GetForkState() && Robot::m_forks.GetOutriggerState()); }

// Called once after isFinished returns true
void ToggleOutriggers::End() {}
