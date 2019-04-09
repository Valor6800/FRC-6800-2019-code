#include "commands/ElevatorMacros/Region3/ElevatorThreeRocketCargoHigh.h"
#include "Robot.h"

ElevatorThreeRocketCargoHigh::ElevatorThreeRocketCargoHigh()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(false));
}
