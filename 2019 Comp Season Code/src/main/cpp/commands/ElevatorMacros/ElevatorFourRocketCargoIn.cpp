#include "commands/ElevatorMacros/ElevatorFourRocketCargoIn.h"
#include "Robot.h"

ElevatorFourRocketCargoIn::ElevatorFourRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}