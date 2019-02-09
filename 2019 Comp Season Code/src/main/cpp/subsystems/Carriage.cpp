/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/Carriage.h>

Carriage::Carriage() : frc::Subsystem("Carriage") {
    
}

void Carriage::InitDefaultCommand() {
    SetDefaultCommand(new AutoPrepareHatch());
}
void Carriage::SetMotors(double val) {
    m_leftMotor.Set(val);
    m_rightMotor.Set(val);
}

void Carriage::SetMotors(double leftVal, double rightVal) {
    m_leftMotor.Set(leftVal);
    m_rightMotor.Set(rightVal);
}

double Carriage::GetMotorL() {
    return m_leftMotor.Get();
}

double Carriage::GetMotorR() {
    return m_rightMotor.Get();
}

void Carriage::Stop() {
    m_leftMotor.Set(0);
    m_rightMotor.Set(0);
}

bool Carriage::IsPhotoelectric() {
    return false; // NOTE: Change this back later
//   return m_photoelectric.Get();
}

bool Carriage::GetHatchScorer() {
    return m_hatchScorer.Get();
}

bool Carriage::GetHatchPreparer() {
    return m_hatchPreparer.Get();
}

void Carriage::SetHatchScorer(bool score) {
    m_hatchScorer.Set(score);
}

void Carriage::SetHatchPreparer(bool prepare) {
    m_hatchPreparer.Set(prepare);
}