#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include "../include/Robot.h"
#include "../include/JointConfig.h"
#include "../include/Joint.h"
#include "Test.h"
#include <Eigen/Dense>


int main() {
  double arm_l1 = 1;
  double arm_l2 = 1;
  double arm_l3 = .25;

  test("SiamangRobotTest");
  Robot siamang("Siamang");
  siamang.SetTranslation(0, 5, 0);
  siamang.SetRotationX(-M_PI_2);
  
  Joint joint_ra_s("Right_Shoulder");
  joint_ra_s.SetTranslation(0, 0, 1);

  Joint joint_ra_e("Right_Elbow");
  joint_ra_e.SetTranslation(0, arm_l1, 0);

  Joint joint_ra_f("Right_Forearm");
  joint_ra_f.SetTranslation(0, arm_l2, 0);
  joint_ra_f.SetRotationX(-M_PI_2);

  Joint joint_ra_ee("Right_EndEffector");
  joint_ra_ee.SetTranslation(0, 0, arm_l3);
  joint_ra_ee.SetRotationX(M_PI_2);

  JointConfiguration right_arm("Right_Arm");
  right_arm.add_node(joint_ra_s);
  right_arm.add_node(joint_ra_e);
  right_arm.add_node(joint_ra_f);
  right_arm.add_node(joint_ra_ee);

  siamang.AddJointConfiguration(right_arm);
  siamang.SolveFwdKin(right_arm);



  



  




  return 0;
}
