#include "Tetramino.h"
#include <array>

Tetramino::Tetramino(const TetroType& _type)
	:tetro(4)
{
	setType(_type);
}

void Tetramino::setType(const TetroType& type)
{
	this->type = type;
	switch (type) {
	case TetroType::L: 
		initL();
		break;
	case TetroType::J:	
		initJ();
		break;
	case TetroType::I:
		initI();
		break;
	case TetroType::O:
		initO();
		break;
	case TetroType::T:
		initT();
		break;
	case TetroType::S:
		initS();
		break;
	case TetroType::Z:
		initZ();
		break;

	default:
		this->type = type;
		break;
	}
}

const std::vector<Point>& Tetramino::getPosition()
{
	return tetro;
}

bool Tetramino::isAlive(const std::array<std::array<bool, 10U>, 20U>& board, const int M, const int N) const
{
	for (int i = 0; i < 4; i++) {
		if (tetro[i].x < 0 || tetro[i].y < 0 || tetro[i].x >= M || tetro[i].y >= N)
			return false;
		else if (board[tetro[i].y][tetro[i].x])
			return false;
	}

	return true;
}

void Tetramino::rotate()
{
	if (type == TetroType::NONE || type == TetroType::O) return;
	 
	Point p = tetro[1]; // задаем центр вращени€
	for (int i = 0; i < 4; i++)
	{
		int x = tetro[i].y - p.y; //y-y0
		int y = tetro[i].x - p.x; //x-x0
		tetro[i].x = p.x - x;
		tetro[i].y = p.y + y;
	}
	// ¬ышли за пределы пол€ после поворота? “огда возвращаем старые координаты 
	//if (!check()) { for (int i = 0; i < 4; i++) a[i] = b[i]; }
}

void Tetramino::moveHorizontal(const int& dx)
{
	for (int i = 0; i < 4; i++) tetro[i].x += dx;
}

void Tetramino::moveVertical(const int& dy)
{
	for (int i = 0; i < 4; i++) tetro[i].y += dy;
}

bool Tetramino::operator==(const Tetramino& t) 
{
	if (this->tetro.size() != t.tetro.size()) return false;
	for (size_t i = 0; i < t.tetro.size(); i++) {
		if (this->tetro[i] != t.tetro[i])
			return false;
	}
	return true;
}

void Tetramino::initL()
{
	tetro[0].x = 0;
	tetro[0].y = 1;
	tetro[1].x = 1;
	tetro[1].y = 1;
	tetro[2].x = 2;
	tetro[2].y = 1;
	tetro[3].x = 2;
	tetro[3].y = 0;
}

void Tetramino::initJ()
{
	tetro[0].x = 0;
	tetro[0].y = 0;
	tetro[1].x = 1;
	tetro[1].y = 0;
	tetro[2].x = 2;
	tetro[2].y = 0;
	tetro[3].x = 2;
	tetro[3].y = 1;
}

void Tetramino::initT()
{
	tetro[0].x = 0;
	tetro[0].y = 1;
	tetro[1].x = 1;
	tetro[1].y = 1;
	tetro[2].x = 2;
	tetro[2].y = 1;
	tetro[3].x = 1;
	tetro[3].y = 0;
}

void Tetramino::initI()
{
	tetro[0].x = 0;
	tetro[0].y = 0;
	tetro[1].x = 1;
	tetro[1].y = 0;
	tetro[2].x = 2;
	tetro[2].y = 0;
	tetro[3].x = 3;
	tetro[3].y = 0;
}

void Tetramino::initS()
{
	tetro[0].x = 0;
	tetro[0].y = 0;
	tetro[1].x = 0;
	tetro[1].y = 1;
	tetro[2].x = 1;
	tetro[2].y = 1;
	tetro[3].x = 1;
	tetro[3].y = 2;
}

void Tetramino::initZ()
{
	tetro[0].x = 1;
	tetro[0].y = 0;
	tetro[1].x = 1;
	tetro[1].y = 1;
	tetro[2].x = 0;
	tetro[2].y = 1;
	tetro[3].x = 0;
	tetro[3].y = 2;
}

void Tetramino::initO()
{
	tetro[0].x = 0;
	tetro[0].y = 0;
	tetro[1].x = 1;
	tetro[1].y = 0;
	tetro[2].x = 1;
	tetro[2].y = 1;
	tetro[3].x = 0;
	tetro[3].y = 1;
}
