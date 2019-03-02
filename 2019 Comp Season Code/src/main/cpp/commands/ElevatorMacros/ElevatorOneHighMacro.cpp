#include "commands/ElevatorMacros/ElevatorOneHighMacro.h"
#include "Robot.h"

ElevatorOneHighMacro::ElevatorOneHighMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}
