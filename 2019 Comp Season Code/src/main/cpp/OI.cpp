/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

OI::OI() {
  // Process operator interface input here.

  m_back.WhenPressed(new EnableGShift());
  bool intakeDown = true;

  // m_bumperR.WhenPressed(new ToggleOutriggers());
  m_bumperR.WhenPressed(new SetElevatorSetpointRelative(30));

  m_bumperL.WhenPressed(new SetIntakePivot());
  m_bumperL.WhenPressed(new SetHatch(true));
  m_bumperL.WhenReleased(new SetHatch(false));

  m_a.WhenPressed(new SetElevatorSetpointDefinite(Elevator::kBottom));
  m_x.WhenPressed(new SetElevatorSetpointDefinite(Elevator::kLevelOneCargo));
  // m_x.WhenPressed(new SetElevatorSetpoint(new ElevatorHatchMacro(Elevator::kLevelOneHatch), new ElevatorHatchMacro(Elevator::kLevelOneCargo)));
  m_b.WhenPressed(new SetElevatorSetpointDefinite(Elevator::kLevelTwoCargo));
  m_y.WhenPressed(new SetElevatorSetpointDefinite(Elevator::kLevelThreeCargo));
  // m_a.WhenPressed(new TestSolenoidProto());

  //pedal = new Button(3);

  One_One.WhenActive(new ElevatorOneOneMacro());
  One_Two.WhenActive(new ElevatorOneTwoMacro());
  One_Three.WhenActive(new ElevatorOneThreeMacro());
  Two_One.WhenActive(new ElevatorTwoOneMacro());
  Two_Three.WhenActive(new ElevatorTwoThreeMacro());
  Three_One.WhenActive(new ElevatorThreeOneMacro());
  Three_Two.WhenActive(new ElevatorThreeTwoMacro());
  Three_Three.WhenActive(new ElevatorThreeThreeMacro());

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