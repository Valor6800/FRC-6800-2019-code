#include "commands/ElevatorMacros/Region2/ElevatorTwoCargoInMacro.h"
#include "Robot.h"

ElevatorTwoCargoInMacro::ElevatorTwoCargoInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
