#include "Player.h"

#include <utility>

DOODLE_JUMP::View::PlayerRenderer::PlayerRenderer(std::shared_ptr<Logic::World> world) : world(std::move(world)) {
    texture.loadFromFile("src/assets/playerUP.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); // Set the texture rectangle to cover the full 64x64 texture
    sprite.setScale(1.5f, 1.5f);
}

void DOODLE_JUMP::View::PlayerRenderer::initialize() {
    world->attach(std::static_pointer_cast<Observer>(shared_from_this()));
}

DOODLE_JUMP::View::PlayerRenderer::~PlayerRenderer() {
    world->detach(std::static_pointer_cast<Observer>(shared_from_this()));
}

void DOODLE_JUMP::View::PlayerRenderer::updateSpriteTexture(bool isGoingUp) {
    if (isGoingUp) {
        if (updateCounter % 20 == 0) {
            if (currentTextureIndex < 9) {
                currentTextureIndex++;
            }
            std::string texturePath = "src/assets/test" + std::to_string(currentTextureIndex) + ".png";
            texture.loadFromFile(texturePath);
            sprite.setTexture(texture);
        }
        updateCounter++;
    } else {
        texture.loadFromFile("src/assets/test9.png");
        sprite.setTexture(texture);
        updateCounter = 0;
        currentTextureIndex = 1;
    }
}

void DOODLE_JUMP::View::PlayerRenderer::update() {
    sprite.setPosition(world->getPlayer()->getX(), world->getPlayer()->getY());
}

void DOODLE_JUMP::View::PlayerRenderer::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}