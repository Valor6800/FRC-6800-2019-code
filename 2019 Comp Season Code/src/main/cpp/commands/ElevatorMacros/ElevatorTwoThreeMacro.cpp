#include "commands/ElevatorMacros/ElevatorTwoThreeMacro.h"
#include "Robot.h"

ElevatorTwoThreeMacro::ElevatorTwoThreeMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelThreeCargo));
}
