#include "commands/ElevatorMacros/Region1/ElevatorOneHighMacro.h"
#include "Robot.h"

ElevatorOneHighMacro::ElevatorOneHighMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}
