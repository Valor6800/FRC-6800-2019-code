#include "commands/ElevatorMacros/ElevatorTwoMedMacro.h"
#include "Robot.h"

ElevatorTwoMedMacro::ElevatorTwoMedMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}