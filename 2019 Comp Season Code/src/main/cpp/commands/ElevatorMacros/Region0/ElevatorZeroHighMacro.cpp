#include "commands/ElevatorMacros/Region0/ElevatorZeroHighMacro.h"
#include "Robot.h"

ElevatorZeroHighMacro::ElevatorZeroHighMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(100));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}

