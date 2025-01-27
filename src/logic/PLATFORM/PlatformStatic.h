#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMSTATIC_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMSTATIC_H

#include "Platform.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class PlatformStatic
     * \brief Represents a static platform in the game.
     *
     * The PlatformStatic class provides functionality for platforms that do not move.
     */
    class PlatformStatic : public Platform {
    public:
        /**
         * \brief Default constructor for PlatformStatic.
         */
        PlatformStatic();

        /**
         * \brief Updates the platform's state.
         *
         * This function does nothing for static platforms as they do not move.
         */
        void update() override {}
    };

}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMSTATIC_H