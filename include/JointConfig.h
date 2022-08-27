#include <iostream>
#include <string>
#include "Joint.h"

// The Joint Configuration of a Robot will be a linked list containing each joint in the kinematic chain


struct JointNode {
  Joint joint;
  JointNode* next_joint;
  
};


class JointConfiguration {
  private:
    JointNode *head, *tail;

  public:

    std::string name;
    JointConfiguration() {
      head = NULL;
      tail = NULL;
    }

    void add_node(Joint joint_to_add) {
      JointNode *tmp = new JointNode;
      tmp->joint = joint_to_add;
      tmp->next_joint = NULL;

      if(head == NULL) {

        head = tmp;
        tail = tmp;

      } else {

        tail->next_joint = tmp;
        tail = tail->next_joint;
      }

    }

    void set_name(std::string name_) {
      name = name_;
    }

    int NumJointsToTail() {
      JointNode *tmp = head;

      int counter = 1;

      while(tmp != this->tail) {
        tmp = tmp->next_joint;
        counter++;
      }
      std::cout << "There are " << counter << " Joints in this kinematic chain" << std::endl;
      return counter;

    }



};
