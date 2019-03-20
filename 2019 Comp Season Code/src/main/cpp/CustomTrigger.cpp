/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CustomTrigger.h"
#include "Robot.h"

CustomTrigger::CustomTrigger() {}

bool CustomTrigger::Get() {

  return Robot::m_oi.GetLeftJoyDrive().GetX() < -.7; 

}


