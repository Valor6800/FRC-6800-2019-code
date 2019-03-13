#include "commands/ElevatorMacros/ElevatorOneRocketCargoIn.h"
#include "Robot.h"

ElevatorOneRocketCargoIn::ElevatorOneRocketCargoIn()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}