/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorCargoSetpoint.h"

#include "Robot.h"

ElevatorCargoSetpoint::ElevatorCargoSetpoint() { Requires(&Robot::m_elevator); Requires(&Robot::m_carriage);}

void ElevatorCargoSetpoint::Initialize() {

    double height = Robot::m_elevator.GetHeight();

    if(height >= -100 && height < 220) {
        group = new ElevatorOneCargoMacro();
        group->Start();
    } else if(height >= 220 && height < 330) {
        if(Robot::m_carriage.GetHatchScorer()) {
            group = new ElevatorTwoCargoMacro();
            group->Start();
        } else {
            group = new ElevatorTwoCargoInMacro();
            group->Start();
        }
    } else if(height >= 330 && height < 550) {
        if(Robot::m_carriage.GetHatchScorer()) {
            group = new ElevatorThreeCargoMacro();
            group->Start();
        } else {
            group = new ElevatorThreeCargoInMacro();
            group->Start();
        }
    } else if(height >= 550 && height < 1000) {
        if(Robot::m_carriage.GetHatchScorer()) {
            group = new ElevatorFourCargoMacro();
            group->Start();
        } else {
            group = new ElevatorFourCargoInMacro();
            group->Start();
        }
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorCargoSetpoint::IsFinished() { return true; }