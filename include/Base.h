#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>

class Base {
  private:

  public:
    //Returns Base to be in line with World
    Base();
    //Returns Base to be transformed w/ respect to the world
    Base(Eigen::Matrix4d transform_world_to_base_);
    Eigen::Matrix4d transform_world_to_base;





};
