/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/Forks.h>

Forks::Forks() : frc::Subsystem("Forks") {}

void Forks::InitDefaultCommand() {
    //SetDefaultCommand(new CarriageTeleop());
}

void Forks::SetForks(double power) {
    m_forks.Set(power);
}

void Forks::SetOutriggers(bool out) {
    m_outriggers.Set(out);    
}

bool Forks::GetForkState() {
    return (m_forksDeployed.Get());
}

bool Forks::GetOutriggerState() {
    return m_outriggers.Get();
}