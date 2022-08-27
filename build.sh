#!/bin/bash

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

}

echo "Building JointConfigTest"
g++ test/JointConfigTest.cpp src/Joint.cpp -I include/ -o joint_config
test joint_config


echo "$GREEN Done"
