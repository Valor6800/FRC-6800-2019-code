#include "commands/ElevatorMacros/Region3/ElevatorThreeLowMacro.h"
#include "Robot.h"

ElevatorThreeLowMacro::ElevatorThreeLowMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}