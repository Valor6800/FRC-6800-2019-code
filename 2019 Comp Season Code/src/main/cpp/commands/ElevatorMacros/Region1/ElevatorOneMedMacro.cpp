#include "commands/ElevatorMacros/Region1/ElevatorOneMedMacro.h"
#include "Robot.h"

ElevatorOneMedMacro::ElevatorOneMedMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(.3));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}
