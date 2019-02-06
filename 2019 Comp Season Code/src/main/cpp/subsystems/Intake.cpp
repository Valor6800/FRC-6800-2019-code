/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() : frc::Subsystem("Intake") {
    m_pivotDown = true;
}

void Intake::InitDefaultCommand() {
    SetDefaultCommand(new SpinIntakeMotors());
}

void Intake::SetWheelMotor(double val) {
    m_wheelMotor.Set(val);
}


void Intake::SetPivot(bool pos) {
    m_pivotSolenoid.Set(pos);
}

void Intake::Stop() {
    m_wheelMotor.Set(0);
}

double Intake::GetWheelMotor() {
    return m_wheelMotor.Get();
}