#include "commands/ElevatorMacros/Region4/ElevatorFourRocketCargo.h"
#include "Robot.h"

ElevatorFourRocketCargo::ElevatorFourRocketCargo()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
