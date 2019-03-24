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

    // if(Robot::m_oi.g_shift || (Robot::m_elevator.GetHeight() < 80 && Robot::m_elevator.hasZeroed)) {
    //     toGo = Robot::m_carriage.GetHatchScorer();
    // } else {
    //     toGo = scorerToGo;
    // }
}

void SetHatch::Initialize() {
    // Set the carriage to go to the new (or old) location
    // toGo = (Robot::m_oi.g_shift || (Robot::m_elevator.GetHeight() < 80 && Robot::m_elevator.hasZeroed)) ? Robot::m_carriage.GetHatchScorer() : !Robot::m_carriage.GetHatchScorer();
    // if(!(Robot::m_elevator.GetHeight() < 80 && Robot::m_elevator.hasZeroed)) {
    //     Robot::m_carriage.scorerToGo = toGo;
    // }

    Robot::m_carriage.scorerToGo = toGo;
}

// Make this return true when this Command no longer needs to run execute()
bool SetHatch::IsFinished() { 
    // Return true when the hatchScorer is actually where it is supposed to be
    return true; 
}


