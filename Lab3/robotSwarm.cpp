/*
Author: Zixuan Kang 
Date Last Modified: 02-25-2020
Organization: ECE2036 Class
Description: Implment the RobotSwarm class, defineing how each function works.
*/

#include "robotSwarm.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

RobotSwarm::RobotSwarm(int number)
{
  RobotSwarm::robotMap = vector<vector<int>>(32, vector<int>(32, 0));
  RobotSwarm::robots = vector<Robot>(number);
  for (int i = 0; i < number; i++)
  {
    int xPosition, yPosition;
    do
    {
      srand(time(NULL));
      xPosition = rand() % 32;
      yPosition = rand() % 32;
    } while (RobotSwarm::robotMap[xPosition][yPosition]);
    RobotSwarm::robots[i] = Robot(xPosition, yPosition);
    RobotSwarm::robotMap[xPosition][yPosition] = 1;
  }
}

void RobotSwarm::moveSwarm()
{
  int times, direction;
  for (int i = 0; i < RobotSwarm::robots.size(); i++)
  {
    for (times = 5; times > 0; times--)
    {
      srand(time(NULL));
      direction = rand() % 4 + 1;
      switch (direction)
      {
      case FORWARD:
        if (RobotSwarm::robots[i].getYPosition() - 1 < 0 || RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition()][RobotSwarm::robots[i].getYPosition() - 1])
          continue;
        RobotSwarm::robots[i].moveForward();
        RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition()][RobotSwarm::robots[i].getYPosition() + 1] = 0;
        break;
      case LEFT:
        if (RobotSwarm::robots[i].getXPosition() - 1 < 0 || RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition() - 1][RobotSwarm::robots[i].getYPosition()])
          continue;
        RobotSwarm::robots[i].moveLeft();
        RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition() + 1][RobotSwarm::robots[i].getYPosition()] = 0;
        break;
      case RIGHT:
        if (RobotSwarm::robots[i].getXPosition() + 1 > 31 || RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition() + 1][RobotSwarm::robots[i].getYPosition()])
          continue;
        RobotSwarm::robots[i].moveRight();
        RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition() - 1][RobotSwarm::robots[i].getYPosition()] = 0;
        break;
      case BACKWARD:
        if (RobotSwarm::robots[i].getYPosition() + 1 > 31 || RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition()][RobotSwarm::robots[i].getYPosition() + 1])
          continue;
        RobotSwarm::robots[i].moveBackward();
        RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition()][RobotSwarm::robots[i].getYPosition() - 1] = 0;
        break;
      default:
        break;
      }
      RobotSwarm::robotMap[RobotSwarm::robots[i].getXPosition()][RobotSwarm::robots[i].getYPosition()] = 1;
      break;
    }
  }
}

void RobotSwarm::printHistory()
{
  for (int i = 0; i < RobotSwarm::robots.size(); i++)
  {
    RobotSwarm::robots[i].printHistory();
  }
}
