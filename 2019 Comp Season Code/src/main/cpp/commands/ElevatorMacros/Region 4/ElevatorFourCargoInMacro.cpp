#include "commands/ElevatorMacros/ElevatorFourCargoInMacro.h"
#include "Robot.h"

ElevatorFourCargoInMacro::ElevatorFourCargoInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}