/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/Forks.h>

Forks::Forks() : frc::Subsystem("Forks") {
    deployed = false;
    outriggersOut = false;
}

void Forks::InitDefaultCommand() {
    //SetDefaultCommand(new CarriageTeleop());
}
void Forks::Deploy(bool deploy) {
    forks.Set(deploy);
    outriggers.Set(deploy);            
}

void Forks::SetOutriggers(bool out) {
    outriggers.Set(out);    
}

bool Forks::GetForkState() {
    return forks.Get();
}

bool Forks::GetOutriggerState() {
    return outriggers.Get();
}