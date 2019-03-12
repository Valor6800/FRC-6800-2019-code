#include "commands/ElevatorMacros/ElevatorFourMedMacro.h"
#include "Robot.h"

ElevatorFourMedMacro::ElevatorFourMedMacro()
{
    AddSequential(new SetIntakeMacro(true));
    // TODO: Possible go down to kLiftBarTopSafe, then out
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}