#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>
#include "Joint.h"

class Revolute : Joint {
  private:

  public:

    Revolute(Eigen::Matrix4d transformation_from_previous_node);
    void AddTransformFromAxis(Eigen::Matrix4d transform, Axis axis);



};

