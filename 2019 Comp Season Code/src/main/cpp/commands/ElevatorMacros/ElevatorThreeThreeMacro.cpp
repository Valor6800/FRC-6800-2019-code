#include "commands/ElevatorMacros/ElevatorThreeThreeMacro.h"
#include "Robot.h"

ElevatorThreeThreeMacro::ElevatorThreeThreeMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelThreeCargo));
}
