#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_GAME_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_GAME_H

#include "SFML/Graphics.hpp"
#include <memory>
#include "../../logic/WORLD/World.h"
#include "../PLAYER/Player.h"
#include "../PLATFORM/Platform.h"
#include "../../logic/STOPWATCH/Stopwatch.h"
#include "../TILEMAP/TileMap.h"

namespace DOODLE_JUMP::View {

    /**
     * \class Game
     * \brief Manages the main game loop and rendering.
     */
    class Game {
    private:
        sf::RenderWindow window; ///< The main window for rendering.
        std::shared_ptr<Logic::World> world; ///< The game world.
        std::shared_ptr<PlayerRenderer> playerRenderer; ///< Renderer for the player.
        std::shared_ptr<PlatformRenderer> platformRenderer; ///< Renderer for platforms.
        std::shared_ptr<TileMap> bgTileMap; ///< Tile map for the background.
        Logic::Stopwatch stopwatch; ///< Stopwatch for game timing.
        Logic::Stopwatch& updateStopwatch; ///< Stopwatch for update timing.
        Logic::Stopwatch& renderStopwatch; ///< Stopwatch for render timing.
        sf::Font font; ///< Font used for text rendering.
        sf::Text scoreText; ///< Text for displaying the score.
        double timeSinceLastGraphicsUpdate = 0.0; ///< Time since the last graphics update.
        float maxFPS; ///< The maximum frames per second.

    public:
        /**
         * \brief Constructor for Game.
         */
        Game();

        /**
         * \brief Initializes the game.
         */
        void initialize();

        /**
         * \brief Runs the main game loop.
         */
        void run();

        /**
         * \brief Loads the score settings.
         */
        void loadScoreSettings();

        /**
         * \brief Updates the game logic.
         * \param deltaTime The time elapsed since the last update.
         */
        void updateLogic(float deltaTime);

        /**
         * \brief Updates the game graphics.
         */
        void updateGraphics();

        /**
         * \brief Handles game over logic.
         */
        void gameOver();

        /**
         * \brief Restarts the game.
         */
        void restartGame();

        /**
         * \brief Initializes a text object.
         * \param text The text object to initialize.
         * \param str The string to display.
         * \param size The font size.
         * \param color The color of the text.
         * \param posX The x position of the text.
         * \param posY The y position of the text.
         */
        void initializeText(sf::Text &text, const std::string &str, int size, const sf::Color &color, float posX, float posY);

        /**
         * \brief Applies a fade effect to a shape.
         * \param fadeShape The shape to apply the fade effect to.
         */
        void fadeEffect(sf::RectangleShape &fadeShape);

        /**
         * \brief Handles game events.
         * \param restartButton The text object for the restart button.
         */
        void handleEvents(sf::Text &restartButton);

        /**
         * \brief Draws the game over screen.
         * \param fadeShape The shape for the fade effect.
         * \param gameOverText The text for the game over message.
         * \param newHighScoreText The text for the new high score message.
         * \param newLowScoreText The text for the new low score message.
         * \param currentScoreText The text for the current score.
         * \param highScoreText The text for the high score.
         * \param lowScoreText The text for the low score.
         * \param restartButton The text for the restart button.
         */
        void drawGameOverScreen(sf::RectangleShape &fadeShape, sf::Text &gameOverText, sf::Text &newHighScoreText, sf::Text &newLowScoreText, sf::Text &currentScoreText, sf::Text &highScoreText, sf::Text &lowScoreText, sf::Text &restartButton);

        /**
        * \brief Sets the maximum frames per second.
        * \param fps The maximum frames per second.
         */
        void setMaxFPS(int fps);
    };
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_GAME_H