#include "Button.h"
#include "graphics.h"

void Button::update(bool new_state)
{
	//True is pressed button and False is not pressed
	//this method updetes the state of the button
	state = new_state;
}

void Button::draw() //draws the button 
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.3f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.6f;
	if (state) {
		br.fill_color[0] = 0.7f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.9f;
	}
	graphics::drawRect(pos_horizontal, pos_vertical, size_horizontal, size_vertical, br);
}

void Button::init(int s_v, int s_h, int p_v, int p_h)
{
	size_vertical = s_v;
	size_horizontal = s_h;
	pos_vertical = p_v;
	pos_horizontal = p_h;
}

bool Button::inBounds() {
	//checks if the mouses coordinates are on the button
	//depends if the button was already pressed
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	if (continuous) {
		return mouse.button_left_down && graphics::windowToCanvasX(mouse.cur_pos_x) < pos_horizontal + size_horizontal / 2 && graphics::windowToCanvasY(mouse.cur_pos_y) < pos_vertical + size_vertical / 2 && graphics::windowToCanvasX(mouse.cur_pos_x) > pos_horizontal - size_horizontal / 2 && graphics::windowToCanvasY(mouse.cur_pos_y) > pos_vertical - size_vertical / 2;
	}
	return mouse.button_left_pressed && graphics::windowToCanvasX(mouse.cur_pos_x) < pos_horizontal + size_horizontal/2 && graphics::windowToCanvasY(mouse.cur_pos_y) < pos_vertical + size_vertical/2 && graphics::windowToCanvasX(mouse.cur_pos_x) > pos_horizontal - size_horizontal/2 && graphics::windowToCanvasY(mouse.cur_pos_y) > pos_vertical - size_vertical/2;
}

bool Button::pressButton(Button * button)
{
	//if thhe mouse is in bound then it can press the button and change its state
	if (button->inBounds()) {
		button->update(1);
		return 1;
	}
	else {
		button->update(0);
		return 0;
	}
}

Button::Button(bool cont)
{
	continuous = cont;
}

Button::~Button()
{
}


