#include "Robot.h"

namespace team254 {
namespace surcake {

static const int JOYSTICK_X_AXIS = 0;
static const int JOYSTICK_Y_AXIS = 1;

static const int GRABBER_IN_BUTTON = 0;
static const int GRABBER_OUT_BUTTON = 1;

using Polarity = ReversingTalon::Polarity;

Robot::Robot()
    : joystick_(1),
      leftDriveTalons_({std::make_shared<ReversingTalon>(0, Polarity::NORMAL)}),
      rightDriveTalons_(
          {std::make_shared<ReversingTalon>(1, Polarity::INVERTED)}),
      surCake_({std::make_shared<ReversingTalon>(2, Polarity::NORMAL),
                std::make_shared<ReversingTalon>(3, Polarity::INVERTED)}) {
}

void Robot::AutonomousInit() {
  surCake_.autoInit();
}

void Robot::AutonomousPeriodic() {
  setTalons(leftDriveTalons_, 0);
  setTalons(rightDriveTalons_, 0);
  surCake_.updateForAuto();
}

void Robot::TeleopPeriodic() {
  // grabber control
  SurCake::GrabberDirection dir = SurCake::GrabberDirection::NEUTRAL;
  if (joystick_.GetRawButton(GRABBER_IN_BUTTON)) {
    dir = SurCake::GrabberDirection::RETRACT;
  } else if (joystick_.GetRawButton(GRABBER_OUT_BUTTON)) {
    dir = SurCake::GrabberDirection::EXTEND;
  }
  surCake_.updateForTeleop(dir);

  // arcade drive calculation
  double x = joystick_.GetRawAxis(JOYSTICK_X_AXIS);
  double y = joystick_.GetRawAxis(JOYSTICK_Y_AXIS);
  setTalons(leftDriveTalons_, y + x);
  setTalons(rightDriveTalons_, y - x);
}


} // namespace surcake
} // namespace team254

START_ROBOT_CLASS(team254::surcake::Robot);
