#include "commands/ElevatorMacros/Region1/ElevatorOneLowMacro.h"
#include "Robot.h"

ElevatorOneLowMacro::ElevatorOneLowMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
}
