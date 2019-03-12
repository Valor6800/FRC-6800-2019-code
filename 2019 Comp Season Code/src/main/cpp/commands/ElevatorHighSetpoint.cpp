/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorHighSetpoint.h"

#include "Robot.h"

ElevatorHighSetpoint::ElevatorHighSetpoint() { Requires(&Robot::m_elevator); Requires(&Robot::m_carriage);}

void ElevatorHighSetpoint::Initialize() {

    double height = Robot::m_elevator.GetHeight();

    if(height >= -100 && height < 220) {
        group = new ElevatorOneHighMacro();
        group->Start();
    } else if(height >= 220 && height < 330) {
        group = new ElevatorTwoHighMacro();
        group->Start();
    } else if(height >= 330 && height < 550) {
        group = new ElevatorThreeHighMacro();
        group->Start();
    } else if(height >= 550 && height < 1000) {
        group = new ElevatorFourHighMacro();
        group->Start();
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorHighSetpoint::IsFinished() { return true; }