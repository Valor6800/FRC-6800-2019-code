/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() : frc::PIDSubsystem("Intake", 7.0, 0.0, 8.0) {
    m_pivotDown = false;
    SetAbsoluteTolerance(0.01);
    GetPIDController()->SetContinuous(false);
}

void Intake::InitDefaultCommand() {
    //SetDefaultCommand(new IntakeTeleop());
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


frc::Encoder& Intake::GetIntakeEncoder() {
    return m_intakeEncoder;
}


double Intake::ReturnPIDInput() { return m_intakeEncoder.Get(); }


void Intake::UsePIDOutput(double output) { m_pivotMotor.PIDWrite(output); }

bool Intake::TogglePivot() {
    m_pivotDown = !m_pivotDown;
    return m_pivotDown;
}

bool Intake::GetPivotState() {
    return m_pivotSolenoid.Get();
}

double Intake::GetWheelMotor() {
    return m_wheelMotor.Get();
}