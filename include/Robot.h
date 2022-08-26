#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <Eigen/Dense>
#include "JointConfig.h"
#include "Joint.h"
#include "Base.h"
#include "EndEffector.h"

class Robot{
  private:

    Eigen::Vector4d current_position;

  public:
    std::vector<JointConfiguration> joint_config_accessor;

    Robot(std::string name_);
    
    std::string robot_name;
    JointConfiguration joint_config;
    Base robot_base;
    int number_of_joint_configs;

    void SetBaseTransform(Eigen::Matrix4d t_world_base);
    void AddJointConfiguration(Eigen::Matrix4d base_to_first_joint, std::string joint_config_name);
    
    // Robot Joint configuration will be a linked list, each node will be a joint. This will allow use to implement a node and analyze whether or not it can fit in the current configuration or not
    void AddJoint(Joint joint, JointConfiguration joint_config);




  








};
