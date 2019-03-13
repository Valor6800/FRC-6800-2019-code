#include "commands/ElevatorMacros/Region1/ElevatorOneCargoMacro.h"
#include "Robot.h"

ElevatorOneCargoMacro::ElevatorOneCargoMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kShip));
    AddSequential(new SetIntakeMacro(false));
}
