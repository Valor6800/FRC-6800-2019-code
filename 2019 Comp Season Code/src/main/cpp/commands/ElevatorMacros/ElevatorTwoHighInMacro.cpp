#include "commands/ElevatorMacros/ElevatorTwoHighInMacro.h"
#include "Robot.h"

ElevatorTwoHighInMacro::ElevatorTwoHighInMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}