#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLATFORM_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLATFORM_H

#include <utility>
#include "../ENTITY/Entity.h"
#include "../RANDOM/Random.h"
#include "../CAMERA/Camera.h"
#include "../BONUS/Bonus.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class Platform
     * \brief Represents a platform entity in the game.
     *
     * The Platform class provides functionality for platforms that the player can jump on.
     */
    class Platform : public Entity {
    protected:
        std::string color; ///< The color of the platform.
        int type; ///< The type of the platform.
        float x; ///< The x-coordinate of the platform.
        float y = 0.09f; ///< The y-coordinate of the platform.
        bool jumpedOn; ///< Flag indicating if the platform has been jumped on.
        std::shared_ptr<Bonus> bonus; ///< The bonus associated with the platform.

    public:
        /**
         * \brief Default constructor for Platform.
         */
        Platform();

        /**
         * \brief Moves the platform by a specified amount.
         * \param dx The amount to move in the x direction.
         * \param dy The amount to move in the y direction.
         */
        void move(float dx, float dy) override;

        /**
         * \brief Gets the x position of the platform.
         * \return The x position of the platform.
         */
        [[nodiscard]] float getX() override;

        /**
         * \brief Gets the y position of the platform.
         * \return The y position of the platform.
         */
        [[nodiscard]] float getY() override;

        /**
         * \brief Gets the true x position of the platform.
         * \return The true x position of the platform.
         */
        [[nodiscard]] float getTrueX();

        /**
         * \brief Gets the true y position of the platform.
         * \return The true y position of the platform.
         */
        [[nodiscard]] float getTrueY();

        /**
         * \brief Sets the x position of the platform.
         * \param x The new x position.
         */
        void setX(float x);

        /**
         * \brief Sets the y position of the platform.
         * \param y The new y position.
         */
        virtual void setY(float y);

        /**
         * \brief Sets the type of the platform.
         * \param type The new type.
         */
        void setType(int type);

        /**
         * \brief Gets the type of the platform.
         * \return The type of the platform.
         */
        [[nodiscard]] int getType() const;

        /**
         * \brief Checks if the platform has been jumped on.
         * \return True if the platform has been jumped on, false otherwise.
         */
        [[nodiscard]] bool isJumpedOn() const;

        /**
         * \brief Sets the platform as jumped on.
         */
        void setJumpedOn();

        /**
         * \brief Gets the color of the platform.
         * \return The color of the platform.
         */
        [[nodiscard]] std::string getColor() const;

        /**
         * \brief Updates the platform.
         */
        virtual void update();

        /**
         * \brief Sets the newBonus for the platform.
         * \param newBonus The newBonus to set.
         */
        void setBonus(std::shared_ptr<Bonus> newBonus) {
            this->bonus = std::move(newBonus);
        }

        /**
         * \brief Gets the bonus of the platform.
         * \return The bonus of the platform.
         */
        [[nodiscard]] std::shared_ptr<Bonus> getBonus() const {
            return bonus;
        }
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_LOGIC_PLATFORM_H