/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorLowSetpoint.h"

#include "Robot.h"

ElevatorLowSetpoint::ElevatorLowSetpoint() { Requires(&Robot::m_elevator); Requires(&Robot::m_carriage);}

void ElevatorLowSetpoint::Initialize() {

    double height = Robot::m_elevator.GetHeight();

    if(height >= -100 && height < 220) {
        ElevatorOneLowMacro oneLow;
        oneLow.Start();
    } else if(height >= 220 && height < 330) {
        ElevatorTwoLowMacro twoLow;
        twoLow.Start();
    } else if(height >= 330 && height < 550) {
        ElevatorThreeLowMacro threeLow;
        threeLow.Start();
    } else if(height >= 550 && height < 1000) {
        ElevatorFourLowMacro fourLow;
        fourLow.Start();
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLowSetpoint::IsFinished() { return true; }