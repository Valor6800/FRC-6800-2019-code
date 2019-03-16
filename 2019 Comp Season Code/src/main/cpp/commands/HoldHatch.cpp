/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoldHatch.h"

#include "Robot.h"

HoldHatch::HoldHatch(bool scorerToGo) {
    toGo = scorerToGo;
}

void HoldHatch::Initialize() {
    Robot::m_carriage.holderToGo = toGo;
}

// Make this return true when this Command no longer needs to run execute()
bool HoldHatch::IsFinished() { 
    // Return true when the hatchScorer is actually where it is supposed to be
    return true; 
}


