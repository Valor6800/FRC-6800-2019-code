#include "commands/ElevatorMacros/Region3/ElevatorThreeCargoMacro.h"
#include "Robot.h"

ElevatorThreeCargoMacro::ElevatorThreeCargoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
