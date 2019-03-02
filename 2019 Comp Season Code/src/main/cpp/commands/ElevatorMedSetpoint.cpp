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
        ElevatorOneMedMacro oneMed;
        oneMed.Start();
    } else if(height >= 220 && height < 330) {
        ElevatorTwoMedMacro twoMed;
        twoMed.Start();
    } else if(height >= 330 && height < 550) {
        ElevatorThreeMedMacro threeMed;
        threeMed.Start();
    } else if(height >= 550 && height < 1000) {
        ElevatorFourMedMacro fourMed;
        fourMed.Start();
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMedSetpoint::IsFinished() { return true; }