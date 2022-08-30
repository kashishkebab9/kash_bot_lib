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
    std::string name;

  public:

    JointConfiguration() {
      num_of_joints = 0;
      head = NULL;
      tail = NULL;
    }

    JointConfiguration(std::string jc_name) {
      num_of_joints = 0;
      head = NULL;
      tail = NULL;
      this->name = jc_name;
    }

    bool operator==(const JointConfiguration &other) const {
      return this->name == other.name;
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
  
    std::string GetName() {
      return this->name;
    }
    void SetName(std::string name_) {
      this->name = name_;
    }

    int NumJointsToTail() {

      return num_of_joints;

   }

    Eigen::Transform<double, 3, Eigen::Affine> SolveFwdKin(Eigen::Transform<double, 3, Eigen::Affine>& chain) {
      Eigen::Transform<double, 3, Eigen::Affine> output;
      if (this->head != NULL) {
        output = chain;
        JointNode * iter;
        iter = head;
          
        while(iter != NULL) {

          output = iter->joint.FwdKinChainCalc(output);
          iter = iter->next_joint;

        }
        std::cout  << "FwdKin for Joint Configuration " << this->name <<":  " << std::endl << output.matrix() << std::endl;
      }

      return output;

      
    }



};
