#include "commands/ElevatorMacros/Region1/ElevatorOneRocketCargoHigh.h"
#include "Robot.h"

ElevatorOneRocketCargoHigh::ElevatorOneRocketCargoHigh()
{
    AddSequential(new SetHatch(false));
    AddSequential(new WaitCommand(.2));
    AddSequential(new SetElevatorSetpointDefinite(Robot::m_elevator.kHighCargo));
}
