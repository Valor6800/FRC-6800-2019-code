/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoPrepareHatch.h"

#include "Robot.h"

AutoPrepareHatch::AutoPrepareHatch() {Requires(&Robot::m_carriage);}

void AutoPrepareHatch::Initialize() {}

void AutoPrepareHatch::Execute() {

    // TODO: Get real values for the encoders, these are roughly on the scale 0 to 1

    // If by the crossbar OR Neil says go out OR the lift is moving
    if((Robot::m_elevator.GetHeight() > .4 && Robot::m_elevator.GetHeight() < .6) || Robot::m_carriage.preparerToGo || Robot::m_elevator.GetSpeed() > .1) {

        // If we are at the bottom, stay out
        if(Robot::m_elevator.GetHeight() < .1) {
            Robot::m_carriage.SetHatchPreparer(true);
        
        // Otherwise, go in 
        } else {
            
            Robot::m_carriage.SetHatchPreparer(false);
        }

    // Otherwise, go out
    } else {
        Robot::m_carriage.SetHatchPreparer(true);
    }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoPrepareHatch::IsFinished() { return false; }


