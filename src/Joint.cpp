#include "../include/Joint.h"


Joint::Joint(std::string joint_name)
:  name(joint_name),
   q_rad(0.0){

  Eigen::AngleAxis<double> rot_z(q_rad, Eigen::Vector3d::UnitZ());
  this->chain.z_rotation = rot_z;
  // values for a joints x and y rotation will be default set to the Identity matrix
  // It will be incumbent upon the user to SetRotation[X|Y]
  this->chain.x_rotation = Eigen::Matrix3d::Identity();
  this->chain.y_rotation = Eigen::Matrix3d::Identity();
  std::cout <<  "Joint " << this->name << " has been created"<< std::endl; 
}



void Joint::SetTranslation(Eigen::Vector3d translation_from_prev_component) {
  std::cout << "Setting Translation for Joint" << this->name <<  " to " << translation_from_prev_component;
  Eigen::Translation3d copy(translation_from_prev_component);
  this->chain.translation = copy;
}

void Joint::SetTranslation(double x, double y, double z) {
  std::cout << "Setting Translation for Joint " << this->name << " to " << x << ", " << y << ", " << z << std::endl;
  Eigen::Translation3d copy(x, y, z);
  this->chain.translation = copy;
}

void Joint::SetRotationX(double angle_in_rad) {
  std::cout << "Rotating the X component of Joint " << this->name << "'s coordinate frame by " << angle_in_rad <<  " radians" << std::endl;
  Eigen::AngleAxisd aa(angle_in_rad, Eigen::Vector3d::UnitX());
  this->chain.x_rotation = aa;
}

void Joint::SetRotationY(double angle_in_rad) {
  std::cout << "Rotating the Y component of Joint " << this->name << "'s coordinate frame by " << angle_in_rad <<  " radians" << std::endl;
  Eigen::AngleAxisd aa(angle_in_rad, Eigen::Vector3d::UnitY());
  this->chain.y_rotation = aa;
}

void Joint::InitializeJoint(Eigen::Vector3d translation_from_prev_component) {
  std::cout << "Initializing Joint" << this->name <<  " with the following translation: " << translation_from_prev_component << std::endl;
  Eigen::Translation3d copy(translation_from_prev_component);
  this->chain.translation = copy;
}

void Joint::InitializeJoint(Eigen::Vector3d translation_from_prev_component, Eigen::AngleAxisd aa_from_prev_component) {
  std::cout << "Initializing Joint" << this->name <<  " with the following translation: " << translation_from_prev_component << std::endl;
  std::cout << "and with a rotation of " << aa_from_prev_component.angle() << " rads about the " << aa_from_prev_component.axis() << " axis"; 

  Eigen::Translation3d copy(translation_from_prev_component);
  this->chain.translation = copy;
  this->chain.y_rotation = aa_from_prev_component;

}




