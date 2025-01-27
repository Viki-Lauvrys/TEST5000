#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_TILEMAP_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_TILEMAP_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <memory>

namespace DOODLE_JUMP::View {

    /**
     * \class TileMap
     * \brief Manages and renders a tile map for the game.
     */
    class TileMap : public sf::Drawable, public sf::Transformable {
    private:
        /**
         * \brief Draws the tile map to the render target.
         * \param target The render target to draw on.
         * \param states The render states to use for drawing.
         */
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        sf::VertexArray m_vertices; ///< Vertex array for the tile map.
        sf::Texture m_tileset; ///< Texture for the tileset.
        unsigned int m_width; ///< Width of the tile map.
        unsigned int m_height; ///< Height of the tile map.
        sf::Vector2u m_tileSize; ///< Size of each tile.

    public:
        /**
         * \brief Loads the tile map from a tileset.
         * \param tileset The path to the tileset image.
         * \param tileSize The size of each tile.
         * \param tiles The array of tile indices.
         * \param width The width of the tile map.
         * \param height The height of the tile map.
         * \return True if the tile map was loaded successfully, false otherwise.
         */
        bool load(const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);

        /**
         * \brief Draws the tile map to the window.
         * \param window The window to draw the tile map on.
         */
        void draw(sf::RenderWindow &window);

        /**
         * \brief Updates the position of the tile map.
         * \param offsetY The offset to move the tile map by.
         */
        void updatePosition(float offsetY);

        /**
         * \brief Scrolls the tile map by a given offset.
         * \param offsetY The offset to scroll the tile map by.
         */
        void scroll(float offsetY);
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_TILEMAP_H