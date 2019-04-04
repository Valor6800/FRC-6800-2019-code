#include "commands/ElevatorMacros/Region4/ElevatorFourHighMacro.h"
#include "Robot.h"

ElevatorFourHighMacro::ElevatorFourHighMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}