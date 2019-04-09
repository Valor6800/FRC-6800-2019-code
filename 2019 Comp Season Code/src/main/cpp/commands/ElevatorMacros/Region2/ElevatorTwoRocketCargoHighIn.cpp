#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargoHighIn.h"
#include "Robot.h"

ElevatorTwoRocketCargoHighIn::ElevatorTwoRocketCargoHighIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}