#pragma once

#include "WPILib.h"

#include "ReversingTalon.h"
#include "SurCake.h"

#include <vector>
#include <memory>

namespace team254 {
namespace surcake {

class Robot : public IterativeRobot {
 public:
  Robot();

  // IterativeRobot overrides
  void AutonomousInit()
  void AutonomousPeriodic();
  void TeleopPeriodic();

 private:
  Joystick joystick_;
  std::vector<std::shared_ptr<ReversingTalon>> leftDriveTalons_;
  std::vector<std::shared_ptr<ReversingTalon>> rightDriveTalons_;
  SurCake surCake_;
};
}
}
