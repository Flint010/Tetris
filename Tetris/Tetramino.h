#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

enum class TetroType {
	L=0,
	J,
	T,
	I,
	S,
	Z,
	O,
	NONE
};

struct Point
{
	int x, y;
	inline bool operator==(const Point& p) {
		if (this->x == p.x && this->y == p.y) return true;
		return false;
	}
	inline bool operator!=(const Point& p) {
		if (*this == p) return false;
		return true;
	}
};

class Tetramino
{
public:
	Tetramino(const TetroType& _type = TetroType::NONE);

	void setType(const TetroType& type);

	const std::vector<Point>& getPosition();

	bool isAlive(const std::array<std::array<bool, 10U>, 20U>& board, const int M, const int N) const;

	void rotate();
	void moveHorizontal(const int& dx);
	void moveVertical(const int& dy);

	bool operator==(const Tetramino& t) ;

private:
	void initL();
	void initJ();
	void initT();
	void initI();
	void initS();
	void initZ();
	void initO();


private:
	//sf::RectangleShape tetro;
	std::vector<Point> tetro;
	TetroType type;
};

