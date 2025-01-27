#include "PlatformTemporary.h"

DOODLE_JUMP::Logic::PlatformTemporary::PlatformTemporary() {
    this->type = 4;
    this->color = "white";
}

void DOODLE_JUMP::Logic::PlatformTemporary::update() {
    if (jumpedOn) {
        y = 1.5f; // Move platform off screen, so it will be removed
    }
}
