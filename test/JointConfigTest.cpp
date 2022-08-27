#include <iostream>
#include <string>
#include "../include/Joint.h"
#include "../include/JointConfig.h"

int main() {

  JointConfiguration jc_1;
  Joint head;
  jc_1.add_node(head);
  jc_1.set_name("jc_1_test");
  jc_1.NumJointsToTail();

  







  return 0;
}
