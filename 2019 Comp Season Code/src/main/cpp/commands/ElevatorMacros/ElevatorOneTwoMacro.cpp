#include "commands/ElevatorMacros/ElevatorOneTwoMacro.h"
#include "Robot.h"

ElevatorOneTwoMacro::ElevatorOneTwoMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelTwoSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelTwoCargo));
}
