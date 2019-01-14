/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/PWMVictorSPX.h>
#include <frc/commands/Subsystem.h>

class Carriage : public frc::Subsystem
{
public:
  Carriage();

  void InitDefaultCommand();
  void SetMotors(double val);
  void SetMotors(double leftVal, double rightVal);
  void Stop();

private:
    frc::PWMVictorSPX m_leftMotor{8};
    frc::PWMVictorSPX m_rightMotor{9};
};
