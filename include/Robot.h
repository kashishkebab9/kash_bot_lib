#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <Eigen/Dense>
#include "JointConfig.h"
#include "Joint.h"
#include "Base.h"
#include "EndEffector.h"

class Robot{
  private:

    Eigen::Translation3d w_b_position;
    Eigen::AngleAxisd w_b_rot_x;
    Eigen::AngleAxisd w_b_rot_y;
    Eigen::AngleAxisd w_b_rot_z;
    int number_of_joint_configs;
    std::string robot_name;
    std::vector<JointConfiguration> joint_config_accessor;

  public:

    Robot(std::string name_);
    
    JointConfiguration joint_config;

    void SetTranslation(Eigen::Vector3d w_b_translation);
    void SetTranslation(double x, double y, double z);
    void SetRotationX(double angle_in_rad);
    void SetRotationY(double angle_in_rad);
    void SetRotationZ(double angle_in_rad);
    void AddJointConfiguration(JointConfiguration& joint_config);
    
    // Robot Joint configuration will be a linked list, each node will be a joint. This will allow use to implement a node and analyze whether or not it can fit in the current configuration or not
    void AddJoint(Joint joint, JointConfiguration joint_config);
    Eigen::Transform<double, 3, Eigen::Affine> SolveFwdKin(JointConfiguration joint_config);
    Eigen::Transform<double, 3, Eigen::Affine> SolveFwdKinAll();




};
