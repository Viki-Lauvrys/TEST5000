#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMVERTICAL_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMVERTICAL_H

#include "Platform.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class PlatformVertical
     * \brief Represents a vertically moving platform in the game.
     *
     * The PlatformVertical class provides functionality for platforms that move vertically within a specified range.
     */
    class PlatformVertical : public Platform {
    protected:
        float minY; ///< The minimum y-coordinate for the platform's movement.
        float maxY; ///< The maximum y-coordinate for the platform's movement.
        float offsetMinY; ///< The offset for the minimum y-coordinate.
        float offsetMaxY; ///< The offset for the maximum y-coordinate.

    private:
        float speed; ///< The speed of the platform's movement.
        bool movingUp; ///< Flag indicating if the platform is moving up.
        float originalY = 0; ///< The original y-coordinate of the platform.

    public:
        /**
         * \brief Constructor for PlatformVertical.
         * \param minY The minimum y-coordinate for the platform's movement.
         * \param maxY The maximum y-coordinate for the platform's movement.
         * \param speed The speed of the platform's movement.
         */
        PlatformVertical(float minY, float maxY, float speed);

        /**
         * \brief Moves the platform by a specified amount.
         * \param dx The amount to move in the x direction.
         * \param dy The amount to move in the y direction.
         */
        void move(float dx, float dy) override;

        /**
         * \brief Updates the bounds of the platform's movement.
         */
        void updateBounds();

        /**
         * \brief Updates the platform's position.
         *
         * This function updates the platform's position based on its speed and direction.
         */
        void update() override;

        /**
         * \brief Sets the y position of the platform.
         * \param y The new y position.
         */
        void setY(float y) override;
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMVERTICAL_H