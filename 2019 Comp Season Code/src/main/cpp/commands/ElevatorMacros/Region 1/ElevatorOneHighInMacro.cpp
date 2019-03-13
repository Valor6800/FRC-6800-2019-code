#include "commands/ElevatorMacros/ElevatorOneHighInMacro.h"
#include "Robot.h"

ElevatorOneHighInMacro::ElevatorOneHighInMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}