#include <iostream>
#include <string>
#include "../include/Joint.h"
#include "../include/JointConfig.h"

int main() {

  JointConfiguration jc_1;
  Joint head;
  jc_1.add_node(head);
  jc_1.set_name("jc_1_test");

  if (jc_1.NumJointsToTail() != 1) {
    std::cout << "NumJointsToTail returned: " << jc_1.NumJointsToTail() << std::endl;
    std::cout << "When it should've returned 1!" << std::endl;
    return 1;
  }

  Joint joint1;
  jc_1.add_node(joint1);

  if (jc_1.NumJointsToTail() != 2) {
    std::cout << "NumJointsToTail returned: " << jc_1.NumJointsToTail() << std::endl;
    std::cout << "When it should've returned 2!" << std::endl;
    return 1;
  }









  







  return 0;
}
