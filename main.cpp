#include "src/logic/WORLD/World.h"
#include "src/gui/PLAYER/Player.h"
#include "src/gui/GAME/Game.h"
#include <memory>

using namespace DOODLE_JUMP::View;

int main() {
    auto game = std::make_shared<Game>();

    game->run();

    return 0;
}