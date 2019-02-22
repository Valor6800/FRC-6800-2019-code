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
  void SetHatchPreparer(bool prepare);

  bool IsPhotoelectric();
  bool GetHatchScorer();
  bool GetHatchPreparer();

  double GetMotorL();
  double GetMotorR();

  bool photoelectricActivated = false;
  bool preparerToGo;

private:
  frc::VictorSP m_leftMotor{1};
  frc::VictorSP m_rightMotor{2};
  
  frc::Solenoid m_hatchPreparer{2};
  frc::Solenoid m_hatchScorer{1};
  frc::DigitalInput m_photoelectric{2};

};
