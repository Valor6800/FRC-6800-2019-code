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
  m_bumperR.WhenPressed(new SetElevatorSetpointRelative(20));

  m_bumperL.WhenPressed(new SetIntakePivot());
  m_bumperL.WhenPressed(new SetHatch(true));
  m_bumperL.WhenReleased(new SetHatch(false));

  // m_a.WhenPressed(new SetElevatorSetpointDefinite(160));

  // m_a.WhenPressed(new ElevatorHighSetpoint());
  m_x.WhenPressed(new ElevatorLowSetpoint());
  // m_x.WhenPressed(new SetElevatorSetpoint(new ElevatorHatchMacro(Elevator::kLevelOneHatch), new ElevatorHatchMacro(Elevator::kLevelOneCargo)));
  m_b.WhenPressed(new ElevatorMedSetpoint());
  m_y.WhenPressed(new ElevatorHighSetpoint());
  m_a.WhenPressed(new ElevatorCargoSetpoint());
  // m_a.WhenPressed(new TestSolenoidProto());

  //pedal = new Button(3);

  // ============== NOTE =====================
  // If you are uncommenting these thhen comment out the code right above this, and vice versa

  // One_Low.WhenActive(new ElevatorOneLowMacro());
  // One_Med.WhenActive(new ElevatorOneMedMacro());
  // One_High.WhenActive(new ElevatorOneHighMacro());
  // Two_Low.WhenActive(new ElevatorTwoLowMacro());
  // Two_Med.WhenActive(new ElevatorTwoMedMacro());
  // Two_High.WhenActive(new ElevatorTwoHighMacro());
  // Three_Low.WhenActive(new ElevatorThreeLowMacro());
  // Three_Med.WhenActive(new ElevatorThreeMedMacro());
  // Three_High.WhenActive(new ElevatorThreeHighMacro());
  // Four_Low.WhenActive(new ElevatorFourLowMacro());
  // Four_Med.WhenActive(new ElevatorFourMedMacro());
  // Four_High.WhenActive(new ElevatorFourHighMacro());
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