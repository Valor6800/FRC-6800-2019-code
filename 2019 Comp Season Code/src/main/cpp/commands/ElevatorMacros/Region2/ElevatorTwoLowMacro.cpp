#include "commands/ElevatorMacros/Region2/ElevatorTwoLowMacro.h"
#include "Robot.h"

ElevatorTwoLowMacro::ElevatorTwoLowMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
}
