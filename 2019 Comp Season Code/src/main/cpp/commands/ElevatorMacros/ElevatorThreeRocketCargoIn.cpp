#include "commands/ElevatorMacros/ElevatorThreeRocketCargo.h"
#include "Robot.h"

ElevatorThreeRocketCargo::ElevatorThreeRocketCargo()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}