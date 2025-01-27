#include "TileMap.h"

bool DOODLE_JUMP::View::TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height) {
    // Load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    m_width = width;
    m_height = height;
    m_tileSize = tileSize;

    // Resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // Populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j) {
            // Get the current tile number
            int tileNumber = tiles[i + j * width];

            // Find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // Get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // Define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, (j -1) * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, (j -1) * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // Define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void DOODLE_JUMP::View::TileMap::draw(sf::RenderWindow& window) {
    window.draw(m_vertices, &m_tileset);
}

void DOODLE_JUMP::View::TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Apply the transform
    states.transform *= getTransform();

    // Apply the tileset texture
    states.texture = &m_tileset;

    // Draw the vertex array
    target.draw(m_vertices, states);
}

void DOODLE_JUMP::View::TileMap::updatePosition(float offsetY) {
    for (unsigned int i = 0; i < m_vertices.getVertexCount(); ++i) {
        m_vertices[i].position.y += offsetY;
    }
}

void DOODLE_JUMP::View::TileMap::scroll(float offsetY) {
    // Update the position of the tiles
    updatePosition(offsetY);

    // Check if any tiles have moved out of view and need to be reset
    for (unsigned int j = 0; j < m_height; ++j) {
        if (m_vertices[j * m_width * 4].position.y >= float(m_height) * float(m_tileSize.y)) {
            // Move the row to the top
            for (unsigned int i = 0; i < m_width; ++i) {
                sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];
                quad[0].position.y -= float(m_height * m_tileSize.y) - 0.5f;
                quad[1].position.y -= float(m_height * m_tileSize.y) - 0.5f;
                quad[2].position.y -= float(m_height * m_tileSize.y) - 0.5f;
                quad[3].position.y -= float(m_height * m_tileSize.y) - 0.5f;
            }
        }
    }
}