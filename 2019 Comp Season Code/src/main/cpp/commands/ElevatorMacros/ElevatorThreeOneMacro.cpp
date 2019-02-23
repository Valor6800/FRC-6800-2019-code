#include "commands/ElevatorMacros/ElevatorThreeOneMacro.h"
#include "Robot.h"

ElevatorThreeOneMacro::ElevatorThreeOneMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLevelOneCargo));
    AddSequential(new SetHatch(true));
}
