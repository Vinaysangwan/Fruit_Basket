#include "Home.h"

void Home::init_Buttons()
{
    // Play Button
    play_button = new Button(Vector2(150, 100), Vector2(window_width / 2, 100), "Play");

    // Quit Button
    quit_button = new Button(Vector2(150, 100), Vector2(window_width / 2, 300), "Quit");
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
    init_Buttons();
}

Home::~Home()
{
    delete play_button;
    delete quit_button;
}

void Home::update_Home()
{
    change_Screen();
}

void Home::draw_Home()
{
    play_button->draw();
    quit_button->draw();
}
