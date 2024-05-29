#pragma once
#include <SFML/Graphics.hpp>
//#include <memory>
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	void run();
	void update(Board& b);

private:
	sf::RenderWindow *window;
	int b_score = 0;
	int b_lines = 0;
	sf::Text t_score;
	sf::Text t_lines;
};

