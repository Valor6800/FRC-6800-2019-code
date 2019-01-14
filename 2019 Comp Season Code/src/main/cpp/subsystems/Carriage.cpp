/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <subsystems/Carriage.h>

Carriage::Carriage() : frc::Subsystem("Carriage") {
}

void Carriage::InitDefaultCommand() {
    //SetDefaultCommand(new CarriageTeleop());
}
void Carriage::SetMotors(double val) {
    m_leftMotor.Set(val);
    m_rightMotor.Set(val);
}

void Carriage::SetMotors(double leftVal, double rightVal) {
    m_leftMotor.Set(leftVal);
    m_rightMotor.Set(rightVal);
}

void Carriage::Stop() {
    m_leftMotor.Set(0);
    m_rightMotor.Set(0);
}