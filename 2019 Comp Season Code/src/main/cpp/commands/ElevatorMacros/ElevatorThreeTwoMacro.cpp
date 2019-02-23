#include "commands/ElevatorMacros/ElevatorThreeTwoMacro.h"
#include "Robot.h"

ElevatorThreeTwoMacro::ElevatorThreeTwoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelTwoCargo));
}
