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
#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <wpi/raw_ostream.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include "../include/commands/EnableGShift.h"
#include "../include/commands/RocketLeftPath.h"


Carriage Robot::m_carriage;
Drivetrain Robot::m_drivetrain;
Elevator Robot::m_elevator;
Intake Robot::m_intake;
Pneumatics Robot::m_pneumatics;
Forks Robot::m_forks;
OI Robot::m_oi;

frc::ShuffleboardTab& tab = frc::Shuffleboard::GetTab("OurTab");

nt::NetworkTableEntry elevatorHeightEntry;
nt::NetworkTableEntry elevatorUpperLimitEntry;
nt::NetworkTableEntry elevatorLowerLimitEntry;
nt::NetworkTableEntry elevatorSpeedEntry;
nt::NetworkTableEntry elevatorBrakeEntry;

nt::NetworkTableEntry intakeAngleEntry;
nt::NetworkTableEntry intakeWheelEntry;

nt::NetworkTableEntry carriageWheelLEntry;
nt::NetworkTableEntry carriageWheelREntry;
nt::NetworkTableEntry carriagePhotoelectricEntry;

nt::NetworkTableEntry driveMotorLeftEntry;
nt::NetworkTableEntry driveMotorRightEntry;
nt::NetworkTableEntry shifterEntry;

nt::NetworkTableEntry forkStateEntry;
nt::NetworkTableEntry outriggerStateEntry;

nt::NetworkTableEntry clientValEntry;

nt::NetworkTableEntry gyroEntry;

nt::NetworkTableEntry drivePowerLeftEntry;
nt::NetworkTableEntry drivePowerRightEntry;

double count;
double count2;

void Robot::RobotInit() {

  auto inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("datatable");
  inst.StartClientTeam(6800);

  //countEntry = tab.Add("count_", 0).withWidget(frc::BuiltInWidgets::kNumberSlider).GetEntry();
  //count2Entry = tab.Add("count2", 100).GetEntry();
  elevatorHeightEntry = tab.Add("Elevator Height", 0).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();
  elevatorLowerLimitEntry = tab.Add("Elevator Lower Limit", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  elevatorUpperLimitEntry = tab.Add("Elevator Upper Limit", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  elevatorSpeedEntry = tab.Add("Elevator Speed", 0).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();
  elevatorBrakeEntry = tab.Add("Elevator Brake", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();

  intakeAngleEntry = tab.Add("Intake Angle", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  intakeWheelEntry = tab.Add("Intake Wheel", 0).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();
 
  carriageWheelLEntry = tab.Add("Carriage Wheel L", 0).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();
  carriageWheelREntry = tab.Add("Carriage Wheel R", 0).WithWidget(frc::BuiltInWidgets::kDial).GetEntry();
  carriagePhotoelectricEntry = tab.Add("Carriage Photoelectric", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  
  driveMotorLeftEntry = tab.Add("Drive Motor Left A", 0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();
  driveMotorRightEntry = tab.Add("Drive Motor Right A", 0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();
  shifterEntry = tab.Add("Shifter Entry", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();

  forkStateEntry = tab.Add("Fork State", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();
  outriggerStateEntry = tab.Add("Outrigger State", false).WithWidget(frc::BuiltInWidgets::kBooleanBox).GetEntry();

  clientValEntry = tab.Add("Client Val Entry", -1).GetEntry();

  gyroEntry = tab.Add("Heading", 0).WithWidget(frc::BuiltInWidgets::kGyro).GetEntry();

  drivePowerLeftEntry = tab.Add("Drive Power Left", 0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();
  drivePowerRightEntry = tab.Add("Drive Power Right", 0).WithWidget(frc::BuiltInWidgets::kTextView).GetEntry();

  // instantiate the command used for the autonomous period
  m_autoChooser.SetDefaultOption("Pathfinder test", &m_pathfinder);
  // m_autoChooser.AddOption("Drive Forward", &m_driveForwardAuto);
  // const frc::BuiltInWidgets::kNumberSlider slider = frc::BuiltInWidgets::kNumberSlider;
  frc::SmartDashboard::PutData("Auto Mode", &m_autoChooser);
    // pneumatics.Start();  // Pressurize the pneumatics.

    Robot::m_elevator.m_liftEncoder.Reset();
}

void Robot::AutonomousInit() {
  
  m_drivetrain.m_driveMotorLeftA.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_drivetrain.m_driveMotorRightA.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_drivetrain.m_driveMotorLeftB.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_drivetrain.m_driveMotorRightB.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_drivetrain.m_driveMotorLeftA.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorLeftB.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorRightA.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorRightB.GetEncoder().SetPosition(0);
  Robot::m_drivetrain.m_gyro.Reset();
  m_autonomousCommand = m_autoChooser.GetSelected();
  m_autonomousCommand->Start();

  Robot::m_elevator.m_liftEncoder.Reset();

}

void Robot::AutonomousPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  Log();
}

void Robot::TeleopInit() {

  m_drivetrain.m_driveMotorLeftA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorRightA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorLeftB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorRightB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
  }
  // std::cout << "Starting Teleop" << std::endl;

    Robot::m_elevator.m_liftEncoder.Reset();
}

void Robot::TeleopPeriodic() {
  frc::Scheduler::GetInstance()->Run();
  Log();
}

void Robot::TestPeriodic() { Log(); }

void Robot::DisabledInit(){
  m_drivetrain.m_driveMotorLeftA.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorLeftB.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorRightA.GetEncoder().SetPosition(0);
  m_drivetrain.m_driveMotorRightB.GetEncoder().SetPosition(0);

  m_drivetrain.m_driveMotorLeftA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorRightA.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorLeftB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_drivetrain.m_driveMotorRightB.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void Robot::DisabledPeriodic() { 
  Log();
  m_drivetrain.m_gyro.Reset(); 
  


}

/**
 * Log interesting values to the SmartDashboard.
 */
void Robot::Log() {
  nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("testtable");
  clientValEntry.SetDouble(table->GetEntry("val").GetDouble(-2));

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
  // elevatorUpperLimitEntry.SetBoolean(m_elevator.IsAtUpperLimit());
  elevatorSpeedEntry.SetDouble(m_elevator.GetSpeed());
  elevatorBrakeEntry.SetBoolean(m_elevator.GetBrake());

  intakeWheelEntry.SetDouble(m_intake.GetWheelMotor());

  carriageWheelLEntry.SetDouble(m_carriage.GetMotorL());
  carriageWheelREntry.SetDouble(m_carriage.GetMotorR());
  carriagePhotoelectricEntry.SetBoolean(m_carriage.IsPhotoelectric());

  driveMotorLeftEntry.SetDouble(m_drivetrain.GetLeftEncoder());
  driveMotorRightEntry.SetDouble(m_drivetrain.GetRightEncoder());
  shifterEntry.SetBoolean(m_drivetrain.GetShifter());

  forkStateEntry.SetBoolean(m_forks.GetForkState());
  outriggerStateEntry.SetBoolean(m_forks.GetOutriggerState());

  gyroEntry.SetDouble(m_drivetrain.GetHeading());

  drivePowerLeftEntry.SetDouble(m_drivetrain.l);
  drivePowerRightEntry.SetDouble(m_drivetrain.r);

  // camera1Entry.SetRaw(outputStream.Get());

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