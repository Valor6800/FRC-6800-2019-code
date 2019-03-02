#include "commands/ElevatorMacros/ElevatorThreeLowMacro.h"
#include "Robot.h"

ElevatorThreeLowMacro::ElevatorThreeLowMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}
