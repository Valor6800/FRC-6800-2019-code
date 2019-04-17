#include "commands/ElevatorMacros/Region3/ElevatorThreeHighMacro.h"
#include "Robot.h"

ElevatorThreeHighMacro::ElevatorThreeHighMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighHatch));
}
