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
    void SetTransform(Eigen::Matrix4d transform);


    


};
