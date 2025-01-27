#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMHORIZONTAL_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMHORIZONTAL_H

#include "Platform.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class PlatformHorizontal
     * \brief Represents a horizontally moving platform in the game.
     *
     * The PlatformHorizontal class provides functionality for platforms that move horizontally within a specified range.
     */
    class PlatformHorizontal : public Platform {
    private:
        float minX; ///< The minimum x-coordinate for the platform's movement.
        float maxX; ///< The maximum x-coordinate for the platform's movement.
        float speed; ///< The speed of the platform's movement.
        bool movingRight; ///< Flag indicating if the platform is moving to the right.

    public:
        /**
         * \brief Constructor for PlatformHorizontal.
         * \param minX The minimum x-coordinate for the platform's movement.
         * \param maxX The maximum x-coordinate for the platform's movement.
         * \param speed The speed of the platform's movement.
         */
        PlatformHorizontal(float minX, float maxX, float speed);

        /**
         * \brief Updates the platform's position.
         *
         * This function updates the platform's position based on its speed and direction.
         */
        void update() override;
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMHORIZONTAL_H