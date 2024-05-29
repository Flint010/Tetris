#include "Board.h"
#include <vector>
#include <random>
#include "Game.h"

constexpr int size = 20;
constexpr int H = N * size;
constexpr int W = M * size;


Board::Board(Game* _game)
	:m_board(), m_score(0), m_lines(0), m_game(_game)
{	
	for (size_t i = 0; i < m_shape.size(); i++) {
		for (size_t j = 0; j < m_shape[0].size(); j++) {
			m_board[i][j] = false;
			m_shape[i][j].setSize(sf::Vector2f(size, size));
			m_shape[i][j].setFillColor(sf::Color::Cyan);
			m_shape[i][j].setOutlineColor(sf::Color::Black);
			m_shape[i][j].setOutlineThickness(2);
			m_shape[i][j].setPosition(sf::Vector2f((int)j*size + 20, (int)i*size + 50));
		}
	}
}

int Board::score()
{
	return m_score;
}

int Board::lines()
{
	return m_lines;
}

void Board::draw(sf::RenderWindow* window)
{
	for(auto& arr: m_shape) 
		for(auto& x: arr)
			window->draw(x);
}

void Board::addNext(Tetramino& t)
{	
	t.moveHorizontal(4);
	prev = t;
	main = t;
}

bool Board::isGameOver()
{
	for (size_t i = 0; i < m_board[0].size(); i++) {
		if (m_board[0][i])
			return true;
	}
	return false;
}

void Board::clear()
{
	m_lines = 0;
	m_score = 0;
	for (size_t i = 0; i < m_shape.size(); i++) {
		for (size_t j = 0; j < m_shape[0].size(); j++) {
			m_board[i][j] = 0;
			m_shape[i][j].setFillColor(sf::Color::Cyan);		
		}
	}
	notify();
}

void Board::eventHeandler(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left) {
		prev = main;
		main.moveHorizontal(-1);
		update();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
		prev = main;
		main.moveHorizontal(1);
		update();
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) {
		prev = main;
		main.rotate();
		update();
	}
}

void Board::update()
{
	//if (prev == main) return;

	const auto pos_prev = prev.getPosition();
	for (auto& t : pos_prev) {
		m_board[t.y][t.x] = 0;
		m_shape[t.y][t.x].setFillColor(sf::Color::Cyan);
	}

	if (!main.isAlive(m_board, M, N)) {
		main = prev;
	}

	const auto pos = main.getPosition();

	for (auto& t: pos) {
		m_board[t.y][t.x] = 1;
		m_shape[t.y][t.x].setFillColor(sf::Color::Red);
	}
	prev = main;
}

void Board::move()
{
	prev = main;
	main.moveVertical(1);
	
	const auto pos_prev = prev.getPosition();
	for (const auto& t : pos_prev) {
		m_board[t.y][t.x] = 0;
		m_shape[t.y][t.x].setFillColor(sf::Color::Cyan);
	}

	if (!main.isAlive(m_board, M, N)) {
		main = prev;
		const auto pos = main.getPosition();
		for (auto& t : pos) {
			m_board[t.y][t.x] = 1;
			m_shape[t.y][t.x].setFillColor(sf::Color::Red);
		}
		checkAndDel();

		TetroType type = static_cast<TetroType>(rand() % (int)TetroType::NONE);

		Tetramino t(type);
		addNext(t);
	}
}

void Board::checkAndDel()
{
	int count = 0;
	bool delFlag = true;
	for (int i = (int)m_board.size() - 1; i >= 0; i--) {
		delFlag = true;
		for (size_t j = 0; j < m_board[0].size(); j++) {
			if (!m_board[i][j]) {
				delFlag = false;
				break;
			}				
		}
		if (delFlag) {
			delLayer(i);
			m_lines++;
			count++;
			i++;
		}			
	}

	switch (count)
	{
	case 1:
		m_score += 10;
		break;
	case 2:
		m_score += 30;
		break;
	case 3:
		m_score += 45;
		break;
	case 4:
		m_score += 100;
		break;
	default:
		break;
	}
	if (count > 0) notify();
}

void Board::delLayer(int ind)
{
	for (size_t i = 0; i < m_board[0].size(); i++) {
		m_board[ind][i] = 0;
		m_shape[ind][i].setFillColor(sf::Color::Cyan);
	}

	for (int i = ind-1; i >= 0; i--) {
		for (size_t j = 0; j < m_board[0].size(); j++) {
			m_board[i+1][j] = m_board[i][j];
			m_shape[i+1][j].setFillColor(m_shape[i][j].getFillColor());
		}		
	}
}

void Board::notify()
{
	m_game->update(*this);
}

