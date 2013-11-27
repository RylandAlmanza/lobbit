#ifndef BEING_H_
#define BEING_H_

#include "bodypart.h"

class Being
{
  public:
    Being(int x, int y);
    int x, y;
    int time_since_last_update;
    std::vector<BodyPart> bodyParts;
    void update(int time_delta);
    void addPart(BodyPart part);
    std::vector<Rectangle> getPartWorldBoxes();
};

#endif
