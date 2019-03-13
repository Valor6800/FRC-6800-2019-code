#include "commands/ElevatorMacros/Region3/ElevatorThreeCargoInMacro.h"
#include "Robot.h"

ElevatorThreeCargoInMacro::ElevatorThreeCargoInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}