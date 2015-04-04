#pragma once

#include "WPILib.h"

#include <vector>
#include <memory>

namespace team254 {
namespace surcake {

class ReversingTalon {
 public:
  enum Polarity {
    NORMAL,
    INVERTED,
  };

  ReversingTalon(int channel, Polarity polarity);
  void set(double power);

 private:
  Talon talon_;
  Polarity polarity_;
};

void setTalons(std::vector<std::shared_ptr<ReversingTalon>>& talons,
               double power);

}
}
