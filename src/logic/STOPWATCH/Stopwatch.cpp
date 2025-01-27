#include "Stopwatch.h"

namespace DOODLE_JUMP::Logic {

    void Stopwatch::start() {
        if (!running) {
            startTime = std::chrono::high_resolution_clock::now();
            running = true;
        }
    }

    void Stopwatch::stop() {
        if (running) {
            endTime = std::chrono::high_resolution_clock::now();
            running = false;
        }
    }

    void Stopwatch::reset() {
        running = false;
    }

    double Stopwatch::getElapsedTime() const {
        if (running) {
            return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime).count();
        } else {
            return std::chrono::duration<double>(endTime - startTime).count();
        }
    }
}