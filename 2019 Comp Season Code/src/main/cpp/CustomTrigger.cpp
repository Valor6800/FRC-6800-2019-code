/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CustomTrigger.h"
#include "Robot.h"

CustomTrigger::CustomTrigger(char button, double lowEnd, double highEnd) {
  m_button = button;
  m_lowEnd = lowEnd;
  m_highEnd = highEnd;
}

bool CustomTrigger::Get() {

    switch(m_button) {
      case 'Y' :
        return (Robot::m_oi.GetGamepad().GetYButtonPressed() && Robot::m_elevator.GetHeight() >= m_lowEnd && Robot::m_elevator.GetHeight() < m_highEnd);
      case 'X' :
        return (Robot::m_oi.GetGamepad().GetXButtonPressed() && Robot::m_elevator.GetHeight() >= m_lowEnd && Robot::m_elevator.GetHeight() < m_highEnd);
      case 'B' :
        return (Robot::m_oi.GetGamepad().GetBButtonPressed() && Robot::m_elevator.GetHeight() >= m_lowEnd && Robot::m_elevator.GetHeight() < m_highEnd);
    }    

}


