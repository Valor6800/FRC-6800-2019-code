#include "commands/ElevatorMacros/ElevatorOneMedMacro.h"
#include "Robot.h"

ElevatorOneMedMacro::ElevatorOneMedMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
