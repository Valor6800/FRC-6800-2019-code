#include "commands/ElevatorMacros/Region2/ElevatorTwoHighInMacro.h"
#include "Robot.h"

ElevatorTwoHighInMacro::ElevatorTwoHighInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighHatch));
    AddSequential(new SetHatch(true));
}