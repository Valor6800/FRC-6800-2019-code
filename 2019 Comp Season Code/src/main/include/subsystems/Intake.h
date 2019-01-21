/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/VictorSP.h>
#include <frc/commands/PIDSubsystem.h>
#include <frc/Encoder.h>
#include <frc/DigitalInput.h>
#include <frc/Solenoid.h>

class Intake : public frc::PIDSubsystem {
public:
  Intake();

  void InitDefaultCommand();
  void SetWheelMotor(double val);
  void SetPivot(bool pos);
  void Stop();

  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;

  bool TogglePivot();
  bool GetPivotState();

  double GetWheelMotor();

  frc::Encoder& GetIntakeEncoder();
  frc::Encoder& GetPivotEncoder();

private:
    frc::VictorSP m_wheelMotor {10};
    frc::VictorSP m_pivotMotor {11};


    frc::Solenoid m_pivotSolenoid {0}; //check port number
    frc::Encoder m_intakeEncoder {6, 7, frc::Encoder::k1X};
    bool m_pivotDown;
};
