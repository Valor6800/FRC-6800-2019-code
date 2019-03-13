#include "commands/ElevatorMacros/Region2/ElevatorTwoCargoMacro.h"
#include "Robot.h"

ElevatorTwoCargoMacro::ElevatorTwoCargoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
