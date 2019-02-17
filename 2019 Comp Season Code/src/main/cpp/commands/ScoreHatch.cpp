/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ScoreHatch.h"

#include "Robot.h"

ScoreHatch::ScoreHatch() {}

void ScoreHatch::Initialize() {

    // IF g_shift, DO set scorerToGo where we already are, ELSE set scorerToGo to toggle
    Robot::m_oi.g_shift ? scorerToGo = Robot::m_carriage.GetHatchScorer() : scorerToGo = !Robot::m_carriage.GetHatchScorer();

    // Set the carriage to go to the new (or old) location
    Robot::m_carriage.SetHatchScorer(scorerToGo);
}

// Make this return true when this Command no longer needs to run execute()
bool ScoreHatch::IsFinished() { 
    // Return true when the hatchScorer is actually where it is supposed to be
    return Robot::m_carriage.GetHatchScorer() == scorerToGo; 
}


