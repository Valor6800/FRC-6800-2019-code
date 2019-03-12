/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorMedSetpoint.h"

#include "Robot.h"

ElevatorMedSetpoint::ElevatorMedSetpoint() { Requires(&Robot::m_elevator); Requires(&Robot::m_carriage);}

void ElevatorMedSetpoint::Initialize() {

    double height = Robot::m_elevator.GetHeight();

    if(height >= -100 && height < 220) {
        if(Robot::m_oi.g_shift) {
            group = new ElevatorOneRocketCargo();
            group->Start();
        } else {
            group = new ElevatorOneMedMacro();
            group->Start();
        }
    } else if(height >= 220 && height < 330) {
        if(Robot::m_oi.g_shift) {
            group = new ElevatorTwoRocketCargo();
            group->Start();
        } else {
            group = new ElevatorTwoMedMacro();
            group->Start();
        }
    } else if(height >= 330 && height < 550) {
        if(Robot::m_oi.g_shift) {
            group = new ElevatorThreeRocketCargo();
            group->Start();
        } else {
            group = new ElevatorThreeMedMacro();
            group->Start();
        }
    } else if(height >= 550 && height < 1000) {
        if(Robot::m_oi.g_shift) {
            group = new ElevatorFourRocketCargo();
            group->Start();
        } else {
            group = new ElevatorFourMedMacro();
            group->Start();
        }
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMedSetpoint::IsFinished() { return true; }