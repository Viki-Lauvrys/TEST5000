#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMTEMPORARY_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMTEMPORARY_H

#include "Platform.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class PlatformTemporary
     * \brief Represents a temporary platform in the game.
     *
     * The PlatformTemporary class provides functionality for platforms that disappear after being jumped on.
     */
    class PlatformTemporary : public Platform {
    public:
        /**
         * \brief Default constructor for PlatformTemporary.
         */
        PlatformTemporary();

        /**
         * \brief Updates the platform's state.
         *
         * This function updates the platform's state, typically handling the disappearance after being jumped on.
         */
        void update() override;
    };

}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORMTEMPORARY_H