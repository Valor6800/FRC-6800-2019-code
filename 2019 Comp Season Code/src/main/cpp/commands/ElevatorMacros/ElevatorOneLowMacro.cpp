#include "commands/ElevatorMacros/ElevatorOneLowMacro.h"
#include "Robot.h"

ElevatorOneLowMacro::ElevatorOneLowMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
}
