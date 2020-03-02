/*
Author: Zixuan Kang 
Date Last Modified: 02-25-2020
Organization: ECE2036 Class
Description: Implment the Robot class, defineing how each function works.
*/

#include "robot.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Robot::Robot() : xPosition{0}, yPosition{0}
{
  Robot::map = vector< vector<int> >(32, vector<int>(32, 0));
  Robot::map[xPosition][yPosition]++;
}

Robot::Robot(int xPosition = 0, int yPosition = 0) : xPosition{xPosition}, yPosition{yPosition}
{
  Robot::map = vector< vector<int> >(32, vector<int>(32, 0));
  Robot::map[xPosition][yPosition]++;
}

void Robot::setXPosition(int xPosition) { Robot::xPosition = xPosition; };

void Robot::setYPosition(int yPosition) { Robot::yPosition = yPosition; };

int Robot::getXPosition() const { return Robot::xPosition; };

int Robot::getYPosition() const { return Robot::yPosition; };

void Robot::moveForward()
{
  Robot::setYPosition(Robot::getYPosition() - 1);
  Robot::map[Robot::getXPosition()][Robot::getYPosition()]++;
}

void Robot::moveLeft()
{
  Robot::setXPosition(Robot::getXPosition() - 1);
  Robot::map[Robot::getXPosition()][Robot::getYPosition()]++;
}

void Robot::moveRight()
{
  Robot::setXPosition(Robot::getXPosition() + 1);
  Robot::map[Robot::getXPosition()][Robot::getYPosition()]++;
}

void Robot::moveBackward()
{
  Robot::setYPosition(Robot::getYPosition() + 1);
  Robot::map[Robot::getXPosition()][Robot::getYPosition()]++;
}

void Robot::inputMove()
{
  int direction;
  cout << "Please input a direction to move:\n(1) Forward (2) Left (3) Right (4) Backward";
  cin >> direction;
  switch (direction)
  {
  case FORWARD:
    Robot::moveForward();
    break;
  case LEFT:
    Robot::moveLeft();
    break;
  case RIGHT:
    Robot::moveRight();
    break;
  case BACKWARD:
    Robot::moveBackward();
    break;
  default:
    break;
  }
}

void Robot::displayPosition() const
{
  cout << "The robot is at " << Robot::getXPosition() << ", " << Robot::getYPosition() << endl;
}

void Robot::printHistory() const
{
  ofstream history("history.txt", fstream::app);
  for (int i = 0; i < 32; i++)
  {
    for (int j = 0; j < 32; j++)
    {
      history << Robot::map[i][j] << " ";
      if (j == 31)
      {
        history << "\n";
      }
    }
  }
  history << endl;
  history.close();
}
