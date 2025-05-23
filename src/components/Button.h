#pragma once
#include <string.h>
#include <vector>

#include "../common.h"

class Button
{
private:
    // Private Functions
    void init_button();

public:
    // Public Functions & Members

    // Constructor & Destructor
    Button(Vector2 button_size, Vector2 button_position, const char *button_text, int font_size = 20, Color text_color = BLACK,
           Color idle_color = LIGHTGRAY, Color hover_color = GRAY, Color active_color = BLUE);
    ~Button();

    // Main Button Functions
    void draw();

    // Return Functions
    bool is_Button_Hover();
    bool is_Button_Active();

private:
    // Private Members
    // Button Stats
    Rectangle button;
    Vector2 button_size;
    Vector2 button_position;

    // Button Colors
    Color current_color;
    Color idle_color;
    Color hover_color;
    Color activer_color;

    // Text Stats
    const char *button_text;
    int text_pos_x;
    int text_pos_y;
    int font_size;
    Color text_color;
};