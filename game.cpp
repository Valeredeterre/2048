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
	std::cout << "\nscore : " << _score << "\033[1;93;49m" << " nombre de coups : " << "\033[0m" << _nbMouvement << "\n";
	for (int i = 0; i < _size * 7 + 1; i++)
	{
		std::cout << "\033[1;93;49m" << "-" << "\033[0m";
	}
	std::cout << "\n";
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if(_board.at(i * _size + j) < 10 )
				std::cout << "\033[1;93;49m" << "| " << "\033[0m" << _board.at(i*_size + j) << "    ";
			else if (_board.at(i * _size + j) < 100)
				std::cout << "\033[1;93;49m" << "| " << "\033[0m" << _board.at(i * _size + j) << "   ";
			else if (_board.at(i * _size + j) < 1000)
				std::cout << "\033[1;93;49m" << "| " << "\033[0m" << _board.at(i * _size + j) << "  ";
			else 
				std::cout << "\033[1;93;49m" << "| " << "\033[0m" << _board.at(i * _size + j) << " ";
		}
		std::cout << "\033[1;93;49m" << "|" << "\033[0m" << std::endl;
		for (int i = 0; i < _size * 7 + 1; i++)
		{
			std::cout << "\033[1;93;49m" << "-" << "\033[0m";
		}
		std::cout << "\n";
	}
}

int Game::getCase(int x, int y)
{
	if (x < _size && y < _size && x >= 0 && y >= 0)
		return _board.at(y * _size + x);
	else return -1;
}

void Game::setCase( int x, int y, int value)
{
	if (x < _size && y < _size && x >= 0 && y >= 0)
		_board.at(y * _size + x) = value;
	else std::cout << "non-valid case\n";
}

bool Game::GetIsLose()
{
	return _isLose;
}

void Game::addRandomCase()
{
	bool isFull = true;
	for (int i = 0; i < _size * _size; i++)
	{
		if (_board.at(i) == 0)
		{
			isFull = false;
		}
	}
	
	if (!isFull)
	{
		int randomValue = ((rand() % 2) + 1) * 2;
		int randomCase = 0;
		do
		{
			randomCase = (rand() % (_size * _size));
		} while (_board.at(randomCase) != 0);
		_board.at(randomCase) = randomValue;
	}
	else std::cout << "board is full\n";
}

void Game::checkIsLoose()
{
	bool loose = true;
	
	for (int i = 0; i < _size * _size; i++)
	{
		if (_board.at(i) == 0)
			loose = false;
		if ((_board.at(i) == _board.at(i + _size)) && _board.at(i) <= _size * _size - _size)
			loose = false;
		if (i - 1 % _size != 0 && _board.at(i) == _board.at(i - 1))
			loose = false;
	}
	
	_isLose = loose;
}

bool Game::move()
{
	bool mouvement = false;
	char direction = _getch();
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
	case 'e':
		_isLose = true;
		mouvement = true;
		break;
	default:
		std::cout << "non valid key\n";
		break;
	}
	if (mouvement)
		addRandomCase();
		_nbMouvement++;
	return mouvement;
}

bool Game::moveUp()
{
	bool mouvement = false;
	for (int i = 0; i < _size; i++)
	{
		for (int j = _size - 2; j >= 0 ; j--)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i, j + 1));
				setCase(i, j + 1, 0);
				mouvement = true;
			}
		}

		for (int j = 0; j < _size - 1; j++)
		{
			if (getCase(i, j) == getCase(i, j + 1))
			{
				int newValue = getCase(i, j + 1) * 2;
				_score += newValue;
				setCase(i, j, newValue);
				setCase(i, j + 1, 0);
				j++;
			}
		}

		for (int j = _size - 2; j >= 0; j--)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i, j + 1));
				setCase(i, j + 1, 0);
				mouvement = true;
			}
		}
	}
	return mouvement;
}

bool Game::moveDown()
{
	bool mouvement = false;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 1 ; j <= _size - 1; j++)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i, j - 1));
				setCase(i, j - 1, 0);
				mouvement = true;
			}
		}

		for (int j = _size - 1; j > 0; j--)
		{
			if (getCase(i, j) == getCase(i, j + 1))
			{
				int newValue = getCase(i, j + 1) * 2;
				_score += newValue;
				setCase(i, j, newValue);
				setCase(i, j + 1, 0);
				j--;
			}
		}

		for (int j = 1; j <= _size - 1; j++)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i, j - 1));
				setCase(i, j - 1, 0);
				mouvement = true;
			}
		}
	}
	return mouvement;
}

bool Game::moveRight()
{
	bool mouvement = false;
	for (int j = 0; j < _size; j++)
	{
		for (int i = 1; i <= _size - 1; i++)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i - 1, j));
				setCase(i - 1, j, 0);
				mouvement = true;
			}
		}

		for (int i = _size - 1; i > 0; i--)
		{
			if (getCase(i, j) == getCase(i + 1, j--))
			{
				int newValue = getCase(i + 1, j) * 2;
				_score += newValue;
				setCase(i, j, newValue);
				setCase(i + 1, j, 0);
				i--;
			}
		}

		for (int i = 1; i <= _size - 1; i++)
		{
			if (getCase(i, j) == 0)
			{
				setCase(i, j, getCase(i - 1, j));
				setCase(i - 1, j, 0);
				mouvement = true;
			}
		}
	}
	return mouvement;
}

bool Game::moveLeft()
{
	bool mouvement = false;
	return mouvement;
}


