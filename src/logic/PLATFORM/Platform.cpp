#include "Platform.h"

DOODLE_JUMP::Logic::Platform::Platform() {
    x = Random::randomFloat(-0.9f, 0.7f);
    y = 0.0f;
    jumpedOn = false;
}

void DOODLE_JUMP::Logic::Platform::move(float dx, float dy) {
    x += dx;
    y += dy;

    if (bonus != nullptr)
    bonus->move(dx, dy);
}

float DOODLE_JUMP::Logic::Platform::getX() {
    return Camera::translateX(x);
}

float DOODLE_JUMP::Logic::Platform::getY() {
    return Camera::translateY(y);
}

float DOODLE_JUMP::Logic::Platform::getTrueX() {
    return x;
}

float DOODLE_JUMP::Logic::Platform::getTrueY() {
    return y;
}

void DOODLE_JUMP::Logic::Platform::setX(float x) {
    this->x = x;
}

void DOODLE_JUMP::Logic::Platform::setY(float y) {
    this->y = y;
}

void DOODLE_JUMP::Logic::Platform::setType(int type) {
    this->type = type;
}

int DOODLE_JUMP::Logic::Platform::getType() const {
    return this->type;
}

std::string DOODLE_JUMP::Logic::Platform::getColor() const {
    return this->color;
}

void DOODLE_JUMP::Logic::Platform::update() {}

bool DOODLE_JUMP::Logic::Platform::isJumpedOn() const {
    return jumpedOn;
}

void DOODLE_JUMP::Logic::Platform::setJumpedOn() {
    this->jumpedOn = true;
}
