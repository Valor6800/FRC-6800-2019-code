/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetHatch.h"

#include "Robot.h"

SetHatch::SetHatch(bool scorerToGo) {
    toGo = scorerToGo;
}

void SetHatch::Initialize() {
    // Set the carriage to go to the new (or old) location
    Robot::m_carriage.SetHatchScorer(toGo);
}

// Make this return true when this Command no longer needs to run execute()
bool SetHatch::IsFinished() { 
    // Return true when the hatchScorer is actually where it is supposed to be
    return Robot::m_carriage.GetHatchScorer() == toGo; 
}


