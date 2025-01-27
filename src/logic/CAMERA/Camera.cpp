#include "Camera.h"

float DOODLE_JUMP::Logic::Camera::translateX(float xVal) {;
    return (xVal + 1) * 384;
}

float DOODLE_JUMP::Logic::Camera::translateY(float yVal) {
    return (yVal + 1) * 512;
}
