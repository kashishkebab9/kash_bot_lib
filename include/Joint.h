#pragma once 

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <Eigen/Dense>

class Joint {
  private:
    Eigen::Matrix4d t_prev_body_this_joint;
    //q is the current angle for the joint, will initialize at 0, should make this configurable
    std::string name;
    double q_rad;
    // Perhaps Matrix4d is not the best way to make this happen
    // There are 3-4 components that need to be outlined to define a Joint
    // Rotation Z: this will be incumbent on the input of the system (Rotation)
    // Translation: this will require the user to supply an x, y, z value, in the form of an Eigen::Vectord
    // Rotation around X/Y: This will require the user to supply an angle alongside axis of rotation
    //
    // I will come back to these definitions once I understand how the fuck Eigen works
    
    struct KinematicChain {
      Eigen::AngleAxis<double> z_rotation;
      Eigen::Translation3d translation;
      Eigen::AngleAxisd x_rotation;
      Eigen::AngleAxisd y_rotation;
    };
    KinematicChain chain;

  public:
    //TODO: Need to determine other methods of construction
    Joint(std::string joint_name);


    void SetTranslation(Eigen::Vector3d translation_from_prev_component);
    void SetTranslation(double x, double y, double z);
    void SetRotationX(double angle_in_rad);
    void SetRotationY(double angle_in_rad);

    void InitializeJoint(Eigen::Vector3d translation_from_prev_component);
    void InitializeJoint(Eigen::Vector3d translation_from_prev_component, Eigen::AngleAxisd aa_from_prev_component);

    


};
