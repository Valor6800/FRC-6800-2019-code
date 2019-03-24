/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ElevatorManual.h"

#include "Robot.h"

ElevatorManual::ElevatorManual() { Requires(&Robot::m_elevator); }

void ElevatorManual::Initialize() {Robot::m_elevator.Disable(); }

// Called repeatedly when this Command is scheduled to run
void ElevatorManual::Execute() {
  auto& gamepad = Robot::m_oi.GetGamepad();

  // If elevator all the way down
  if(Robot::m_elevator.IsAtLowerLimit()) {
    
    // Re-zero the encoder
    Robot::m_elevator.m_liftEncoder.Reset();
    Robot::m_elevator.hasZeroed = true;

  }

  // Get the y-Value of the joystick for use later on
  yVal = gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand);

  // If we are going down, DO half-speed mode, ELSE full speed mode
  // NOTE: Negative yVal runs the lift up and vice versa
  if(yVal > 0) {
    yVal = yVal / 1.5;
  }

  // If we are out of deadband
  if(std::abs(gamepad.GetY(frc::GenericHID::JoystickHand::kLeftHand)) > .05) {
    
    // if(!Robot::m_elevator.IsAtLowerLimit()) {
    //   Robot::m_elevator.SetLiftSpeed(yVal);
    //   Robot::m_elevator.EngageBrake(false);
    // } else {
    //   if(yVal < 0) {
    //     Robot::m_elevator.SetLiftSpeed(0);
    //     Robot::m_elevator.EngageBrake(true);
    //   } else {

        // If the elevator is moving, disengage the brake
        Robot::m_elevator.EngageBrake(false);


        // TODO: Make this .25 with comp code
        // If we are already towards the bottom and still trying to run the lift down
        if(Robot::m_elevator.GetHeight() < 80 && yVal > .25) {
            // Set the elevator to go quite slow
            Robot::m_elevator.SetLiftSpeed(.25);

        // As long as we are not at the very bottom and trying to go down
        } else if(!(Robot::m_elevator.IsAtLowerLimit() && yVal > 0)) {
            // Set the elevator to the y Value of the joystick
            Robot::m_elevator.SetLiftSpeed(yVal);
      
        // This means we are 0'd on the encoder
        } else {
            // Set it to 0 completely
            Robot::m_elevator.SetLiftSpeed(0);
        }
        
    //   }
    // }
    
  // Otherwise
  } else {

    // Stop the lift
    Robot::m_elevator.SetLiftSpeed(0);

    // Engage the brake to prevent decay
    Robot::m_elevator.EngageBrake(true);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorManual::IsFinished() { return false; }

// Called once after isFinished returns true
void ElevatorManual::End() { Robot::m_elevator.SetLiftSpeed(0); }