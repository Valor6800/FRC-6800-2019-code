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
    if(Robot::m_elevator.hasZeroed) {
        if(height >= -100 && height < 220) {
            if(Robot::m_oi.g_shift) {
                if(height < 80 && Robot::m_carriage.GetHatchScorer()) {
                    
                    group = new ElevatorZeroRocketCargoMacro();
                    group->Start();

                    // Robot::m_intake.SetWheelMotor(.5);
                } else if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorOneRocketCargo();
                    group->Start();
                    // Robot::m_intake.SetWheelMotor(-.5);

                } else {
                    group = new ElevatorOneRocketCargoIn();
                    group->Start();
                }
            } else {
                if(height < 80 && Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorZeroMedMacro();
                    group->Start(); 
                } else if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorOneMedMacro();
                    group->Start();
                } else {
                    group = new ElevatorOneMedInMacro();
                    group->Start();
                }
            }
        } else if(height >= 220 && height < 330) {
            if(Robot::m_oi.g_shift) {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorTwoRocketCargo();
                    group->Start();
                } else {
                    group = new ElevatorTwoRocketCargoIn();
                    group->Start();
                }
            } else {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorTwoMedMacro();
                    group->Start();
                } else {
                    group = new ElevatorTwoMedInMacro();
                    group->Start();
                }
            }
        } else if(height >= 330 && height < 550) {
            if(Robot::m_oi.g_shift) {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorThreeRocketCargo();
                    group->Start();
                } else {
                    group = new ElevatorThreeRocketCargoIn();
                    group->Start();
                }
            } else {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorThreeMedMacro();
                    group->Start();
                } else {
                    group = new ElevatorThreeMedInMacro();
                    group->Start();
                }
            }
        } else if(height >= 550 && height < 1000) {
            if(Robot::m_oi.g_shift) {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorFourRocketCargo();
                    group->Start();
                } else {
                    group = new ElevatorFourRocketCargoIn();
                    group->Start();
                }
            } else {
                if (Robot::m_carriage.GetHatchScorer()) {
                    group = new ElevatorFourMedMacro();
                    group->Start();
                } else {
                    group = new ElevatorFourMedInMacro();
                    group->Start();
                }
            }
        }
    }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorMedSetpoint::IsFinished() { return true; }