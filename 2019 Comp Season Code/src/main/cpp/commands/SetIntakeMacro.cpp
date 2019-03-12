/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetIntakeMacro.h"

#include "Robot.h"

SetIntakeMacro::SetIntakeMacro(bool intakeToGo) {
    toGo = intakeToGo;
}

void SetIntakeMacro::Initialize() {
    // Set the carriage to go to the new (or old) location
    Robot::m_intake.SetPivot(toGo);
}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakeMacro::IsFinished() { 
    // Return true when the hatchScorer is actually where it is supposed to be
    return Robot::m_intake.GetPivot() == toGo; 
}


