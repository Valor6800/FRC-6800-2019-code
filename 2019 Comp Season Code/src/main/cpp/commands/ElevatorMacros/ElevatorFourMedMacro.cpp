#include "commands/ElevatorMacros/ElevatorFourMedMacro.h"
#include "Robot.h"

ElevatorFourMedMacro::ElevatorFourMedMacro()
{
    // TODO: Possible go down to kLiftBarTopSafe, then out
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}