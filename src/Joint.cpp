#include "../include/Joint.h"

Joint::Joint()
:  name("joint_no_name"),
   q_rad(0.0){

  Eigen::AngleAxis<double> rot_z(q_rad, Eigen::Vector3d::UnitZ());
  this->chain.z_rotation = rot_z;
  Eigen::Translation3d zero_trans(0, 0, 0);
  this->chain.translation = zero_trans; 
  this->chain.x_rotation = Eigen::Matrix3d::Identity();
  this->chain.y_rotation = Eigen::Matrix3d::Identity();
  std::cout <<  "Joint " << this->name << " has been created"<< std::endl; 
}

Joint::Joint(std::string joint_name)
:  name(joint_name),
   q_rad(0.0){

  Eigen::AngleAxis<double> rot_z(q_rad, Eigen::Vector3d::UnitZ());
  this->chain.z_rotation = rot_z;
  Eigen::Translation3d zero_trans(0, 0, 0);
  this->chain.translation = zero_trans; 
  this->chain.x_rotation = Eigen::Matrix3d::Identity();
  this->chain.y_rotation = Eigen::Matrix3d::Identity();
  std::cout <<  "Joint " << this->name << " has been created"<< std::endl; 
}

Joint::Joint(const Joint &source)
:  name(source.name + "_copy"),
   q_rad(source.q_rad),
   chain(source.chain) {

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
  std::cout << "and with the following rotation: " << aa_from_prev_component.angle() << " radians about the " << aa_from_prev_component.axis() << " axis" << std::endl; 

  Eigen::Translation3d copy(translation_from_prev_component);
  this->chain.translation = copy;
  this->chain.y_rotation = aa_from_prev_component;

}

void Joint::SetJointAngleRad(double angle_in_rad) {
  std::cout << "Setting " << this->name << "'s Joint Angle to " << angle_in_rad << " radians or " << angle_in_rad / (M_PI/180) << " degrees" << std::endl; 

  this->q_rad = angle_in_rad;
  this->UpdateZRot();
}

void Joint::SetJointAngleDeg(double angle_in_deg) {
  std::cout << "Setting " << this->name << "'s Joint Angle to " << angle_in_deg << " degs or " << angle_in_deg * (M_PI/180) << " radians" << std::endl; 
  this->q_rad = angle_in_deg * (M_PI/ 180);
  this->UpdateZRot();
}

double Joint::GetCurrentAngleRad() {
  return this->q_rad;
}

double Joint::GetCurrentAngleDeg() {
  return this->q_rad / (M_PI/180);
}

Eigen::Transform<double, 3, Eigen::Affine> Joint::FwdKinChainCalc(Eigen::Transform<double, 3, Eigen::Affine> input) {
  
  Eigen::Transform<double, 3, Eigen::Affine> output;

  output =  this->chain.translation * this->chain.x_rotation * this->chain.y_rotation * this->chain.z_rotation;
  output = input * output;
  return output;
}

void Joint::UpdateZRot() {
  this->chain.z_rotation = Eigen::AngleAxisd(this->q_rad, Eigen::Vector3d::UnitZ());
}


