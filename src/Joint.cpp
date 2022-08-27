#include "../include/Joint.h"


Joint::Joint()
  : t_prev_body_this_joint(Eigen::Matrix4d::Identity()) {

  std::cout << "Creating Joint with Identity Matrix Transform to the World" << std::endl;

}

Joint::Joint(Eigen::Matrix4d transform)
  :t_prev_body_this_joint(transform) {
    std::cout <<  "Creating Joint with Transform " << this->t_prev_body_this_joint << " from the World" << std::endl; 

  }


