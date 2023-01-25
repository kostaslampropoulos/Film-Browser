#include "Widget.h"
#include "graphics.h"

void Widget::update(int p_v, int p_h)
{
	pos_vertical = p_v;
	pos_horizontal = p_h;
}

void Widget::draw()
{
	
}

void Widget::init(int s_v, int s_h, int p_v, int p_h)
{
	size_vertical = s_v;
	size_horizontal = s_h;
	pos_vertical = p_v;
	pos_horizontal = p_h;
}

Widget::Widget()
{

}

Widget::~Widget()
{
}
