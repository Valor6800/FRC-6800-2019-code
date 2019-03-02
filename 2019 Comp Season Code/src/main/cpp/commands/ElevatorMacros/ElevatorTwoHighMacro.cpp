#include "commands/ElevatorMacros/ElevatorTwoHighMacro.h"
#include "Robot.h"

ElevatorTwoHighMacro::ElevatorTwoHighMacro()
{
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kLiftBarBottomSafe));
    AddSequential(new SetHatch(false));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
    AddSequential(new SetHatch(true));
}
