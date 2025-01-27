#include "Player.h"

void DOODLE_JUMP::Logic::Player::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void DOODLE_JUMP::Logic::Player::update(double deltaTime) {
    this->y += static_cast<float>(this->velocity * deltaTime * jumpHeight);
    if (this->y >= 0) {
        this->y += static_cast<float>(this->velocity * deltaTime);
    } else {
        this->y = 0;
    }

    if (this->x > 1.1) {
        this->x = -1.1;
    } else if (this->x < -1.1) {
        this->x = 1.1;
    }

    // Check and remove expired bonuses
    auto now = std::chrono::steady_clock::now();
    for (auto it = activeBonuses.begin(); it != activeBonuses.end();) {
        if (now >= it->second) {
            it->first->remove(*this);
            it = activeBonuses.erase(it);
        } else {
            ++it;
        }
    }
}
