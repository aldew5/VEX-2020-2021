/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Alec Dewulf                                               */
/*    Created:      Thu Nov 05 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <vex_triport.h>

using namespace vex;
using namespace std;

#define rf rightFront
#define rb rightBack
#define lf leftFront
#define lb leftBack


//creating motors and setting their ports (port 4 gave an error for some reason, so using 5 instead)
vex::motor rf = vex::motor(vex::PORT1);
vex::motor rb = vex::motor(vex::PORT2);
vex::motor lf = vex::motor(vex::PORT3);
vex::motor lb = vex::motor(vex::PORT5);


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Brain.Screen.print("Hello World\n");
  Brain.Screen.print("The Clank boys are in business");

  //left motors need to be revesed as they are attached differently on the robot
  rf.setReversed(true); 
  rb.setReversed(true);

  double speed = 70;

  vex::wait(2, timeUnits::sec);

  //spin wheels for 1 second

  rf.spin(vex::directionType::fwd, speed, vex::percentUnits::pct);
  lf.spin(vex::directionType::fwd, speed, vex::percentUnits::pct);
  lb.spin(vex::directionType::fwd, speed, vex::percentUnits::pct);
  rb.spin(vex::directionType::fwd, speed, vex::percentUnits::pct);

  vex::wait(2, timeUnits::sec);
  
  rf.stop();
  lf.stop();
  lb.stop();
  rb.stop();
}
