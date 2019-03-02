#include "commands/ElevatorMacros/ElevatorFourHighMacro.h"
#include "Robot.h"

ElevatorFourHighMacro::ElevatorFourHighMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}