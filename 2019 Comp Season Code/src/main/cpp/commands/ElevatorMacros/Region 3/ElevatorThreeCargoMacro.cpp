#include "commands/ElevatorMacros/ElevatorThreeCargoMacro.h"
#include "Robot.h"

ElevatorThreeCargoMacro::ElevatorThreeCargoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.5));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
