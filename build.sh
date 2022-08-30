#!/bin/bash

time

RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
NC=$'\e[1;0m'
CYAN=$'\e[1;36m'
PURPLE=$'\e[1;35m'

# Testing:
function test() {
  echo "Running Test on Binary: $1";
  ./$1;

  if  [ $? -eq 0 ] 
  then
    echo "Testing on $1 $GREEN Suceeded!$NC"
  else
    echo "Testing on $1 $RED Failed!$NC"
  fi
  
  echo "======================================================"

}

echo "======================================================"
echo "$CYAN Building JointConfigTest... $NC"
g++ -std=c++11 test/JointConfigTest.cpp src/Joint.cpp -I include/ -o joint_config_test
test joint_config_test

echo "$CYAN Building JointTest... $NC"
g++ -std=c++11 test/JointTest.cpp src/Joint.cpp -I include/ -o joint_test
test joint_test

echo "$CYAN Building RobotTest... $NC"
g++ -std=c++11 test/RobotTest.cpp src/Robot.cpp src/Joint.cpp -I include/ -o robot_test
test robot_test

echo "$GREEN Done $PURPLE"
