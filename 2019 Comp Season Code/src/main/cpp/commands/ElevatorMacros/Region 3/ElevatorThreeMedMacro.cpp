#include "commands/ElevatorMacros/ElevatorThreeMedMacro.h"
#include "Robot.h"

ElevatorThreeMedMacro::ElevatorThreeMedMacro()
{
    AddSequential(new SetIntakeMacro(true));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}
