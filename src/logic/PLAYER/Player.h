#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLAYER_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLAYER_H

#include <chrono>
#include "../ENTITY/Entity.h"
#include "../CAMERA/Camera.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class Player
     * \brief Represents the player entity in the game.
     *
     * The Player class provides functionality for the player character, including movement, jumping, and bonus management.
     */
    class Player : public Entity {
    public:
        /**
         * \brief Default constructor for Player.
         */
        Player() = default;

        /**
         * \brief Default destructor for Player.
         */
        ~Player() override = default;

        /**
         * \brief Moves the player by a specified amount.
         * \param dx The amount to move in the x direction.
         * \param dy The amount to move in the y direction.
         */
        void move(float dx, float dy) override;

        /**
         * \brief Gets the x position of the player.
         * \return The x position of the player.
         */
        float getX() override { return Camera::translateX(x); }

        /**
         * \brief Gets the y position of the player.
         * \return The y position of the player.
         */
        float getY() override { return Camera::translateY(y); }

        /**
         * \brief Gets the true x position of the player.
         * \return The true x position of the player.
         */
        [[nodiscard]] float getTrueX() const { return x; }

        /**
         * \brief Gets the true y position of the player.
         * \return The true y position of the player.
         */
        [[nodiscard]] float getTrueY() const { return y; }

        /**
         * \brief Makes the player jump.
         */
        void jump() { velocity = -1 * jumpForce; }

        /**
         * \brief Updates the player's state.
         * \param deltaTime The time elapsed since the last update.
         *
         * This function updates the player's position based on velocity and handles the removal of expired bonuses.
         */
        void update(double deltaTime);

        float x = 0; ///< The x-coordinate of the player.
        float y = 0.7; ///< The y-coordinate of the player.
        float jumpDirection = 1; ///< The direction of the player's jump.
        float velocity = 0; ///< The velocity of the player.
        float gravity = 0.0000000000076; ///< The gravity affecting the player.
        float jumpForce = 0.0000013; ///< The force of the player's jump.
        std::vector<std::pair<std::shared_ptr<BonusStrategy>, std::chrono::steady_clock::time_point>> activeBonuses; ///< The active bonuses of the player.
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLAYER_H