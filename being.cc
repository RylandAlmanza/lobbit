#include "being.h"

Being::Being(int x, int y) {
    this->x = x;
    this->y = y;
    time_since_last_update = 0;
    std::vector<BodyPart> bodyParts();
}

void Being::update(int time_delta) {
    time_since_last_update += time_delta;
    while (time_since_last_update >= 100) {
        x += 2;
        time_since_last_update -= 100;
    }
    for (int i = 0; i < bodyParts.size(); i++) {
        bodyParts.at(i).update(time_delta);
    }
}

void Being::addPart(BodyPart part) {
    bodyParts.push_back(part);
}

std::vector<Rectangle> Being::getPartWorldBoxes() {
    std::vector<Rectangle> worldBoxes;
    for (int i = 0; i < bodyParts.size(); i++) {
        worldBoxes.push_back(bodyParts.at(i).getWorldCollisionBox(x, y));
    }
    return worldBoxes;
}
