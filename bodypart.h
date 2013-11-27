#ifndef BODYPART_H_
#define BODYPART_H_

#include <iostream>
#include <vector>
#include "rectangle.h"
#include "point.h"

class BodyPart
{
  public:
    BodyPart(std::string name, Rectangle collisionBox,
             std::vector<Point> framePositions);
    std::string name;
    Rectangle collisionBox;
    std::vector<Point> framePositions;
    int currentFrame;
    int totalFrames;
    int time_since_last_update;
    void update(int time_delta);
    int getWorldX(int parent_x);
    int getWorldY(int parent_y);
    Point getWorldPosition(int parent_x, int parent_y);
    Point getWorldPosition(Point parent_position);
    Rectangle getWorldCollisionBox(int parent_x, int parent_y);
    Rectangle getWorldCollisionBox(Point parent_position);
};

#endif
