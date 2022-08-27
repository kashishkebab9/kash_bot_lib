#!/bin/bash

# Testing:
function test() {
  echo "Running Test on Binary: $1";
  ./$1;

  if  [$? -eq 0] 
  then
    echo "$1 Suceeded!"
  else
    echo "$1 Failed!"
  fi

}

echo "Building JointConfigTest"
g++ test/JointConfigTest.cpp src/Joint.cpp -I include/ -o joint_config
test joint_config


echo "Done"
