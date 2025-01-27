#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_CAMERA_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_CAMERA_H

namespace DOODLE_JUMP::Logic {

    /**
     * \class Camera
     * \brief Handles the translation of coordinates in the game.
     */
    class Camera {
    public:
        /**
         * \brief Default constructor for Camera.
         */
        Camera() = default;

        /**
         * \brief Translates the x-coordinate.
         * \param xVal The x-coordinate to translate.
         * \return The translated x-coordinate.
         */
        [[nodiscard]] static float translateX(float xVal);

        /**
         * \brief Translates the y-coordinate.
         * \param yVal The y-coordinate to translate.
         * \return The translated y-coordinate.
         */
        [[nodiscard]] static float translateY(float yVal);
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_CAMERA_H