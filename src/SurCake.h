#pragma once

#include "WPILib.h"

#include "ReversingTalon.h"

#include <vector>
#include <memory>

namespace team254 {
namespace surcake {

/** controls the Citrus Circuits' RC grabber */
class SurCake {
 public:
  enum GrabberDirection {
    EXTEND,
    NEUTRAL,
    RETRACT,
  };

  SurCake(std::vector<std::shared_ptr<ReversingTalon>> talons);

  /** Call from auto init */
  void initForAuto();

  /** Call this in the auto periodic callback */
  void updateForAuto();

  /**
   * Call this in the tele-op periodic callback
   * @param grabberDirection Output to the can grabber
   */
  void updateForTeleop(GrabberDirection grabberDirection);

 private:
  double autoStartTime_;
  std::vector<std::shared_ptr<ReversingTalon>> talons_;
};

}
}
