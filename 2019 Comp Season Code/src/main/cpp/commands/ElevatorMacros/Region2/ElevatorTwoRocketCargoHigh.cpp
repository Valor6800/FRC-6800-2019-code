#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargoHigh.h"
#include "Robot.h"

ElevatorTwoRocketCargoHigh::ElevatorTwoRocketCargoHigh()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}
