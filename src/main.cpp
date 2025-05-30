#include "core/Game.h"
#include <cstdlib>

int main()
{
    Game *game = new Game();

    std::srand(static_cast<unsigned int>(time(0)));

    while (game->is_Running())
    {
        game->update_Game();

        BeginDrawing();

        game->draw_Game();

        EndDrawing();
    }

    delete game;

    return 0;
}