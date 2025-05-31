#include "Home.h"

void Home::init_Variables()
{
    // Background
    home_background = LoadTexture("assets/Home_Screen.png");
}

void Home::init_Buttons()
{
    // Play Button
    play_button = new Button(Vector2(150, 100), Vector2(130, 415), "Play", 20, WHITE, Conversion::hex_RGB("#FFA94D"), Conversion::hex_RGB("#FFCB7C"), Conversion::hex_RGB("#D8771A"));

    // Quit Button
    quit_button = new Button(Vector2(150, 100), Vector2(window_width - 130, 415), "Quit", 20, WHITE, Conversion::hex_RGB("#E05B5B"), Conversion::hex_RGB("#F47174"), Conversion::hex_RGB("#B03B3B"));
}

void Home::change_Screen()
{
    if (play_button->is_Button_Active() || IsKeyPressed(KEY_ENTER))
    {
        e_Screen = play_screen;
    }

    if (quit_button->is_Button_Active() || IsKeyPressed(KEY_ESCAPE))
    {
        e_Screen = quit_screen;
    }
}

Home::Home()
{
    init_Variables();
    init_Buttons();
}

Home::~Home()
{
    delete play_button;
    delete quit_button;

    UnloadTexture(home_background);
}

void Home::ready()
{
}

void Home::update_Home()
{
    change_Screen();
}

void Home::draw_Home()
{
    DrawTexture(home_background, 0, 0, WHITE);

    play_button->draw();
    quit_button->draw();
}
