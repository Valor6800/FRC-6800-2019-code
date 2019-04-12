#include "commands/ElevatorMacros/Region3/ElevatorThreeRocketCargo.h"
#include "Robot.h"

ElevatorThreeRocketCargo::ElevatorThreeRocketCargo()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo - 10));
}
