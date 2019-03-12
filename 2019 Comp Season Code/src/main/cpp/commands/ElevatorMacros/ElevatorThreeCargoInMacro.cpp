#include "commands/ElevatorMacros/ElevatorThreeCargoInMacro.h"
#include "Robot.h"

ElevatorThreeCargoInMacro::ElevatorThreeCargoInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
