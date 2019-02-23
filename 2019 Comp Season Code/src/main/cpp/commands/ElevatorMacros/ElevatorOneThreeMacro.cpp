#include "commands/ElevatorMacros/ElevatorOneThreeMacro.h"
#include "Robot.h"

ElevatorOneThreeMacro::ElevatorOneThreeMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelThreeCargo));
    AddSequential(new SetHatch(true));
}
