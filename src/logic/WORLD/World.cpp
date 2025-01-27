#include "World.h"

DOODLE_JUMP::Logic::World::World() {
    creator = std::make_unique<PlayerCreator>();
    player = creator->createObject();
    for (int i = 0; i < platformCount; i++) {

        //start with all static platforms (easy)
        creator = std::make_unique<PlatformStaticCreator>();
        auto platform = creator->createObject();
        std::static_pointer_cast<Platform>(platform)->setY(Random::randomNewPlatformY());
        Random::setPlatformY(std::static_pointer_cast<Platform>(platform)->getTrueY());
        platforms.push_back(std::static_pointer_cast<Platform>(platform));
    }
    score = std::make_shared<Score>();
    attach(score);
}

void DOODLE_JUMP::Logic::World::setPlatformType() {
    int random = Random::randomInt(1, 100);
    if (random <= int(chanceStatic)) {
        creator = std::make_unique<PlatformStaticCreator>();
    } else if (random <= int(chanceStatic + chanceHorizontal)) {
        creator = std::make_unique<PlatformHorizontalCreator>();
    } else if (random <= int(chanceStatic + chanceHorizontal + chanceVertical)) {
        creator = std::make_unique<PlatformVerticalCreator>();
    } else {
        creator = std::make_unique<PlatformTemporaryCreator>();
    }
}

void DOODLE_JUMP::Logic::World::simulate(double deltaTime) {
    getPlayer()->velocity += static_cast<float>(getPlayer()->gravity * deltaTime /2);
    if (getPlayer()->velocity < -1 * getPlayer()->jumpForce / 1) getPlayer()->velocity = -1 * getPlayer()->jumpForce / 1;

    if (getPlayer()->getTrueY() >= 0.9 && bottomIsGround) {
        getPlayer()->jump();
    } else if (getPlayer()->getTrueY() >= 1.15) {
        running = false;
        Random::reset();
        score->saveScore();
    }

    if (getPlayer()->getY() <= 512 && getPlayer()->jumpDirection == 1) {
        changed = true;
        notifyObservers();
        Random::updatePlatformY(getPlayer()->jumpForce * 1.0f);
    }

    for (auto it = platforms.begin(); it != platforms.end(); ) {
        (*it)->update();

        if (getPlayer()->getY() <= 512 && getPlayer()->jumpDirection == 1) {
            bottomIsGround = false;
            (*it)->move(0.0f, static_cast<float>(getPlayer()->jumpForce * 1.2f * deltaTime * player->jumpHeight));
            moving = true;

            if ((*it)->getTrueY() > 1.3f) {
                it = platforms.erase(it);

                setPlatformType();

                auto newPlatform = creator->createObject();
                std::static_pointer_cast<Platform>(newPlatform)->setY(Random::randomNewPlatformY());
                Random::setPlatformY(std::static_pointer_cast<Platform>(newPlatform)->getTrueY());
                platforms.push_back(std::static_pointer_cast<Platform>(newPlatform));

                // 5% chance to spawn a bonus on a platform => for demonstration purposes easier to get a bonus, normally I would do 5 - 10%
                if (Random::randomInt(1, 100) <= 5) {
                    creator = std::make_unique<BonusCreator>();
                    auto bonus = creator->createObject();
                    platforms.back()->setBonus(std::static_pointer_cast<Bonus>(bonus));
                    platforms.back()->getBonus()->setX(platforms.back()->getTrueX());
                    platforms.back()->getBonus()->setY(platforms.back()->getTrueY() - 0.05f);
                }

                increaseDifficulty();
            }
        } else {
            moving = false;
        }
        it++;
    }

    if (getPlayer()->velocity > 0) {
        getPlayer()->jumpDirection = -1; //falling down
        getPlayer()->jumpHeight = 1.0f; //reset jump height when falling down
    } else {
        getPlayer()->jumpDirection = 1; //jumping up
    }

    getPlayer()->update(deltaTime);
}

std::shared_ptr<DOODLE_JUMP::Logic::Player> DOODLE_JUMP::Logic::World::getPlayer() {
    return std::static_pointer_cast<Player>(player);
}

std::vector<std::shared_ptr<DOODLE_JUMP::Logic::Platform>> DOODLE_JUMP::Logic::World::getPlatforms() {
    return platforms;
}

void DOODLE_JUMP::Logic::World::movePlayerLeft(float deltaTime) {
    getPlayer()->move(-0.0001f * 2000 * deltaTime, 0);
}

void DOODLE_JUMP::Logic::World::movePlayerRight(float deltaTime) {
    getPlayer()->move(0.0001f * 2000 * deltaTime, 0);
}

void DOODLE_JUMP::Logic::World::checkCollisionsPlayer() {
    // Check for collisions with player
    if (getPlayer()->jumpDirection == -1 && std::abs(getPlayer()->velocity) > std::abs(getPlayer()->jumpForce / 4)) {
        for (auto& platform : getPlatforms()) {
            if (getPlayer()->getY() <= platform->getY() - 80 &&
                getPlayer()->getY() >= platform->getY() - 90 &&
                getPlayer()->getX() >= platform->getX() - 80 &&
                getPlayer()->getX() <= platform->getX() + 80) {

                getPlayer()->jump();

                // If already jumped on same platforms before, decrement score
                if (platform->isJumpedOn()) {
                    score->decrementScore(10);
                }
                platform->setJumpedOn();

                // Check for bonus
                auto bonus = platform->getBonus();
                if (bonus) {
                    bonus->apply(*getPlayer());
                    score->addBonusScore(bonus->getScore());
                }
            }
        }
    }
}

void DOODLE_JUMP::Logic::World::getHighScore() {
    score->getHighScore();
}

void DOODLE_JUMP::Logic::World::increaseDifficulty() {
    if (chanceStatic > 10) {
        chanceStatic -= 0.25;
    }
    if (chanceHorizontal < 100 - chanceStatic - chanceVertical - chanceTemporary) {
        chanceHorizontal += 0.2;
    }
    if (chanceVertical < 100 - chanceStatic - chanceHorizontal - chanceTemporary) {
        chanceVertical += 0.1;
    }
    if (chanceTemporary < 100 - chanceStatic - chanceHorizontal - chanceVertical) {
        chanceTemporary += 0.2;
    }
    randomObj->increaseDifficulty();
}

bool DOODLE_JUMP::Logic::World::isMoving() const {
    return moving;
}