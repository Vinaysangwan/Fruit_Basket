#include "Game.h"

void Game::init_Window()
{
    InitWindow(window_width, window_height, "Fruit Basket");

    SetExitKey(KEY_NULL);
}

void Game::init_Screens()
{
    // Home Screen
    home = new Home();

    // Play Screen
    play = new Play();
}

Game::Game()
{
    init_Window();
    init_Screens();
}

Game::~Game()
{
    delete home;
    delete play;

    CloseWindow();
}

void Game::update_Game()
{
    switch (e_Screen)
    {
    case home_screen:
        home->update_Home();
        break;

    case play_screen:
        play->update_Play();
        break;

    case quit_screen:
        break;
    }
}

void Game::draw_Game()
{
    ClearBackground(WHITE);

    switch (e_Screen)
    {
    case home_screen:
        home->draw_Home();
        break;

    case play_screen:
        play->draw_Play();
        break;

    case quit_screen:
        break;
    }
}

bool Game::is_Running()
{
    if (!WindowShouldClose())
    {
        if (e_Screen == quit_screen)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
