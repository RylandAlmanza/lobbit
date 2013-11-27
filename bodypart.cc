#include "bodypart.h"

BodyPart::BodyPart(std::string name, Rectangle collisionBox,
                   std::vector<Point> framePositions) : collisionBox(collisionBox) {
    this->name = name;
    this->collisionBox = collisionBox;
    this->framePositions = framePositions;
    currentFrame = 0;
    totalFrames = framePositions.size();
    time_since_last_update = 0;
}

void BodyPart::update(int time_delta) {
    time_since_last_update += time_delta;
    while (time_since_last_update >= 100) {
        currentFrame++;
        if (currentFrame == totalFrames) {
            currentFrame = 0;
        }
        collisionBox.setPosition(framePositions.at(currentFrame));
        time_since_last_update -= 100;
    }
}

int BodyPart::getWorldX(int parent_x) {
    return collisionBox.x + parent_x;
}

int BodyPart::getWorldY(int parent_y) {
    return collisionBox.y + parent_y;
}

Point BodyPart::getWorldPosition(int parent_x, int parent_y) {
    return Point(parent_x + collisionBox.x, parent_y + collisionBox.y);
}

Point BodyPart::getWorldPosition(Point parent_position) {
    return Point(parent_position.x + collisionBox.x,
                 parent_position.y + collisionBox.y);
}

Rectangle BodyPart::getWorldCollisionBox(int parent_x, int parent_y) {
    return Rectangle(parent_x + collisionBox.x, parent_y + collisionBox.y,
                     collisionBox.width, collisionBox.height);
}

Rectangle BodyPart::getWorldCollisionBox(Point parent_position) {
    return Rectangle(parent_position.x + collisionBox.x,
                     parent_position.y + collisionBox.y,
                     collisionBox.width,
                     collisionBox.height);
}
