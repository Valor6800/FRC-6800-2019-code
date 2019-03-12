#include "commands/ElevatorMacros/ElevatorTwoRocketCargoIn.h"
#include "Robot.h"

ElevatorTwoRocketCargoIn::ElevatorTwoRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}