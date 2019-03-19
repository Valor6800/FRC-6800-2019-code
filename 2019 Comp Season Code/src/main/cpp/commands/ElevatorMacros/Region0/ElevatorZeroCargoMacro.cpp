#include "commands/ElevatorMacros/Region0/ElevatorZeroCargoMacro.h"
#include "Robot.h"

ElevatorZeroCargoMacro::ElevatorZeroCargoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(100));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}

