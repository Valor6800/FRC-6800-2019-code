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
    Robot::m_oi.g_shift ? scorerToGo = Robot::m_carriage.GetHatchScorer() : scorerToGo = !Robot::m_carriage.GetHatchScorer();
    Robot::m_carriage.SetHatchScorer(scorerToGo);
}

// Make this return true when this Command no longer needs to run execute()
bool ScoreHatch::IsFinished() { return Robot::m_carriage.GetHatchScorer() == scorerToGo; }


