/*
Author: Zixuan Kang 
Date Last Modified: 02-25-2020
Organization: ECE2036 Class
Description: This is where the main file is. It first asks the user to input how many robots
the Robot Swarm should control and let then let the user input how many times they wish the Robots to move.
*/

#include "robot.h"
#include "robotSwarm.h"
#include <iostream>

using namespace std;

int main()
{
  int number, times;
  cout << "Please input the number of robots you want to control: " << endl;
  cin >> number;
  RobotSwarm mySwarm = RobotSwarm(number);
  cout << "Please input the number of times you want to move the robots: " << endl;
  cin >> times;
  for (int i = 0; i < times; i++)
  {
    mySwarm.moveSwarm();
  }
  mySwarm.printHistory();
  return 0;
}