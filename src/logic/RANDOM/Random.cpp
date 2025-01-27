#include <iostream>
#include "Random.h"

float DOODLE_JUMP::Logic::Random::highestPlatformY = 1.5f;
float DOODLE_JUMP::Logic::Random::heightBetweenPlatformsMAX = 0.2f; //0.55f maximum, misschien 0.5 voor zekerheid?
float DOODLE_JUMP::Logic::Random::heightBetweenPlatformsMIN = 0.05f;
float DOODLE_JUMP::Logic::Random::lowerBound = 1.0f;
float DOODLE_JUMP::Logic::Random::upperBound = lowerBound + heightBetweenPlatformsMAX;

[[nodiscard]] float DOODLE_JUMP::Logic::Random::randomFloat(float min, float max) {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

float DOODLE_JUMP::Logic::Random::randomNewPlatformY() {
    lowerBound = highestPlatformY - heightBetweenPlatformsMIN;
    upperBound = highestPlatformY - heightBetweenPlatformsMAX;
    float result = randomFloat(lowerBound, upperBound);
    highestPlatformY = result;
    return result;
}

[[nodiscard]] int DOODLE_JUMP::Logic::Random::randomInt(int min, int max) {
    static std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}


void DOODLE_JUMP::Logic::Random::updatePlatformY(float y) {
    highestPlatformY += y;
}

void DOODLE_JUMP::Logic::Random::setPlatformY(float y) {
    highestPlatformY = y;
}

void DOODLE_JUMP::Logic::Random::reset() {
    highestPlatformY = 1.5f;
    heightBetweenPlatformsMAX = 0.2f; //0.55f maximum, misschien 0.5 voor zekerheid?
    heightBetweenPlatformsMIN = 0.05f;
    lowerBound = 1.0f;
    upperBound = lowerBound + heightBetweenPlatformsMAX;
}

void DOODLE_JUMP::Logic::Random::increaseDifficulty() {
    if (heightBetweenPlatformsMIN < heightBetweenPlatformsMAX - 0.5f) {
        heightBetweenPlatformsMIN += 0.0000001f;
    }
    if (heightBetweenPlatformsMAX < 0.50f) {
        heightBetweenPlatformsMAX += 0.000000001f; //slower increase
    }
}
