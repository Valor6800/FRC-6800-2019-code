#include "commands/ElevatorMacros/Region1/ElevatorOneHighInMacro.h"
#include "Robot.h"

ElevatorOneHighInMacro::ElevatorOneHighInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighHatch));
    AddSequential(new SetHatch(true));
}