#include "commands/ElevatorMacros/ElevatorOneLowMacro.h"
#include "Robot.h"

ElevatorOneLowMacro::ElevatorOneLowMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
}
