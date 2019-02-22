#include "commands/ElevatorHatchMacro.h"
#include "Robot.h"

ElevatorHatchMacro::ElevatorHatchMacro(double toGo)
{

    // Level 1 = anywhere from 0 to 200
    // Level 2 = anywhere from 200 to 550
    // Level 3 = 550 and up

    // 1 to 3
    if(Robot::m_elevator.GetHeight() < 200 && toGo == Robot::m_elevator.kLevelThreeCargo) {
        // AddSequential(new SetHatch(false)); 
        // AddSequential(new SetElevatorSetpointDefinite(toGo));
        AddSequential(new SetHatch(true));
    } 
    // 3 to 1
    else if(Robot::m_elevator.GetHeight() > 550 && toGo == Robot::m_elevator.kLevelOneCargo) {
        AddSequential(new SetHatch(true));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
        AddSequential(new SetHatch(true));
    }
    // 1 to 2
    else if(Robot::m_elevator.GetHeight() < 200 && toGo == Robot::m_elevator.kLevelTwoCargo) {
        AddSequential(new SetHatch(false));
        AddSequential(new SetElevatorSetpointDefinite(toGo + 70));
        AddSequential(new SetHatch(true));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
    }
    // 2 to 1
    else if((Robot::m_elevator.GetHeight() >= 200 && Robot::m_elevator.GetHeight() <= 550) && toGo == Robot::m_elevator.kLevelOneCargo) {
        AddSequential(new SetElevatorSetpointDefinite(520));
        AddSequential(new SetHatch(false));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
        AddSequential(new SetHatch(true));
    // 2 to 3 or 3 to 2
    } else if((Robot::m_elevator.GetHeight() >= 200 && Robot::m_elevator.GetHeight() <= 550) && toGo == Robot::m_elevator.kLevelThreeCargo){
        AddSequential(new SetHatch(true));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
    } else if((Robot::m_elevator.GetHeight() > 550) && toGo == Robot::m_elevator.kLevelTwoCargo){
        AddSequential(new SetHatch(true));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
    } else if((Robot::m_elevator.GetHeight() < 200) && toGo == Robot::m_elevator.kLevelOneCargo){
        AddSequential(new SetHatch(true));
        AddSequential(new SetElevatorSetpointDefinite(toGo));
    }
}
