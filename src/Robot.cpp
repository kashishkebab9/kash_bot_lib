#include "../include/Robot.h"
//This is a test

Robot::Robot(std::string name_) {
  //By default the base of the robot will be initiliazed to be in the same frame as the world itself
  this->w_b_position = Eigen::Translation3d(0, 0, 0);
  this->w_b_rot_x = Eigen::Matrix3d::Identity(); 
  this->w_b_rot_y = Eigen::Matrix3d::Identity(); 
  this->w_b_rot_z = Eigen::Matrix3d::Identity(); 
  this->robot_name = name_;
  this->number_of_joint_configs = 0;
  

}

void Robot::SetTranslation(Eigen::Vector3d trans_world_robot) {
  std::cout << "Setting translation for Robot " << this->robot_name << " to: " << trans_world_robot << std::endl;
  Eigen::Translation3d copy(trans_world_robot);
  this->w_b_position = copy;

}

void Robot::SetTranslation(double x, double y, double z) {
  std::cout << "Setting translation for Robot " << this->robot_name << " to: " << x << ", " << y << ", " << z << std::endl;
  Eigen::Translation3d copy(x, y, z);
  this->w_b_position = copy;
}

void Robot::SetRotationX(double angle_in_rad) {
  std::cout << "Rotating the X component of Robot " << this->robot_name << "'s coordinate frame by " << angle_in_rad << " radians" << std::endl;  

  Eigen::AngleAxisd aa(angle_in_rad, Eigen::Vector3d::UnitX());
  this->w_b_rot_x = aa;
}

void Robot::SetRotationY(double angle_in_rad) {
  std::cout << "Rotating the Y component of Robot " << this->robot_name << "'s coordinate frame by " << angle_in_rad << " radians" << std::endl;  

  Eigen::AngleAxisd aa(angle_in_rad, Eigen::Vector3d::UnitY());
  this->w_b_rot_y = aa;
}

void Robot::SetRotationZ(double angle_in_rad) {
  std::cout << "Rotating the Z component of Robot " << this->robot_name << "'s coordinate frame by " << angle_in_rad << " radians" << std::endl;  

  Eigen::AngleAxisd aa(angle_in_rad, Eigen::Vector3d::UnitZ());
  this->w_b_rot_z = aa;
}

void Robot::AddJointConfiguration(JointConfiguration &joint_config) {
  std::cout << "Adding Joint Configuration " << joint_config.GetName() <<  " to Base of Robot " << this->robot_name << std::endl;

  this->joint_config_accessor.push_back(joint_config);
  this->number_of_joint_configs++;

}

void AddJoint(Joint joint, JointConfiguration joint_config) {
  std::cout << "Adding Joint to Joint Configuration " << joint_config.GetName() << std::endl;
  joint_config.add_node(joint);
}

Eigen::Transform<double, 3, Eigen::Affine> Robot::SolveFwdKin(const JointConfiguration joint_config) {

  auto jc = std::find(this->joint_config_accessor.begin(), this->joint_config_accessor.end(), joint_config);

  Eigen::Transform<double, 3, Eigen::Affine> t_w_b;
  t_w_b = this->w_b_position * this->w_b_rot_x * this->w_b_rot_y * this->w_b_rot_z;
  std::cout << "t_w_b: "<< std::endl <<t_w_b.matrix() << std::endl;
  return jc->SolveFwdKin(t_w_b);

}








