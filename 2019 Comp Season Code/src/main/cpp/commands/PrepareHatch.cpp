/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrepareHatch.h"

#include "Robot.h"

PrepareHatch::PrepareHatch() {}

void PrepareHatch::Initialize() {

    // Toggle the preparer solenoid
    Robot::m_carriage.preparerToGo = !Robot::m_carriage.preparerToGo;
}

// Make this return true when this Command no longer needs to run execute()
bool PrepareHatch::IsFinished() { 

    // Return the command is finished if the hatch state is actually where it should be
    return Robot::m_carriage.GetHatchPreparer() == Robot::m_carriage.preparerToGo; 
}


