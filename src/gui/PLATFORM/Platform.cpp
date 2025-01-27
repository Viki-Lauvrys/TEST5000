#include "Platform.h"

#include <utility>

void DOODLE_JUMP::View::PlatformRenderer::updateSpriteTextures() {
    //TODO: maybe only update the textures that have changed, idk how or if it's worth it
    sprites.clear();
    bonusSprites.clear();
    for (const auto& platform : world->getPlatforms()) {
        //Platform
        sf::Sprite sprite;
        if (platform->getType() == 1) sprite.setTexture(texture1);
        else if (platform->getType() == 2) sprite.setTexture(texture2);
        else if (platform->getType() == 3) sprite.setTexture(texture3);
        else if (platform->getType() == 4) sprite.setTexture(texture4);
        else sprite.setTexture(texture1);
        sprite.setScale(2.0f, 2.0f);
        sprites.push_back(sprite);

        //Bonus
        if (platform->getBonus()) {
            sf::Sprite bonusSprite;
            textureBonus.loadFromFile("src/assets/" + platform->getBonus()->getTextureName() + ".png");
            bonusSprite.setTexture(textureBonus);
            bonusSprite.setScale(1.5f, 1.5f);
            bonusSprite.setPosition(platform->getBonus()->getX(), platform->getBonus()->getY());
            bonusSprites.push_back(bonusSprite);
        } else {
            bonusSprites.emplace_back();
        }
    }
}

DOODLE_JUMP::View::PlatformRenderer::PlatformRenderer(std::shared_ptr<Logic::World> world) : world(std::move(world)) {
    texture1.loadFromFile("src/assets/platformTex1.png");
    texture2.loadFromFile("src/assets/platformTex2.png");
    texture3.loadFromFile("src/assets/platformTex3.png");
    texture4.loadFromFile("src/assets/platformTex4.png");

    updateSpriteTextures();
}

void DOODLE_JUMP::View::PlatformRenderer::initialize() {
    world->attach(std::static_pointer_cast<Observer>(shared_from_this()));
}

DOODLE_JUMP::View::PlatformRenderer::~PlatformRenderer() {
    world->detach(std::static_pointer_cast<Observer>(shared_from_this()));
}

void DOODLE_JUMP::View::PlatformRenderer::update() {
    updateSpriteTextures();
    for (size_t i = 0; i < world->getPlatforms().size(); ++i) {
        sprites[i].setPosition(world->getPlatforms()[i]->getX(), world->getPlatforms()[i]->getY());
        if (bonusSprites[i].getTexture()) {
            bonusSprites[i].setPosition(world->getPlatforms()[i]->getX() + 40, world->getPlatforms()[i]->getY() - 45);
        }
    }
}

void DOODLE_JUMP::View::PlatformRenderer::draw(sf::RenderWindow& window) {
    for (const sf::Sprite& sprite : sprites) {
        window.draw(sprite);
    }
    for (const sf::Sprite& bonusSprite : bonusSprites) {
        window.draw(bonusSprite);
    }
}