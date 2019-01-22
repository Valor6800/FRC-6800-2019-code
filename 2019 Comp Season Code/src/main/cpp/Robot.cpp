/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <frc/commands/Scheduler.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

Carriage Robot::m_carriage;
Drivetrain Robot::m_drivetrain;
Elevator Robot::m_elevator;
Intake Robot::m_intake;
Pneumatics Robot::m_pneumatics;
Forks Robot::m_forks;
OI Robot::m_oi;
frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("LiveWindow");

nt::NetworkTableEntry countEntry;
nt::NetworkTableEntry count2Entry;

nt::NetworkTableEntry elevatorHeightEntry;
nt::NetworkTableEntry elevatorUpperLimitEntry;
nt::NetworkTableEntry elevatorLowerLimitEntry;
nt::NetworkTableEntry elevatorSpeedEntry;

nt::NetworkTableEntry intakeAngleEntry;
nt::NetworkTableEntry intakeWheelEntry;

nt::NetworkTableEntry carriageWheelLEntry;
nt::NetworkTableEntry carriageWheelREntry;

nt::NetworkTableEntry driveMotorLeftAEntry;
nt::NetworkTableEntry driveMotorLeftBEntry;
nt::NetworkTableEntry driveMotorRightAEntry;
nt::NetworkTableEntry driveMotorRightBEntry;
nt::NetworkTableEntry shifterEntry;

nt::NetworkTableEntry forkStateEntry;
nt::NetworkTableEntry outriggerStateEntry;

double count;
double count2;


void Robot::RobotInit() {
  
  //countEntry = tab.Add("count_", 0).withWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  //count2Entry = tab.Add("count2", 100).GetEntry();
  elevatorHeightEntry = tab.Add("Elevator Height", 0).withWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  elevatorLowerLimitEntry = tab.Add("Elevator Lower Limit", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  elevatorUpperLimitEntry = tab.Add("Elevator Upper Limit", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  elevatorSpeedEntry = tab.Add("Elevator Speed", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();

  intakeAngleEntry = tab.Add("Intake Angle", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  intakeWheelEntry = tab.Add("Intake Wheel", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
 
  carriageWheelLEntry = tab.Add("Carriage Wheel L", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  carriageWheelREntry = tab.Add("Carriage Wheel R", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  
  driveMotorLeftAEntry = tab.Add("Drive Motor Left A", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  driveMotorLeftBEntry = tab.Add("Drive Motor Left B", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  driveMotorRightAEntry = tab.Add("Drive Motor Right A", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  driveMotorRightBEntry = tab.Add("Drive Motor Right B", 0).withWidget(frc::BuiltInWidgets::kDial).GetEntry();
  shifterEntry = tab.Add("Shifter Entry", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();

  forkStateEntry = tab.Add("Fork State", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  outriggerStateEntry = tab.Add("Outrigger State", false).withWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();



  // instantiate the command used for the autonomous period
  // m_autoChooser.SetDefaultOption("Drive and Shoot", &m_driveAndShootAuto);
  // m_autoChooser.AddOption("Drive Forward", &m_driveForwardAuto);
  // const frc::BuiltInWidgets::kNumberSlider slider = frc::BuiltInWidgets::kNumberSlider;
  frc::SmartDashboard::PutData("Auto Mode", &m_autoChooser);
    // pneumatics.Start();  // Pressurize the pneumatics.
}

void Robot::AutonomousInit() {
  m_autonomousCommand = m_autoChooser.GetSelected();
  m_autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  Log();
}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
  }
  // std::cout << "Starting Teleop" << std::endl;
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  Log();
}

void Robot::TestPeriodic() { Log(); }

void Robot::DisabledInit(){
  
}

void Robot::DisabledPeriodic() { Log(); }

/** 
 * Log interesting values to the SmartDashboard.
 */
void Robot::Log() {
  // Robot::pneumatics.WritePressure();
  // frc::SmartDashboard::PutNumber("Pivot Pot Value", pivot.GetAngle());
  // frc::SmartDashboard::PutNumber("Left Distance", m_drivetrain.GetLeftEncoder().GetDistance());
  // frc::SmartDashboard::PutNumber("Right Distance", m_drivetrain.GetRightEncoder().GetDistance());
 
  //frc::SmartDashboard::PutNumber("Elevator Height", m_elevator.GetHeight());
  //frc::SmartDashboard::PutNumber("Differential Drive", m_drivetrain.m_driveMotorLeftA.Get());
  //frc::SmartDashboard::PutNumber("Differential Drive", m_drivetrain.m_driveMotorRightA.Get());
  
  //count += .0001;
  //count2 += 1;
  //countEntry.SetDouble(count); // shooter.Unlatch(); 
  //count2Entry.SetDouble(count2);

  elevatorHeightEntry.SetDouble(m_elevator.GetHeight());
  elevatorLowerLimitEntry.SetBoolean(m_elevator.IsAtLowerLimit());
  elevatorUpperLimitEntry.SetBoolean(m_elevator.IsAtUpperLimit());
  elevatorSpeedEntry.SetDouble(m_elevator.GetSpeed());

  intakeWheelEntry.SetDouble(m_intake.GetWheelMotor());

  carriageWheelLEntry.SetDouble(m_carriage.GetMotorL());
  carriageWheelREntry.SetDouble(m_carriage.GetMotorR());

  driveMotorLeftAEntry.SetDouble(m_drivetrain.GetMotorLeftA());
  driveMotorLeftBEntry.SetDouble(m_drivetrain.GetMotorLeftB());
  driveMotorRightAEntry.SetDouble(m_drivetrain.GetMotorRightA());
  driveMotorRightBEntry.SetDouble(m_drivetrain.GetMotorRightB());
  shifterEntry.SetBoolean(m_drivetrain.GetShifter());

  forkStateEntry.SetBoolean(m_forks.GetForkState());
  outriggerStateEntry.SetBoolean(m_forks.GetOutriggerState());

  frc::SmartDashboard::PutData(&Robot::m_drivetrain);
  frc::SmartDashboard::PutData(&Robot::m_forks);
  frc::SmartDashboard::PutData(&Robot::m_carriage);
  frc::SmartDashboard::PutData(&Robot::m_intake);
  frc::SmartDashboard::PutData(&Robot::m_elevator);
  frc::SmartDashboard::PutData(&Robot::m_pneumatics);

  frc::SmartDashboard::PutData("DriveWithJoystick", new DriveWithJoystick());
  // frc::SmartDashboard.putData("DriveWithJoystick", new DriveWithJoystick());
  // frc::SmartDashboard.putData("DriveWithJoystick", new DriveWithJoystick());
  // frc::SmartDashboard.putData("DriveWithJoystick", new DriveWithJoystick());
  // frc::SmartDashboard.putData("DriveWithJoystick", new DriveWithJoystick());
  // frc::SmartDashboard.putData("DriveWithJoystick", new DriveWithJoystick());
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif