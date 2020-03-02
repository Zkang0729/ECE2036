/*
Author: Zixuan Kang 
Date Last Modified: 02-25-2020
Organization: ECE2036 Class
Description: Define the RobotSwarm class including its public variables and functions.
*/

#ifndef ROBOTSWARM_H
#define ROBOTSWARM_H

#include "robot.h"
#include <vector>

using namespace std;

class RobotSwarm
{
public:
  vector<Robot> robots;
  vector< vector<int> > robotMap;
  RobotSwarm(int number);
  void moveSwarm();
  void printHistory();
};

#endif