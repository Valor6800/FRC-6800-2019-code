/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <subsystems/Forks.h>

Forks::Forks() : frc::Subsystem("Forks") {
}

void Forks::InitDefaultCommand() {
    //SetDefaultCommand(new CarriageTeleop());
}
void Forks::Deploy() {
    forks.Set(true);
    outriggers.Set(true);            
}

void Forks::DisengageOutriggers() {
    outriggers.Set(false);    
}

bool Forks::GetForkState() {
    return forks.Get();
}

bool Forks::GetOutriggerState() {
    return outriggers.Get();
}