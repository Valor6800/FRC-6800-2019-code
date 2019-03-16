/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DigitalInput.h>
#include <frc/VictorSP.h>
#include <frc/commands/Subsystem.h>
#include <frc/Solenoid.h>
#include "../commands/AutoPrepareHatch.h"

class Carriage : public frc::Subsystem
{
public:
  Carriage();

  void InitDefaultCommand();
  void SetMotors(double val);
  void SetMotors(double leftVal, double rightVal);
  void Stop();
  void SetHatchScorer(bool score);
  void SetHatchHolder(bool prepare);

  bool IsPhotoelectric();
  bool GetHatchScorer();
  bool GetHatchHolder();

  double GetMotorL();
  double GetMotorR();

  bool photoelectricActivated = false;

  bool holderToGo;

private:
  frc::VictorSP m_leftMotor{2};
  frc::VictorSP m_rightMotor{3};
  
  frc::Solenoid m_hatchHolder{2};
  frc::Solenoid m_hatchScorer{1};
  frc::DigitalInput m_photoelectric{2};

};
