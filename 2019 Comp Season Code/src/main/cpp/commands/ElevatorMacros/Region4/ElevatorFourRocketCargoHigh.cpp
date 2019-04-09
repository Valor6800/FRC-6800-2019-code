#include "commands/ElevatorMacros/Region4/ElevatorFourRocketCargoHigh.h"
#include "Robot.h"

ElevatorFourRocketCargoHigh::ElevatorFourRocketCargoHigh()
{
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}
