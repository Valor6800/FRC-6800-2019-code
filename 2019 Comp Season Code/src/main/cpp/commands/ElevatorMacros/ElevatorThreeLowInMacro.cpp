#include "commands/ElevatorMacros/ElevatorThreeLowMacro.h"
#include "Robot.h"

ElevatorThreeLowMacro::ElevatorThreeLowMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}