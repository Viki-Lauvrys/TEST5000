#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_PLAYER_RENDERER_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_PLAYER_RENDERER_H

#include "../../logic/OBSERVER/Observer.h"
#include "../../logic/WORLD/World.h"
#include "SFML/Graphics.hpp"
#include <memory>

namespace DOODLE_JUMP::View {

    /**
     * \class PlayerRenderer
     * \brief Renders the player in the game and observes changes in the world.
     */
    class PlayerRenderer : public Logic::Observer, public std::enable_shared_from_this<PlayerRenderer> {
    private:
        std::shared_ptr<Logic::World> world; ///< The game world.
        sf::Sprite sprite; ///< Sprite for the player.
        sf::Texture texture; ///< Texture for the player sprite.
        int updateCounter = 0; ///< Counter for updating the sprite.
        int currentTextureIndex = 1; ///< Index of the current texture.

    public:
        /**
         * \brief Constructor for PlayerRenderer.
         * \param world A shared pointer to the game world.
         */
        explicit PlayerRenderer(std::shared_ptr<Logic::World> world);

        /**
         * \brief Destructor for PlayerRenderer.
         */
        ~PlayerRenderer() override;

        /**
         * \brief Initializes the player renderer.
         */
        void initialize();

        /**
         * \brief Updates the player renderer based on changes in the world.
         */
        void update() override;

        /**
         * \brief Draws the player sprite to the window.
         * \param window The window to draw the sprite on.
         */
        void draw(sf::RenderWindow &window);

        /**
         * \brief Updates the texture of the player sprite.
         * \param isGoingUp Indicates if the player is moving up.
         */
        void updateSpriteTexture(bool isGoingUp);
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_PLAYER_RENDERER_H