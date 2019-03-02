#include "commands/ElevatorMacros/ElevatorTwoMedMacro.h"
#include "Robot.h"

ElevatorTwoMedMacro::ElevatorTwoMedMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
