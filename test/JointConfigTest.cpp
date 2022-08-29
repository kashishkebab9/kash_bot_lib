#include "Test.h"
#include "../include/Joint.h"
#include "../include/JointConfig.h"



int main() {

  test("JointCounterTest");
  JointConfiguration jc_1;
  Joint head("head");
  jc_1.add_node(head);
  jc_1.set_name("jc_1_test");

  if (jc_1.NumJointsToTail() != 1) {
    std::cout << RED << "NumJointsToTail returned: " << jc_1.NumJointsToTail() << std::endl;
    std::cout << "When it should've returned 1!" << RESET << std::endl;
    return 1;
  }
  

  Joint joint1("index_1");
  jc_1.add_node(joint1);

  if (jc_1.NumJointsToTail() != 2) {
    std::cout << "NumJointsToTail returned: " << jc_1.NumJointsToTail() << std::endl;
    std::cout << "When it should've returned 2!" << std::endl;
    return 1;
  }

  test_succeeded("JointCounterTest");


  test("JointFwdKinTest");
  Joint joint_test_2_0("test2_0");
  joint_test_2_0.SetTranslation(1, 0, 0);

  Joint joint_test_2_1("test2_1");
  joint_test_2_1.SetTranslation(0, 0, -5);

  JointConfiguration test2;
  test2.add_node(joint_test_2_0);
  test2.add_node(joint_test_2_1);
  
  Eigen::Transform<double, 3, Eigen::Affine> input;
  input = Eigen::Matrix4d::Identity();
  Eigen::Transform<double, 3, Eigen::Affine> ans = test2.SolveFwdKin(input);

  Eigen::Matrix4d test2_soln;
  test2_soln << 1, 0, 0, 1,
                0, 1, 0, 0,
                0, 0, 1, -5,
                0, 0, 0, 1;

  if (ans.matrix() != test2_soln) {
    test_failed("JointFwdKinTest");
    return 1;

  }
  test_succeeded("JointFwdKinTest");


  return 0;
}
