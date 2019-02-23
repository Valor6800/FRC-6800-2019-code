#include "commands/ElevatorMacros/ElevatorTwoOneMacro.h"
#include "Robot.h"

ElevatorTwoOneMacro::ElevatorTwoOneMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelTwoSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelOneCargo));
    AddSequential(new SetHatch(true));
}
