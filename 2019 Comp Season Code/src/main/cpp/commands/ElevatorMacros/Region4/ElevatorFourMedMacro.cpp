#include "commands/ElevatorMacros/Region4/ElevatorFourMedMacro.h"
#include "Robot.h"

ElevatorFourMedMacro::ElevatorFourMedMacro()
{
    // TODO: Possible go down to kLiftBarTopSafe, then out
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}