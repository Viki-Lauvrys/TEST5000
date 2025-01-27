#include "EntityModel.h"
#include "../PLATFORM/PlatformStatic.h"
#include "../PLATFORM/PlatformHorizontal.h"
#include "../PLATFORM/PlatformVertical.h"
#include "../PLATFORM/PlatformTemporary.h"
#include "../BONUS/BonusStrategy.h"

std::shared_ptr<DOODLE_JUMP::Logic::Entity> DOODLE_JUMP::Logic::EntityModel::createObject() {
    return FactoryMethod();
}

std::shared_ptr<DOODLE_JUMP::Logic::Entity> DOODLE_JUMP::Logic::PlayerCreator::FactoryMethod() {
    return std::make_shared<Player>();
}

std::shared_ptr<DOODLE_JUMP::Logic::Player::Entity> DOODLE_JUMP::Logic::PlatformStaticCreator::FactoryMethod() {
    return std::make_shared<PlatformStatic>();
}

std::shared_ptr<DOODLE_JUMP::Logic::Platform::Entity> DOODLE_JUMP::Logic::PlatformHorizontalCreator::FactoryMethod() {
    return std::make_shared<PlatformHorizontal>(-1.0f, 1.0f, Random::randomFloat(0.0005f, 0.0001f));
}

std::shared_ptr<DOODLE_JUMP::Logic::Platform::Entity> DOODLE_JUMP::Logic::PlatformVerticalCreator::FactoryMethod() {
    return std::make_shared<PlatformVertical>(-0.3f, 0.3f, Random::randomFloat(0.0005f, 0.0001f));
}

std::shared_ptr<DOODLE_JUMP::Logic::Platform::Entity> DOODLE_JUMP::Logic::PlatformTemporaryCreator::FactoryMethod() {
    return std::make_shared<PlatformTemporary>();
}

std::shared_ptr<DOODLE_JUMP::Logic::Entity> DOODLE_JUMP::Logic::BonusCreator::FactoryMethod() {
    // Create a default BonusStrategy or pass an existing one
    std::shared_ptr<BonusStrategy> strategy = getRandomBonusStrategy();
    return std::make_shared<Bonus>(strategy);
}
