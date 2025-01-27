#include "BG_Tile.h"

std::unique_ptr <DOODLE_JUMP::View::TileMap> DOODLE_JUMP::View::BG_Tile() {
    // define the level with an array of tile indices. Each number corresponds to a tile from the tileset.
    const int level[24 * 32] = {0};

    // create the tilemap from the level definition
    auto map = std::make_unique<TileMap>();
    if (!map->load("src/assets/tileset.png", sf::Vector2u(32, 32), level, 24, 32)) {
        std::cout << "Error loading tilemap" << std::endl;
    }

    return map;
}
