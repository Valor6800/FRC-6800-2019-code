#include "commands/ElevatorMacros/ElevatorFourLowMacro.h"
#include "Robot.h"

ElevatorFourLowMacro::ElevatorFourLowMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLowCargo));
    AddSequential(new SetHatch(true));
}