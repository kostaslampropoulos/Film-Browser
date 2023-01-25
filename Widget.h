#pragma once

class Widget {
	int size_vertical;
	int size_horizontal;
	int pos_vertical;
	int pos_horizontal;
public:
	void update(int p_v, int p_h);
	void draw();
	void init(int s_v, int s_h, int p_v, int p_h);
	Widget();
	~Widget();
};