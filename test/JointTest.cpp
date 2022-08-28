#include <iostream>

#include "../include/Joint.h"

int main() {
  //Actually Test!

  Eigen::Vector4d position;
  position << 0, 0, 0, 0;
  Joint joint("right_arm");

  
  joint.SetTranslation(1, 1, 1);
  joint.SetRotationX(M_PI/2);
  joint.SetJointAngleRad(M_PI/8);
  joint.GetCurrentRelativePosition();
  


  





  return 0;
}
