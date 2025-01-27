#include "PlatformHorizontal.h"

DOODLE_JUMP::Logic::PlatformHorizontal::PlatformHorizontal(float minX, float maxX, float speed) : minX(minX), maxX(maxX), speed(speed) {
    this->type = 2;
    this->color = "blue";
    if (Random::randomInt(0, 1) == 0) {
        movingRight = true;
    } else {
        movingRight = false;
    }
}

void DOODLE_JUMP::Logic::PlatformHorizontal::update() {
    if (movingRight) {
        x += speed;
        if (x > maxX) {
            movingRight = false;
        }
    } else {
        x -= speed;
        if (x < minX) {
            x = minX;
            movingRight = true;
        }
    }
}
