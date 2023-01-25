#pragma once

#include "graphics.h"
#include "Widget.h"
#include "Button.h"
#include "Bar.h"
#include "config.h"
#include "Movie.h"

class FilmBrowser {
	Button* button_drama = nullptr;
	Button* button_comedy = nullptr;
	Button* button_crime = nullptr;
	Button* button_adventure = nullptr;
	Button* button_action = nullptr;
	Button* button_scifi = nullptr;
	Button* button_history = nullptr;
	Button* button_fantasy = nullptr;

	Button* button_bar_up = nullptr;
	Button* button_bar_down = nullptr;
	bool b_init = 0;
	
	Bar* bar = nullptr;
	bool bar_init = 0;

	Movie movie_collection[20];
	Movie current_movie;
	int active_movies = 20;
	int selec;
	graphics::Brush brr;
	graphics::Brush br;

public:
	void update();
	void draw();
	void init();
	FilmBrowser();
	~FilmBrowser();
};