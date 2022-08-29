#pragma once

#include <iostream>
#include <string>
#include "Joint.h"
#include <Eigen/Dense>

// The Joint Configuration of a Robot will be a linked list containing each joint in the kinematic chain


struct JointNode {
  Joint joint;
  JointNode* next_joint;
  
};


class JointConfiguration {
  private:
    JointNode *head, *tail;
    int num_of_joints;

  public:

    std::string name;
    JointConfiguration() {
      num_of_joints = 0;
      head = NULL;
      tail = NULL;
    }

    void add_node(Joint joint_to_add) {
      JointNode *tmp = new JointNode;
      tmp->joint =joint_to_add;
      tmp->next_joint = NULL;

      if(head == NULL) {

        head = tmp;
        tail = tmp;

      } else {

        tail->next_joint = tmp;
        tail = tail->next_joint;
      }
      num_of_joints++;

    }

    void set_name(std::string name_) {
      name = name_;
    }

    int NumJointsToTail() {

      return num_of_joints;

   }

    Eigen::Transform<double, 3, Eigen::Affine> SolveFwdKin(Eigen::Transform<double, 3, Eigen::Affine> &chain) {
      if (this->head != NULL) {
        JointNode * iter;
        iter = head;

        do {

          chain = iter->joint.FwdKinChainCalc(chain);
          iter = iter->next_joint;

        } while(iter->next_joint != NULL);
          
      }
      

      return chain;

      
    }



};
