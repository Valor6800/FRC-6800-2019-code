/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveEncoder.h"

#include "Robot.h"

DriveEncoder::DriveEncoder(double distance, double angle, double speed) {
    
    // TODO: Negative distances?
    targetDist = distance*(18 / (6 * 3.14159265359)) + Robot::m_drivetrain.GetEncoderAverage();
    targetHeading = angle;
    power = speed;
    Requires(&Robot::m_drivetrain);
}

DriveEncoder::DriveEncoder(double distance, double speed) {
    targetDist = distance*(18 / (6 * 3.14159265359)) + Robot::m_drivetrain.GetEncoderAverage();
    // 18 TICKS PER REV ?
    // dist inch   1 rev     18 tick
    //             6pi inch  1 rev        
    targetHeading = Robot::m_drivetrain.GetHeading();
    power = speed;
    Requires(&Robot::m_drivetrain);
}

void DriveEncoder::Execute() {
    currHeading = Robot::m_drivetrain.GetHeading();
    
    angError = targetHeading - currHeading;    // Make sure to bound this from -180 to 180, otherwise you will get super large values

    turn = .02 * angError;
    
    Robot::m_drivetrain.TankDrive(power + turn, power - turn);
}

bool DriveEncoder::IsFinished() {
    return Robot::m_drivetrain.GetEncoderAverage() >= targetDist;
}

void DriveEncoder::End() {
    Robot::m_drivetrain.TankDrive(0, 0);
}