/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Solenoid.h>
#include <frc/VictorSP.h>
#include <frc/DigitalInput.h>
#include "../commands/DeployForklift.h"

class Forks : public frc::Subsystem
{
public:
  Forks();

  void InitDefaultCommand();
  void SetForks(double power);
  void SetOutriggers(bool out);
  bool GetForkState();
  bool GetOutriggerState();

  bool outriggersOut;

private:
    frc::Solenoid m_outriggers{4};
    frc::VictorSP m_forks{7};
    frc::DigitalInput m_forksDeployed{3};
};
