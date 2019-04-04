#include "commands/ElevatorMacros/Region1/ElevatorOneHighInMacro.h"
#include "Robot.h"

ElevatorOneHighInMacro::ElevatorOneHighInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}