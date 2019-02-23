#include "commands/ElevatorMacros/ElevatorOneOneMacro.h"
#include "Robot.h"

ElevatorOneOneMacro::ElevatorOneOneMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelOneCargo));
}
