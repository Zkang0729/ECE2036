/*
Author: Zixuan Kang 
Date Last Modified: 02-25-2020
Organization: ECE2036 Class
Description: Define the Robot class including its private and public variables and functions.
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

using namespace std;

#define FORWARD 1
#define LEFT 2
#define RIGHT 3
#define BACKWARD 4

class Robot
{
private:
  int xPosition;
  int yPosition;

public:
  vector< vector<int> > map;
  Robot();
  Robot(int xPosition, int yPosition);
  void setXPosition(int xPosition);
  void setYPosition(int yPosition);
  int getXPosition() const;
  int getYPosition() const;
  void moveForward();
  void moveLeft();
  void moveRight();
  void moveBackward();
  void inputMove();
  void displayPosition() const;
  void printHistory() const;
};

#endif