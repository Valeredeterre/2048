#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

class Game
{
public:
	Game(int size);
	Game();
	void displayBoard();
	int getCase(int x, int y);
	void setCase(int x, int y, int value);
	bool GetIsLose();
	
private:
	//bool moveUp();
	//bool moveLeft();
	//bool moveDown();
	//bool moveRight();
	void addRandomCase();
	bool move(char direction);
	int _size;
	std::vector<int> _board;
	int _score;
	int _nbMouvement;
	bool _isLose;
};

