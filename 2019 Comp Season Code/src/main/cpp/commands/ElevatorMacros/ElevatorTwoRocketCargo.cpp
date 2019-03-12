#include "commands/ElevatorMacros/ElevatorTwoRocketCargo.h"
#include "Robot.h"

ElevatorTwoRocketCargo::ElevatorTwoRocketCargo()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}