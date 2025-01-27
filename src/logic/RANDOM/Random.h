#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_RANDOM_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_RANDOM_H

#include <random>
#include <ctime>

namespace DOODLE_JUMP::Logic {

    /**
     * \class Random
     * \brief Provides random number generation functionality for the game.
     *
     * The Random class provides static methods for generating random floats and integers, as well as managing platform heights.
     */
    class Random {
    private:
        static float lowerBound; ///< The lower bound for random number generation.
        static float upperBound; ///< The upper bound for random number generation.

        static float heightBetweenPlatformsMAX; ///< The maximum height between platforms.
        static float heightBetweenPlatformsMIN; ///< The minimum height between platforms.

        static float highestPlatformY; ///< The highest y-coordinate of the platforms.

    public:
        /**
         * \brief Generates a random float between the specified minimum and maximum values.
         * \param min The minimum value.
         * \param max The maximum value.
         * \return A random float between min and max.
         */
        [[nodiscard]] static float randomFloat(float min, float max);

        /**
         * \brief Generates a random integer between the specified minimum and maximum values.
         * \param min The minimum value.
         * \param max The maximum value.
         * \return A random integer between min and max.
         */
        [[nodiscard]] static int randomInt(int min, int max);

        /**
         * \brief Generates a new y-coordinate for a platform.
         * \return A random y-coordinate for a new platform.
         */
        static float randomNewPlatformY();

        /**
         * \brief Updates the highest y-coordinate of the platforms.
         * \param y The new highest y-coordinate.
         */
        static void updatePlatformY(float y);

        /**
         * \brief Sets the highest y-coordinate of the platforms.
         * \param y The y-coordinate to set.
         */
        static void setPlatformY(float y);

        /**
         * \brief Resets the random number generator and platform heights.
         */
        static void reset();

        /**
         * \brief Increases the difficulty of the game by adjusting platform heights.
         */
        static void increaseDifficulty();
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_RANDOM_H