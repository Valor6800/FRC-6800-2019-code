#include "commands/ElevatorMacros/Region2/ElevatorTwoMedInMacro.h"
#include "Robot.h"

ElevatorTwoMedInMacro::ElevatorTwoMedInMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}