/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TestSolenoidProto.h"

#include "Robot.h"

TestSolenoidProto::TestSolenoidProto() {}

void TestSolenoidProto::Initialize() {
   Robot::m_drivetrain.prototypeDeployed = !Robot::m_drivetrain.prototypeDeployed;
}

// Called repeatedly when this Command is scheduled to run
void TestSolenoidProto::Execute() {
    Robot::m_drivetrain.SetPrototype(Robot::m_drivetrain.prototypeDeployed);
}

// Make this return true when this Command no longer needs to run execute()
bool TestSolenoidProto::IsFinished() {}

// Called once after isFinished returns true
void TestSolenoidProto::End() {}
