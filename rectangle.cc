#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rectangle::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Rectangle::setPosition(Point position) {
    x = position.x;
    y = position.y;
}
