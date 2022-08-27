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

void Robot::AddJointConfiguration(Eigen::Matrix4d base_to_first_joint, std::string joint_config_name) {
  std::cout << "Adding Joint Configuration to Base of Robot " << this->robot_name << std::endl;
  std::cout << "First Joint of this chain will be transformed from the base by " << base_to_first_joint << std::endl;

  JointConfiguration new_config;
  Joint joint_leading_new_config;

  joint_leading_new_config.SetTransform(base_to_first_joint);
  new_config.add_node(joint_leading_new_config);
  new_config.set_name(joint_config_name);

  this->joint_config_accessor.push_back(new_config);
  this->number_of_joint_configs++;

}

void AddJoint(Joint joint, JointConfiguration joint_config) {
  std::cout << "Adding Joint to Joint Configuration " << joint_config.name << std::endl;
  joint_config.add_node(joint);
}




