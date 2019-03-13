#include "commands/ElevatorMacros/ElevatorFourRocketCargo.h"
#include "Robot.h"

ElevatorFourRocketCargo::ElevatorFourRocketCargo()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.5));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
