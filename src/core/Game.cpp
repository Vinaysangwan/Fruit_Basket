#include "Game.h"

// ###########################################################################
//                          Private Funcitons
// ###########################################################################
// Initialize Variables
void Game::init_Variables()
{
    delta_time = 0.0f;
}

// Initialize Window
void Game::init_Window()
{
    InitWindow(window_width, window_height, "Fruit Basket");

    SetExitKey(KEY_NULL);
}

// Initialize Screens
void Game::init_Screens()
{
    // Home Screen
    home = new Home();

    // Play Screen
    play = new Play();
}

// ###########################################################################
//                          Constructor & Destructor
// ###########################################################################
// Constructor
Game::Game()
{
    init_Variables();
    init_Window();
    init_Screens();
}

// Destructor
Game::~Game()
{
    delete home;
    delete play;

    CloseWindow();
}

// ###########################################################################
//                            Main Game Functions
// ###########################################################################
// Update Function of the Game
void Game::update_Game()
{
    delta_time = GetFrameTime();

    switch (e_Screen)
    {
    case home_screen:
        home->update_Home();
        break;

    case play_screen:
        play->update_Play(delta_time);
        break;

    case quit_screen:
        break;
    }
}

// Draw Funciton of the game
void Game::draw_Game()
{
    ClearBackground(BLACK);

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

// ###########################################################################
//                              Return Functions
// ###########################################################################
// Reutrn the Game Window Running Status
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
