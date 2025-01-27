#include "Game.h"
#include "../BG_TILE/BG_Tile.h"

DOODLE_JUMP::View::Game::Game() : maxFPS(120.0),
                                  updateStopwatch(Logic::Stopwatch::getInstance()),
                                  renderStopwatch(Logic::Stopwatch::getInstance()) {
    initialize();
}

void DOODLE_JUMP::View::Game::initialize() {
    world = std::make_shared<Logic::World>();
    playerRenderer = std::make_shared<PlayerRenderer>(world);
    playerRenderer->initialize();
    platformRenderer = std::make_shared<PlatformRenderer>(world);
    platformRenderer->initialize();
    loadScoreSettings();
    window.create(sf::VideoMode(768, 1024), "DOODLE JUMP - VIKI LAUVRYS :D");
    updateStopwatch.start();
    renderStopwatch.start();
    bgTileMap = BG_Tile(); // Initialize the background tile map
}



void DOODLE_JUMP::View::Game::updateLogic(float deltaTime) {
    playerRenderer->update();
    platformRenderer->update();

    world->simulate(deltaTime);
    world->checkCollisionsPlayer();


    if (world->isMoving()) {
        // Update background position
        float offsetY = world->getPlayer()->jumpForce * 15 * deltaTime;
        bgTileMap->scroll(offsetY);
    }
}

void DOODLE_JUMP::View::Game::updateGraphics() {
    window.clear();
    playerRenderer->updateSpriteTexture(world->getPlayer()->jumpDirection == 1);
    bgTileMap->draw(window);
    platformRenderer->draw(window);
    playerRenderer->draw(window);
    scoreText.setString("Score: " + std::to_string(world->getScoreObject()->getScore()));
    window.draw(scoreText);
    window.display();
}

void DOODLE_JUMP::View::Game::run() {
    updateStopwatch.start();
    renderStopwatch.start();
    float deltaTime = updateStopwatch.getElapsedTime() * 200000;

    while (window.isOpen() && world->isRunning()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Handle keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            world->movePlayerLeft(deltaTime / 200000);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            world->movePlayerRight(deltaTime / 200000);
        }

        updateLogic(deltaTime);

        // Check if enough time has passed since the last graphics update
        timeSinceLastGraphicsUpdate += deltaTime;
        if (timeSinceLastGraphicsUpdate >= 500000.0 / maxFPS) {
            updateGraphics();
            timeSinceLastGraphicsUpdate = 0.0;
        }
    }

    // If loop exits, call gameOver
    gameOver();
}


void DOODLE_JUMP::View::Game::loadScoreSettings() {

    if (!font.loadFromFile("src/assets/Arial.ttf")) {
        std::cerr << "Could not load font" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

void DOODLE_JUMP::View::Game::restartGame() {
    // Clear existing state
    world = nullptr;
    playerRenderer = nullptr;
    platformRenderer = nullptr;
    updateStopwatch.reset();
    renderStopwatch.reset();

    // Reinitialize everything and run the game again
    initialize();
    run();
}


void DOODLE_JUMP::View::Game::initializeText(sf::Text &text, const std::string &str, int size, const sf::Color &color, float posX, float posY) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setStyle(sf::Text::Bold);
    text.setPosition(posX - text.getGlobalBounds().width / 2, posY - text.getGlobalBounds().height / 2);
}

void DOODLE_JUMP::View::Game::fadeEffect(sf::RectangleShape &fadeShape) {
    sf::Clock clock;
    float elapsed = clock.getElapsedTime().asSeconds();
    for (int i = 1; i < 8; i++) {
        while (elapsed < i * 0.25) {
            fadeShape.setFillColor(sf::Color(0, 0, 0, i * 2));
            window.draw(fadeShape);
            window.display();
            elapsed = clock.getElapsedTime().asSeconds();
        }
    }
}

void DOODLE_JUMP::View::Game::handleEvents(sf::Text &restartButton) {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::FloatRect buttonBounds = restartButton.getGlobalBounds();
                if (buttonBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                    restartGame();
                    return;
                }
            }
        }
    }
}

void DOODLE_JUMP::View::Game::drawGameOverScreen(sf::RectangleShape &fadeShape, sf::Text &gameOverText, sf::Text &newHighScoreText, sf::Text &newLowScoreText, sf::Text &currentScoreText, sf::Text &highScoreText, sf::Text &lowScoreText, sf::Text &restartButton) {
    window.clear();
    window.draw(fadeShape);
    window.draw(gameOverText);
    window.display();

    // 2 SECOND DELAY
    sf::Clock delay;
    while (delay.getElapsedTime().asSeconds() < 2) {}
    window.clear();
    window.draw(fadeShape);
    window.draw(gameOverText);
    window.draw(newHighScoreText);
    window.draw(newLowScoreText);
    window.draw(currentScoreText);
    window.draw(highScoreText);
    window.draw(lowScoreText);
    window.draw(restartButton);
    window.display();
}

void DOODLE_JUMP::View::Game::gameOver() {
    sf::RectangleShape fadeShape(sf::Vector2f(window.getSize().x, window.getSize().y));
    fadeShape.setFillColor(sf::Color(0, 0, 0, 0)); // Start fully transparent

    sf::Text gameOverText, restartButton, newHighScoreText, newLowScoreText, currentScoreText, highScoreText, lowScoreText;

    initializeText(gameOverText, "GAME OVER", 100, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2);
    initializeText(restartButton, "RESTART", 50, sf::Color(139, 0, 0), window.getSize().x / 2, window.getSize().y / 2 + gameOverText.getGlobalBounds().height);

    if (world->getScoreObject()->isNewHighScore()) {
        initializeText(newHighScoreText, "NEW HIGHSCORE!", 50, sf::Color::Yellow, window.getSize().x / 2, window.getSize().y / 2 - 450);
    }

    if (world->getScoreObject()->isNewLowScore()) {
        initializeText(newLowScoreText, "LOWEST SCORE EVER!", 50, sf::Color::Yellow, window.getSize().x / 2, window.getSize().y / 2 - 450);
    }

    initializeText(currentScoreText, "Score: " + std::to_string(world->getScoreObject()->getScore()), 50, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2 + gameOverText.getGlobalBounds().height + 260);

    if (!world->getScoreObject()->isNewLowScore()) {
        initializeText(highScoreText, "Highscore: " + std::to_string(world->getScoreObject()->getHighScore()), 50, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2 + gameOverText.getGlobalBounds().height + 320);
    }

    if (world->getScoreObject()->isNewLowScore()) {
        initializeText(lowScoreText, "Lowscore: " + std::to_string(world->getScoreObject()->getLowScore()), 50, sf::Color::White, window.getSize().x / 2, window.getSize().y / 2 + gameOverText.getGlobalBounds().height + 320);
    }

    bool faded = false;
    while (window.isOpen()) {
        handleEvents(restartButton);

        if (!faded) {
            fadeEffect(fadeShape);
            sf::Clock delay;
            drawGameOverScreen(fadeShape, gameOverText, newHighScoreText, newLowScoreText, currentScoreText, highScoreText, lowScoreText, restartButton);
            faded = true;
        }
    }
}

void DOODLE_JUMP::View::Game::setMaxFPS(int fps) {
    maxFPS = fps;
}