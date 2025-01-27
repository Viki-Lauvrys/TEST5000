#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_BG_TILE_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_BG_TILE_H

#include "../TILEMAP/TileMap.h"

namespace DOODLE_JUMP::View {

    /**
     * \brief Creates a unique pointer to a TileMap object representing the background tile.
     *
     * \return A unique pointer to a TileMap object.
     */
    std::unique_ptr<TileMap> BG_Tile();
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_BG_TILE_H