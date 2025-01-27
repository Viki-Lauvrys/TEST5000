#include "PlatformVertical.h"

DOODLE_JUMP::Logic::PlatformVertical::PlatformVertical(float minY, float maxY, float speed) : minY(minY), maxY(maxY), speed(speed), movingUp(true) {
    this->type = 3;
    this->color = "yellow";
    this->offsetMinY = minY;
    this->offsetMaxY = maxY;
    if (Random::randomInt(0, 1) == 0) {
        movingUp = true;
    } else {
        movingUp = false;
    }
}

void DOODLE_JUMP::Logic::PlatformVertical::setY(float y) {
    this->y = y;
    this->originalY = y;
    minY = y + offsetMinY;
    maxY = y + offsetMaxY;
}

void DOODLE_JUMP::Logic::PlatformVertical::move(float dx, float dy) {
    x += dx;
    y += dy;
    originalY += dy;
    updateBounds();
}

void DOODLE_JUMP::Logic::PlatformVertical::updateBounds() {
    minY = originalY + offsetMinY;
    maxY = originalY + offsetMaxY;
}

void DOODLE_JUMP::Logic::PlatformVertical::update() {
    if (movingUp) {
        y += speed;
        if (y > maxY) {
            movingUp = false;
        }
    } else {
        y -= speed;
        if (y < minY) {
            movingUp = true;
        }
    }
}
