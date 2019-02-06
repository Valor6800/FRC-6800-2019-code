/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() {
  // Process operator interface input here.

  //m_bumperR.ToggleWhenPressed(new SetIntakePivot());

  m_back.WhenPressed(new EnableGShift(true));
  m_back.WhenReleased(new EnableGShift(false));

  if (g_shift) {
    m_bumperR.WhenPressed(new ToggleOutriggers());
    // m_bumperR.WhenPressed(new SpinIntakeMotors());
    m_bumperL.WhenPressed(new SetIntakePivot(false));
  } else {
    m_bumperR.WhenPressed(new DeployForklift());
    // m_bumperR.WhenPressed(new SpinIntakeMotors());
    m_bumperL.WhenPressed(new SetIntakePivot(true));
  }



  

  m_a.WhenPressed(new SetElevatorSetpointDefinite(Elevator::kBottom));
  m_b.WhenPressed(new SetElevatorSetpoint(new SetElevatorSetpointDefinite(Elevator::kLevelOneHatch), new SetElevatorSetpointDefinite(Elevator::kLevelOneCargo)));
  m_x.WhenPressed(new SetElevatorSetpoint(new SetElevatorSetpointDefinite(Elevator::kLevelTwoHatch), new SetElevatorSetpointDefinite(Elevator::kLevelTwoCargo)));
  m_y.WhenPressed(new SetElevatorSetpoint(new SetElevatorSetpointDefinite(Elevator::kLevelThreeHatch), new SetElevatorSetpointDefinite(Elevator::kLevelThreeCargo)));

  // m_a.WhenPressed(new TestSolenoidProto());

  //pedal = new Button(3);
}

frc::Joystick& OI::GetLeftJoyDrive() {
  return m_leftJoyDrive;
}

frc::Joystick& OI::GetRightJoyDrive() {
  return m_rightJoyDrive;
}

frc::XboxController& OI::GetGamepad() {
  return m_gamepad;
}

frc::JoystickButton& OI::GetShifter() {
  return shifter;
}