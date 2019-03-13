#include "commands/ElevatorMacros/Region4/ElevatorFourCargoInMacro.h"
#include "Robot.h"

ElevatorFourCargoInMacro::ElevatorFourCargoInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}