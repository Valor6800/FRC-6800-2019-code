#include "commands/ElevatorMacros/Region0/ElevatorZeroRocketCargoMacro.h"
#include "Robot.h"

ElevatorZeroRocketCargoMacro::ElevatorZeroRocketCargoMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(100));
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedCargo));
}
