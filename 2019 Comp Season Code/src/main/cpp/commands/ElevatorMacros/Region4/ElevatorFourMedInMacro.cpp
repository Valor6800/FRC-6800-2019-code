#include "commands/ElevatorMacros/Region4/ElevatorFourMedInMacro.h"
#include "Robot.h"

ElevatorFourMedInMacro::ElevatorFourMedInMacro()
{
    // TODO: Possible go down to kLiftBarTopSafe, then out
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}