#include "commands/ElevatorMacros/Region1/ElevatorOneRocketCargoIn.h"
#include "Robot.h"

ElevatorOneRocketCargoIn::ElevatorOneRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo - 10));
}