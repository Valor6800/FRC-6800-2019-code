/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/AnalogInput.h>
#include <frc/Compressor.h>
#include <frc/commands/Subsystem.h>

/**
 * The Pneumatics subsystem contains the compressor and a pressure sensor.
 *
 * NOTE: The simulator currently doesn't support the compressor or pressure
 * sensors.
 */
class Pneumatics : public frc::Subsystem {
 public:

  Pneumatics();
  void Start();

 private:

  frc::Compressor m_compressor;

};
