#include "commands/ElevatorMacros/ElevatorOneMedMacro.h"
#include "Robot.h"

ElevatorOneMedMacro::ElevatorOneMedMacro()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarTopSafe));
    AddSequential(new SetHatch(true));
    AddSequential(new WaitCommand(1));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kMedHatch));
}
