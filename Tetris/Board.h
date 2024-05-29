#pragma once

#include <array>
#include <SFML/Graphics.hpp>
#include "Tetramino.h"

constexpr int N = 20;
constexpr int M = 10;

class Game;

class Board
{
public:
	Board(Game* _game);

	int score();
	int lines();

	void draw(sf::RenderWindow* window);

	void addNext(Tetramino& t);	
	bool isGameOver();
	void clear();

	void eventHeandler(const sf::Event& event);

	void update();
	void move();

protected:
	void checkAndDel();
	void delLayer(int);
	void notify();

private:
	std::array<std::array<bool, M>, N> m_board;
	std::array<std::array<sf::RectangleShape, M>, N> m_shape;
	Tetramino main;
	Tetramino prev;
	int m_score;
	int m_lines;	
	Game* m_game;
};

