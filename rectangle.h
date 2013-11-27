#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "point.h"

class Rectangle
{
  public:
    Rectangle(int x, int y, int width, int height);
    int x, y;
    int width, height;
    void setPosition(int x, int y);
    void setPosition(Point position);
};

#endif
