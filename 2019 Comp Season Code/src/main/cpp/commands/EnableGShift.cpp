/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/EnableGShift.h"

#include "Robot.h"

EnableGShift::EnableGShift(bool enable) {
    Robot::m_oi.g_shift = enable; 
}

// Make this return true when this Command no longer needs to run execute()
bool EnableGShift::IsFinished() { return false; }

// Called once after isFinished returns true
void EnableGShift::End() { Robot::m_drivetrain.Stop(); }

