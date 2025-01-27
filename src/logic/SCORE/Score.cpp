#include <fstream>
#include <iostream>
#include "Score.h"

DOODLE_JUMP::Logic::Score::Score() noexcept : score(0) {}

void DOODLE_JUMP::Logic::Score::incrementScore() {
    score += 0.1f;
}

int DOODLE_JUMP::Logic::Score::getScore() const {
    return int(score);
}

void DOODLE_JUMP::Logic::Score::resetScore() {
    score = 0;
}

void DOODLE_JUMP::Logic::Score::update() {
    incrementScore();
}

std::pair<int, int> DOODLE_JUMP::Logic::Score::getScores() {
    std::ifstream infile("src/logic/SCORE/score.txt");
    int worstScore, bestScore;
    infile >> worstScore >> bestScore;
    infile.close();
    return {worstScore, bestScore};
}

int DOODLE_JUMP::Logic::Score::getHighScore() {
    return getScores().second;
}

int DOODLE_JUMP::Logic::Score::getLowScore() {
    return getScores().first;
}

bool DOODLE_JUMP::Logic::Score::isNewHighScore() const {
    auto [worstScore, bestScore] = getScores();
    return int(score) == bestScore;
}

bool DOODLE_JUMP::Logic::Score::isNewLowScore() const {
    auto [worstScore, bestScore] = getScores();
    return int(score) == worstScore;
}

void DOODLE_JUMP::Logic::Score::saveScore() const {
    auto [worstScore, bestScore] = getScores();
    int currentScore = int(score);

    if (currentScore > bestScore) {
        bestScore = currentScore;
    }
    if (currentScore < worstScore) {
        worstScore = currentScore;
    }

    std::ofstream outfile("src/logic/SCORE/score.txt");
    outfile << worstScore << "\n" << bestScore;
    outfile.close();
}

void DOODLE_JUMP::Logic::Score::decrementScore(float amount) {
    score -= amount;
}

void DOODLE_JUMP::Logic::Score::addBonusScore(float bonusScore) {
    score += bonusScore;
}
