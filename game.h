#pragma once
#include <vector>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

class Game
{
public:
	Game();
	Game(int size);
	bool move();
	bool GetIsLose();
	void displayBoard();
	void checkIsLoose();
	void setCase(int x, int y, int value);
	
private:
	
	//private methods
	bool moveUp();
	bool moveLeft();
	bool moveDown();
	bool moveRight();
	void addRandomCase();
	int getCase(int x, int y);
	
	//private variables
	int _size;
	int _score;
	bool _isLose;
	int _nbMouvement;
	std::vector<int> _board;
	
};

