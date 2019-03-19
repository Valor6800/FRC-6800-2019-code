#include "commands/ElevatorMacros/Region4/ElevatorFourCargoMacro.h"
#include "Robot.h"

ElevatorFourCargoMacro::ElevatorFourCargoMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
