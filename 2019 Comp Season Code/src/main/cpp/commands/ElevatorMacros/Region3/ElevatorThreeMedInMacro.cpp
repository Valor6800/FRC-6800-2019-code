#include "commands/ElevatorMacros/Region3/ElevatorThreeMedInMacro.h"
#include "Robot.h"

ElevatorThreeMedInMacro::ElevatorThreeMedInMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}