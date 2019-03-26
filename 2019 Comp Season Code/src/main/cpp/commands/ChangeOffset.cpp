/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ChangeOffset.h"

#include "Robot.h"

ChangeOffset::ChangeOffset(double add) {
    toAdd = add;
}

void ChangeOffset::Initialize() {

    // Set the g_shift to the same state as the back button, permanently running
    Robot::m_drivetrain.AddOffset(toAdd);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeOffset::IsFinished() { return true; }


