#include "SurCake.h"

namespace team254 {
namespace surcake {

static const double GRABBER_EXTEND_TIME = 1.0;

static const double GRABBER_EXTEND_DIR = 1.0;
static const double GRABBER_RETRACT_DIR = -1.0;

SurCake::SurCake(std::vector<std::shared_ptr<ReversingTalon>> talons)
    : talons_(talons) {
}

void SurCake::initForAuto() {
  autoStartTime_ = Timer::GetFPGATimestamp();
}

void SurCake::updateForAuto() {
  double matchTime = Timer::GetFPGATimestamp() - autoStartTime_;
  setTalons(
      talons_,
      (matchTime < GRABBER_EXTEND_TIME) ? GRABBER_EXTEND_DIR : 0);
}

void SurCake::updateForTeleop(GrabberDirection grabberDirection) {
  double power;
  switch (grabberDirection) {
    case EXTEND:
      power = GRABBER_EXTEND_DIR;
      break;
    case RETRACT:
      power = GRABBER_RETRACT_DIR;
      break;
    default:
      power = 0;
  }
  setTalons(talons_, power);
}
}
}
