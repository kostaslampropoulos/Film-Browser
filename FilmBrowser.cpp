#include "FilmBrowser.h"
#include <iostream>
void FilmBrowser::update()
{
	//initialization of all the buttons 
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
	if (!b_init && graphics::getGlobalTime() > 100) {
		b_init = 1;

		button_action = new Button();
		button_action->init(30, 80, 220 , 50);
		button_adventure = new Button();
		button_adventure->init(30, 80, 255, 50);
		button_comedy = new Button();
		button_comedy->init(30, 80, 290, 50);
		button_crime = new Button();
		button_crime->init(30, 80, 325, 50);
		button_drama = new Button();
		button_drama->init(30, 80, 360, 50);
		button_fantasy = new Button();
		button_fantasy->init(30, 80, 395, 50);
		button_history = new Button();
		button_history->init(30, 80, 430, 50);
		button_scifi = new Button();
		button_scifi->init(30, 80, 465, 50);
		button_bar_up = new Button(0);
		button_bar_up->init(25,20,12,990);
		button_bar_down = new Button(0);
		button_bar_down->init(25, 20, 487, 990);
	}
	
	if (button_action) {
		button_action->pressButton(button_action);
	}
	if (button_adventure) {
		button_adventure->pressButton(button_adventure);
	}
	if (button_comedy) {
		button_comedy->pressButton(button_comedy);
	}
	if (button_crime) {
		button_crime->pressButton(button_crime);
	}
	if (button_drama) {
		button_drama->pressButton(button_drama);
	}
	if (button_fantasy) {
		button_fantasy->pressButton(button_fantasy);
	}
	if (button_history) {
		button_history->pressButton(button_history);
	}
	if (button_scifi) {
		button_scifi->pressButton(button_scifi);
	}
	if (button_bar_up) {
		//button that moves the scrollbar up
		//it depends on the number of movies
		if (button_bar_up->pressButton(button_bar_up) && bar->inBoundsUp()) {
			bar->update(bar->get_bar_center_y() - 450 / active_movies, 0);
		}
	}
	if (button_bar_down) {
		//button that moves the scrollbar down
		//it depends on the number of movies
		if (button_bar_down->pressButton(button_bar_down) && bar->inBoundsDown()) {
			bar->update(bar->get_bar_center_y() + 450 / active_movies, 0);
		}
	}
	
	//initiaization of the scroll bar
	if (!bar_init && graphics::getGlobalTime() > 100) {
		bar_init = 1;
		bar = new Bar();
		bar->init(990, 250, 20, 450, 990, 25+225/active_movies, 15, 450/active_movies);
	}
	if (bar) {
		bar->scrollBar(bar);
	}
	
}

void FilmBrowser::draw()
{	
	//Draws all the widgets

	graphics::drawRect(100, 250, 200, 500, br);

	if (button_action) {
		button_action->draw();
		graphics::drawText(25, 228, 20, "Action", brr);
	}
	if (button_adventure) {
		button_adventure->draw();
		graphics::drawText(13, 262, 18, "Adventure", brr);
	}
	if (button_comedy) {
		button_comedy->draw();
		graphics::drawText(18, 297, 20, "Comedy", brr);
	}
	if (button_crime) {
		button_crime->draw();
		graphics::drawText(27, 332, 20, "Crime", brr);
	}
	if (button_drama) {
		button_drama->draw();
		graphics::drawText(23, 367, 20, "Drama", brr);
	}
	if (button_fantasy) {
		button_fantasy->draw();
		graphics::drawText(20, 402, 19, "Fantasy", brr);
	}
	if (button_history) {
		button_history->draw();
		graphics::drawText(22, 437, 20, "History", brr);
	}
	if (button_scifi) {
		button_scifi->draw();
		graphics::drawText(30, 472, 20, "SciFi", brr);
	}
	if (bar) {
		bar->draw();
	}
	if (button_bar_up) {
		button_bar_up->draw();
	}
	if (button_bar_down) {
		button_bar_down->draw();
	}
	
	//of the bar is moved the selected movie(index selec) changes
	//then the new selected movie is being displayed
	//thats because 
	if (bar) {
		selec = div(bar->get_bar_center_y(), 450 / active_movies).quot-1;
	}
	else {
		selec = 0;
	}
	if (selec > active_movies) {
		selec = active_movies;
	}
	if (selec < 0) {
		selec = 0;
	}

	//Draw the movie details
	current_movie = movie_collection[selec];
	current_movie.draw();
	graphics::drawText(570,50,45, current_movie.get_title(), brr);
	graphics::drawText(570, 100, 25, "Director:  " + current_movie.get_director(), brr);
	graphics::drawText(570, 150, 25, "Stars:  " + current_movie.get_cast(), brr);
	graphics::drawText(570, 200, 25, "Year:  " + current_movie.get_production_year(), brr);
}

void FilmBrowser::init()
{
	//initialization of the movies on the array
	
	graphics::preloadBitmaps(ASSET_PATH);
	graphics::setFont(std::string(ASSET_PATH) + "nonserif.ttf");

	movie_collection[0] = Movie("The Godfather", std::string(ASSET_PATH) + "godfather.png", "Francis Ford Coppola", "Marlon Brando, Al Pacino, James Caan", "The aging patriarch of an organized crime dynasty in postwar New York City transfers control of his clandestine empire to his reluctant youngest son.", "Crime, Drama", "1972", "175");
	movie_collection[1] = Movie("The Godfather Part II", std::string(ASSET_PATH) + "godfather2.png", "Francis Ford Coppola", "Robert De Niro, Al Pacino, Robert Duvall", "The early life and career of Vito Corleone in 1920s New York City is portrayed, while his son, Michael, expands and tightens his grip on the family crime syndicate.", "Crime, Drama", "1974", "202");
	movie_collection[2] = Movie("Inception", std::string(ASSET_PATH) + "inception.png", "Christopher Nolan", "Leonardo Dicaprio, Joseph Gordon-Levitt, Elliot Page, Tom Hardy", "A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a C.E.O., but his tragic past may doom the project and his team to disaster.", "Action, Adventure, SciFi", "2010", "158");
	movie_collection[3] = Movie("Independence Day", std::string(ASSET_PATH) + "indepedenceday.png", "Roland Emmerich", "Will Smith, Bill Pullman, Jeff Goldblum", "The aliens are coming and their goal is to invade and destroy Earth. Fighting superior technology, mankind's best weapon is the will to survive.", "Action, SciFi", "1996", "145");
	movie_collection[4] = Movie("The Shawshank Redemption", std::string(ASSET_PATH) + "shawshank.png", "Frank Darabont", "Tim Robbins, Morgan Freeman, Bob Gunton", "Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.", "Drama", "1994", "142");
	movie_collection[5] = Movie("Good Will Hunting", std::string(ASSET_PATH) + "goodwillhunting.png", "Gus Van Sant", "Robin Williams, Matt Damon, Ben Affleck", "Will Hunting, a janitor at M.I.T., has a gift for mathematics, but needs help from a psychologist to find direction in his life.", "Drama, Romance", "1997", "126");
	movie_collection[6] = Movie("Schindler's List", std::string(ASSET_PATH) + "schindlerslist.png", "Steven Spielberg", "Liam Neeson, Ralph Fiennes, Ben Kingsley", "In German - occupied Poland during World War II, industrialist Oskar Schindler gradually becomes concerned for his Jewish workforce after witnessing their persecution by the Nazis", "Drama, History", "1993", "195"); 
	movie_collection[7] = Movie("The Lord of the Rings: The Fellowship of the Ring", std::string(ASSET_PATH) + "lotr1.png", "Peter Jackson", "Elijah Wood, Ian McKellen, Orlando Bloom", "A meek Hobbit from the Shire and eight companions set out on a journey to destroy the powerful One Ring and save Middle-earth from the Dark Lord Sauron.", "Action, Adventure, Fantasy", "2001", "198");
	movie_collection[8] = Movie("The Lord of the Rings: The Two Towers", std::string(ASSET_PATH) + "lotr2.png", "Peter Jackson", "Elijah Wood, Ian McKellen, Viggo Mortensen", "While Frodo and Sam edge closer to Mordor with the help of the shifty Gollum, the divided fellowship makes a stand against Sauron's new ally, Saruman, and his hordes of Isengard.", "Action, Adventure, Fantasy", "2002", "199");
	movie_collection[9] = Movie("The Lord of the Rings: The Return of the King", std::string(ASSET_PATH) + "lotr3.png", "Peter Jackson", "Elijah Wood, Ian McKellen, Viggo Mortensen", "Gandalf and Aragorn lead the World of Men against Sauron's army to draw his gaze from Frodo and Sam as they approach Mount Doom with the One Ring.", "Action, Adventure, Fantasy", "2003", "201");
	movie_collection[10] = Movie("The Dark Knight", std::string(ASSET_PATH) + "darkknight.png", "Christopher Nolan", "Christian Bale, Heath Ledger, Aaron Eckhart", "When the menace known as the Joker wreaks havoc and chaos on the people of Gotham, Batman must accept one of the greatest psychological and physical tests of his ability to fight injustice.", "Action, Crime", "2008", "152");
	movie_collection[11] = Movie("Pulp Fiction", std::string(ASSET_PATH) + "pulpfiction.png", "Quentin Tarantino", "John Travolta, Uma Thurman, Samuel L. Jackson", "The lives of two mob hitmen, a boxer, a gangster and his wife, and a pair of diner bandits intertwine in four tales of violence and redemption.", "Crime, Drama", "1994", "154");
	movie_collection[12] = Movie("Forrest Gump", std::string(ASSET_PATH) + "forrestgump.png", "Robert Zemeckis", "Tom Hanks, Robin Wright, Gary Sinise", "The presidencies of Kennedy and Johnson, the Vietnam War, the Watergate scandal and other historical events unfold from the perspective of an Alabama man with an IQ of 75, whose only desire is to be reunited with his childhood sweetheart.", "Drama, Comedy", "1994", "142");
	movie_collection[13] = Movie("Fight Club", std::string(ASSET_PATH) + "fightclub.png", "David Fincher", "Brad Pitt, Edward Norton", "An insomniac office worker and a devil - may - care soap maker form an underground fight club that evolves into much more.","Drama", "1999", "139");
	movie_collection[14] = Movie("Star Wars: Episode 5 - The Empire Strikes Back", std::string(ASSET_PATH) + "starwars5.png", "Irvin Kershner", "Mark Hamil, Harrison Ford, Carrie Fisher", "After the Rebels are brutally overpowered by the Empire on the ice planet Hoth, Luke Skywalker begins Jedi training with Yoda, while his friends are pursued across the galaxy by Darth Vader and bounty hunter Boba Fett", "Action, Adventure, SciFi", "1980", "124");
	movie_collection[15] = Movie("The Matrix", std::string(ASSET_PATH) + "matrix.png", "Lana Wachowski - Lilly Wachowski", "Keanu Reeves, Laurence Fishburne, Carrie - Anne Moss", "When a beautiful stranger leads computer hacker Neo to a forbidding underworld, he discovers the shocking truth--the life he knows is the elaborate deception of an evil cyber - intelligence.", "Action, SciFi", "1999", "136");
	movie_collection[16] = Movie("Goodfellas", std::string(ASSET_PATH) + "goodfellas.png", "Martin Scorsese", "Robert De Niro, Ray Liotta, Joe Pesci", "The story of Henry Hill and his life in the mob, covering his relationship with his wife Karen Hill and his mob partners Jimmy Conway and Tommy DeVito in the Italian - American crime syndicate.", "Crime, Drama", "1990", "145");
	movie_collection[17] = Movie("Seven", std::string(ASSET_PATH) + "seven.png", "David Fincher", "Brad Pitt, Morgan Freeman, Kevin Spacey", "Two detectives, a rookie and a veteran, hunt a serial killer who uses the seven deadly sins as his motives.", "Crime, Drama", "1995", "127");
	movie_collection[18] = Movie("Terminator 2: Judgment Day", std::string(ASSET_PATH) + "terminator2.png", "James Cameron", "Arnold Schwarzenegger, Linda Hamilton, Edward Furlong", "A cyborg, identical to the one who failed to kill Sarah Connor, must now protect her 10-year old adolescent son John from an even more advanced and powerful cyborg.", "Action, SciFi", "1991", "137");
	movie_collection[19] = Movie("Django Unchained", std::string(ASSET_PATH) + "django.png", "Quentin Tarantino", "Jamie Foxx, Christoph Waltz, Leonardo DiCaprio", "With the help of a German bounty-hunter, a freed slave sets out to rescue his wife from a brutal plantation-owner in Mississippi.", "Action, Drama", "2012", "165");
	
	brr.outline_opacity = 0.0f;
	brr.fill_color[0] = 0.0f;
	brr.fill_color[1] = 0.0f;
	brr.fill_color[2] = 0.0f;
	
	br.outline_opacity = 0.0f;
	br.fill_color[0] = 0.1f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.3f;

}
 


FilmBrowser::FilmBrowser()
{
}

FilmBrowser::~FilmBrowser()
{
}
