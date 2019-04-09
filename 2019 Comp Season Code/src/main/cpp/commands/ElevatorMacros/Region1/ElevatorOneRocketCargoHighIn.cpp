#include "commands/ElevatorMacros/Region1/ElevatorOneRocketCargoHighIn.h"
#include "Robot.h"

ElevatorOneRocketCargoHighIn::ElevatorOneRocketCargoHighIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}
