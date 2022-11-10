#include "game.h"

Game::Game(int size)
	:_size(size), _score(0), _nbMouvement(0), _isLose(false)
{
	srand(time(NULL));
	for (int i = 0; i < size*size; i++)
	{
		_board.push_back(0);
	}
	addRandomCase();
	addRandomCase();
}

Game::Game()
	:_score(0), _nbMouvement(0), _isLose(false)
{
	srand(time(NULL));
	std::cout << "Enter game size : ";
	std::cin >> _size;
	for (int i = 0; i < _size * _size; i++)
	{
		_board.push_back(0);
	}
	addRandomCase();
	addRandomCase();
}

void Game::displayBoard()
{
	std::cout << "score : " << _score << " nombre de coups : " << _nbMouvement << "\n";
	for (int i = 0; i < _size * 7 + 1; i++)
	{
		std::cout << "-";
	}
	std::cout << "\n";
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if(_board.at(i * _size + j) < 10 )
				std::cout << "| " << _board.at(i*_size + j) << "    ";
			else if (_board.at(i * _size + j) < 100)
				std::cout << "| " << _board.at(i * _size + j) << "   ";
			else if (_board.at(i * _size + j) < 1000)
				std::cout << "| " << _board.at(i * _size + j) << "  ";
			else 
				std::cout << "| " << _board.at(i * _size + j) << " ";
		}
		std::cout << "|" << std::endl;
		for (int i = 0; i < _size * 7 + 1; i++)
		{
			std::cout << "-";
		}
		std::cout << "\n";
	}
}

int Game::getCase(int x, int y)
{
	if (x <= _size && y <= _size && x >= 0 && y <= 0)
		return _board.at(x * _size + y);
	else return -1;
}

void Game::setCase( int x, int y, int value)
{
	if (x <= _size && y <= _size && x >= 0 && y <= 0)
		_board.at(x * _size + y) = value;
	else std::cout << "non-valid case\n";
}

bool Game::GetIsLose()
{
	return _isLose;
}

void Game::addRandomCase()
{
	int randomValue = ((rand() % 2) +1 ) * 2;
	int randomCase = 0;
	do
	{
		randomCase = (rand() % (_size * _size));
	} while (_board.at(randomCase) != 0);
	_board.at(randomCase) = randomValue;
}

bool Game::move(char direction)
{
	bool mouvement = false;
	switch (direction)
	{
	case 'z':
		mouvement = moveUp();
		break;
	case 's':
		mouvement = moveDown();
		break;
	case 'q':
		mouvement = moveLeft();
		break;
	case 'd':
		mouvement = moveRight();
		break;
	case 'o':
		mouvement = true;
		break;
	default:
		break;
	}
	if (mouvement)
		this->addRandomCase();
	return mouvement;
}





