#include "commands/ElevatorMacros/ElevatorFourCargoMacro.h"
#include "Robot.h"

ElevatorFourCargoMacro::ElevatorFourCargoMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.5));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
