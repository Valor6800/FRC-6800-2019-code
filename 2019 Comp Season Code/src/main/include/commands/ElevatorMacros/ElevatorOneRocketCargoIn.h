#pragma once

#include <frc/commands/CommandGroup.h>
#include "commands/SetHatch.h"
#include "commands/SetElevatorSetpointDefinite.h"
#include "commands/SetIntakeMacro.h"
/**
 * This command allows PS3 joystick to drive the robot. It is always running
 * except when interrupted by another command.
 */
class ElevatorOneRocketCargoIn : public frc::CommandGroup {
 public:
  ElevatorOneRocketCargoIn();
};