#include "core/Game.h"

int main()
{
    Game *game = new Game();

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