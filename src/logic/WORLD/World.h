#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_WORLD_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_WORLD_H

#include "../SUBJECT/Subject.h"
#include "../ENTITY_MODEL/EntityModel.h"
#include "../SCORE/Score.h"
#include <memory>
#include <vector>

namespace DOODLE_JUMP::Logic {

    /**
     * \class World
     * \brief Manages the game world, including the player, platforms, and score.
     *
     * The World class is responsible for simulating the game world, handling player movements,
     * checking collisions, and managing the score and platforms.
     */
    class World : public Subject {
    private:
        std::unique_ptr<EntityModel> creator; ///< The entity model creator.
        std::shared_ptr<Entity> player; ///< The player entity.
        std::vector<std::shared_ptr<Platform>> platforms; ///< The list of platforms in the game.
        std::shared_ptr<Score> score; ///< The score object.
        int platformCount = 20; ///< The number of platforms.
        bool bottomIsGround = true; ///< Flag indicating if the bottom is ground.
        bool running = true; ///< Flag indicating if the game is running.
        bool moving = false; ///< Flag indicating if the player is moving.

        std::unique_ptr<Random> randomObj; ///< The random number generator object.

        float chanceStatic = 100; ///< The chance of a static platform.
        float chanceHorizontal = 0; ///< The chance of a horizontal platform.
        float chanceVertical = 0; ///< The chance of a vertical platform.
        float chanceTemporary = 0; ///< The chance of a temporary platform.

    public:
        /**
         * \brief Constructor for World.
         */
        World();

        /**
         * \brief Destructor for World.
         */
        virtual ~World() {
            player.reset();
            platforms.clear();
            score.reset();
        }

        /**
         * \brief Simulates the world (e.g., movements).
         * \param deltaTime The time elapsed since the last simulation step.
         */
        void simulate(double deltaTime);

        /**
         * \brief Gets a pointer to the player.
         * \return A shared pointer to the player.
         */
        std::shared_ptr<Player> getPlayer();

        /**
         * \brief Gets a pointer to the platforms.
         * \return A vector of shared pointers to the platforms.
         */
        std::vector<std::shared_ptr<Platform>> getPlatforms();

        /**
         * \brief Moves the player to the left.
         * \param deltaTime The time elapsed since the last movement.
         */
        void movePlayerLeft(float deltaTime);

        /**
         * \brief Moves the player to the right.
         * \param deltaTime The time elapsed since the last movement.
         */
        void movePlayerRight(float deltaTime);

        /**
         * \brief Checks for collisions between the player and platforms.
         */
        void checkCollisionsPlayer();

        /**
         * \brief Gets the score object.
         * \return A shared pointer to the score object.
         */
        std::shared_ptr<Score> getScoreObject() { return score; }

        /**
         * \brief Checks if the game is running.
         * \return True if the game is running, false otherwise.
         */
        [[nodiscard]] bool isRunning() const { return running; };

        /**
         * \brief Checks if the player is moving.
         * \return True if the player is moving, false otherwise.
         */
        [[nodiscard]] bool isMoving() const;

        /**
         * \brief Sets the type of platform.
         */
        void setPlatformType();

        /**
         * \brief Gets the high score.
         */
        void getHighScore();

        /**
         * \brief Increases the difficulty of the game.
         */
        void increaseDifficulty();
    };
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_WORLD_H