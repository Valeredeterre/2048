#include "game.h"

int main()
{
	Game game(3);
	while (!game.GetIsLose())
	{
		game.displayBoard();
		Sleep(500);
		do
		{
			std::cout << "Enter a direction (z,q,s,d) or 'e' to quit:\n";
		}
		while (!game.move());
		//game.checkIsLoose();
	}
	return EXIT_SUCCESS;
}