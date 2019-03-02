#include "commands/ElevatorMacros/ElevatorThreeHighMacro.h"
#include "Robot.h"

ElevatorThreeHighMacro::ElevatorThreeHighMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}
