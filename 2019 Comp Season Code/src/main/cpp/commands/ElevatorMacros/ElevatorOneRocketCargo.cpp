#include "commands/ElevatorMacros/ElevatorOneRocketCargo.h"
#include "Robot.h"

ElevatorOneRocketCargo::ElevatorOneRocketCargo()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}