#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargoIn.h"
#include "Robot.h"

ElevatorTwoRocketCargoIn::ElevatorTwoRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo - 10));
}