/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetCarriageSpeed.h"

#include "Robot.h"

SetCarriageSpeed::SetCarriageSpeed() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_carriage);
}

// Called just before this Command runs the first time
void SetCarriageSpeed::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetCarriageSpeed::Execute() {
    if (Robot::m_carriage.photoelectricActivated)
    {
        if (Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand) > .05)
        {
           Robot::m_carriage.SetMotors(0);
        }
        else
        {
            Robot::m_carriage.photoelectricActivated = false;
        }
    } 
    else {
        if (Robot::m_carriage.IsPhotoelectric() && !Robot::m_carriage.photoelectricTriggeredOnce) {
          Robot::m_carriage.photoelectricTriggeredOnce = true;
          Robot::m_carriage.photoelectricActivated = true;
          Robot::m_carriage.SetMotors(0);
        } 
      else {
         Robot::m_carriage.SetMotors(Robot::m_oi.GetGamepad().GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand));
         if (!Robot::m_carriage.IsPhotoelectric() && Robot::m_carriage.photoelectricTriggeredOnce) {
            Robot::m_carriage.photoelectricTriggeredOnce = false;
         }
      }
    }
  
}

// Make this return true when this Command no longer needs to run execute()
bool SetCarriageSpeed::IsFinished() { return false; }

// Called once after isFinished returns true
void SetCarriageSpeed::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetCarriageSpeed::Interrupted() {}