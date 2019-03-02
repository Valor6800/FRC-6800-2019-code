#include "commands/ElevatorMacros/ElevatorThreeMedMacro.h"
#include "Robot.h"

ElevatorThreeMedMacro::ElevatorThreeMedMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}
