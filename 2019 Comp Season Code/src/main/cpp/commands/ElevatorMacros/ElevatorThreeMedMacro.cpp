#include "commands/ElevatorMacros/ElevatorThreeMedMacro.h"
#include "Robot.h"

ElevatorThreeMedMacro::ElevatorThreeMedMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
