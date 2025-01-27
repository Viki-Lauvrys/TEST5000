#include <algorithm>
#include "Subject.h"

void DOODLE_JUMP::Logic::Subject::attach(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void DOODLE_JUMP::Logic::Subject::detach(std::shared_ptr<Observer> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void DOODLE_JUMP::Logic::Subject::notifyObservers() {
    if (changed) {
        for (const auto& observer : observers) {
            observer->update();
        }
        changed = false;
    }
}