#include "commands/ElevatorMacros/Region2/ElevatorTwoRocketCargo.h"
#include "Robot.h"

ElevatorTwoRocketCargo::ElevatorTwoRocketCargo()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}