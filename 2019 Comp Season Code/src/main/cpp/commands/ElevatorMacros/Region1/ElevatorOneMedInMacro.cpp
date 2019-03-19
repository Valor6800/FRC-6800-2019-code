#include "commands/ElevatorMacros/Region1/ElevatorOneMedInMacro.h"
#include "Robot.h"

ElevatorOneMedInMacro::ElevatorOneMedInMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}