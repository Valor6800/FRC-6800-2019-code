/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorLowSetpoint.h"

#include "Robot.h"

ElevatorLowSetpoint::ElevatorLowSetpoint() {}

void ElevatorLowSetpoint::Initialize() {

    double height = Robot::m_elevator.GetHeight();

    if(height >= -100 && height < 220) {
        group = new ElevatorOneLowMacro();
        group->Start();
    } else if(height >= 220 && height < 330) {
        group = new ElevatorTwoLowMacro();
        group->Start();
    } else if(height >= 330 && height < 550) {
        group = new ElevatorThreeLowMacro();
        group->Start();
    } else if(height >= 550 && height < 1000) {
        group = new ElevatorFourLowMacro();
        group->Start();
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLowSetpoint::IsFinished() { return group->IsCompleted(); }