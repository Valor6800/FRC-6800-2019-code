#include "commands/ElevatorMacros/ElevatorFourLowMacro.h"
#include "Robot.h"

ElevatorFourLowMacro::ElevatorFourLowMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}