#include "ReversingTalon.h"

namespace team254 {
namespace surcake {

ReversingTalon::ReversingTalon(int channel, Polarity polarity)
    : talon_(channel),
      polarity_(polarity) {
}

void ReversingTalon::set(double power) {
  talon_.Set(power * ((polarity_ == NORMAL) ? 1 : -1));
}

void setTalons(std::vector<std::shared_ptr<ReversingTalon>>& talons,
               double power) {
  for (auto& talon : talons) {
    talon->set(power);
  }
}
}
}
