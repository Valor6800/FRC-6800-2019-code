#include "commands/ElevatorMacros/Region4/ElevatorFourLowInMacro.h"
#include "Robot.h"

ElevatorFourLowInMacro::ElevatorFourLowInMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}