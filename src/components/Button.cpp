#include "Button.h"

void Button::init_button()
{
    button.height = button_size.y;
    button.width = button_size.x;

    button.x = MathHelper::get_Center(button_position.x, button_size.x);
    button.y = MathHelper::get_Center(button_position.y, button_size.y);

    current_color = idle_color;

    // Text Position
    int text_width = MeasureText(button_text, font_size);
    text_pos_x = MathHelper::get_Center(button_position.x, text_width);
    text_pos_y = MathHelper::get_Center(button_position.y, font_size);
}

Button::Button(Vector2 button_size, Vector2 button_position, const char *button_text, int font_size, Color text_color, Color idle_color, Color hover_color, Color active_color)
{
    this->button_size.x = button_size.x;
    this->button_size.y = button_size.y;
    this->button_position.x = button_position.x;
    this->button_position.y = button_position.y;
    this->button_text = button_text;

    // Setting Button Colors
    this->idle_color = idle_color;
    this->hover_color = hover_color;
    this->activer_color = active_color;

    // Setting Text Stats
    this->font_size = font_size;
    this->text_color = text_color;

    init_button();
}

Button::~Button()
{
}

void Button::draw()
{
    DrawRectangleRec(button, current_color);
    DrawText(button_text, text_pos_x, text_pos_y, font_size, text_color);
}

bool Button::is_Button_Hover()
{
    const Vector2 mouse_pos = GetMousePosition();

    if (CheckCollisionPointRec(mouse_pos, button))
    {
        current_color = hover_color;

        return true;
    }
    else
    {
        current_color = idle_color;

        return false;
    }
}

bool Button::is_Button_Active()
{
    if (is_Button_Hover())
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            current_color = activer_color;

            return true;
        }
        else
        {
            current_color = hover_color;

            return false;
        }
    }
    else
    {
        current_color = idle_color;

        return false;
    }
}
