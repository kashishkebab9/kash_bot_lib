#include "../include/Robot.h"

Robot::Robot(std::string name_) {
  //By default the base of the robot will be initiliazed to be in the same frame as the world itself
  this->robot_name = name_;
  this->number_of_joint_configs = 0;
  

}

void Robot::SetBaseTransform(Eigen::Matrix4d world_to_base) {
  std::cout << "Transforming Base of Robot " 
    << this->robot_name 
    <<  " by: " 
    << world_to_base 
    << std::endl;

  robot_base.transform_world_to_base = world_to_base;

}

void Robot::AddJointConfiguration(JointConfiguration joint_config) {
  std::cout << "Adding Joint Configuration " << joint_config.name <<  " to Base of Robot " << this->robot_name << std::endl;

  this->joint_config_accessor.push_back(joint_config);
  this->number_of_joint_configs++;

}

void AddJoint(Joint joint, JointConfiguration joint_config) {
  std::cout << "Adding Joint to Joint Configuration " << joint_config.name << std::endl;
  joint_config.add_node(joint);
}








