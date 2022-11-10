#include "game.h"
#include <conio.h>

int main()
{
	char input = ' ';
	Game game(4);
	game.displayBoard();
	//while (!game.GetIsLose() && input != 'o')
	//{
	//	game.displayBoard();
	//	do
	//	{
	//		std::cout << "Enter a direction (z,q,s,d) or q to quit:  ";
	//		input = _getch();
	//		std::cout imput;
	//	}
	//	while (!game.move(input));
	//}
	return EXIT_SUCCESS;
}