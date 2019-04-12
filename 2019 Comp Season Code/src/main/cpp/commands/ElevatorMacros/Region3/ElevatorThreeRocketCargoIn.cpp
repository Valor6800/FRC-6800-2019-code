#include "commands/ElevatorMacros/Region3/ElevatorThreeRocketCargoIn.h"
#include "Robot.h"

ElevatorThreeRocketCargoIn::ElevatorThreeRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo - 10));
}