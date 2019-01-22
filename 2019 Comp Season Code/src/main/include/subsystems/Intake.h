/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/VictorSP.h>
#include <frc/commands/Subsystem.h>
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>

class Intake : public frc::Subsystem {
public:
  Intake();

  void InitDefaultCommand();
  void SetWheelMotor(double val);
  void SetPivot(bool pos);
  void Stop();

  double GetWheelMotor();
  bool m_pivotDown;
  
  frc::Solenoid m_pivotSolenoid {0};

private:
    frc::VictorSP m_wheelMotor {10};
 //check port number
};
