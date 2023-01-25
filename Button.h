#pragma once
#include "graphics.h"
#include "Widget.h"

class Button: public Widget {
	bool continuous;
	bool state = 0;
	int size_vertical;
	int size_horizontal;
	int pos_vertical;
	int pos_horizontal;
public:
	void update(bool new_state);
	void draw();
	void init(int s_v, int s_h, int p_v, int p_h);
	bool inBounds();
	bool pressButton(Button * button);
	Button(bool continuous = 1);
	~Button();
};