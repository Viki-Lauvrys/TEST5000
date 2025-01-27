#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORM_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORM_H

#include "../../logic/OBSERVER/Observer.h"
#include "../../logic/WORLD/World.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>

namespace DOODLE_JUMP::View {

    /**
     * \class PlatformRenderer
     * \brief Renders platforms in the game and observes changes in the world.
     */
    class PlatformRenderer : public Logic::Observer, public std::enable_shared_from_this<PlatformRenderer> {
    private:
        std::shared_ptr<Logic::World> world; ///< The game world.
        std::vector<sf::Sprite> sprites; ///< Sprites for the platforms.
        std::vector<sf::Sprite> bonusSprites; ///< Sprites for bonus platforms.
        sf::Texture texture1; ///< Texture for the first type of platform.
        sf::Texture texture2; ///< Texture for the second type of platform.
        sf::Texture texture3; ///< Texture for the third type of platform.
        sf::Texture texture4; ///< Texture for the fourth type of platform.
        sf::Texture textureBonus; ///< Texture for the bonus platform.

    public:
        /**
         * \brief Constructor for PlatformRenderer.
         * \param world A shared pointer to the game world.
         */
        explicit PlatformRenderer(std::shared_ptr<Logic::World> world);

        /**
         * \brief Destructor for PlatformRenderer.
         */
        ~PlatformRenderer() override;

        /**
         * \brief Updates the textures of the platform sprites.
         */
        void updateSpriteTextures();

        /**
         * \brief Updates the platform renderer based on changes in the world.
         */
        void update() override;

        /**
         * \brief Draws the platform sprites to the window.
         * \param window The window to draw the sprites on.
         */
        void draw(sf::RenderWindow &window);

        /**
         * \brief Initializes the platform renderer.
         */
        void initialize();
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_PLATFORM_H