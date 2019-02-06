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

class Carriage : public frc::Subsystem
{
public:
  Carriage();

  void InitDefaultCommand();
  void SetMotors(double val);
  void SetMotors(double leftVal, double rightVal);
  void Stop();
  void SetHatchPusher(bool pivot);
  void SetFlipper(bool flip);

  bool IsPhotoelectric();

  double GetMotorL();
  double GetMotorR();

  bool photoelectricActivated = false;
  bool photoelectricTriggeredOnce = false;


private:
  frc::VictorSP m_leftMotor{8};
  frc::VictorSP m_rightMotor{9};
  frc::Solenoid hatchPusher{5};
  frc::DigitalInput m_photoelectric{10}; // TODO: Get port here

};
