#include "commands/ElevatorMacros/ElevatorThreeRocketCargoIn.h"
#include "Robot.h"

ElevatorThreeRocketCargoIn::ElevatorThreeRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}