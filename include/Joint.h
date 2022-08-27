#pragma once 

#include <iostream>
#include <vector>
#include <string>

#include <Eigen/Dense>

class Joint {
  private:
    Eigen::Matrix4d t_prev_body_this_joint;

  public:
    Joint();
    Joint(Eigen::Matrix4d t_prev_body_this_joint);

    void SetTransform(Eigen::Matrix4d transform) {
      this->t_prev_body_this_joint = transform;

    }


    


};
